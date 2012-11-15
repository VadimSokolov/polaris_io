import re
import sys
import os
# usage: generate_odb_classes.py Link_File.hpp Link Node node_a Node node_b
# here Link is the class name
# Node node_a is the type and field name referenced
# Node node_b is the type and field name referenced

	

def generate(cpp_path, class_name, odb_fh=None, adapter_fh=None):
	fields = []
	types = []
	accessors = []
	#populate fields, types, accessors
	with open(cpp_path.replace("\\","/")) as fh:
		for line in fh:
			m = p.search(line)
			if m is not None:
				types.append(m.group(1))
				fields.append(m.group(3))
				accessors.append(m.group(2))
	nscn = "%s::%s"%(odb_namespace,class_name)		
	# create constructor
	#First part of the constructor
	constructor1 = "%s ( "%class_name
	#Second part of the constructor
	constructor2 = " \n\t: "
	#Adapter from transims type to polaris
	adpater_method = "shared_ptr<%s> %sAdapter( %s_File &file, %s::%s& container) \n{\n\tshared_ptr<%s> result (new %s ());"%(nscn,class_name, class_name, odb_namespace,container_type, nscn, nscn)
	members = ""
	odb_accessors = ""
	#Whether the table has a unique key is a class member
	# if not then a dummy id field will need to be added
	auto_primary_key_member = "\n\t#pragma db id auto\n\tunsigned long auto_id;"
	key_type = "unsigned long"
	for i in range(len(fields)):
		field =  fields[i]
		type = types[i]
		accessor = accessors[i]
		original_type = ""
		#skip the geometry
		if field in ["x", "y", "z"]:
			print "A geo field %s was skipped for relation %s"%(field, class_name)
			continue
		found_flag = False
		ref_type = ""
		for item in ref_types:
			if item.lower() in field.lower():
				found_flag = True
				ref_type = item
		if found_flag and field != class_name.lower():
			original_type = type
			type = "shared_ptr<%s>"%ref_type
		if type == "string":
			type = "std::string"
		if type == "string":
			constructor1 += "const std::string&"
		else:
			constructor1 += type
		constructor1 += " %s_, "%field
		constructor2 += "%s (%s_), "%(field, field)
		if class_name.lower() in field.lower(): #this field is an primary key field
			key_type = type
			auto_primary_key_member = ""
			members += "\t#pragma db id\n"
		members += "\t%s %s;\n"%(type, field)
		
		odb_accessors += "\tconst %s& get%s () const {return %s;}\n"%(type, field.title(), field)
		odb_accessors += "\tvoid set%s (const %s& %s_){%s = %s_;}\n"%(field.title(),type, field,field, field)

		if original_type != "":			
			odb_accessors += "\tvoid set%s (const %s& %s_, %s& container){%s = container.%ss[%s_];}\n"%(field.title(),original_type, field, container_type,field,ref_type,field)
			odb_accessors += "\tconst %s& get%s () const {return %s;}\n"%(type, field.title(), field)
			adpater_method += "\n\tresult->set%s(file.%s (), container); "%(field.title(), accessor)
		else:
			adpater_method += "\n\tresult->set%s(file.%s ()); "%(field.title(), accessor)
	relation_primary_key_types.append(key_type)
	if auto_primary_key_member!="":
		odb_accessors += "\tconst %s& get%s () const {return %s;}\n"%("unsigned long", "Auto_id", "auto_id")	
		

	odb_code = """
#pragma db object
class %s
{
public:
	// Default Constructor
	%s () {}	
	//Contructor
	%s ) %s
	{
	}
	//Accessors
%s
//Data Fields
private:
	friend class odb::access;%s
%s
};
"""%(class_name, class_name, constructor1[:-2], constructor2[:-2],  odb_accessors, auto_primary_key_member, members)
	
	adapter_code = """//Converter for %s
%s
	return result;
}
"""%(class_name, adpater_method[:-1])
	if odb_fh is not None:
		odb_fh.write(odb_code);
	if adapter_fh is not None:
		adapter_fh.write(adapter_code);
					


#parse the command line arguments
s = """
usage: generate_odb_classes.py hpp_file polaris_class_name polaris_class_name field polaris_class_name field ...
example: generate_odb_classes.py Link_File.hpp Link Node node_a Node node_b
here Link is the class name
Node node_a is the type and field name referenced
Node node_b is the type and field name referenced

usage: generate_odb_classes.py generate_all syslib_include_path
usage: generate_odb_classes.py generate_all C:\\Users\\vsokolov\\usr\\transims\\sf-version5\\branches\\aecom\\1457\\SysLib\\Include\\
will generate a single cpp file with the classes defined for the relations defined in File_Service.hpp

"""
if len(sys.argv) < 2:
	print s
	sys.exit()
	
ref_types = []
#this pattern is applied to *_File.hpp file to extract the fileds
p = re.compile("(int|string|double)\s*(\w+).*Get_\w+\s*\((\w+)\)")
#this temlate is applied to File_Service.hpp file to exract the names of *_File objects
p_tables = re.compile("#include\s*\"(\w+)_File\.hpp\"")	
odb_namespace = "pio"
container_type = "InputContainer"
relations = []
relation_primary_key_types = []
if sys.argv[1] == "generate_all" and len(sys.argv)==3:
	syslib_include_path = sys.argv[2]
	temp =  os.path.join(syslib_include_path, "File_Service.hpp")
	if not os.path.exists(temp):
		print "The %s path does not exist, exiting..."%temp
		sys.exit()

	with open(temp, 'r') as fh:
		for line in fh:
			m = p_tables.match(line)
			if m is not None:
				relations.append(m.group(1))
	forward_declarations = ""
	input_container = "class %s \n{\npublic:\n"%container_type


	odb_fh =  open("out\\odb_data_model.h", 'w')
	adapter_fh =  open("out\\adapter_methods.h", 'w') 
	odb_fh.write("namespace %s\n{\n"%odb_namespace)
	for i in range(len(relations)):
		item = relations[i]
		if item.lower() in ["type", "use"]:
			continue
		ref_types.append(item)	
		forward_declarations  += "class %s;\n"%item 	
	forward_declarations += "class %s;\n"%container_type
	odb_fh.write("//Forward declarations.\n//\n"+forward_declarations)
	
	for item in relations:
		print "Processing %s"%item
		generate(os.path.join(syslib_include_path,"%s_File.hpp"%item), item, odb_fh, adapter_fh)
	
	for i in range(len(relations)):
		item = relations[i]
		if item.lower() in ["type", "use"]:
			continue
		
		input_container += "\tstd::map<%s,shared_ptr<%s>> %ss;\n"%(relation_primary_key_types[i],item, item)
	odb_fh.write("//Input Container.\n//\n"+input_container+"};\n")
	odb_fh.write("\n}//end of namespace") #close namespace bracket
	
	
		

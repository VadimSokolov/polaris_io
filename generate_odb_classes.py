import re
import sys
import os
# usage: generate_odb_classes.py Link_File.hpp Link Node node_a Node node_b
# here Link is the class name
# Node node_a is the type and field name referenced
# Node node_b is the type and field name referenced

	

def generate(cpp_path, class_name, out_file_handler=None):
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
				
	# create constructor
	#First part of the constructor
	constructor1 = "%s ( "%class_name
	#Second part of the constructor
	constructor2 = " \n\t: "
	#Constructor - Adpater
	constructor3 = "\n\t %s( %s_File *file) \n\t{"%(class_name,class_name)
	members = ""
	odb_accessors = ""
	for i in range(len(types)):
		field =  fields[i]
		type = types[i]
		accessor = accessors[i]
		original_type = ""
		#skip the geometry
		if field in ["x", "y", "z"]:
			print "A geo field %s was skipped for relation %s"%(field, class_name)
			continue
		found_flag = False
		for item in ref_types:
			if item.lower() in field.lower():
				found_flag = True
				rt = item
		if found_flag and field != class_name.lower():
			original_type = type
			type = "shared_ptr<%s>"%rt
		if type == "string":
			type = "std::string"
		if type == "string":
			constructor1 += "const std::string&"
		else:
			constructor1 += type
		constructor1 += " %s_, "%field
		constructor2 += "%s (%s_), "%(field, field)
		members += "\t%s %s;\n"%(type, field)
		constructor3 += "\n\t\tset%s(file -> %s ()); "%(field.title(), accessor)
		odb_accessors += "\tconst %s& get%s () const {return %s;}\n"%(type, field.title(), field)
		odb_accessors += "\tvoid set%s (const %s& %s_){%s = %s_;}\n"%(field.title(),type, field,field, field)
		if original_type != "":
			odb_accessors += "\tvoid set%s (const %s& %s_){/*TODO: imlement this setter*/;}\n"%(field.title(),original_type, field)

	s = """
#pragma db object
class %s
{
public:
	//Contructor
	%s ) %s
	{
	}
	//ConverterConstructor
	%s
	}
	//Accessors
%s
//Data Fields
private:
	friend class odb::access;
	%s () {}
	#pragma db id
%s
};

	"""%(class_name, constructor1[:-2], constructor2[:-2], constructor3[:-1], odb_accessors, class_name, members)
	if out_file_handler == None:
		print s
	else:
		out_file_handler.write(s);


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

if sys.argv[1] == "generate_all" and len(sys.argv)==3:
	syslib_include_path = sys.argv[2]
	temp =  os.path.join(syslib_include_path, "File_Service.hpp")
	if not os.path.exists(temp):
		print "The %s path does not exist, exiting..."%temp
		sys.exit()
	relations = []
	with open(temp, 'r') as fh:
		for line in fh:
			m = p_tables.match(line)
			if m is not None:
				relations.append(m.group(1))
	for item in relations:
		if item.lower() in ["type", "use"]:
			continue
		ref_types.append(item)
	with open("tables\\all.cpp", 'w') as fh:
		for item in relations:
			print "Processing %s"%item
			generate(os.path.join(syslib_include_path,"%s_File.hpp"%item), item, fh)
		

import re
import sys
import os	

def generate(cpp_path, class_name, odb_fh=None, adapter_fh=None):
	fields = []
	types = []
	accessors = []
	#populate fields, types, accessors
	with open(cpp_path.replace("\\","/")) as fh:
		for line in fh:
			m = file_class_member_p.search(line)
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
	adpater_method = "shared_ptr<%s> Adapter( %s_File &file, %s::%s& container) \n{\n\tshared_ptr<%s> result (new %s ());"%(nscn, class_name, odb_namespace,container_type, nscn, nscn)
	members = ""
	odb_accessors = ""
	#Whether the table has a unique key is a class member
	# if not then a dummy id field will need to be added
	
	key_type = "unsigned long"
	key_field = "auto_id"
	auto_primary_key_member = "\n\t#pragma db id auto\n\t%s %s;"%(key_type, key_field)
	
	for i in range(len(fields)):
		mapping_info = None
		conversion_info = None
		field =  fields[i]
		type = types[i]
		accessor = accessors[i]
		if type in type_map:
			mapping_info = type_map[type]
			type = mapping_info[0]
		if (class_name, field) in field_conversion:
			conversion_info = field_conversion[(class_name, field)]
			type = conversion_info[0]
		original_type = ""
		#skip the geometry
		if field in ["x", "y", "z"]:
			print "A geo field %s was skipped for relation %s"%(field, class_name)
			continue
		ref_type = ""
		#check if this field is a foreign key
		for item in potential_ref_types:
			if item.lower() in field.lower() and (class_name,field) not in false_foreign_keys:
				ref_type = item
		if (class_name,field) in true_ref_fields_types:
			ref_type = true_ref_fields_types[(class_name, field)]
		if ref_type!="" and field != class_name.lower():
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
		if (class_name.lower() in field.lower() and (class_name, field) not in false_primary_keys) or (class_name, field) in true_primary_keys: #this field is a primary key field
			key_type = type
			key_field = field
			auto_primary_key_member = ""
			members += "\t#pragma db id\n"
		members += "\t%s %s;\n"%(type, field)
		
		odb_accessors += "\tconst %s& get%s () const {return %s;}\n"%(type, field.title(), field)
		odb_accessors += "\tvoid set%s (const %s& %s_){%s = %s_;}\n"%(field.title(),type, field,field, field)

		if original_type != "":			
			odb_accessors += "\tvoid set%s (const %s& %s_, %s& container){%s = container.%ss[%s_];}\n"%(field.title(),original_type, field, container_type,field,ref_type,field)
			#odb_accessors += "\tconst %s& get%s () const {return %s;}\n"%(type, field.title(), field)
			adpater_method += "\n\tresult->set%s(file.%s (), container); "%(field.title(), accessor)
			actual_ref_types.append(ref_type)
		elif mapping_info is not None:
			adpater_method += "\n\tresult->set%s(file.%s ().%s()); "%(field.title(), accessor, mapping_info[2])
		elif conversion_info is not None:
			adpater_method += "\n\tresult->set%s(%s(%sfile.%s())); "%( field.title(), conversion_info[1],conversion_info[2], accessor)
		else: 
			adpater_method += "\n\tresult->set%s(file.%s ()); "%(field.title(), accessor)
	odb_accessors += "\tconst %s& get%s () const {return %s;}\n"%(key_type, "PrimaryKey", key_field)
	relation_primary_key_types[class_name] = key_type
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
	return (odb_code, adapter_code)
	# if odb_fh is not None:
		# odb_fh.write(odb_code);
	# if adapter_fh is not None:
		# adapter_fh.write(adapter_code);
					

def generate_head():
	s = """
#ifndef OutNetwork
#define OutNetwork
#pragma warning(disable:4068)

#include <map>
#include <vector>
#include <string>

#include <odb/core.hxx>

// Include TR1 <memory> header in a compiler-specific fashion. Fall back
// on the Boost implementation if the compiler does not support TR1.
//
#include <odb/tr1/memory.hxx>
using std::tr1::shared_ptr;
"""
	return s
#parse the command line arguments
help_msg = """
usage: generate_odb_classes.py syslib_include_path
usage: generate_odb_classes.py C:\\Users\\vsokolov\\usr\\transims\\sf-version5\\branches\\aecom\\1457\\SysLib\\Include\\
will generate a single cpp file with the classes defined for the relations defined in File_Service.hpp

"""
if len(sys.argv) < 2:
	print help_msg
	sys.exit()
	

#this pattern is applied to *_File.hpp file to extract the fileds
file_class_member_p = re.compile("(char|bool|int|string|double|float|short|Dtime)\s*(\w+).*Get_\w+\s*\((\w+)\)")
#this template is applied to File_Service.hpp file to exract the names of *_File objects
p_tables = re.compile("#include\s*\"(\w+)_File\.hpp\"")	
odb_namespace = "pio"
container_type = "InputContainer"
relations = []
relation_primary_key_types = {}
#(relation name, field name)
false_primary_keys = [("Trip", "trip"), ("Vehicle", "vehicle"), ("Sign", "sign"), ("Timing", "timing"), ("Phasing", "phasing")]
#(relation, field name)
false_foreign_keys = [("Phasing","detectors"), ("Ridership", "schedule"),("Event", "schedule")]
#(relation name, field name)
true_primary_keys = [("Veh_Type", "type")]
# (field name, in relation name):referes to relation
true_ref_fields_types = {("Trip","origin"):"Location", ("Trip","destination"):"Location",("Vehicle", "type"):"Veh_Type"}
#transims type -> (polaris type, transims type, transms type getter)
type_map = {"Dtime":("double", "Dtime", "Seconds")}
# (type,field) -> (new type, conversion method, class to cast to)
field_conversion = {("Connect","lanes"):("string", "Static_Service::Lane_Range_Code", "")}
field_conversion[("Connect","to_lanes")] = ("string", "Static_Service::Lane_Range_Code","")
field_conversion[("Connect","type")] = ("string", "Static_Service::Connect_Code","(Connect_Type)")
field_conversion[("Link","type")] = ("string", "Static_Service::Facility_Code","(Facility_Type)")
field_conversion[("Signal","type")] = ("string", "Static_Service::Signal_Code","(Signal_Type)")

potential_ref_types = []
actual_ref_types = []
if len(sys.argv)==2:
	syslib_include_path = sys.argv[1]
	temp =  os.path.join(syslib_include_path, "File_Service.hpp")
	if not os.path.exists(temp):
		print "The %s path does not exist, exiting..."%temp
		sys.exit()
	#populate the relations list
	with open(temp, 'r') as fh:
		for line in fh:
			m = p_tables.match(line)
			if m is not None:
				relations.append(m.group(1))
	#initialize strings anf file handlers
	forward_declarations = ""
	odb_code=""
	adapter_code=""
	input_container = "class %s \n{\npublic:\n"%container_type
	odb_fh =  open("out\\odb_data_model.h", 'w')
	adapter_fh =  open("out\\adapter_methods.h", 'w') 

	#populate potential_ref_types and forward_declarations
	for item in relations:
		if item.lower() not in ["type", "use"] and item not in zip(*false_primary_keys)[0]:			
			potential_ref_types.append(item)	
		forward_declarations  += "class %s;\n"%item 	
	forward_declarations += "class %s;\n"%container_type
	
	#generate c++ code for new classes as well as adapter methods from transims to the new classes
	for item in relations:
		print "Processing %s"%item
		(o,a) = generate(os.path.join(syslib_include_path,"%s_File.hpp"%item), item)
		odb_code+=o
		adapter_code+=a
	#generate input container class
	for i in range(len(relations)):
		item = relations[i]
		if item not in actual_ref_types:
			continue
		input_container += "\tstd::map<%s,shared_ptr<%s>> %ss;\n"%(relation_primary_key_types[item],item, item)
	
	#write content to the files
	odb_fh.write(generate_head())
	odb_fh.write("namespace %s\n{\n"%odb_namespace)	
	odb_fh.write("//Forward declarations.\n//\n"+forward_declarations)
	odb_fh.write("//Input Container.\n//\n"+input_container+"};\n")
	odb_fh.write(odb_code)
	odb_fh.write("\n}//end of namespace\n") #close namespace bracket
	odb_fh.write("#endif // OutNetwork")
	
	adapter_fh.write("""#pragma once
#include "OutNetwork.h"
#include "File_Service.hpp"
""")
	adapter_fh.write(adapter_code)
	
	
		

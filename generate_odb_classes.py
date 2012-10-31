import re
import sys

# usage: generate_odb_classes.py Link_File.hpp Link Node node_a Node node_b
# here Link is the class name
# Node node_a is the type and field name referenced
# Node node_b is the type and field name referenced

cpp_path = sys.argv[1]
class_name = sys.argv[2]

reffield2type = dict()
for i in range(3,len(sys.argv),2):
	reffield2type[sys.argv[i+1]] = sys.argv[i]


	
fields = []
types = []
accessors = []

p = re.compile("(int|string|double)\s*(\w+).*Get_\w+\s*\((\w+)\)")
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
	if field in reffield2type.keys():
		original_type = type
		type = "shared_ptr<%s>"%reffield2type[field]
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
print s
# print  """
 # "Constructor: \n", constructor
# print "Members: \n", members

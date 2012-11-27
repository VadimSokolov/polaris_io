#pragma once
#include "adopter_methods.h"
#include "database.h" // create_database
#include <memory>   // std::auto_ptr
#include <odb/database.hxx>
#include <odb/transaction.hxx>
#include "InputContext-odb.hxx"
#include "transims_network.h"
#include <time.h>
using odb::database;
using odb::transaction;
using namespace pio;
using namespace std;
using namespace odb::core;


template<class FileType, class ODBType, class KeyType>
void Convert(TransimsNetwork *net, InputContainer &container, std::map<KeyType,shared_ptr<ODBType>> &container_map, System_File_Type file_type, string odb_type_name, bool nested_flag)
{
	if (!net->System_File_Flag(file_type))
		return;
	cout << "Converting " << odb_type_name << "\n";
	shared_ptr<ODBType> record;

	FileType *file = (FileType *) net->System_File_Handle (file_type);
	try
	{
		auto_ptr<database> db (open_sqlite_database (net->path_to_database));
		transaction t (db->begin());
		while (file->Read(nested_flag))
		{		
			net->Show_Progress();
			record = Adapter(*file, container);
			container_map[record->getPrimaryKey()] = record;		
			try 
			{
				db->persist(record);
			}
			catch (odb::object_already_persistent e)
			{
				cout << "Persist for " << odb_type_name << " failed.\n";
				cout << "Primary key value: " << record->getPrimaryKey() << ". This object will not be converted\n";
			}
			int num = file->Num_Nest ();
			for (int i=1; i <= num; i++) {
				file->Read (true);
			}
		}
		t.commit();
	}
	catch (odb::sqlite::database_exception e)
	{
		cout << "Convert" << odb_type_name <<"s failed. " <<e.message() << "\n";
		exit(0);
	}
}

template<class FileType, class ODBType, class KeyType>
void Convert(TransimsNetwork *net, InputContainer &container, System_File_Type file_type, string odb_type_name, bool nested_flag)
{
	if (!net->System_File_Flag(file_type))
		return;
	cout << "Converting " << odb_type_name << "\n";
	shared_ptr<ODBType> record;
	FileType *file = (FileType *) net->System_File_Handle (file_type);
	try
	{
		auto_ptr<database> db (open_sqlite_database (net->path_to_database));
		transaction t (db->begin());
		while (file->Read(nested_flag))
		{		
			net->Show_Progress();
			record = Adapter(*file, container);
			try 
			{
				db->persist(record);
			}
			catch (odb::object_already_persistent e)
			{
				cout << "Persist for " << odb_type_name << " failed.\n";
				cout << "Primary key value: " << record->getPrimaryKey() << ". This object will not be converted\n";
			}
			int num = file->Num_Nest ();
			for (int i=1; i <= num; i++) {
				file->Read (true);
			}
		}
		t.commit();
	}
	catch (odb::sqlite::database_exception e)
	{
		cout << "Convert" << odb_type_name <<"s failed. " <<e.message() << "\n";
		exit(0);
	}
}
template<class FileType, class ODBType, class KeyType>
void ConvertNoRef(TransimsNetwork *net, InputContainer &container, System_File_Type file_type, string odb_type_name, bool nested_flag)
{
	if (!net->System_File_Flag(file_type))
		return;
	cout << "Converting " << odb_type_name << "\n";
	shared_ptr<ODBType> record;
	FileType *file = (FileType *) net->System_File_Handle (file_type);
	file->Rewind();
	try
	{
		auto_ptr<database> db (open_sqlite_database (net->path_to_database));
		transaction t (db->begin());
		while (file->Read(nested_flag))
		{		
			net->Show_Progress();
			record = AdapterNoRef(*file, container);
			try 
			{
				db->persist(record);
			}
			catch (odb::object_already_persistent e)
			{
				cout << "Persist for " << odb_type_name << " failed.\n";
				cout << "Primary key value: " << record->getPrimaryKey() << ". This object will not be converted\n";
			}
			int num = file->Num_Nest ();
			for (int i=1; i <= num; i++) {
				file->Read (true);
			}
		}
		t.commit();
	}
	catch (odb::sqlite::database_exception e)
	{
		cout << "Convert" << odb_type_name <<"s failed. " <<e.message() << "\n";
		exit(0);
	}
}
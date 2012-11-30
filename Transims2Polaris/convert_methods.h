#pragma once
#include "adopter_methods.h"
#include "database.h" // create_database
#include <memory>   // std::auto_ptr
#include <odb/database.hxx>
#include <odb/transaction.hxx>
#include "InputContext-odb.hxx"
#include "transims_network.h"
#include <time.h>
#include <string>
#include "Geometry.h"
using odb::database;
using odb::transaction;
using namespace pio;
using namespace std;
using namespace odb::core;


static void trace_callback(void *log_file, const char* content)
{
	ofstream *fh = new ofstream();
	fh = reinterpret_cast<ofstream*>(log_file);
	*fh << content << "\n";
}

template<class FileType, class ODBType, class KeyType>
void Convert(TransimsNetwork *net, InputContainer &container, System_File_Type file_type, string odb_type_name, std::map<KeyType,shared_ptr<ODBType>> *container_map = NULL)
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
		while (file->Read(false))
		{		
			net->Show_Progress();
			record = Adapter(*file, container);
			if (container_map!=NULL)
				(*container_map)[record->getPrimaryKey()] = record;
			try 
			{
				db->persist(record);
			}
			catch (odb::object_already_persistent e)
			{
				cout << "Persist for " << odb_type_name << " failed.\n";
				cout << "Primary key value: " << record->getPrimaryKey() << ". This object will not be converted\n";
			}
			//the nested records are flattened out
			int num = file->Num_Nest ();
			for (int i=1; i <= num; i++) 
			{
				file->Read (true);
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
void ConvertNoRef(TransimsNetwork *net, InputContainer &container, System_File_Type file_type, string odb_type_name, std::map<KeyType,shared_ptr<ODBType>> *container_map = NULL)
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
		while (file->Read(false))
		{		
			net->Show_Progress();
			record = AdapterNoRef(*file, container);
			if (container_map!=NULL)
				(*container_map)[record->getPrimaryKey()] = record;
			try 
			{
				db->persist(record);
			}
			catch (odb::object_already_persistent e)
			{
				cout << "Persist for " << odb_type_name << " failed.\n";
				cout << "Primary key value: " << record->getPrimaryKey() << ". This object will not be converted\n";
			}
			//the nested records are flattened out
			int num = file->Num_Nest ();
			for (int i=1; i <= num; i++) 
			{
				file->Read (true);
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

//This function is to be used when a nested record is defined as a separate classs. As a result the nested records will be stored in a separate table
template<class FileType, class ODBType, class KeyType, class NestedRecordType>
void ConvertNested(TransimsNetwork *net, InputContainer &container, System_File_Type file_type, string odb_type_name, std::map<KeyType,shared_ptr<ODBType>> *container_map = NULL)
{
	if (!net->System_File_Flag(file_type))
		return;
	cout << "Converting " << odb_type_name << " with nested records\n";
	shared_ptr<ODBType> record;
	NestedRecordType nested_record;
	FileType *file = (FileType *) net->System_File_Handle (file_type);
	try
	{
		auto_ptr<database> db (open_sqlite_database (net->path_to_database));
		transaction t (db->begin());
		while (file->Read(false))
		{		
			net->Show_Progress();
			record = Adapter(*file, container);
			int num = file->Num_Nest ();
			for (int i=1; i <= num; i++) 
			{
				file->Read (true);
				nested_record = AdapterNested(*file);
				record->nested_records.push_back(nested_record);
			}
			if (container_map!=NULL)
				(*container_map)[record->getPrimaryKey()] = record;
			try 
			{
				db->persist(record);
			}
			catch (odb::object_already_persistent e)
			{
				cout << "Persist for " << odb_type_name << " failed.\n";
				cout << "Primary key value: " << record->getPrimaryKey() << ". This object will not be converted\n";
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

//void ConvertShape(TransimsNetwork *net)
//{
//	ofstream fh, fh1;
//	fh.open("sql_trace.txt");
//	fh1.open("sql_profile.txt");
//	char sql[2048];
//	char buff[1024];
//	string geometry;
//    sqlite3 *db_handle;
//    sqlite3_stmt *stmt;
//    int ret;
//	size_t pos;
//    char *err_msg = NULL;
//	int link_id;
//	double x,y;
//	if (!net->System_File_Flag(SHAPE))
//		return;
//
//	typedef odb::query<Link> query;
//	typedef odb::result<Link> result;
//	cout << "Converting SHAPE" << "\n";
//	Shape_File *file = (Shape_File *) net->System_File_Handle (SHAPE);
//
//	//add geometry column to links table
//	db_handle = AddGeometryTables(net->path_to_database);
//
//	//open another connection to get node data
//	auto_ptr<database> db (open_sqlite_database (net->path_to_database));
//	//db_handle = ((odb::sqlite::database*)db.get())->connection()->handle();
//	transaction t (db->begin ());
//	#ifdef _DEBUG
//		sqlite3_trace(db_handle,trace_callback, fh);
//	#endif
//	strcpy (sql, "UPDATE Link SET geom=GeomFromText(?, 26916) WHERE link=?");
//    ret = sqlite3_prepare_v2 (db_handle, sql, strlen (sql), &stmt, NULL);
//    if (ret != SQLITE_OK)
//	{
//		fprintf (stderr, "SQL error: %s\n%s\n", sql,
//		sqlite3_errmsg (db_handle));
//		goto stop;
//	}
//	ret = sqlite3_exec (db_handle, "BEGIN", NULL, NULL, &err_msg);
//    if (ret != SQLITE_OK)
//	{
//		fprintf (stderr, "Error: %s\n", err_msg);
//		sqlite3_free (err_msg);
//		goto stop;
//	}
//	
//	while (file->Read(false))
//	{		
//		
//		//net->Show_Progress();
//		link_id = file->Link();	
//		if (link_id == 11216)
//		{
//			int a = 5;
//		}
//		cout << link_id << "\n";
//		result r(db->query<Link> (query::link==link_id));
//		bool empty_flag = r.empty();
//		if (empty_flag)
//			continue;
//		x = r.begin()->getNode_A()->getX();
//		y = r.begin()->getNode_A()->getY();
//		t.commit();
//		t.reset (db->begin ());
//		sprintf (buff, "%1.6f %1.6f, ", x, y);
//		geometry += buff;
//		int num = file->Num_Nest ();
//		geometry = "LINESTRING(";
//		for (int i=1; i <= num; i++) {
//			file->Read (true);
//			//net->Show_Progress ();
//			x = file->X();
//			y = file->Y();			
//			sprintf (buff, "%1.6f %1.6f, ", x, y);
//			geometry += buff;
//		}
//		//pos = geometry.find_last_of(",");
//		//geometry = geometry.substr(0, pos);
//		x = r.begin()->getNode_B()->getX();
//		y = r.begin()->getNode_B()->getY();
//		sprintf (buff, "%1.6f %1.6f", x, y);
//		geometry += buff;
//		geometry += ")";
//		sqlite3_reset (stmt);
//		sqlite3_clear_bindings (stmt);
//		sqlite3_bind_int (stmt, 2, link_id);
//		sqlite3_bind_text (stmt, 1, geometry.c_str(), strlen (geometry.c_str()), SQLITE_STATIC);
//		ret = sqlite3_step (stmt);
//		if (ret == SQLITE_DONE || ret == SQLITE_ROW)
//			continue;
//		else
//		{
//			fprintf (stderr, "Error: %s\n", err_msg);
//			sqlite3_free (err_msg);
//			goto stop;
//		}
//	}
//	t.commit();
//	sqlite3_finalize (stmt);
//	ret = sqlite3_exec (db_handle, "COMMIT", NULL, NULL, &err_msg);
//	if (ret != SQLITE_OK)
//	{
//		fprintf (stderr, "Error: %s\n", err_msg);
//		sqlite3_free (err_msg);
//	}
//	stop:
//		sqlite3_close (db_handle);
//}
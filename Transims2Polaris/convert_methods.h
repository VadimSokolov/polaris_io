#pragma once
#include "adopter_methods.h"
#include "database.h" // create_database
#include <memory>   // std::auto_ptr
#include <odb/database.hxx>
#include <odb/transaction.hxx>
#include "InputContext-odb.hxx"
#include "transims_network.h"
#include <time.h>
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

void ConvertShape(TransimsNetwork *net)
{
	ofstream fh, fh1;
	fh.open("sql_trace.txt");
	fh1.open("sql_profile.txt");
	char sql[2048];
	char sql2[1024];
	char geom[2048];
    sqlite3 *db_handle;
    sqlite3_stmt *stmt;
    int ret;
    char *err_msg = NULL;
	if (!net->System_File_Flag(SHAPE))
		return;
	cout << "Converting SHAPE" << "\n";
	Shape_File *file = (Shape_File *) net->System_File_Handle (SHAPE);
	//add geometry column to links table
	db_handle = AddGeometryTables(net->path_to_database);
	#ifdef DEBUG
	sqlite3_trace(db_handle,trace_callback, fh);
	#endif
	int link_id;
	double x,y,z;
	strcpy (sql, "UPDATE Link set geom = ");
	strcat (sql, "GeomFromText(?, 4326) where link=?");
    ret = sqlite3_prepare_v2 (db_handle, sql, strlen (sql), &stmt, NULL);
    if (ret != SQLITE_OK)
	{
		fprintf (stderr, "SQL error: %s\n%s\n", sql,
		sqlite3_errmsg (db_handle));
	}
	ret = sqlite3_exec (db_handle, "BEGIN", NULL, NULL, &err_msg);
    if (ret != SQLITE_OK)
	{
		fprintf (stderr, "Error: %s\n", err_msg);
		sqlite3_free (err_msg);
	}
	int i = 10;
	while (file->Read(false))
	{
		strcpy (geom, "LINESTRING(");
		net->Show_Progress();
		link_id = file->Link();
        strcat (geom, "-180.0 -90.0, ");
        sprintf (sql2, "%1.6f %1.6f, ", -10.0 - (i / 1000.0),
        	 -10.0 - (i / 1000.0));
        strcat (geom, sql2);
        sprintf (sql2, "%1.6f %1.6f, ", -10.0 - (i / 1000.0),
        	 10.0 + (i / 1000.0));
        strcat (geom, sql2);
        sprintf (sql2, "%1.6f %1.6f, ", 10.0 + (i / 1000.0),
        	 10.0 + (i / 1000.0));
        strcat (geom, sql2);
        strcat (geom, "180.0 90.0");
		strcat (geom, ")");
		sqlite3_reset (stmt);
		sqlite3_clear_bindings (stmt);
		sqlite3_bind_int (stmt, 2, link_id);
		sqlite3_bind_text (stmt, 1, geom, strlen (geom), SQLITE_STATIC);
		ret = sqlite3_step (stmt);
		if (ret == SQLITE_DONE || ret == SQLITE_ROW)
			continue;
		else
		{
			fprintf (stderr, "Error: %s\n", err_msg);
			sqlite3_free (err_msg);
		}
		

		int num = file->Num_Nest ();
		for (int i=1; i <= num; i++) {
			file->Read (true);
			net->Show_Progress ();
			x = file->X();
			y = file->Y();
			z = file->Z();

		}
	}
	sqlite3_finalize (stmt);
	ret = sqlite3_exec (db_handle, "COMMIT", NULL, NULL, &err_msg);
	if (ret != SQLITE_OK)
	{
		fprintf (stderr, "Error: %s\n", err_msg);
		sqlite3_free (err_msg);
	}
}
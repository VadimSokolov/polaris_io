// file      : access/database.hxx
// copyright : not copyrighted - public domain

//
// Create concrete database instance based on the DATABASE_* macros.
//

#ifndef DATABASE
#define DATABASE

#include <string>
#include <memory>   // auto_ptr
#include <cstdlib>  // std::exit
#include <iostream>

#include <odb/database.hxx>
#include <odb/connection.hxx>
#include <odb/sqlite/connection.hxx>
#include <odb/transaction.hxx>
#include <odb/schema-catalog.hxx>
#include <odb/sqlite/database.hxx>
#include <odb/sqlite//exceptions.hxx> 
#include <sqlite3.h>

#include <iostream>
#include <fstream>

using namespace std;
using namespace odb::core;


namespace polaris
{
namespace io
{
	// This method returns a vector that contains named schemas available in the IO library. Note, this list is duplicated in db-inventory.txt file. 
	// create-io-odb-step.py script uses  db-inventory.txt file to generate the project file wiht the required pre-build steps (obd compiler). So, make sure that the list here and in the file are in SYNC!
	// I know not the best design, but will be changed to something better in the future
	static std::vector<string> get_schemas()
	{		
		std::vector<string> result;
		result.push_back("Supply");
		result.push_back("Result");
		result.push_back("Demand");
		result.push_back("System");
#ifdef _DEBUG
		string schema;
		result.clear();
		std::ifstream inventory_file ("C:/Users/vsokolov/usr/polaris_io/polaris_io/db-inventory.txt");
		while (inventory_file.good())
		{
			getline(inventory_file, schema);
			result.push_back(schema);
		}
		inventory_file.close();
#endif
		assert(result.size() > 0);
		return result;
	}
	static std::vector<string> db_inventory = get_schemas();
	static string make_name(string db_name, string schema_name)
	{
		return db_name+"-"+schema_name+".sqlite";
	}
	static string make_attach_string(string db_name, string schema_name)
	{
		return "ATTACH \'" + make_name(db_name, schema_name) + "\' as " + schema_name;
	}
}
}
using namespace polaris::io;

inline sqlite3* open_raw_sqlite_database(const std::string& name)
{
	int ret;
	char sql[1024];
	char *err_msg = NULL;
	sqlite3* db_handle;
	ret = sqlite3_open_v2(make_name(name,"Supply").c_str(), &db_handle, SQLITE_OPEN_READWRITE , NULL);
	if (ret != SQLITE_OK)
	{
		fprintf (stderr, "Error: %s\n", err_msg);
		sqlite3_free (err_msg);
		return NULL;
	}
	for (vector<string>::iterator it = db_inventory.begin()+1; it != db_inventory.end(); ++it)
	{
		ret = sqlite3_exec (db_handle, make_attach_string(name, *it).c_str(), NULL, NULL, &err_msg);
		if (ret != SQLITE_OK)
		{
			fprintf (stderr, "Error: %s\n", err_msg);
			sqlite3_free (err_msg);
			return NULL;
		}
	}
	return db_handle;
}

inline int attach_spatialite(sqlite3* db_handle) 
{
	char sql[2048];
	char buff[1024];
	char *err_msg = NULL;
	int ret;
	sqlite3_enable_load_extension (db_handle, 1);
	strcpy (sql, "SELECT load_extension('libspatialite-4.dll')");
#ifdef _DEBUG
	strcpy (sql, "SELECT load_extension('C:\\Users\\vsokolov\\usr\\io_sdk\\x86\\bin\\libspatialite-4.dll')");
#endif
	ret = sqlite3_exec (db_handle, sql, NULL, NULL, &err_msg);
	if (ret != SQLITE_OK)
	{
		fprintf (stderr, "load_extension() error: %s\n", err_msg);
		sqlite3_free (err_msg);
		return ret;
	}
    strcpy (sql, "SELECT InitSpatialMetadata()");
    ret = sqlite3_exec (db_handle, sql, NULL, NULL, &err_msg);
    if (ret != SQLITE_OK)
    {
		fprintf (stderr, "InitSpatialMetadata() error: %s\n", err_msg);
		sqlite3_free (err_msg);
		return ret;
    }
    fprintf(stderr, "\n\n**** SpatiaLite loaded as an extension ***\n\n");

	return ret;
}

inline sqlite3* open_spatialite_database(const std::string& name )
{
	int ret;
	char *err_msg = NULL;
	sqlite3* db_handle;
	db_handle = open_raw_sqlite_database(name);
	assert(db_handle != NULL);
	ret = attach_spatialite(db_handle);
	assert(ret == SQLITE_OK);
	return db_handle;
}

inline auto_ptr<odb::database> open_sqlite_database(const std::string& name)
{
	auto_ptr<database> db (new odb::sqlite::database (make_name(name, db_inventory[0]), SQLITE_OPEN_READWRITE));
	connection_ptr c (db->connection ());
	c->execute("PRAGMA synchronous = OFF");
	c->execute("PRAGMA journal_mode = MEMORY");
	if (db_inventory.size()>1)
	{
		for (vector<string>::iterator it = db_inventory.begin()+1; it != db_inventory.end(); ++it)
		{
			c->execute(make_attach_string(name,*it));
		}
	}
	return db;
}

inline auto_ptr<database> create_sqlite_database(const string& name, string& schema)
{
	try
	{
		auto_ptr<database> db (new odb::sqlite::database (make_name(name, schema), SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE));
		// Create the database schema. Due to bugs in SQLite foreign key
		// support for DDL statements, we need to temporarily disable
		// foreign keys.
		connection_ptr c (db->connection ());
		c->execute ("PRAGMA foreign_keys=OFF");
		transaction t (c->begin ());
		try
		{
			schema_catalog::create_schema (*db, schema);
		}
		catch (odb::unknown_schema e)
		{
			throw e;
		}
		t.commit ();
		c->execute ("PRAGMA foreign_keys=ON");
		return db;
	}
	catch (odb::sqlite::database_exception e)
	{
		cout << e.message() << "\n";
		exit(0);
	}

}

inline auto_ptr<database> create_sqlite_database(const string& name)
{
	auto_ptr<database> db = create_sqlite_database(name, db_inventory[0]);
	auto_ptr<database> temp;
	connection_ptr c (db->connection ());
	if (db_inventory.size()>1)
	{
		for (vector<string>::iterator it = db_inventory.begin()+1; it != db_inventory.end(); ++it)
		{
			try
			{
			auto_ptr<database> temp = create_sqlite_database(name, *it);
			}
			catch (odb::unknown_schema e)
			{
				cout << e.what()  << "\n";
				continue;
			}
			c->execute(make_attach_string(name,*it));
		}
	}
	return db;
}
//
//
//inline auto_ptr<database> create_database (int& argc, char* argv[])
//{
//  if (argc > 1 && argv[1] == string ("--help"))
//  {
//    cout << "Usage: " << argv[0] << " [options]" << endl
//         << "Options:" << endl;
//
//#if defined(DATABASE_MYSQL)
//    odb::mysql::database::print_usage (cout);
//#elif defined(DATABASE_SQLITE)
//    odb::sqlite::database::print_usage (cout);
//#elif defined(DATABASE_PGSQL)
//    odb::pgsql::database::print_usage (cout);
//#elif defined(DATABASE_ORACLE)
//    odb::oracle::database::print_usage (cout);
//#elif defined(DATABASE_MSSQL)
//    odb::mssql::database::print_usage (cout);
//#endif
//
//    exit (0);
//  }
//
//#if defined(DATABASE_MYSQL)
//  auto_ptr<database> db (new odb::mysql::database (argc, argv));
//#elif defined(DATABASE_SQLITE)
//  auto_ptr<database> db (
//    new odb::sqlite::database (
//      argc, argv, false, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE));
//	// Create the database schema. Due to bugs in SQLite foreign key
//	// support for DDL statements, we need to temporarily disable
//	// foreign keys.
//	{
//		connection_ptr c (db->connection ());
//		c->execute ("PRAGMA foreign_keys=OFF");
//		transaction t (c->begin ());
//		schema_catalog::create_schema (*db);
//		t.commit ();
//		c->execute ("PRAGMA foreign_keys=ON");
//	}
//#elif defined(DATABASE_PGSQL)
//  auto_ptr<database> db (new odb::pgsql::database (argc, argv));
//#elif defined(DATABASE_ORACLE)
//  auto_ptr<database> db (new odb::oracle::database (argc, argv));
//#elif defined(DATABASE_MSSQL)
//  auto_ptr<database> db (new odb::mssql::database (argc, argv));
//#endif
//
//  return db;
//}

#endif // DATABASE_HXX

// file      : access/database.hxx
// copyright : not copyrighted - public domain

//
// Create concrete database instance based on the DATABASE_* macros.
//

#ifndef DATABASE
#define DATABASE

#ifndef DATABASE_SQLITE
#define DATABASE_SQLITE
#endif

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

#include <iostream>
#include <fstream>

using namespace std;
using namespace odb::core;


namespace polaris
{
namespace io
{
	
	std::vector<string> get_schemas()
	{
		string schema;
		std::vector<string> result;
		std::ifstream inventory_file ("C:/Users/vsokolov/usr/polaris_io/polaris_io/db-inventory.txt");
		while (inventory_file.good())
		{
			getline(inventory_file, schema);
			result.push_back(schema);
		}
		inventory_file.close();
		assert(result.size() > 0);
		return result;
	}
	std::vector<string> db_inventory = get_schemas();
	string make_name(string db_name, string schema_name)
	{
		return db_name+"-"+schema_name+".sqlite";
	}
	string make_attach_string(string db_name, string schema_name)
	{
		return "ATTACH \'" + make_name(db_name, schema_name) + "\' as " + schema_name;
	}
}
}
using namespace polaris::io;

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

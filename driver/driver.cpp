#include <memory>   // std::auto_ptr
#include <odb/database.hxx>
#include <odb/transaction.hxx>
#include "database.h" // create_database
#include "OutNetwork.h"
#include "OutNetwork-odb.hxx"
//#include <sqlite3.h>
using namespace std;
using namespace odb::core;
using namespace pio;

//using odb::database;
//using odb::transaction;
//
typedef odb::query<Node> node_query;
typedef odb::result<Node> node_result;

int AddGeoColumn(string table_name, string geo_type, string epsg, auto_ptr<database> db)
{
	char buff[500];
	long ret;
	char *err_msg = NULL;
	sprintf_s(buff, "SELECT AddGeometryColumn ( '%s', 'GEO', %s, '%s', 2 );", table_name.c_str(), epsg.c_str(), geo_type.c_str());
	connection_ptr c (db->connection ());
	ret = c->execute(buff);
	sprintf_s(buff, "lalal hahah ( '%s', 'GEO', %s, '%s', 2 );", table_name.c_str(), epsg.c_str(), geo_type.c_str());
	if (ret != SQLITE_OK)
	{
	  fprintf (stderr, "AddGeometryColumn error: %s\n", err_msg);
      return ret;
	}
	return SQLITE_OK;

}

int main (int argc, char *argv [])
{
	sqlite3 *db_handle;
	int ret;
	string sql;
	char *err_msg = NULL;
	char buff[500];
	auto_ptr<database> db (create_database (argc, argv));
	cout << "A new " << argv[2] << " was generated\n";

	shared_ptr<Node> n1 (new Node(1,1,1));
	shared_ptr<Node> n2 (new Node(2,2,1));
	shared_ptr<Node> n3 (new Node(3,1,1));
	shared_ptr<Node> n4 (new Node(4,1,1));
	//shared_ptr<Node> n2 (new Node(2,1,2,3,4,5));
	//Node *n3 = new Node(3,4,4,5,6,7);
	//Node n4 (4,3,3,3,3,5 );
	//transaction t (db->begin());
	//db->persist(n1);
	//db->persist(n2);
	//t.commit();
	//ret = sqlite3_open(argv[1], &(db_handle));
	//sqlite3_enable_load_extension (db_handle, 1);
	//sql = "SELECT load_extension('C:/Users/vsokolov/usr/io_sdk/x86/bin/libspatialite-2.dll');";
	//ret = sqlite3_exec (db_handle, sql.c_str(), NULL, NULL, &err_msg);
	//ret = sqlite3_close_v2(db_handle);
	//transaction t1 (db->begin());
	//node_result r(db->query<Node> (node_query. == 1));
 //   for (node_result::iterator i (r.begin ()); i != r.end (); ++i)
 //   {
	//	cout << i->first () << " " << i->last () << " " << i->age () << endl;
 //   }

	shared_ptr<Link> l1 (new Link(1, "lalal", n1, n2, 1.0, 2.0, 3.0, 10, 20, 2, 0, 8, 12, 0.3, 2,22,22,122,1,33,333,2,3,2,1,2));
	shared_ptr<Link> l2 (new Link(2, "lalal", n3, n4, 1.0, 2.0, 3.0, 10, 20, 2, 0, 8, 12, 0.3, 2,22,22,122,1,33,333,2,3,2,1, 3));

	transaction t (db->begin());
	db->persist(n1);
	db->persist(n2);
	db->persist(n3);
	db->persist(n4);
	db->persist(l1);
	db->persist(l2);
	t.commit();
	cout << "Press any key...\n";
	getchar();
	return 0;
}


#include <memory>   // std::auto_ptr
#include <odb/database.hxx>
#include <odb/transaction.hxx>
#include "database.h" // create_database
#include "InputContext.h"
#include "InputContext-odb.hxx"
#include <time.h>
#include <iostream>
#include <fstream>
using namespace std;
using namespace odb::core;
using namespace pio;

//using odb::database;
//using odb::transaction;
//
typedef odb::query<Node> node_query;
typedef odb::result<Node> node_result;

__int64 AddGeoColumn(string table_name, string geo_type, string epsg, auto_ptr<database> db)
{
	char buff[500];
	__int64 ret;
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

static int callback(void *NotUsed, int n_columns, char **columns, char **column_names)
{
	int id;
	id = atoi(columns[0]);
	if (id % 100000 == 0)
		printf("%s = %d\n", column_names[0],  atoi(columns[0]));
	 return 0;
}
static void profile_callback(void *log_file, const char* content, sqlite3_uint64 wall_time)
{
	ofstream *fh = new ofstream();
	fh = reinterpret_cast<ofstream*>(log_file);
	*fh << content << "\n";
	*fh << "Wall time is (in sec): " <<  wall_time/1000000000 << "\n";
}
static void trace_callback(void *log_file, const char* content)
{
	ofstream *fh = new ofstream();
	fh = reinterpret_cast<ofstream*>(log_file);
	*fh << content << "\n";
}

int TestReadTripsSQL(string path_to_database)
{
	sqlite3* db_handler;
	int ret;
	string sql;
	char *err_msg = NULL;
	ret = sqlite3_open(path_to_database.c_str(), &db_handler);
	sql = "select * from Trip";
	clock_t now = clock();
	ret = sqlite3_exec(db_handler, sql.c_str(), callback, 0, &err_msg);
	clock_t later = clock();
	printf("%.3f trip table access (raw sql)\n",(double)(later-now)/(double)CLOCKS_PER_SEC);
	return 0;
}

template<class TripClass>
int TestReadTrips(string path_to_database)
{
	typedef odb::query<TripClass> query;
	typedef odb::result<TripClass> result;
	//int a,b, c, dest, origin;
	int a;
	int res;
	ofstream fh, fh1;
	fh.open("sql_trace.txt");
	fh1.open("sql_profile.txt");
	a = 0;
	Trip trip;
	auto_ptr<database> db (open_sqlite_database (path_to_database));
	//sqlite3* db_handle = ((odb::sqlite::database*)db.get())->connection()->handle();
	//sqlite3_profile(db_handle,profile_callback, fh1);
	//sqlite3_trace(db_handle,trace_callback, fh);
	transaction t (db->begin ());
	result r(db->query<TripClass> (query::true_expr, true));
	clock_t now = clock();	
	for (result::iterator it (r.begin()); it!=r.end(); ++it)
	{
		a++;
		res = it->getAuto_id();
		//it.load();
		//res  = it.id();
		if (a % 100000 ==0)
			cout << a << "\n";
	}
	clock_t later = clock();
	printf("%.3f trip table access\n",(double)(later-now)/(double)CLOCKS_PER_SEC);
	t.commit();
	fh.close();
	fh1.close();
	cout << "OK\n";
	return 0;
}
void test_location()
{
	auto_ptr<database> db (open_sqlite_database ("C:\\Users\\vsokolov\\usr\\polaris_io\\Transims2Polaris\\chicago_with_demand.sqlite"));
	typedef odb::query<pio::Location> query;
	typedef odb::result<pio::Location> result;
	transaction t (db->begin ());
	result r(db->query<pio::Location> (query::location==82434, true));
	shared_ptr<pio::Link> l =  r.begin()->getLink();
}
int main (int argc, char *argv [])
{
	//TestReadTrips<Trip>("C:\\Users\\vsokolov\\usr\\polaris_io\\Transims2Polaris\\TestNet50.sqlite");
	//TestReadTrips<TripNoRef>("C:\\Users\\vsokolov\\usr\\polaris_io\\Transims2Polaris\\chicago_with_demand.sqlite");
	//TestReadTripsSQL("C:\\Users\\vsokolov\\usr\\polaris_io\\Transims2Polaris\\chicago_with_demand.sqlite");
	test_location();
	cout << "Press any key...\n";
	getchar();
	return 0;
}


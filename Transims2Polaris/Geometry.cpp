#include "Geometry.h"


int AddGeometryCoumn(sqlite3* db_handle, int srid, std::string table, std::string type, std::string dim)
{
	char sql[2048];
	int ret;
	char buff[1024];
	char *err_msg = NULL;
	sprintf (buff, "SELECT DiscardGeometryColumn('%s','GEO')", table.c_str());
	strcpy (sql, buff);
	ret = sqlite3_exec (db_handle, sql, NULL, NULL, &err_msg);
	if (ret != SQLITE_OK)
	{
		fprintf (stderr, "Error: %s\n", err_msg);
		sqlite3_free (err_msg);
		return ret;
	}
	sprintf (buff, "SELECT AddGeometryColumn('%s', 'GEO', %d, '%s', '%s')", table.c_str(), srid, type.c_str(), dim.c_str());
	strcpy (sql, buff);
	ret = sqlite3_exec (db_handle, sql, NULL, NULL, &err_msg);
	if (ret != SQLITE_OK)
	{
		fprintf (stderr, "Error in AddGeometryCoumn: %s\n", err_msg);
		sqlite3_free (err_msg);
	}
	return ret;
}

int AddGeometryTables(sqlite3* db_handle, int srid)
{
	char sql[2048];
	char buff[1024];
	char *err_msg = NULL;
	int ret;
	sqlite3_enable_load_extension (db_handle, 1);
	strcpy (sql, "SELECT load_extension('C:\\Users\\vsokolov\\usr\\io_sdk\\x86\\bin\\libspatialite-4.dll')");
	ret = sqlite3_exec (db_handle, sql, NULL, NULL, &err_msg);
	if (ret != SQLITE_OK)
	{
		fprintf (stderr, "load_extension() error: %s\n", err_msg);
		sqlite3_free (err_msg);
		return 0;
	}
    strcpy (sql, "SELECT InitSpatialMetadata()");
    ret = sqlite3_exec (db_handle, sql, NULL, NULL, &err_msg);
    if (ret != SQLITE_OK)
    {
		fprintf (stderr, "InitSpatialMetadata() error: %s\n", err_msg);
		sqlite3_free (err_msg);
		return 0;
    }
    fprintf(stderr, "\n\n**** SpatiaLite loaded as an extension ***\n\n");

	ret = AddGeometryCoumn(db_handle, srid, "LINK", "LINESTRING", "XY");
	if (ret != SQLITE_OK) goto stop;
	ret = AddGeometryCoumn(db_handle, srid, "Zone", "POINT", "XY");
	if (ret != SQLITE_OK) goto stop;
	ret = AddGeometryCoumn(db_handle, srid, "Node", "POINT", "XY");
	if (ret != SQLITE_OK) goto stop;
	stop:
		return ret;
}
#include "Geometry.h"

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

	strcpy (sql, "SELECT DiscardGeometryColumn('Link', 'GEO')");
	if (ret != SQLITE_OK)
	{
		fprintf (stderr, "Error: %s\n", err_msg);
		sqlite3_free (err_msg);
		goto stop;
	}
	strcpy (sql, "SELECT AddGeometryColumn('Link', ");
	sprintf (buff, "'GEO', %d, ", srid);
    strcat (sql, buff);
    strcat (sql, "'LINESTRING', 'XY')");
	ret = sqlite3_exec (db_handle, sql, NULL, NULL, &err_msg);
	if (ret != SQLITE_OK)
	{
		fprintf (stderr, "Error: %s\n", err_msg);
		sqlite3_free (err_msg);
		goto stop;
	}

	strcpy (sql, "SELECT DiscardGeometryColumn('Zone', 'GEO')");
	if (ret != SQLITE_OK)
	{
		fprintf (stderr, "Error: %s\n", err_msg);
		sqlite3_free (err_msg);
		goto stop;
	}
	strcpy (sql, "SELECT AddGeometryColumn('Zone', ");
	sprintf (buff, "'GEO', %d, ", srid);
    strcat (sql, buff);
    strcat (sql, "'POINT', 'XY')");
	ret = sqlite3_exec (db_handle, sql, NULL, NULL, &err_msg);
	if (ret != SQLITE_OK)
	{
		fprintf (stderr, "Error: %s\n", err_msg);
		sqlite3_free (err_msg);
		goto stop;
	}
	stop:
		return ret;
}
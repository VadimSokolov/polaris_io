#include "Geometry.h"

sqlite3* AddGeometryTables(const std::string& name)
{
	sqlite3 *db_handle;
	char sql[2048];
	char *err_msg = NULL;
	int ret;
	ret = sqlite3_open_v2(name.c_str(), &db_handle, SQLITE_OPEN_READWRITE , NULL);
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
	strcpy (sql, "SELECT DiscardGeometryColumn('Link', 'geom')");
	if (ret != SQLITE_OK)
	{
		fprintf (stderr, "Error: %s\n", err_msg);
		sqlite3_free (err_msg);
		goto stop;
	}
	strcpy (sql, "SELECT AddGeometryColumn('Link', ");
    strcat (sql, "'geom', 26916, 'LINESTRING', 'XY')");
	ret = sqlite3_exec (db_handle, sql, NULL, NULL, &err_msg);
	if (ret != SQLITE_OK)
	{
		fprintf (stderr, "Error: %s\n", err_msg);
		sqlite3_free (err_msg);
		goto stop;
	}
	stop:
		//sqlite3_close (db_handle);
		return db_handle;
}
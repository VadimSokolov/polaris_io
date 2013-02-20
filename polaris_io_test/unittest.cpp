#include "gtest/gtest.h"
#include <vector>
#include <ostream>
#include <sqlite3.h>
#include <database.h>
#include <Geometry.h>


TEST(database, open_raw_sqlite_database)
{
	sqlite3* db_handle;
	db_handle = open_raw_sqlite_database("C:/Users/vsokolov/usr/polaris_io/Transims2Polaris/TestNet50");
	EXPECT_TRUE(db_handle != NULL);
}
TEST(database, attach_spatialite)
{
	sqlite3* db_handle;
	int ret;
	db_handle = open_raw_sqlite_database("C:/Users/vsokolov/usr/polaris_io/Transims2Polaris/TestNet50");
	ret = attach_spatialite(db_handle);
	EXPECT_EQ(ret,SQLITE_OK);
}

TEST(database, open_spatialite_database)
{
	sqlite3* db_handle;
	int ret;
	db_handle =  open_spatialite_database("C:/Users/vsokolov/usr/polaris_io/Transims2Polaris/TestNet50");
	EXPECT_TRUE(db_handle != NULL);
}
TEST(Geometry, GetLinkShapes)
{
	std::map<int, std::vector<shape_geometry>> res;
	res = GetLinkShapes("C:/Users/vsokolov/usr/polaris_io/Transims2Polaris/TestNet50");
	ASSERT_NE(res.size(),0);
}

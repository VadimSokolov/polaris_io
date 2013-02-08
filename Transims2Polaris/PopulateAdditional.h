#include<database.h>

void PopulateLinkType(string db_path)
{
	auto_ptr<database> db (open_sqlite_database (db_path)); 
	connection_ptr c (db->connection ());
	c->execute ( "insert into LINK_TYPE values ( 'FREEWAY',		10, 'ANY|AUTO|TRUCK|BUS|SOV|HOV2|HOV3|HOV4|LIGHTTRUCK|HEAVYTRUCK|NONE|TAXI|RESTRICTED|NONE',				'', '' );" );
	c->execute ( "insert into LINK_TYPE values ( 'EXPRESSWAY',	20, 'ANY|AUTO|TRUCK|BUS|SOV|HOV2|HOV3|HOV4|LIGHTTRUCK|HEAVYTRUCK|NONE|TAXI|RESTRICTED|NONE',				'XPRESSWAY', '' );" );
	c->execute ( "insert into LINK_TYPE values ( 'PRINCIPAL',		30, 'ANY|WALK|BICYCLE|AUTO|TRUCK|BUS|SOV|HOV2|HOV3|HOV4|LIGHTTRUCK|HEAVYTRUCK|TAXI|RESTRICTED|NONE',		'', '' );" );
	c->execute ( "insert into LINK_TYPE values ( 'MAJOR',			40, 'ANY|WALK|BICYCLE|AUTO|TRUCK|BUS|SOV|HOV2|HOV3|HOV4|LIGHTTRUCK|HEAVYTRUCK|TAXI|RESTRICTED|NONE',		'PRIARTER', '' );" );
	c->execute ( "insert into LINK_TYPE values ( 'MINOR',			50, 'ANY|WALK|BICYCLE|AUTO|TRUCK|BUS|SOV|HOV2|HOV3|HOV4|LIGHTTRUCK|HEAVYTRUCK|TAXI|RESTRICTED|NONE',		'SECARTER', '' );" );
	c->execute ( "insert into LINK_TYPE values ( 'COLLECTOR',		60, 'ANY|WALK|BICYCLE|AUTO|TRUCK|BUS|SOV|HOV2|HOV3|HOV4|LIGHTTRUCK|HEAVYTRUCK|TAXI|RESTRICTED|NONE',		'', '' );" );
	c->execute ( "insert into LINK_TYPE values ( 'LOCAL_THRU',	70, 'ANY|WALK|BICYCLE|AUTO|TRUCK|BUS|SOV|HOV2|HOV3|HOV4|LIGHTTRUCK|HEAVYTRUCK|TAXI|RESTRICTED|NONE',		'THRU|LOCAL_ACCESS', '' );" );
	c->execute ( "insert into LINK_TYPE values ( 'LOCAL',			80, 'ANY|WALK|BICYCLE|AUTO|TRUCK|BUS|SOV|HOV2|HOV3|HOV4|LIGHTTRUCK|HEAVYTRUCK|TAXI|RESTRICTED|NONE',		'', '' );" );
	c->execute ( "insert into LINK_TYPE values ( 'FRONTAGE',		90, 'ANY|WALK|BICYCLE|AUTO|TRUCK|BUS|SOV|HOV2|HOV3|HOV4|LIGHTTRUCK|HEAVYTRUCK|TAXI|RESTRICTED|NONE',		'', '' );" );
	c->execute ( "insert into LINK_TYPE values ( 'RAMP',			100, 'ANY|AUTO|TRUCK|BUS|SOV|HOV2|HOV3|HOV4|LIGHTTRUCK|HEAVYTRUCK|TAXI|RESTRICTED|NONE',					'', '' );" );
	c->execute ( "insert into LINK_TYPE values ( 'BRIDGE',		110, 'ANY|WALK|BICYCLE|AUTO|TRUCK|BUS|SOV|HOV2|HOV3|HOV4|LIGHTTRUCK|HEAVYTRUCK|TAXI|RESTRICTED|NONE',		'', '' );" );
	c->execute ( "insert into LINK_TYPE values ( 'TUNNEL',		120, 'ANY|WALK|BICYCLE|AUTO|TRUCK|BUS|SOV|HOV2|HOV3|HOV4|LIGHTTRUCK|HEAVYTRUCK|TAXI|RESTRICTED|NONE',		'', '' );" );
	c->execute ( "insert into LINK_TYPE values ( 'EXTERNAL',		130, 'ANY|WALK|BICYCLE|AUTO|TRUCK|BUS|RAIL|SOV|HOV2|HOV3|HOV4|LIGHTTRUCK|HEAVYTRUCK|RESTRICTED|NONE|TAXI',	'ZONECONN', '' );" );
	c->execute ( "insert into LINK_TYPE values ( 'WALKWAY',		200, 'ANY|WALK|RESTRICTED|NONE',																			'', '' );" );
	c->execute ( "insert into LINK_TYPE values ( 'BIKEWAY',		210, 'ANY|BICYCLE|RESTRICTED|NONE',																			'', '' );" );
	c->execute ( "insert into LINK_TYPE values ( 'BUSWAY',		220, 'ANY|BUS|RESTRICTED|NONE',																				'', '' );" );
	c->execute ( "insert into LINK_TYPE values ( 'LIGHTRAIL',		300, 'ANY|WALK|RAIL|RESTRICTED|NONE',																			'', '' );" );
	c->execute ( "insert into LINK_TYPE values ( 'HEAVYRAIL',		310, 'ANY|WALK|RAIL|RESTRICTED|NONE',																			'', '' );" );
	c->execute ( "insert into LINK_TYPE values ( 'FERRY', 		400, 'ANY|RESTRICTED|NONE',																					'', '' );" );
	c->execute ( "insert into LINK_TYPE values ( 'OTHER', 		500, 'ANY|WALK|BICYCLE|AUTO|TRUCK|BUS|RAIL|SOV|HOV2|HOV3|HOV4|LIGHTTRUCK|HEAVYTRUCK|RESTRICTED|NONE|TAXI',	'', '' );" );
}

void PopulateAreaType (string db_path)
{
	auto_ptr<database> db (open_sqlite_database (db_path)); 
	connection_ptr c (db->connection ());
	c->execute ( "insert into AREA_TYPE values ( 1, 'AREATYPE1', 'Default' );" );
	c->execute ( "insert into AREA_TYPE values ( 2, 'AREATYPE2', 'Default' );" );
	c->execute ( "insert into AREA_TYPE values ( 3, 'AREATYPE3', 'Default' );" );
	c->execute ( "insert into AREA_TYPE values ( 4, 'AREATYPE4', 'Default' );" );
	c->execute ( "insert into AREA_TYPE values ( 5, 'AREATYPE5', 'Default' );" );
	c->execute ( "insert into AREA_TYPE values ( 6, 'AREATYPE6', 'Default' );" );
	c->execute ( "insert into AREA_TYPE values ( 7, 'AREATYPE7', 'Default' );" );
	c->execute ( "insert into AREA_TYPE values ( 8, 'AREATYPE8', 'Default' );" );
}

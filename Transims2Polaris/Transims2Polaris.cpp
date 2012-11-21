// Transims2Polaris.cpp : Defines the entry point for the console application.
//

#include "convert_methods.h"
#include "InputContext.h"
//#include <sqlite3.h>

#include "transims_network.h"

using namespace std;

void test_create(const string& name)
{
	pio::InputContainer container;
	shared_ptr<Node> n1 (new Node(1,1,1,0,0,0));
	shared_ptr<Node> n2 (new Node(2,2,1,0,0,0));
	shared_ptr<Node> n3 (new Node(3,1,1,0,0,0));
	shared_ptr<Node> n4 (new Node(4,1,1,0,0,0));
	container.Nodes[1] = n1;
	container.Nodes[2] = n2;
	container.Nodes[3] = n3;
	container.Nodes[4] = n4;
	//auto_ptr<database> db (create_database (argc, argv));
	auto_ptr<database> db (create_sqlite_database (name));
	cout << "New database "<< ((odb::sqlite::database*)&(*db))->name() <<" was created\n";
	//shared_ptr<Link> l1 (new Link(1, "lalal", container.Nodes[1], container.Nodes[2], 1.0, 2.0, 3.0, 10, 20, 2, 0, 8, 12, 0.3, 2,22,22,122,1,33,333,2,3,2,1,2));
	//shared_ptr<Link> l2 (new Link(2, "lalal", container.Nodes[3], container.Nodes[4], 1.0, 2.0, 3.0, 10, 20, 2, 0, 8, 12, 0.3, 2,22,22,122,1,33,333,2,3,2,1, 3));
	//container.Links[1] = l1;
	//container.Links[2] = l2;

	transaction t (db->begin());
	db->persist(n1);
	db->persist(n2);
	db->persist(n3);
	db->persist(n4);
	//db->persist(l1);
	//db->persist(l2);
	t.commit();
	cout << "Press any key...\n";
	getchar();
}
void test_read(const string& name)
{
	typedef odb::query<pio::Link> query;
	typedef odb::result<pio::Link> result;
	auto_ptr<database> db (open_sqlite_database (name));
	cout << "Database "<< ((odb::sqlite::database*)&(*db))->name() <<" was opened\n";
	transaction t (db->begin ());
	result r (db->query<pio::Link> ( (query::node_a <120)));
    for (result::iterator i (r.begin ()); i != r.end (); ++i)
    {
		cout << i->getLink() << " " << i->getNode_A()->getNode() << " " << i->getNode_B()->getNode() << endl;
		
    }
	cout << "Press any key...\n";
	getchar();
}

int main(int argc, char* argv[])
{
	//test_create("C:\\Users\\vsokolov\\usr\\polaris_io\\Transims2Polaris\\test.sqlite");
	//test_read("C:\\Users\\vsokolov\\usr\\polaris_io\\Transims2Polaris\\test.sqlite");

	TransimsNetwork* net = new TransimsNetwork();
	pio::InputContainer container;
	if (argc==1)
		net->Init();
	else
		net->Init(argc, argv);
	create_sqlite_database (net->path_to_database);
	Convert<Node_File,Node, int>(net,container, container.Nodes, NODE, "NODE", false);
	Convert<Zone_File,Zone, int>(net,container, container.Zones, ZONE, "ZONE", false);
	Convert<Link_File,Link, int>(net,container, container.Links, LINK, "LINK", false);

	Convert<Pocket_File,Pocket, int>(net,container, POCKET, "POCKET", false);
	Convert<Sign_File,Sign, int>(net,container, SIGN, "SIGN", false);
	Convert<Signal_File,Signal, int>(net,container, container.Signals,SIGNAL, "SIGNAL", false);
	Convert<Timing_File,Timing, int>(net,container, TIMING_PLAN, "TIMING_PLAN", false);
	Convert<Phasing_File,Phasing, int>(net,container, PHASING_PLAN, "PHASING_PLAN", false);

	Convert<Connect_File,Connect, int>(net,container, CONNECTION, "CONNECTION", false);
	Convert<Location_File,Location, int>(net,container, container.Locations, LOCATION, "LOCATION", false);
	Convert<Parking_File,Parking, int>(net,container, container.Parkings, PARKING, "PARKING", false);	
	Convert<Veh_Type_File,Veh_Type, int>(net,container, container.Veh_Types, VEHICLE_TYPE, "VEHICLE_TYPE", false);
	Convert<Vehicle_File,Vehicle, int>(net,container, VEHICLE, "VEHICLE", false);
	Convert<Trip_File,Trip, int>(net,container, TRIP, "TRIP", false);


	cout << "Press any key...\n";
	getchar();

	return 0;
}


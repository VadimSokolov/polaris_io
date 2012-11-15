#pragma once
#include "adopter_methods.h"
#include "database.h" // create_database
#include <memory>   // std::auto_ptr
#include <odb/database.hxx>
#include <odb/transaction.hxx>
#include "OutNetwork-odb.hxx"
#include "transims_network.h"
using odb::database;
using odb::transaction;
using namespace pio;
using namespace std;
using namespace odb::core;

void ConvertNodes(string db_file_path, TransimsNetwork *net, InputContainer& container)
{
	cout << "ConvertNodes\n";
	shared_ptr<pio::Node> n;
	Node_File *file = (Node_File *) net->System_File_Handle (NODE);
	try
	{
		auto_ptr<database> db (create_sqlite_database (db_file_path));
		transaction t (db->begin());
		while (file->Read())
		{		
			net->Show_Progress();
			n = NodeAdapter(*file, container);
			container.Nodes[n->getNode()] = n;		
			db->persist(n);
		}
		t.commit();
	}
	catch (odb::sqlite::database_exception e)
	{
		cout << "ConvertNodes failed. " <<e.message() << "\n";
		exit(0);
	}
}

void ConvertLinks(string db_file_path, TransimsNetwork *net, InputContainer& container)
{
	cout << "ConvertLinks\n";
	shared_ptr<pio::Link> n;
	Link_File *file = (Link_File *) net->System_File_Handle (LINK);
	try
	{
		auto_ptr<database> db (open_sqlite_database (db_file_path));
		transaction t (db->begin());
		while (file->Read())
		{
			
			net->Show_Progress();
			n = LinkAdapter(*file, container);
			container.Links[n->getLink()] = n;		
			db->persist(n);
			
		}
		t.commit();
	}
	catch (odb::sqlite::database_exception e)
	{
		cout << "ConvertLinks failed. " <<e.message() << "\n";
		exit(0);
	}
}

void ConvertConnects(string db_file_path, TransimsNetwork *net, InputContainer& container)
{
	cout << "ConvertConnects\n";
	shared_ptr<pio::Connect> n;
	Connect_File *file = (Connect_File *) net->System_File_Handle (CONNECTION);
	try
	{
		auto_ptr<database> db (open_sqlite_database (db_file_path));
		transaction t (db->begin());
		while (file->Read())
		{
			
			net->Show_Progress();
			n = ConnectAdapter(*file, container);
			container.Connects[n->getAuto_id()] = n;		
			db->persist(n);
			
		}
		t.commit();
	}
	catch (odb::sqlite::database_exception e)
	{
		cout << "ConvertConnects failed. " <<e.message() << "\n";
		exit(0);
	}
}
void ConvertLocations(string db_file_path, TransimsNetwork *net, InputContainer& container)
{
	cout << "ConvertLocations\n";
	shared_ptr<pio::Location> n;
	Location_File *file = (Location_File *) net->System_File_Handle (LOCATION);
	try
	{
		auto_ptr<database> db (open_sqlite_database (db_file_path));
		
		while (file->Read())
		{
			transaction t (db->begin());
			net->Show_Progress();
			n = LocationAdapter(*file, container);
			container.Locations[n->getLocation()] = n;		
			db->persist(n);
			t.commit();
		}
		
	}
	catch (odb::sqlite::database_exception e)
	{
		cout << "ConvertLocations failed. " <<e.message() << "\n";
		exit(0);
	}
}
void ConvertZones(string db_file_path, TransimsNetwork *net, InputContainer& container)
{
	cout << "ConvertZones\n";
	shared_ptr<pio::Zone> n;
	Zone_File *file = (Zone_File *) net->System_File_Handle (ZONE);
	try
	{
		auto_ptr<database> db (open_sqlite_database (db_file_path));
		
		while (file->Read())
		{
			transaction t (db->begin());
			net->Show_Progress();
			n = ZoneAdapter(*file, container);
			container.Zones[n->getZone()] = n;		
			db->persist(n);
			t.commit();
		}
		
	}
	catch (odb::sqlite::database_exception e)
	{
		cout << "ConvertZones failed. " <<e.message() << "\n";
		exit(0);
	}
}
void ConvertTrips(string db_file_path, TransimsNetwork *net, InputContainer& container)
{
	cout << "ConvertTrips\n";
	bool flag = net->System_File_Flag (TRIP);
	if (!flag)
	{
		cout << "Trip File was not found\n";
		return;
	}
	shared_ptr<pio::Trip> n;
	Trip_File *file = (Trip_File *) net->System_File_Handle (TRIP);
	try
	{
		auto_ptr<database> db (open_sqlite_database (db_file_path));
		transaction t (db->begin());
		while (file->Read())
		{
			
			net->Show_Progress();
			n = TripAdapter(*file, container);
			container.Trips[n->getTrip()] = n;		
			db->persist(n);
			
		}
		t.commit();
	}
	catch (odb::sqlite::database_exception e)
	{
		cout << "ConvertTrips failed. " <<e.message() << "\n";
		exit(0);
	}
}
void ConvertVeh_Types(string db_file_path, TransimsNetwork *net, InputContainer& container)
{
	cout << "ConvertVeh_Types\n";
	bool flag = net->System_File_Flag (VEHICLE_TYPE);
	if (!flag)
	{
		cout << "Veh_Type File was not found\n";
		return;
	}
	shared_ptr<pio::Veh_Type> n;
	Veh_Type_File *file = (Veh_Type_File *) net->System_File_Handle (VEHICLE_TYPE);
	try
	{
		auto_ptr<database> db (open_sqlite_database (db_file_path));
		transaction t (db->begin());
		while (file->Read())
		{
			
			net->Show_Progress();
			n = Veh_TypeAdapter(*file, container);
			container.Veh_Types[n->getType()] = n;		
			db->persist(n);
			
		}
		t.commit();
	}
	catch (odb::sqlite::database_exception e)
	{
		cout << "ConvertVeh_Types failed. " <<e.message() << "\n";
		exit(0);
	}
}
void ConvertVehicles(string db_file_path, TransimsNetwork *net, InputContainer& container)
{
	cout << "ConvertVehicles\n";
	bool flag = net->System_File_Flag (VEHICLE);
	if (!flag)
	{
		cout << "Vehicle File was not found\n";
		return;
	}
	shared_ptr<pio::Vehicle> n;
	Vehicle_File *file = (Vehicle_File *) net->System_File_Handle (VEHICLE);
	try
	{
		auto_ptr<database> db (open_sqlite_database (db_file_path));
		transaction t (db->begin());
		while (file->Read())
		{
			
			net->Show_Progress();
			n = VehicleAdapter(*file, container);
			container.Vehicles[n->getAuto_id()] = n;		
			db->persist(n);
			
		}
		t.commit();
	}
	catch (odb::sqlite::database_exception e)
	{
		cout << "ConvertVehicles failed. " <<e.message() << "\n";
		exit(0);
	}
}
void ConvertParkings(string db_file_path, TransimsNetwork *net, InputContainer& container)
{
	cout << "ConvertParkings\n";
	bool flag = net->System_File_Flag (PARKING);
	if (!flag)
	{
		cout << "Parking File was not found\n";
		return;
	}
	shared_ptr<pio::Parking> n;
	Parking_File *file = (Parking_File *) net->System_File_Handle (PARKING);
	try
	{
		auto_ptr<database> db (open_sqlite_database (db_file_path));
		transaction t (db->begin());	
		while (file->Read(false))
		{			
			if (!file->Nested())
			{
				net->Show_Progress();
				n = ParkingAdapter(*file, container);
				container.Parkings[n->getParking()] = n;
				try 
				{
					db->persist(n);
				}
				catch (odb::object_already_persistent e)
				{
					cout << "Persist for Parking failed.\n";
					cout << "Primary key value: " << n->getParking() << ". This object will not be converted\n";
				}			
			}
		}
		t.commit();
		
	}
	catch (odb::sqlite::database_exception e)
	{
		cout << "ConvertParkings failed. " <<e.message() << "\n";
		exit(0);
	}
}
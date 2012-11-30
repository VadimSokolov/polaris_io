
#pragma once
#include "InputContext.h"
#include "File_Service.hpp"
//Converter for Node
shared_ptr<pio::Node> Adapter( Node_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::Node> result (new pio::Node ());
	result->setNode(file.Node ()); 
	result->setX(file.X ()); 
	result->setY(file.Y ()); 
	result->setZ(file.Z ()); 
	result->setSubarea(file.Subarea ()); 
	result->setPart(file.Partition ());
	return result;
}
//Converter for Zone
shared_ptr<pio::Zone> Adapter( Zone_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::Zone> result (new pio::Zone ());
	result->setZone(file.Zone ()); 
	result->setX(file.X ()); 
	result->setY(file.Y ()); 
	result->setZ(file.Z ()); 
	result->setArea(file.Area_Type ()); 
	result->setMin_X(file.Min_X ()); 
	result->setMin_Y(file.Min_Y ()); 
	result->setMax_X(file.Max_X ()); 
	result->setMax_Y(file.Max_Y ());
	return result;
}
//Converter for Shape
shared_ptr<pio::Shape> Adapter( Shape_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::Shape> result (new pio::Shape ());
	result->setLink(file.Link (), container); 
	result->setPoints(file.Points ());
	return result;
}
//Converter for Link
shared_ptr<pio::Link> Adapter( Link_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::Link> result (new pio::Link ());
	result->setLink(file.Link ()); 
	result->setName(file.Name ()); 
	result->setNode_A(file.Node_A (), container); 
	result->setNode_B(file.Node_B (), container); 
	result->setLength(file.Length ()); 
	result->setSetback_A(file.Setback_A ()); 
	result->setSetback_B(file.Setback_B ()); 
	result->setBearing_A(file.Bearing_A ()); 
	result->setBearing_B(file.Bearing_B ()); 
	result->setType(Static_Service::Facility_Code((Facility_Type)file.Type())); 
	result->setDivided(file.Divided ()); 
	result->setArea_Type(file.Area_Type ()); 
	result->setUse(file.Use ()); 
	result->setGrade(file.Grade ()); 
	result->setLanes_Ab(file.Lanes_AB ()); 
	result->setSpeed_Ab(file.Speed_AB ()); 
	result->setFspd_Ab(file.Fspd_AB ()); 
	result->setCap_Ab(file.Cap_AB ()); 
	result->setLanes_Ba(file.Lanes_BA ()); 
	result->setSpeed_Ba(file.Speed_BA ()); 
	result->setFspd_Ba(file.Fspd_BA ()); 
	result->setCap_Ba(file.Cap_BA ()); 
	result->setLeft_Ab(file.Left_AB ()); 
	result->setRight_Ab(file.Right_AB ()); 
	result->setLeft_Ba(file.Left_BA ()); 
	result->setRight_Ba(file.Right_BA ());
	return result;
}
//Converter for Pocket
shared_ptr<pio::Pocket> Adapter( Pocket_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::Pocket> result (new pio::Pocket ());
	result->setLink(file.Link (), container); 
	result->setDir(file.Dir ()); 
	result->setType(Static_Service::Pocket_Code((Pocket_Type)file.Type())); 
	result->setLanes(file.Lanes ()); 
	result->setLength(file.Length ()); 
	result->setOffset(file.Offset ());
	return result;
}
//Converter for Lane_Use
shared_ptr<pio::Lane_Use> Adapter( Lane_Use_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::Lane_Use> result (new pio::Lane_Use ());
	result->setLink(file.Link (), container); 
	result->setDir(file.Dir ()); 
	result->setLanes(file.Lanes ()); 
	result->setUse(file.Use ()); 
	result->setType(file.Type ()); 
	result->setMin_Type(file.Min_Veh_Type ()); 
	result->setMax_Type(file.Max_Veh_Type ()); 
	result->setMin_Trav(file.Min_Traveler ()); 
	result->setMax_Trav(file.Max_Traveler ()); 
	result->setStart(file.Start ().Seconds()); 
	result->setEnd(file.End ().Seconds()); 
	result->setOffset(file.Offset ()); 
	result->setLength(file.Length ()); 
	result->setToll(file.Toll ()); 
	result->setRate(file.Toll_Rate ()); 
	result->setMin_Delay(file.Min_Delay ()); 
	result->setMax_Delay(file.Max_Delay ());
	return result;
}
//Converter for Connect
shared_ptr<pio::Connect> Adapter( Connect_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::Connect> result (new pio::Connect ());
	result->setLink(file.Link (), container); 
	result->setDir(file.Dir ()); 
	result->setTo_Link(file.To_Link (), container); 
	result->setLanes(Static_Service::Lane_Range_Code(file.Lanes())); 
	result->setTo_Lanes(Static_Service::Lane_Range_Code(file.To_Lanes())); 
	result->setType(Static_Service::Connect_Code((Connect_Type)file.Type())); 
	result->setPenalty(file.Penalty ()); 
	result->setSpeed(file.Speed ()); 
	result->setCapacity(file.Capacity ()); 
	result->setIn_High(file.In_High ()); 
	result->setOut_High(file.Out_High ());
	return result;
}
//Converter for Turn_Pen
shared_ptr<pio::Turn_Pen> Adapter( Turn_Pen_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::Turn_Pen> result (new pio::Turn_Pen ());
	result->setLink(file.Link (), container); 
	result->setDir(file.Dir ()); 
	result->setTo_Link(file.To_Link (), container); 
	result->setStart(file.Start ().Seconds()); 
	result->setEnd(file.End ().Seconds()); 
	result->setUse(file.Use ()); 
	result->setMin_Type(file.Min_Veh_Type ()); 
	result->setMax_Type(file.Max_Veh_Type ()); 
	result->setPenalty(file.Penalty ()); 
	result->setIn_Node(file.In_Node (), container); 
	result->setOut_Node(file.Out_Node (), container);
	return result;
}
//Converter for Parking
shared_ptr<pio::Parking> Adapter( Parking_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::Parking> result (new pio::Parking ());
	result->setParking(file.Parking ()); 
	result->setLink(file.Link (), container); 
	result->setDir(file.Dir ()); 
	result->setOffset(file.Offset ()); 
	result->setType(file.Type ()); 
	result->setUse(file.Use ()); 
	result->setStart(file.Start ().Seconds()); 
	result->setEnd(file.End ().Seconds()); 
	result->setSpace(file.Space ()); 
	result->setTime_In(file.Time_In ().Seconds()); 
	result->setTime_Out(file.Time_Out ().Seconds()); 
	result->setHourly(file.Hourly ()); 
	result->setDaily(file.Daily ());
	return result;
}
//Converter for Location
shared_ptr<pio::Location> Adapter( Location_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::Location> result (new pio::Location ());
	result->setLocation(file.Location ()); 
	result->setLink(file.Link (), container); 
	result->setDir(file.Dir ()); 
	result->setOffset(file.Offset ()); 
	result->setSetback(file.Setback ()); 
	result->setZone(file.Zone (), container);
	return result;
}
//Converter for Access
shared_ptr<pio::Access> Adapter( Access_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::Access> result (new pio::Access ());
	result->setLink(file.Link (), container); 
	result->setFrom_Id(file.From_ID ()); 
	result->setFrom_Type(file.From_Type ()); 
	result->setTo_Id(file.To_ID ()); 
	result->setTo_Type(file.To_Type ()); 
	result->setDir(file.Dir ()); 
	result->setTime(file.Time ().Seconds()); 
	result->setCost(file.Cost ());
	return result;
}
//Converter for Sign
shared_ptr<pio::Sign> Adapter( Sign_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::Sign> result (new pio::Sign ());
	result->setLink(file.Link (), container); 
	result->setDir(file.Dir ()); 
	result->setSign(Static_Service::Control_Code((Control_Type)file.Sign()));
	return result;
}
//Converter for Signal
shared_ptr<pio::Signal> Adapter( Signal_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::Signal> result (new pio::Signal ());
	result->setSignal(file.Signal ()); 
	result->setGroup(file.Group ()); 
	result->setTimes(file.Times ()); 
	result->setType(Static_Service::Signal_Code((Signal_Type)file.Type())); 
	result->setOffset(file.Offset ());
	return result;
}
//Converter for Timing
shared_ptr<pio::Timing> Adapter( Timing_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::Timing> result (new pio::Timing ());
	result->setSignal(file.Signal (), container); 
	result->setTiming(file.Timing ()); 
	result->setType(file.Type ()); 
	result->setCycle(file.Cycle ()); 
	result->setOffset(file.Offset ()); 
	result->setPhases(file.Phases ()); 
	result->setPhase(file.Phase ()); 
	result->setBarrier(file.Barrier ()); 
	result->setRing(file.Ring ()); 
	result->setPosition(file.Position ()); 
	result->setMinimum(file.Min_Green ()); 
	result->setMaximum(file.Max_Green ()); 
	result->setExtend(file.Extension ()); 
	result->setYellow(file.Yellow ()); 
	result->setRed(file.All_Red ());
	return result;
}
//Converter for Phasing
shared_ptr<pio::Phasing> Adapter( Phasing_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::Phasing> result (new pio::Phasing ());
	result->setSignal(file.Signal (), container); 
	result->setPhasing(file.Phasing ()); 
	result->setPhase(file.Phase ()); 
	result->setDetectors(file.Detectors ()); 
	result->setMovements(file.Movements ()); 
	result->setMovement(Static_Service::Movement_Code((Movement_Type)file.Movement())); 
	result->setLink(file.Link (), container); 
	result->setDir(file.Dir ()); 
	result->setTo_Link(file.To_Link (), container); 
	result->setProtect(file.Protection ());
	return result;
}
//Converter for Detector
shared_ptr<pio::Detector> Adapter( Detector_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::Detector> result (new pio::Detector ());
	result->setDetector(file.Detector ()); 
	result->setLink(file.Link (), container); 
	result->setDir(file.Dir ()); 
	result->setOffset(file.Offset ()); 
	result->setLength(file.Length ()); 
	result->setLanes(file.Lanes ()); 
	result->setType(file.Type ()); 
	result->setUse(file.Use ()); 
	result->setLow(file.Low_Lane ()); 
	result->setHigh(file.High_Lane ());
	return result;
}
//Converter for Stop
shared_ptr<pio::Stop> Adapter( Stop_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::Stop> result (new pio::Stop ());
	result->setStop(file.Stop ()); 
	result->setName(file.Name ()); 
	result->setLink(file.Link (), container); 
	result->setDir(file.Dir ()); 
	result->setOffset(file.Offset ()); 
	result->setUse(file.Use ()); 
	result->setType(file.Type ()); 
	result->setSpace(file.Space ());
	return result;
}
//Converter for Fare
shared_ptr<pio::Fare> Adapter( Fare_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::Fare> result (new pio::Fare ());
	result->setFrom_Zone(file.iFrom_Zone (), container); 
	result->setTo_Zone(file.iTo_Zone (), container); 
	result->setFrom_Mode(file.iFrom_Mode ()); 
	result->setTo_Mode(file.iTo_Mode ()); 
	result->setPeriod(file.iPeriod ()); 
	result->setType(file.iClass ()); 
	result->setFare(file.Fare ());
	return result;
}
//Converter for Line
shared_ptr<pio::Line> Adapter( Line_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::Line> result (new pio::Line ());
	result->setRoute(file.Route ()); 
	result->setStops(file.Stops (), container); 
	result->setMode(file.Mode ()); 
	result->setType(file.Type ()); 
	result->setName(file.Name ()); 
	result->setStop(file.Stop (), container); 
	result->setZone(file.Zone (), container); 
	result->setFlag(file.Time_Flag ());
	return result;
}
//Converter for Schedule
shared_ptr<pio::Schedule> Adapter( Schedule_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::Schedule> result (new pio::Schedule ());
	result->setRoute(file.Route ()); 
	result->setStops(file.Stops (), container); 
	result->setStop(file.Stop (), container);
	return result;
}
//Converter for Driver
shared_ptr<pio::Driver> Adapter( Driver_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::Driver> result (new pio::Driver ());
	result->setRoute(file.Route ()); 
	result->setLinks(file.Links (), container); 
	result->setType(file.Type ()); 
	result->setSubtype(file.SubType ()); 
	result->setLink(file.Link (), container); 
	result->setDir(file.Dir ());
	return result;
}
//Converter for Route_Nodes
shared_ptr<pio::Route_Nodes> Adapter( Route_Nodes_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::Route_Nodes> result (new pio::Route_Nodes ());
	result->setRoute(file.Route ()); 
	result->setMode(file.Mode ()); 
	result->setVeh_Type(file.Veh_Type (), container); 
	result->setNodes(file.Nodes (), container); 
	result->setName(file.Name ()); 
	result->setNode(file.Node (), container); 
	result->setType(file.Type ()); 
	result->setDwell(file.Dwell ().Seconds()); 
	result->setTime(file.Time ().Seconds()); 
	result->setSpeed(file.Speed ());
	return result;
}
//Converter for Selection
shared_ptr<pio::Selection> Adapter( Selection_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::Selection> result (new pio::Selection ());
	result->setHhold(file.Household ()); 
	result->setPerson(file.Person ()); 
	result->setTour(file.Tour ()); 
	result->setTrip(file.Trip ()); 
	result->setType(file.Type ()); 
	result->setPartition(file.Partition ());
	return result;
}
//Converter for Household
shared_ptr<pio::Household> Adapter( Household_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::Household> result (new pio::Household ());
	result->setHhold(file.Household ()); 
	result->setLocation(file.Location (), container); 
	result->setPersons(file.Persons ()); 
	result->setWorkers(file.Workers ()); 
	result->setVehicles(file.Vehicles ()); 
	result->setType(file.Type ()); 
	result->setPartition(file.Partition ()); 
	result->setPerson(file.Person ()); 
	result->setAge(file.Age ()); 
	result->setRelate(file.Relate ()); 
	result->setGender(file.Gender ()); 
	result->setWork(file.Work ()); 
	result->setDrive(file.Drive ());
	return result;
}
//Converter for Link_Delay
shared_ptr<pio::Link_Delay> Adapter( Link_Delay_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::Link_Delay> result (new pio::Link_Delay ());
	result->setLink(file.Link (), container); 
	result->setDir(file.Dir ()); 
	result->setType(file.Type ()); 
	result->setStart(file.Start ().Seconds()); 
	result->setEnd(file.End ().Seconds()); 
	result->setFlow(file.Flow ()); 
	result->setTime(file.Time ().Seconds()); 
	result->setOut_Link(file.Out_Link (), container); 
	result->setOut_Flow(file.Out_Flow ()); 
	result->setOut_Time(file.Out_Time ().Seconds());
	return result;
}
//Converter for Performance
shared_ptr<pio::Performance> Adapter( Performance_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::Performance> result (new pio::Performance ());
	result->setSpeed(file.Speed ()); 
	result->setDelay(file.Delay ().Seconds()); 
	result->setDensity(file.Density ()); 
	result->setMax_Den(file.Max_Density ()); 
	result->setRatio(file.Time_Ratio ()); 
	result->setQueue(file.Queue ()); 
	result->setMax_Que(file.Max_Queue ()); 
	result->setFail(file.Cycle_Failure ());
	return result;
}
//Converter for Ridership
shared_ptr<pio::Ridership> Adapter( Ridership_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::Ridership> result (new pio::Ridership ());
	result->setMode(file.Mode ()); 
	result->setRoute(file.Route ()); 
	result->setRun(file.Run ()); 
	result->setStop(file.Stop (), container); 
	result->setSchedule(file.Schedule ().Seconds()); 
	result->setTime(file.Time ().Seconds()); 
	result->setBoard(file.Board ()); 
	result->setAlight(file.Alight ()); 
	result->setLoad(file.Load ()); 
	result->setFactor(file.Factor ());
	return result;
}
//Converter for Veh_Type
shared_ptr<pio::Veh_Type> Adapter( Veh_Type_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::Veh_Type> result (new pio::Veh_Type ());
	result->setType(file.Type ()); 
	result->setLength(file.Length ()); 
	result->setMax_Speed(file.Max_Speed ()); 
	result->setMax_Accel(file.Max_Accel ()); 
	result->setMax_Decel(file.Max_Decel ()); 
	result->setOp_Cost(file.Op_Cost ()); 
	result->setUse(file.Use ()); 
	result->setCapacity(file.Capacity ()); 
	result->setLoad(file.Loading ()); 
	result->setUnload(file.Unloading ()); 
	result->setMethod(file.Method ()); 
	result->setMin_Dwell(file.Min_Dwell ().Seconds()); 
	result->setMax_Dwell(file.Max_Dwell ().Seconds()); 
	result->setSubtype(file.SubType ());
	return result;
}
//Converter for Vehicle
shared_ptr<pio::Vehicle> Adapter( Vehicle_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::Vehicle> result (new pio::Vehicle ());
	result->setHhold(file.Household ()); 
	result->setVehicle(file.Vehicle ()); 
	result->setParking(file.Parking (), container); 
	result->setType(file.Type (), container); 
	result->setSubtype(file.SubType ()); 
	result->setPartition(file.Partition ());
	return result;
}
//Converter for Trip
shared_ptr<pio::Trip> Adapter( Trip_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::Trip> result (new pio::Trip ());
	result->setHhold(file.Household ()); 
	result->setPerson(file.Person ()); 
	result->setTour(file.Tour ()); 
	result->setTrip(file.Trip ()); 
	result->setStart(file.Start ().Seconds()); 
	result->setEnd(file.End ().Seconds()); 
	result->setDuration(file.Duration ().Seconds()); 
	result->setOrigin(file.Origin (), container); 
	result->setDestination(file.Destination (), container); 
	result->setPurpose(file.Purpose ()); 
	result->setMode(file.Mode ()); 
	result->setConstraint(file.Constraint ()); 
	result->setPriority(file.Priority ()); 
	result->setVehicle(file.Vehicle ()); 
	result->setPassengers(file.Passengers ()); 
	result->setType(file.Type ()); 
	result->setPartition(file.Partition ());
	return result;
}
//Converter for Problem
shared_ptr<pio::Problem> Adapter( Problem_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::Problem> result (new pio::Problem ());
	result->setProblem(file.Problem ()); 
	result->setTime(file.Time ().Seconds()); 
	result->setLink(file.Link (), container); 
	result->setDir(file.Dir ()); 
	result->setLane(file.Lane ()); 
	result->setOffset(file.Offset ()); 
	result->setRoute(file.Route ()); 
	result->setSurvey(file.Survey ());
	return result;
}
//Converter for Plan
shared_ptr<pio::Plan> Adapter( Plan_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::Plan> result (new pio::Plan ());
	result->setDepart(file.Depart ().Seconds()); 
	result->setArrive(file.Arrive ().Seconds()); 
	result->setActivity(file.Activity ().Seconds()); 
	result->setWalk(file.Walk ().Seconds()); 
	result->setDrive(file.Drive ().Seconds()); 
	result->setTransit(file.Transit ().Seconds()); 
	result->setWait(file.Wait ().Seconds()); 
	result->setOther(file.Other ().Seconds()); 
	result->setLength(file.Length ()); 
	result->setCost(file.Cost ()); 
	result->setImpedance(file.Impedance ()); 
	result->setLeg_Mode(file.Leg_Mode ()); 
	result->setLeg_Type(file.Leg_Type ()); 
	result->setLeg_Id(file.Leg_ID ()); 
	result->setLeg_Time(file.Leg_Time ().Seconds()); 
	result->setLeg_Length(file.Leg_Length ()); 
	result->setLeg_Cost(file.Leg_Cost ()); 
	result->setLeg_Imp(file.Leg_Impedance ());
	return result;
}
//Converter for Skim
shared_ptr<pio::Skim> Adapter( Skim_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::Skim> result (new pio::Skim ());
	result->setTime(file.Time ().Seconds()); 
	result->setWalk(file.Walk ().Seconds()); 
	result->setDrive(file.Drive ().Seconds()); 
	result->setTransit(file.Transit ().Seconds()); 
	result->setWait(file.Wait ().Seconds()); 
	result->setOther(file.Other ().Seconds()); 
	result->setLength(file.Length ()); 
	result->setCost(file.Cost ()); 
	result->setImpedance(file.Impedance ());
	return result;
}
//Converter for Event
shared_ptr<pio::Event> Adapter( Event_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::Event> result (new pio::Event ());
	result->setHhold(file.Household ()); 
	result->setPerson(file.Person ()); 
	result->setTour(file.Tour ()); 
	result->setTrip(file.Trip ()); 
	result->setMode(file.Mode ()); 
	result->setType(file.Event ()); 
	result->setSchedule(file.Schedule ().Seconds()); 
	result->setActual(file.Actual ().Seconds()); 
	result->setLink(file.Link (), container); 
	result->setDir(file.Dir ()); 
	result->setLane(file.Lane ()); 
	result->setOffset(file.Offset ()); 
	result->setRoute(file.Route ());
	return result;
}
//Converter for Traveler
shared_ptr<pio::Traveler> Adapter( Traveler_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::Traveler> result (new pio::Traveler ());
	result->setHhold(file.Household ()); 
	result->setPerson(file.Person ()); 
	result->setTour(file.Tour ()); 
	result->setTrip(file.Trip ()); 
	result->setMode(file.Mode ()); 
	result->setTime(file.Time ().Seconds()); 
	result->setDistance(file.Distance ()); 
	result->setSpeed(file.Speed ()); 
	result->setLink(file.Link (), container); 
	result->setDir(file.Dir ()); 
	result->setLane(file.Lane ()); 
	result->setOffset(file.Offset ()); 
	result->setRoute(file.Route ());
	return result;
}
//Converter for Trip
shared_ptr<pio::TripNoRef> AdapterNoRef( Trip_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::TripNoRef> result (new pio::TripNoRef ());
	result->setHhold(file.Household ()); 
	result->setPerson(file.Person ()); 
	result->setTour(file.Tour ()); 
	result->setTrip(file.Trip ()); 
	result->setStart(file.Start ().Seconds()); 
	result->setEnd(file.End ().Seconds()); 
	result->setDuration(file.Duration ().Seconds()); 
	result->setOrigin(file.Origin ()); 
	result->setDestination(file.Destination ()); 
	result->setPurpose(file.Purpose ()); 
	result->setMode(file.Mode ()); 
	result->setConstraint(file.Constraint ()); 
	result->setPriority(file.Priority ()); 
	result->setVehicle(file.Vehicle ()); 
	result->setPassengers(file.Passengers ()); 
	result->setType(file.Type ()); 
	result->setPartition(file.Partition ());
	return result;
}
pio::shape_geometry AdapterNested(Shape_File &file)
{
	pio::shape_geometry nested_record;
	nested_record.x = file.X ();
	nested_record.y = file.Y ();
	nested_record.z = file.Z ();
	return nested_record;
};
pio::signal_time AdapterNested(Signal_File &file)
{
	pio::signal_time nested_record;
	nested_record.start = file.Start().Seconds ();
	nested_record.end = file.End().Seconds ();
	nested_record.timing = file.Timing ();
	nested_record.phasing = file.Phasing ();
	nested_record.notes = file.Notes ();
	return nested_record;
};

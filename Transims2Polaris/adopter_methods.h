
#pragma once
#include "InputContext.h"
#include "File_Service.hpp"
//Converter for Node
void Adapter( Node_File &file, pio::InputContainer& container, shared_ptr<pio::Node> result) 
{
	result->setNode(file.Node ()); 
	result->setX(file.X ()); 
	result->setY(file.Y ()); 
	result->setZ(file.Z ()); 
	result->setSubarea(file.Subarea ()); 
	result->setPart(file.Partition ());
}
//Converter for Zone
void Adapter( Zone_File &file, pio::InputContainer& container, shared_ptr<pio::Zone> result) 
{
	result->setZone(file.Zone ()); 
	result->setX(file.X ()); 
	result->setY(file.Y ()); 
	result->setZ(file.Z ()); 
	result->setArea(file.Area_Type ()); 
	result->setMin_X(file.Min_X ()); 
	result->setMin_Y(file.Min_Y ()); 
	result->setMax_X(file.Max_X ()); 
	result->setMax_Y(file.Max_Y ());
}
//Converter for Shape
void Adapter( Shape_File &file, pio::InputContainer& container, shared_ptr<pio::Shape> result) 
{
	result->setLink(file.Link (), container); 
	result->setPoints(file.Points ()); 
	result->setX(file.X ()); 
	result->setY(file.Y ()); 
	result->setZ(file.Z ());
}
//Converter for Link
void Adapter( Link_File &file, pio::InputContainer& container, shared_ptr<pio::Link> result) 
{
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
}
//Converter for Pocket
void Adapter( Pocket_File &file, pio::InputContainer& container, shared_ptr<pio::Pocket> result) 
{
	result->setLink(file.Link (), container); 
	result->setDir(file.Dir ()); 
	result->setType(Static_Service::Pocket_Code((Pocket_Type)file.Type())); 
	result->setLanes(file.Lanes ()); 
	result->setLength(file.Length ()); 
	result->setOffset(file.Offset ());
}
//Converter for Lane_Use
void Adapter( Lane_Use_File &file, pio::InputContainer& container, shared_ptr<pio::Lane_Use> result) 
{
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
}
//Converter for Connect
void Adapter( Connect_File &file, pio::InputContainer& container, shared_ptr<pio::Connect> result) 
{
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
}
//Converter for Turn_Pen
void Adapter( Turn_Pen_File &file, pio::InputContainer& container, shared_ptr<pio::Turn_Pen> result) 
{
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
}
//Converter for Parking
void Adapter( Parking_File &file, pio::InputContainer& container, shared_ptr<pio::Parking> result) 
{
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
}
//Converter for Location
void Adapter( Location_File &file, pio::InputContainer& container, shared_ptr<pio::Location> result) 
{
	result->setLocation(file.Location ()); 
	result->setLink(file.Link (), container); 
	result->setDir(file.Dir ()); 
	result->setOffset(file.Offset ()); 
	result->setSetback(file.Setback ()); 
	result->setZone(file.Zone (), container);
}
//Converter for Access
void Adapter( Access_File &file, pio::InputContainer& container, shared_ptr<pio::Access> result) 
{
	result->setLink(file.Link (), container); 
	result->setFrom_Id(file.From_ID ()); 
	result->setFrom_Type(file.From_Type ()); 
	result->setTo_Id(file.To_ID ()); 
	result->setTo_Type(file.To_Type ()); 
	result->setDir(file.Dir ()); 
	result->setTime(file.Time ().Seconds()); 
	result->setCost(file.Cost ());
}
//Converter for Sign
void Adapter( Sign_File &file, pio::InputContainer& container, shared_ptr<pio::Sign> result) 
{
	result->setLink(file.Link (), container); 
	result->setDir(file.Dir ()); 
	result->setSign(Static_Service::Control_Code((Control_Type)file.Sign()));
}
//Converter for Signal
void Adapter( Signal_File &file, pio::InputContainer& container, shared_ptr<pio::Signal> result) 
{
	result->setSignal(file.Signal ()); 
	result->setGroup(file.Group ()); 
	result->setTimes(file.Times ()); 
	result->setStart(file.Start ().Seconds()); 
	result->setEnd(file.End ().Seconds()); 
	result->setTiming(file.Timing ()); 
	result->setPhasing(file.Phasing ()); 
	result->setType(Static_Service::Signal_Code((Signal_Type)file.Type())); 
	result->setOffset(file.Offset ());
}
//Converter for Timing
void Adapter( Timing_File &file, pio::InputContainer& container, shared_ptr<pio::Timing> result) 
{
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
}
//Converter for Phasing
void Adapter( Phasing_File &file, pio::InputContainer& container, shared_ptr<pio::Phasing> result) 
{
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
}
//Converter for Detector
void Adapter( Detector_File &file, pio::InputContainer& container, shared_ptr<pio::Detector> result) 
{
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
}
//Converter for Stop
void Adapter( Stop_File &file, pio::InputContainer& container, shared_ptr<pio::Stop> result) 
{
	result->setStop(file.Stop ()); 
	result->setName(file.Name ()); 
	result->setLink(file.Link (), container); 
	result->setDir(file.Dir ()); 
	result->setOffset(file.Offset ()); 
	result->setUse(file.Use ()); 
	result->setType(file.Type ()); 
	result->setSpace(file.Space ());
}
//Converter for Fare
void Adapter( Fare_File &file, pio::InputContainer& container, shared_ptr<pio::Fare> result) 
{
	result->setFrom_Zone(file.iFrom_Zone (), container); 
	result->setTo_Zone(file.iTo_Zone (), container); 
	result->setFrom_Mode(file.iFrom_Mode ()); 
	result->setTo_Mode(file.iTo_Mode ()); 
	result->setPeriod(file.iPeriod ()); 
	result->setType(file.iClass ()); 
	result->setFare(file.Fare ());
}
//Converter for Line
void Adapter( Line_File &file, pio::InputContainer& container, shared_ptr<pio::Line> result) 
{
	result->setRoute(file.Route ()); 
	result->setStops(file.Stops (), container); 
	result->setMode(file.Mode ()); 
	result->setType(file.Type ()); 
	result->setName(file.Name ()); 
	result->setStop(file.Stop (), container); 
	result->setZone(file.Zone (), container); 
	result->setFlag(file.Time_Flag ());
}
//Converter for Schedule
void Adapter( Schedule_File &file, pio::InputContainer& container, shared_ptr<pio::Schedule> result) 
{
	result->setRoute(file.Route ()); 
	result->setStops(file.Stops (), container); 
	result->setStop(file.Stop (), container);
}
//Converter for Driver
void Adapter( Driver_File &file, pio::InputContainer& container, shared_ptr<pio::Driver> result) 
{
	result->setRoute(file.Route ()); 
	result->setLinks(file.Links (), container); 
	result->setType(file.Type ()); 
	result->setSubtype(file.SubType ()); 
	result->setLink(file.Link (), container); 
	result->setDir(file.Dir ());
}
//Converter for Route_Nodes
void Adapter( Route_Nodes_File &file, pio::InputContainer& container, shared_ptr<pio::Route_Nodes> result) 
{
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
}
//Converter for Selection
void Adapter( Selection_File &file, pio::InputContainer& container, shared_ptr<pio::Selection> result) 
{
	result->setHhold(file.Household ()); 
	result->setPerson(file.Person ()); 
	result->setTour(file.Tour ()); 
	result->setTrip(file.Trip ()); 
	result->setType(file.Type ()); 
	result->setPartition(file.Partition ());
}
//Converter for Household
void Adapter( Household_File &file, pio::InputContainer& container, shared_ptr<pio::Household> result) 
{
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
}
//Converter for Link_Delay
void Adapter( Link_Delay_File &file, pio::InputContainer& container, shared_ptr<pio::Link_Delay> result) 
{
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
}
//Converter for Performance
void Adapter( Performance_File &file, pio::InputContainer& container, shared_ptr<pio::Performance> result) 
{
	result->setSpeed(file.Speed ()); 
	result->setDelay(file.Delay ().Seconds()); 
	result->setDensity(file.Density ()); 
	result->setMax_Den(file.Max_Density ()); 
	result->setRatio(file.Time_Ratio ()); 
	result->setQueue(file.Queue ()); 
	result->setMax_Que(file.Max_Queue ()); 
	result->setFail(file.Cycle_Failure ());
}
//Converter for Ridership
void Adapter( Ridership_File &file, pio::InputContainer& container, shared_ptr<pio::Ridership> result) 
{
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
}
//Converter for Veh_Type
void Adapter( Veh_Type_File &file, pio::InputContainer& container, shared_ptr<pio::Veh_Type> result) 
{
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
}
//Converter for Vehicle
void Adapter( Vehicle_File &file, pio::InputContainer& container, shared_ptr<pio::Vehicle> result) 
{
	result->setHhold(file.Household ()); 
	result->setVehicle(file.Vehicle ()); 
	result->setParking(file.Parking (), container); 
	result->setType(file.Type (), container); 
	result->setSubtype(file.SubType ()); 
	result->setPartition(file.Partition ());
}
//Converter for Trip
void Adapter( Trip_File &file, pio::InputContainer& container, shared_ptr<pio::Trip> result) 
{
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
}
//Converter for Problem
void Adapter( Problem_File &file, pio::InputContainer& container, shared_ptr<pio::Problem> result) 
{
	result->setProblem(file.Problem ()); 
	result->setTime(file.Time ().Seconds()); 
	result->setLink(file.Link (), container); 
	result->setDir(file.Dir ()); 
	result->setLane(file.Lane ()); 
	result->setOffset(file.Offset ()); 
	result->setRoute(file.Route ()); 
	result->setSurvey(file.Survey ());
}
//Converter for Plan
void Adapter( Plan_File &file, pio::InputContainer& container, shared_ptr<pio::Plan> result) 
{
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
}
//Converter for Skim
void Adapter( Skim_File &file, pio::InputContainer& container, shared_ptr<pio::Skim> result) 
{
	result->setTime(file.Time ().Seconds()); 
	result->setWalk(file.Walk ().Seconds()); 
	result->setDrive(file.Drive ().Seconds()); 
	result->setTransit(file.Transit ().Seconds()); 
	result->setWait(file.Wait ().Seconds()); 
	result->setOther(file.Other ().Seconds()); 
	result->setLength(file.Length ()); 
	result->setCost(file.Cost ()); 
	result->setImpedance(file.Impedance ());
}
//Converter for Event
void Adapter( Event_File &file, pio::InputContainer& container, shared_ptr<pio::Event> result) 
{
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
}
//Converter for Traveler
void Adapter( Traveler_File &file, pio::InputContainer& container, shared_ptr<pio::Traveler> result) 
{
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
}
//Converter for Trip
void AdapterNoRef( Trip_File &file, pio::InputContainer& container, shared_ptr<pio::TripNoRef> result) 
{
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
}

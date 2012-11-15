//Converter for Node
shared_ptr<pio::Node> NodeAdapter( Node_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::Node> result (new pio::Node ());
	result->setNode(file.Node ()); 
	result->setSubarea(file.Subarea ()); 
	result->setPart(file.Partition ());
	return result;
}
//Converter for Zone
shared_ptr<pio::Zone> ZoneAdapter( Zone_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::Zone> result (new pio::Zone ());
	result->setZone(file.Zone ()); 
	result->setArea(file.Area_Type ()); 
	result->setMin_X(file.Min_X ()); 
	result->setMin_Y(file.Min_Y ()); 
	result->setMax_X(file.Max_X ()); 
	result->setMax_Y(file.Max_Y ());
	return result;
}
//Converter for Shape
shared_ptr<pio::Shape> ShapeAdapter( Shape_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::Shape> result (new pio::Shape ());
	result->setLink(file.Link (), container); 
	result->setPoints(file.Points ());
	return result;
}
//Converter for Link
shared_ptr<pio::Link> LinkAdapter( Link_File &file, pio::InputContainer& container) 
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
	result->setType(file.Type ()); 
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
shared_ptr<pio::Pocket> PocketAdapter( Pocket_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::Pocket> result (new pio::Pocket ());
	result->setLink(file.Link (), container); 
	result->setDir(file.Dir ()); 
	result->setType(file.Type ()); 
	result->setLanes(file.Lanes ()); 
	result->setLength(file.Length ()); 
	result->setOffset(file.Offset ());
	return result;
}
//Converter for Lane_Use
shared_ptr<pio::Lane_Use> Lane_UseAdapter( Lane_Use_File &file, pio::InputContainer& container) 
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
	result->setOffset(file.Offset ()); 
	result->setLength(file.Length ()); 
	result->setToll(file.Toll ()); 
	result->setRate(file.Toll_Rate ()); 
	result->setMin_Delay(file.Min_Delay ()); 
	result->setMax_Delay(file.Max_Delay ());
	return result;
}
//Converter for Connect
shared_ptr<pio::Connect> ConnectAdapter( Connect_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::Connect> result (new pio::Connect ());
	result->setLink(file.Link (), container); 
	result->setDir(file.Dir ()); 
	result->setTo_Link(file.To_Link (), container); 
	result->setLanes(file.Lanes ()); 
	result->setTo_Lanes(file.To_Lanes ()); 
	result->setType(file.Type ()); 
	result->setPenalty(file.Penalty ()); 
	result->setSpeed(file.Speed ()); 
	result->setCapacity(file.Capacity ()); 
	result->setIn_High(file.In_High ()); 
	result->setOut_High(file.Out_High ());
	return result;
}
//Converter for Turn_Pen
shared_ptr<pio::Turn_Pen> Turn_PenAdapter( Turn_Pen_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::Turn_Pen> result (new pio::Turn_Pen ());
	result->setLink(file.Link (), container); 
	result->setDir(file.Dir ()); 
	result->setTo_Link(file.To_Link (), container); 
	result->setUse(file.Use ()); 
	result->setMin_Type(file.Min_Veh_Type ()); 
	result->setMax_Type(file.Max_Veh_Type ()); 
	result->setPenalty(file.Penalty ()); 
	result->setIn_Node(file.In_Node (), container); 
	result->setOut_Node(file.Out_Node (), container);
	return result;
}
//Converter for Parking
shared_ptr<pio::Parking> ParkingAdapter( Parking_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::Parking> result (new pio::Parking ());
	result->setParking(file.Parking ()); 
	result->setLink(file.Link (), container); 
	result->setDir(file.Dir ()); 
	result->setOffset(file.Offset ()); 
	result->setType(file.Type ()); 
	result->setUse(file.Use ()); 
	result->setSpace(file.Space ()); 
	result->setHourly(file.Hourly ()); 
	result->setDaily(file.Daily ());
	return result;
}
//Converter for Location
shared_ptr<pio::Location> LocationAdapter( Location_File &file, pio::InputContainer& container) 
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
shared_ptr<pio::Access> AccessAdapter( Access_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::Access> result (new pio::Access ());
	result->setLink(file.Link (), container); 
	result->setFrom_Id(file.From_ID ()); 
	result->setFrom_Type(file.From_Type ()); 
	result->setTo_Id(file.To_ID ()); 
	result->setTo_Type(file.To_Type ()); 
	result->setDir(file.Dir ()); 
	result->setCost(file.Cost ());
	return result;
}
//Converter for Sign
shared_ptr<pio::Sign> SignAdapter( Sign_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::Sign> result (new pio::Sign ());
	result->setLink(file.Link (), container); 
	result->setDir(file.Dir ()); 
	result->setSign(file.Sign ());
	return result;
}
//Converter for Signal
shared_ptr<pio::Signal> SignalAdapter( Signal_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::Signal> result (new pio::Signal ());
	result->setSignal(file.Signal ()); 
	result->setGroup(file.Group ()); 
	result->setTimes(file.Times ()); 
	result->setTiming(file.Timing (), container); 
	result->setPhasing(file.Phasing (), container); 
	result->setType(file.Type ()); 
	result->setOffset(file.Offset ());
	return result;
}
//Converter for Timing
shared_ptr<pio::Timing> TimingAdapter( Timing_File &file, pio::InputContainer& container) 
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
shared_ptr<pio::Phasing> PhasingAdapter( Phasing_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::Phasing> result (new pio::Phasing ());
	result->setSignal(file.Signal (), container); 
	result->setPhasing(file.Phasing ()); 
	result->setPhase(file.Phase ()); 
	result->setDetectors(file.Detectors (), container); 
	result->setMovements(file.Movements ()); 
	result->setMovement(file.Movement ()); 
	result->setLink(file.Link (), container); 
	result->setDir(file.Dir ()); 
	result->setTo_Link(file.To_Link (), container); 
	result->setProtect(file.Protection ());
	return result;
}
//Converter for Detector
shared_ptr<pio::Detector> DetectorAdapter( Detector_File &file, pio::InputContainer& container) 
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
shared_ptr<pio::Stop> StopAdapter( Stop_File &file, pio::InputContainer& container) 
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
shared_ptr<pio::Fare> FareAdapter( Fare_File &file, pio::InputContainer& container) 
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
shared_ptr<pio::Line> LineAdapter( Line_File &file, pio::InputContainer& container) 
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
shared_ptr<pio::Schedule> ScheduleAdapter( Schedule_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::Schedule> result (new pio::Schedule ());
	result->setRoute(file.Route ()); 
	result->setStops(file.Stops (), container); 
	result->setStop(file.Stop (), container);
	return result;
}
//Converter for Driver
shared_ptr<pio::Driver> DriverAdapter( Driver_File &file, pio::InputContainer& container) 
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
shared_ptr<pio::Route_Nodes> Route_NodesAdapter( Route_Nodes_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::Route_Nodes> result (new pio::Route_Nodes ());
	result->setRoute(file.Route ()); 
	result->setMode(file.Mode ()); 
	result->setVeh_Type(file.Veh_Type (), container); 
	result->setNodes(file.Nodes (), container); 
	result->setName(file.Name ()); 
	result->setNode(file.Node (), container); 
	result->setType(file.Type ()); 
	result->setSpeed(file.Speed ());
	return result;
}
//Converter for Selection
shared_ptr<pio::Selection> SelectionAdapter( Selection_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::Selection> result (new pio::Selection ());
	result->setHhold(file.Household ()); 
	result->setPerson(file.Person ()); 
	result->setTour(file.Tour ()); 
	result->setTrip(file.Trip (), container); 
	result->setType(file.Type ()); 
	result->setPartition(file.Partition ());
	return result;
}
//Converter for Household
shared_ptr<pio::Household> HouseholdAdapter( Household_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::Household> result (new pio::Household ());
	result->setHhold(file.Household ()); 
	result->setLocation(file.Location (), container); 
	result->setPersons(file.Persons ()); 
	result->setWorkers(file.Workers ()); 
	result->setVehicles(file.Vehicles (), container); 
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
shared_ptr<pio::Link_Delay> Link_DelayAdapter( Link_Delay_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::Link_Delay> result (new pio::Link_Delay ());
	result->setLink(file.Link (), container); 
	result->setDir(file.Dir ()); 
	result->setType(file.Type ()); 
	result->setFlow(file.Flow ()); 
	result->setOut_Link(file.Out_Link (), container); 
	result->setOut_Flow(file.Out_Flow ());
	return result;
}
//Converter for Performance
shared_ptr<pio::Performance> PerformanceAdapter( Performance_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::Performance> result (new pio::Performance ());
	result->setSpeed(file.Speed ()); 
	result->setDensity(file.Density ()); 
	result->setMax_Den(file.Max_Density ()); 
	result->setRatio(file.Time_Ratio ()); 
	result->setQueue(file.Queue ()); 
	result->setMax_Que(file.Max_Queue ()); 
	result->setFail(file.Cycle_Failure ());
	return result;
}
//Converter for Ridership
shared_ptr<pio::Ridership> RidershipAdapter( Ridership_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::Ridership> result (new pio::Ridership ());
	result->setMode(file.Mode ()); 
	result->setRoute(file.Route ()); 
	result->setRun(file.Run ()); 
	result->setStop(file.Stop (), container); 
	result->setBoard(file.Board ()); 
	result->setAlight(file.Alight ()); 
	result->setLoad(file.Load ()); 
	result->setFactor(file.Factor ());
	return result;
}
//Converter for Veh_Type
shared_ptr<pio::Veh_Type> Veh_TypeAdapter( Veh_Type_File &file, pio::InputContainer& container) 
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
	result->setSubtype(file.SubType ());
	return result;
}
//Converter for Vehicle
shared_ptr<pio::Vehicle> VehicleAdapter( Vehicle_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::Vehicle> result (new pio::Vehicle ());
	result->setHhold(file.Household ()); 
	result->setVehicle(file.Vehicle ()); 
	result->setParking(file.Parking (), container); 
	result->setType(file.Type ()); 
	result->setSubtype(file.SubType ()); 
	result->setPartition(file.Partition ());
	return result;
}
//Converter for Trip
shared_ptr<pio::Trip> TripAdapter( Trip_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::Trip> result (new pio::Trip ());
	result->setHhold(file.Household ()); 
	result->setPerson(file.Person ()); 
	result->setTour(file.Tour ()); 
	result->setTrip(file.Trip ()); 
	result->setOrigin(file.Origin ()); 
	result->setDestination(file.Destination ()); 
	result->setPurpose(file.Purpose ()); 
	result->setMode(file.Mode ()); 
	result->setConstraint(file.Constraint ()); 
	result->setPriority(file.Priority ()); 
	result->setVehicle(file.Vehicle (), container); 
	result->setPassengers(file.Passengers ()); 
	result->setType(file.Type ()); 
	result->setPartition(file.Partition ());
	return result;
}
//Converter for Problem
shared_ptr<pio::Problem> ProblemAdapter( Problem_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::Problem> result (new pio::Problem ());
	result->setProblem(file.Problem ()); 
	result->setLink(file.Link (), container); 
	result->setDir(file.Dir ()); 
	result->setLane(file.Lane ()); 
	result->setOffset(file.Offset ()); 
	result->setRoute(file.Route ()); 
	result->setSurvey(file.Survey ());
	return result;
}
//Converter for Plan
shared_ptr<pio::Plan> PlanAdapter( Plan_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::Plan> result (new pio::Plan ());
	result->setLength(file.Length ()); 
	result->setCost(file.Cost ()); 
	result->setImpedance(file.Impedance ()); 
	result->setLeg_Mode(file.Leg_Mode ()); 
	result->setLeg_Type(file.Leg_Type ()); 
	result->setLeg_Id(file.Leg_ID ()); 
	result->setLeg_Length(file.Leg_Length ()); 
	result->setLeg_Cost(file.Leg_Cost ()); 
	result->setLeg_Imp(file.Leg_Impedance ());
	return result;
}
//Converter for Skim
shared_ptr<pio::Skim> SkimAdapter( Skim_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::Skim> result (new pio::Skim ());
	result->setLength(file.Length ()); 
	result->setCost(file.Cost ()); 
	result->setImpedance(file.Impedance ());
	return result;
}
//Converter for Event
shared_ptr<pio::Event> EventAdapter( Event_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::Event> result (new pio::Event ());
	result->setHhold(file.Household ()); 
	result->setPerson(file.Person ()); 
	result->setTour(file.Tour ()); 
	result->setTrip(file.Trip (), container); 
	result->setMode(file.Mode ()); 
	result->setType(file.Event ()); 
	result->setLink(file.Link (), container); 
	result->setDir(file.Dir ()); 
	result->setLane(file.Lane ()); 
	result->setOffset(file.Offset ()); 
	result->setRoute(file.Route ());
	return result;
}
//Converter for Traveler
shared_ptr<pio::Traveler> TravelerAdapter( Traveler_File &file, pio::InputContainer& container) 
{
	shared_ptr<pio::Traveler> result (new pio::Traveler ());
	result->setHhold(file.Household ()); 
	result->setPerson(file.Person ()); 
	result->setTour(file.Tour ()); 
	result->setTrip(file.Trip (), container); 
	result->setMode(file.Mode ()); 
	result->setDistance(file.Distance ()); 
	result->setSpeed(file.Speed ()); 
	result->setLink(file.Link (), container); 
	result->setDir(file.Dir ()); 
	result->setLane(file.Lane ()); 
	result->setOffset(file.Offset ()); 
	result->setRoute(file.Route ());
	return result;
}

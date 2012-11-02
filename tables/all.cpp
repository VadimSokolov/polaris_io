
#pragma db object
class Node
{
public:
	//Contructor
	Node ( int node_, int subarea_, int part_ )  
	: node (node_), subarea (subarea_), part (part_)
	{
	}
	//ConverterConstructor
	
	 Node( Node_File *file) 
	{
		setNode(file -> Node ()); 
		setSubarea(file -> Subarea ()); 
		setPart(file -> Partition ());
	}
	//Accessors
	const int& getNode () const {return node;}
	void setNode (const int& node_){node = node_;}
	const int& getSubarea () const {return subarea;}
	void setSubarea (const int& subarea_){subarea = subarea_;}
	const int& getPart () const {return part;}
	void setPart (const int& part_){part = part_;}

//Data Fields
private:
	friend class odb::access;
	Node () {}
	#pragma db id
	int node;
	int subarea;
	int part;

};

	
#pragma db object
class Zone
{
public:
	//Contructor
	Zone ( int zone_, int area_, double min_x_, double min_y_, double max_x_, double max_y_ )  
	: zone (zone_), area (area_), min_x (min_x_), min_y (min_y_), max_x (max_x_), max_y (max_y_)
	{
	}
	//ConverterConstructor
	
	 Zone( Zone_File *file) 
	{
		setZone(file -> Zone ()); 
		setArea(file -> Area_Type ()); 
		setMin_X(file -> Min_X ()); 
		setMin_Y(file -> Min_Y ()); 
		setMax_X(file -> Max_X ()); 
		setMax_Y(file -> Max_Y ());
	}
	//Accessors
	const int& getZone () const {return zone;}
	void setZone (const int& zone_){zone = zone_;}
	const int& getArea () const {return area;}
	void setArea (const int& area_){area = area_;}
	const double& getMin_X () const {return min_x;}
	void setMin_X (const double& min_x_){min_x = min_x_;}
	const double& getMin_Y () const {return min_y;}
	void setMin_Y (const double& min_y_){min_y = min_y_;}
	const double& getMax_X () const {return max_x;}
	void setMax_X (const double& max_x_){max_x = max_x_;}
	const double& getMax_Y () const {return max_y;}
	void setMax_Y (const double& max_y_){max_y = max_y_;}

//Data Fields
private:
	friend class odb::access;
	Zone () {}
	#pragma db id
	int zone;
	int area;
	double min_x;
	double min_y;
	double max_x;
	double max_y;

};

	
#pragma db object
class Shape
{
public:
	//Contructor
	Shape ( shared_ptr<Link> link_, int points_ )  
	: link (link_), points (points_)
	{
	}
	//ConverterConstructor
	
	 Shape( Shape_File *file) 
	{
		setLink(file -> Link ()); 
		setPoints(file -> Points ());
	}
	//Accessors
	const shared_ptr<Link>& getLink () const {return link;}
	void setLink (const shared_ptr<Link>& link_){link = link_;}
	void setLink (const int& link_){/*TODO: imlement this setter*/;}
	const int& getPoints () const {return points;}
	void setPoints (const int& points_){points = points_;}

//Data Fields
private:
	friend class odb::access;
	Shape () {}
	#pragma db id
	shared_ptr<Link> link;
	int points;

};

	
#pragma db object
class Link
{
public:
	//Contructor
	Link ( int link_, std::string name_, shared_ptr<Node> node_a_, shared_ptr<Node> node_b_, double length_, double setback_a_, double setback_b_, int bearing_a_, int bearing_b_, int type_, int divided_, int area_type_, int use_, double grade_, int lanes_ab_, double speed_ab_, double fspd_ab_, int cap_ab_, int lanes_ba_, double speed_ba_, double fspd_ba_, int cap_ba_, int left_ab_, int right_ab_, int left_ba_, int right_ba_ )  
	: link (link_), name (name_), node_a (node_a_), node_b (node_b_), length (length_), setback_a (setback_a_), setback_b (setback_b_), bearing_a (bearing_a_), bearing_b (bearing_b_), type (type_), divided (divided_), area_type (area_type_), use (use_), grade (grade_), lanes_ab (lanes_ab_), speed_ab (speed_ab_), fspd_ab (fspd_ab_), cap_ab (cap_ab_), lanes_ba (lanes_ba_), speed_ba (speed_ba_), fspd_ba (fspd_ba_), cap_ba (cap_ba_), left_ab (left_ab_), right_ab (right_ab_), left_ba (left_ba_), right_ba (right_ba_)
	{
	}
	//ConverterConstructor
	
	 Link( Link_File *file) 
	{
		setLink(file -> Link ()); 
		setName(file -> Name ()); 
		setNode_A(file -> Node_A ()); 
		setNode_B(file -> Node_B ()); 
		setLength(file -> Length ()); 
		setSetback_A(file -> Setback_A ()); 
		setSetback_B(file -> Setback_B ()); 
		setBearing_A(file -> Bearing_A ()); 
		setBearing_B(file -> Bearing_B ()); 
		setType(file -> Type ()); 
		setDivided(file -> Divided ()); 
		setArea_Type(file -> Area_Type ()); 
		setUse(file -> Use ()); 
		setGrade(file -> Grade ()); 
		setLanes_Ab(file -> Lanes_AB ()); 
		setSpeed_Ab(file -> Speed_AB ()); 
		setFspd_Ab(file -> Fspd_AB ()); 
		setCap_Ab(file -> Cap_AB ()); 
		setLanes_Ba(file -> Lanes_BA ()); 
		setSpeed_Ba(file -> Speed_BA ()); 
		setFspd_Ba(file -> Fspd_BA ()); 
		setCap_Ba(file -> Cap_BA ()); 
		setLeft_Ab(file -> Left_AB ()); 
		setRight_Ab(file -> Right_AB ()); 
		setLeft_Ba(file -> Left_BA ()); 
		setRight_Ba(file -> Right_BA ());
	}
	//Accessors
	const int& getLink () const {return link;}
	void setLink (const int& link_){link = link_;}
	const std::string& getName () const {return name;}
	void setName (const std::string& name_){name = name_;}
	const shared_ptr<Node>& getNode_A () const {return node_a;}
	void setNode_A (const shared_ptr<Node>& node_a_){node_a = node_a_;}
	void setNode_A (const int& node_a_){/*TODO: imlement this setter*/;}
	const shared_ptr<Node>& getNode_B () const {return node_b;}
	void setNode_B (const shared_ptr<Node>& node_b_){node_b = node_b_;}
	void setNode_B (const int& node_b_){/*TODO: imlement this setter*/;}
	const double& getLength () const {return length;}
	void setLength (const double& length_){length = length_;}
	const double& getSetback_A () const {return setback_a;}
	void setSetback_A (const double& setback_a_){setback_a = setback_a_;}
	const double& getSetback_B () const {return setback_b;}
	void setSetback_B (const double& setback_b_){setback_b = setback_b_;}
	const int& getBearing_A () const {return bearing_a;}
	void setBearing_A (const int& bearing_a_){bearing_a = bearing_a_;}
	const int& getBearing_B () const {return bearing_b;}
	void setBearing_B (const int& bearing_b_){bearing_b = bearing_b_;}
	const int& getType () const {return type;}
	void setType (const int& type_){type = type_;}
	const int& getDivided () const {return divided;}
	void setDivided (const int& divided_){divided = divided_;}
	const int& getArea_Type () const {return area_type;}
	void setArea_Type (const int& area_type_){area_type = area_type_;}
	const int& getUse () const {return use;}
	void setUse (const int& use_){use = use_;}
	const double& getGrade () const {return grade;}
	void setGrade (const double& grade_){grade = grade_;}
	const int& getLanes_Ab () const {return lanes_ab;}
	void setLanes_Ab (const int& lanes_ab_){lanes_ab = lanes_ab_;}
	const double& getSpeed_Ab () const {return speed_ab;}
	void setSpeed_Ab (const double& speed_ab_){speed_ab = speed_ab_;}
	const double& getFspd_Ab () const {return fspd_ab;}
	void setFspd_Ab (const double& fspd_ab_){fspd_ab = fspd_ab_;}
	const int& getCap_Ab () const {return cap_ab;}
	void setCap_Ab (const int& cap_ab_){cap_ab = cap_ab_;}
	const int& getLanes_Ba () const {return lanes_ba;}
	void setLanes_Ba (const int& lanes_ba_){lanes_ba = lanes_ba_;}
	const double& getSpeed_Ba () const {return speed_ba;}
	void setSpeed_Ba (const double& speed_ba_){speed_ba = speed_ba_;}
	const double& getFspd_Ba () const {return fspd_ba;}
	void setFspd_Ba (const double& fspd_ba_){fspd_ba = fspd_ba_;}
	const int& getCap_Ba () const {return cap_ba;}
	void setCap_Ba (const int& cap_ba_){cap_ba = cap_ba_;}
	const int& getLeft_Ab () const {return left_ab;}
	void setLeft_Ab (const int& left_ab_){left_ab = left_ab_;}
	const int& getRight_Ab () const {return right_ab;}
	void setRight_Ab (const int& right_ab_){right_ab = right_ab_;}
	const int& getLeft_Ba () const {return left_ba;}
	void setLeft_Ba (const int& left_ba_){left_ba = left_ba_;}
	const int& getRight_Ba () const {return right_ba;}
	void setRight_Ba (const int& right_ba_){right_ba = right_ba_;}

//Data Fields
private:
	friend class odb::access;
	Link () {}
	#pragma db id
	int link;
	std::string name;
	shared_ptr<Node> node_a;
	shared_ptr<Node> node_b;
	double length;
	double setback_a;
	double setback_b;
	int bearing_a;
	int bearing_b;
	int type;
	int divided;
	int area_type;
	int use;
	double grade;
	int lanes_ab;
	double speed_ab;
	double fspd_ab;
	int cap_ab;
	int lanes_ba;
	double speed_ba;
	double fspd_ba;
	int cap_ba;
	int left_ab;
	int right_ab;
	int left_ba;
	int right_ba;

};

	
#pragma db object
class Pocket
{
public:
	//Contructor
	Pocket ( shared_ptr<Link> link_, int dir_, int type_, int lanes_, double length_, double offset_ )  
	: link (link_), dir (dir_), type (type_), lanes (lanes_), length (length_), offset (offset_)
	{
	}
	//ConverterConstructor
	
	 Pocket( Pocket_File *file) 
	{
		setLink(file -> Link ()); 
		setDir(file -> Dir ()); 
		setType(file -> Type ()); 
		setLanes(file -> Lanes ()); 
		setLength(file -> Length ()); 
		setOffset(file -> Offset ());
	}
	//Accessors
	const shared_ptr<Link>& getLink () const {return link;}
	void setLink (const shared_ptr<Link>& link_){link = link_;}
	void setLink (const int& link_){/*TODO: imlement this setter*/;}
	const int& getDir () const {return dir;}
	void setDir (const int& dir_){dir = dir_;}
	const int& getType () const {return type;}
	void setType (const int& type_){type = type_;}
	const int& getLanes () const {return lanes;}
	void setLanes (const int& lanes_){lanes = lanes_;}
	const double& getLength () const {return length;}
	void setLength (const double& length_){length = length_;}
	const double& getOffset () const {return offset;}
	void setOffset (const double& offset_){offset = offset_;}

//Data Fields
private:
	friend class odb::access;
	Pocket () {}
	#pragma db id
	shared_ptr<Link> link;
	int dir;
	int type;
	int lanes;
	double length;
	double offset;

};

	
#pragma db object
class Lane_Use
{
public:
	//Contructor
	Lane_Use ( shared_ptr<Link> link_, int dir_, int lanes_, int use_, int type_, int min_type_, int max_type_, int min_trav_, int max_trav_, double offset_, double length_, int toll_, double rate_, double min_delay_, double max_delay_ )  
	: link (link_), dir (dir_), lanes (lanes_), use (use_), type (type_), min_type (min_type_), max_type (max_type_), min_trav (min_trav_), max_trav (max_trav_), offset (offset_), length (length_), toll (toll_), rate (rate_), min_delay (min_delay_), max_delay (max_delay_)
	{
	}
	//ConverterConstructor
	
	 Lane_Use( Lane_Use_File *file) 
	{
		setLink(file -> Link ()); 
		setDir(file -> Dir ()); 
		setLanes(file -> Lanes ()); 
		setUse(file -> Use ()); 
		setType(file -> Type ()); 
		setMin_Type(file -> Min_Veh_Type ()); 
		setMax_Type(file -> Max_Veh_Type ()); 
		setMin_Trav(file -> Min_Traveler ()); 
		setMax_Trav(file -> Max_Traveler ()); 
		setOffset(file -> Offset ()); 
		setLength(file -> Length ()); 
		setToll(file -> Toll ()); 
		setRate(file -> Toll_Rate ()); 
		setMin_Delay(file -> Min_Delay ()); 
		setMax_Delay(file -> Max_Delay ());
	}
	//Accessors
	const shared_ptr<Link>& getLink () const {return link;}
	void setLink (const shared_ptr<Link>& link_){link = link_;}
	void setLink (const int& link_){/*TODO: imlement this setter*/;}
	const int& getDir () const {return dir;}
	void setDir (const int& dir_){dir = dir_;}
	const int& getLanes () const {return lanes;}
	void setLanes (const int& lanes_){lanes = lanes_;}
	const int& getUse () const {return use;}
	void setUse (const int& use_){use = use_;}
	const int& getType () const {return type;}
	void setType (const int& type_){type = type_;}
	const int& getMin_Type () const {return min_type;}
	void setMin_Type (const int& min_type_){min_type = min_type_;}
	const int& getMax_Type () const {return max_type;}
	void setMax_Type (const int& max_type_){max_type = max_type_;}
	const int& getMin_Trav () const {return min_trav;}
	void setMin_Trav (const int& min_trav_){min_trav = min_trav_;}
	const int& getMax_Trav () const {return max_trav;}
	void setMax_Trav (const int& max_trav_){max_trav = max_trav_;}
	const double& getOffset () const {return offset;}
	void setOffset (const double& offset_){offset = offset_;}
	const double& getLength () const {return length;}
	void setLength (const double& length_){length = length_;}
	const int& getToll () const {return toll;}
	void setToll (const int& toll_){toll = toll_;}
	const double& getRate () const {return rate;}
	void setRate (const double& rate_){rate = rate_;}
	const double& getMin_Delay () const {return min_delay;}
	void setMin_Delay (const double& min_delay_){min_delay = min_delay_;}
	const double& getMax_Delay () const {return max_delay;}
	void setMax_Delay (const double& max_delay_){max_delay = max_delay_;}

//Data Fields
private:
	friend class odb::access;
	Lane_Use () {}
	#pragma db id
	shared_ptr<Link> link;
	int dir;
	int lanes;
	int use;
	int type;
	int min_type;
	int max_type;
	int min_trav;
	int max_trav;
	double offset;
	double length;
	int toll;
	double rate;
	double min_delay;
	double max_delay;

};

	
#pragma db object
class Connect
{
public:
	//Contructor
	Connect ( shared_ptr<Link> link_, int dir_, shared_ptr<Link> to_link_, int lanes_, int to_lanes_, int type_, int penalty_, double speed_, int capacity_, int in_high_, int out_high_ )  
	: link (link_), dir (dir_), to_link (to_link_), lanes (lanes_), to_lanes (to_lanes_), type (type_), penalty (penalty_), speed (speed_), capacity (capacity_), in_high (in_high_), out_high (out_high_)
	{
	}
	//ConverterConstructor
	
	 Connect( Connect_File *file) 
	{
		setLink(file -> Link ()); 
		setDir(file -> Dir ()); 
		setTo_Link(file -> To_Link ()); 
		setLanes(file -> Lanes ()); 
		setTo_Lanes(file -> To_Lanes ()); 
		setType(file -> Type ()); 
		setPenalty(file -> Penalty ()); 
		setSpeed(file -> Speed ()); 
		setCapacity(file -> Capacity ()); 
		setIn_High(file -> In_High ()); 
		setOut_High(file -> Out_High ());
	}
	//Accessors
	const shared_ptr<Link>& getLink () const {return link;}
	void setLink (const shared_ptr<Link>& link_){link = link_;}
	void setLink (const int& link_){/*TODO: imlement this setter*/;}
	const int& getDir () const {return dir;}
	void setDir (const int& dir_){dir = dir_;}
	const shared_ptr<Link>& getTo_Link () const {return to_link;}
	void setTo_Link (const shared_ptr<Link>& to_link_){to_link = to_link_;}
	void setTo_Link (const int& to_link_){/*TODO: imlement this setter*/;}
	const int& getLanes () const {return lanes;}
	void setLanes (const int& lanes_){lanes = lanes_;}
	const int& getTo_Lanes () const {return to_lanes;}
	void setTo_Lanes (const int& to_lanes_){to_lanes = to_lanes_;}
	const int& getType () const {return type;}
	void setType (const int& type_){type = type_;}
	const int& getPenalty () const {return penalty;}
	void setPenalty (const int& penalty_){penalty = penalty_;}
	const double& getSpeed () const {return speed;}
	void setSpeed (const double& speed_){speed = speed_;}
	const int& getCapacity () const {return capacity;}
	void setCapacity (const int& capacity_){capacity = capacity_;}
	const int& getIn_High () const {return in_high;}
	void setIn_High (const int& in_high_){in_high = in_high_;}
	const int& getOut_High () const {return out_high;}
	void setOut_High (const int& out_high_){out_high = out_high_;}

//Data Fields
private:
	friend class odb::access;
	Connect () {}
	#pragma db id
	shared_ptr<Link> link;
	int dir;
	shared_ptr<Link> to_link;
	int lanes;
	int to_lanes;
	int type;
	int penalty;
	double speed;
	int capacity;
	int in_high;
	int out_high;

};

	
#pragma db object
class Turn_Pen
{
public:
	//Contructor
	Turn_Pen ( shared_ptr<Link> link_, int dir_, shared_ptr<Link> to_link_, int use_, int min_type_, int max_type_, int penalty_, shared_ptr<Node> in_node_, shared_ptr<Node> out_node_ )  
	: link (link_), dir (dir_), to_link (to_link_), use (use_), min_type (min_type_), max_type (max_type_), penalty (penalty_), in_node (in_node_), out_node (out_node_)
	{
	}
	//ConverterConstructor
	
	 Turn_Pen( Turn_Pen_File *file) 
	{
		setLink(file -> Link ()); 
		setDir(file -> Dir ()); 
		setTo_Link(file -> To_Link ()); 
		setUse(file -> Use ()); 
		setMin_Type(file -> Min_Veh_Type ()); 
		setMax_Type(file -> Max_Veh_Type ()); 
		setPenalty(file -> Penalty ()); 
		setIn_Node(file -> In_Node ()); 
		setOut_Node(file -> Out_Node ());
	}
	//Accessors
	const shared_ptr<Link>& getLink () const {return link;}
	void setLink (const shared_ptr<Link>& link_){link = link_;}
	void setLink (const int& link_){/*TODO: imlement this setter*/;}
	const int& getDir () const {return dir;}
	void setDir (const int& dir_){dir = dir_;}
	const shared_ptr<Link>& getTo_Link () const {return to_link;}
	void setTo_Link (const shared_ptr<Link>& to_link_){to_link = to_link_;}
	void setTo_Link (const int& to_link_){/*TODO: imlement this setter*/;}
	const int& getUse () const {return use;}
	void setUse (const int& use_){use = use_;}
	const int& getMin_Type () const {return min_type;}
	void setMin_Type (const int& min_type_){min_type = min_type_;}
	const int& getMax_Type () const {return max_type;}
	void setMax_Type (const int& max_type_){max_type = max_type_;}
	const int& getPenalty () const {return penalty;}
	void setPenalty (const int& penalty_){penalty = penalty_;}
	const shared_ptr<Node>& getIn_Node () const {return in_node;}
	void setIn_Node (const shared_ptr<Node>& in_node_){in_node = in_node_;}
	void setIn_Node (const int& in_node_){/*TODO: imlement this setter*/;}
	const shared_ptr<Node>& getOut_Node () const {return out_node;}
	void setOut_Node (const shared_ptr<Node>& out_node_){out_node = out_node_;}
	void setOut_Node (const int& out_node_){/*TODO: imlement this setter*/;}

//Data Fields
private:
	friend class odb::access;
	Turn_Pen () {}
	#pragma db id
	shared_ptr<Link> link;
	int dir;
	shared_ptr<Link> to_link;
	int use;
	int min_type;
	int max_type;
	int penalty;
	shared_ptr<Node> in_node;
	shared_ptr<Node> out_node;

};

	
#pragma db object
class Parking
{
public:
	//Contructor
	Parking ( int parking_, shared_ptr<Link> link_, int dir_, double offset_, int type_, int use_, int space_, int hourly_, int daily_ )  
	: parking (parking_), link (link_), dir (dir_), offset (offset_), type (type_), use (use_), space (space_), hourly (hourly_), daily (daily_)
	{
	}
	//ConverterConstructor
	
	 Parking( Parking_File *file) 
	{
		setParking(file -> Parking ()); 
		setLink(file -> Link ()); 
		setDir(file -> Dir ()); 
		setOffset(file -> Offset ()); 
		setType(file -> Type ()); 
		setUse(file -> Use ()); 
		setSpace(file -> Space ()); 
		setHourly(file -> Hourly ()); 
		setDaily(file -> Daily ());
	}
	//Accessors
	const int& getParking () const {return parking;}
	void setParking (const int& parking_){parking = parking_;}
	const shared_ptr<Link>& getLink () const {return link;}
	void setLink (const shared_ptr<Link>& link_){link = link_;}
	void setLink (const int& link_){/*TODO: imlement this setter*/;}
	const int& getDir () const {return dir;}
	void setDir (const int& dir_){dir = dir_;}
	const double& getOffset () const {return offset;}
	void setOffset (const double& offset_){offset = offset_;}
	const int& getType () const {return type;}
	void setType (const int& type_){type = type_;}
	const int& getUse () const {return use;}
	void setUse (const int& use_){use = use_;}
	const int& getSpace () const {return space;}
	void setSpace (const int& space_){space = space_;}
	const int& getHourly () const {return hourly;}
	void setHourly (const int& hourly_){hourly = hourly_;}
	const int& getDaily () const {return daily;}
	void setDaily (const int& daily_){daily = daily_;}

//Data Fields
private:
	friend class odb::access;
	Parking () {}
	#pragma db id
	int parking;
	shared_ptr<Link> link;
	int dir;
	double offset;
	int type;
	int use;
	int space;
	int hourly;
	int daily;

};

	
#pragma db object
class Location
{
public:
	//Contructor
	Location ( int location_, shared_ptr<Link> link_, int dir_, double offset_, double setback_, shared_ptr<Zone> zone_ )  
	: location (location_), link (link_), dir (dir_), offset (offset_), setback (setback_), zone (zone_)
	{
	}
	//ConverterConstructor
	
	 Location( Location_File *file) 
	{
		setLocation(file -> Location ()); 
		setLink(file -> Link ()); 
		setDir(file -> Dir ()); 
		setOffset(file -> Offset ()); 
		setSetback(file -> Setback ()); 
		setZone(file -> Zone ());
	}
	//Accessors
	const int& getLocation () const {return location;}
	void setLocation (const int& location_){location = location_;}
	const shared_ptr<Link>& getLink () const {return link;}
	void setLink (const shared_ptr<Link>& link_){link = link_;}
	void setLink (const int& link_){/*TODO: imlement this setter*/;}
	const int& getDir () const {return dir;}
	void setDir (const int& dir_){dir = dir_;}
	const double& getOffset () const {return offset;}
	void setOffset (const double& offset_){offset = offset_;}
	const double& getSetback () const {return setback;}
	void setSetback (const double& setback_){setback = setback_;}
	const shared_ptr<Zone>& getZone () const {return zone;}
	void setZone (const shared_ptr<Zone>& zone_){zone = zone_;}
	void setZone (const int& zone_){/*TODO: imlement this setter*/;}

//Data Fields
private:
	friend class odb::access;
	Location () {}
	#pragma db id
	int location;
	shared_ptr<Link> link;
	int dir;
	double offset;
	double setback;
	shared_ptr<Zone> zone;

};

	
#pragma db object
class Access
{
public:
	//Contructor
	Access ( shared_ptr<Link> link_, int from_id_, int from_type_, int to_id_, int to_type_, int dir_, int cost_ )  
	: link (link_), from_id (from_id_), from_type (from_type_), to_id (to_id_), to_type (to_type_), dir (dir_), cost (cost_)
	{
	}
	//ConverterConstructor
	
	 Access( Access_File *file) 
	{
		setLink(file -> Link ()); 
		setFrom_Id(file -> From_ID ()); 
		setFrom_Type(file -> From_Type ()); 
		setTo_Id(file -> To_ID ()); 
		setTo_Type(file -> To_Type ()); 
		setDir(file -> Dir ()); 
		setCost(file -> Cost ());
	}
	//Accessors
	const shared_ptr<Link>& getLink () const {return link;}
	void setLink (const shared_ptr<Link>& link_){link = link_;}
	void setLink (const int& link_){/*TODO: imlement this setter*/;}
	const int& getFrom_Id () const {return from_id;}
	void setFrom_Id (const int& from_id_){from_id = from_id_;}
	const int& getFrom_Type () const {return from_type;}
	void setFrom_Type (const int& from_type_){from_type = from_type_;}
	const int& getTo_Id () const {return to_id;}
	void setTo_Id (const int& to_id_){to_id = to_id_;}
	const int& getTo_Type () const {return to_type;}
	void setTo_Type (const int& to_type_){to_type = to_type_;}
	const int& getDir () const {return dir;}
	void setDir (const int& dir_){dir = dir_;}
	const int& getCost () const {return cost;}
	void setCost (const int& cost_){cost = cost_;}

//Data Fields
private:
	friend class odb::access;
	Access () {}
	#pragma db id
	shared_ptr<Link> link;
	int from_id;
	int from_type;
	int to_id;
	int to_type;
	int dir;
	int cost;

};

	
#pragma db object
class Sign
{
public:
	//Contructor
	Sign ( shared_ptr<Link> link_, int dir_, int sign_ )  
	: link (link_), dir (dir_), sign (sign_)
	{
	}
	//ConverterConstructor
	
	 Sign( Sign_File *file) 
	{
		setLink(file -> Link ()); 
		setDir(file -> Dir ()); 
		setSign(file -> Sign ());
	}
	//Accessors
	const shared_ptr<Link>& getLink () const {return link;}
	void setLink (const shared_ptr<Link>& link_){link = link_;}
	void setLink (const int& link_){/*TODO: imlement this setter*/;}
	const int& getDir () const {return dir;}
	void setDir (const int& dir_){dir = dir_;}
	const int& getSign () const {return sign;}
	void setSign (const int& sign_){sign = sign_;}

//Data Fields
private:
	friend class odb::access;
	Sign () {}
	#pragma db id
	shared_ptr<Link> link;
	int dir;
	int sign;

};

	
#pragma db object
class Signal
{
public:
	//Contructor
	Signal ( int signal_, int group_, int times_, shared_ptr<Timing> timing_, shared_ptr<Phasing> phasing_, int type_, int offset_ )  
	: signal (signal_), group (group_), times (times_), timing (timing_), phasing (phasing_), type (type_), offset (offset_)
	{
	}
	//ConverterConstructor
	
	 Signal( Signal_File *file) 
	{
		setSignal(file -> Signal ()); 
		setGroup(file -> Group ()); 
		setTimes(file -> Times ()); 
		setTiming(file -> Timing ()); 
		setPhasing(file -> Phasing ()); 
		setType(file -> Type ()); 
		setOffset(file -> Offset ());
	}
	//Accessors
	const int& getSignal () const {return signal;}
	void setSignal (const int& signal_){signal = signal_;}
	const int& getGroup () const {return group;}
	void setGroup (const int& group_){group = group_;}
	const int& getTimes () const {return times;}
	void setTimes (const int& times_){times = times_;}
	const shared_ptr<Timing>& getTiming () const {return timing;}
	void setTiming (const shared_ptr<Timing>& timing_){timing = timing_;}
	void setTiming (const int& timing_){/*TODO: imlement this setter*/;}
	const shared_ptr<Phasing>& getPhasing () const {return phasing;}
	void setPhasing (const shared_ptr<Phasing>& phasing_){phasing = phasing_;}
	void setPhasing (const int& phasing_){/*TODO: imlement this setter*/;}
	const int& getType () const {return type;}
	void setType (const int& type_){type = type_;}
	const int& getOffset () const {return offset;}
	void setOffset (const int& offset_){offset = offset_;}

//Data Fields
private:
	friend class odb::access;
	Signal () {}
	#pragma db id
	int signal;
	int group;
	int times;
	shared_ptr<Timing> timing;
	shared_ptr<Phasing> phasing;
	int type;
	int offset;

};

	
#pragma db object
class Timing
{
public:
	//Contructor
	Timing ( shared_ptr<Signal> signal_, int timing_, int type_, int cycle_, int offset_, int phases_, int phase_, int barrier_, int ring_, int position_, int minimum_, int maximum_, int extend_, int yellow_, int red_ )  
	: signal (signal_), timing (timing_), type (type_), cycle (cycle_), offset (offset_), phases (phases_), phase (phase_), barrier (barrier_), ring (ring_), position (position_), minimum (minimum_), maximum (maximum_), extend (extend_), yellow (yellow_), red (red_)
	{
	}
	//ConverterConstructor
	
	 Timing( Timing_File *file) 
	{
		setSignal(file -> Signal ()); 
		setTiming(file -> Timing ()); 
		setType(file -> Type ()); 
		setCycle(file -> Cycle ()); 
		setOffset(file -> Offset ()); 
		setPhases(file -> Phases ()); 
		setPhase(file -> Phase ()); 
		setBarrier(file -> Barrier ()); 
		setRing(file -> Ring ()); 
		setPosition(file -> Position ()); 
		setMinimum(file -> Min_Green ()); 
		setMaximum(file -> Max_Green ()); 
		setExtend(file -> Extension ()); 
		setYellow(file -> Yellow ()); 
		setRed(file -> All_Red ());
	}
	//Accessors
	const shared_ptr<Signal>& getSignal () const {return signal;}
	void setSignal (const shared_ptr<Signal>& signal_){signal = signal_;}
	void setSignal (const int& signal_){/*TODO: imlement this setter*/;}
	const int& getTiming () const {return timing;}
	void setTiming (const int& timing_){timing = timing_;}
	const int& getType () const {return type;}
	void setType (const int& type_){type = type_;}
	const int& getCycle () const {return cycle;}
	void setCycle (const int& cycle_){cycle = cycle_;}
	const int& getOffset () const {return offset;}
	void setOffset (const int& offset_){offset = offset_;}
	const int& getPhases () const {return phases;}
	void setPhases (const int& phases_){phases = phases_;}
	const int& getPhase () const {return phase;}
	void setPhase (const int& phase_){phase = phase_;}
	const int& getBarrier () const {return barrier;}
	void setBarrier (const int& barrier_){barrier = barrier_;}
	const int& getRing () const {return ring;}
	void setRing (const int& ring_){ring = ring_;}
	const int& getPosition () const {return position;}
	void setPosition (const int& position_){position = position_;}
	const int& getMinimum () const {return minimum;}
	void setMinimum (const int& minimum_){minimum = minimum_;}
	const int& getMaximum () const {return maximum;}
	void setMaximum (const int& maximum_){maximum = maximum_;}
	const int& getExtend () const {return extend;}
	void setExtend (const int& extend_){extend = extend_;}
	const int& getYellow () const {return yellow;}
	void setYellow (const int& yellow_){yellow = yellow_;}
	const int& getRed () const {return red;}
	void setRed (const int& red_){red = red_;}

//Data Fields
private:
	friend class odb::access;
	Timing () {}
	#pragma db id
	shared_ptr<Signal> signal;
	int timing;
	int type;
	int cycle;
	int offset;
	int phases;
	int phase;
	int barrier;
	int ring;
	int position;
	int minimum;
	int maximum;
	int extend;
	int yellow;
	int red;

};

	
#pragma db object
class Phasing
{
public:
	//Contructor
	Phasing ( shared_ptr<Signal> signal_, int phasing_, int phase_, shared_ptr<Detector> detectors_, int movements_, int movement_, shared_ptr<Link> link_, int dir_, shared_ptr<Link> to_link_, int protect_ )  
	: signal (signal_), phasing (phasing_), phase (phase_), detectors (detectors_), movements (movements_), movement (movement_), link (link_), dir (dir_), to_link (to_link_), protect (protect_)
	{
	}
	//ConverterConstructor
	
	 Phasing( Phasing_File *file) 
	{
		setSignal(file -> Signal ()); 
		setPhasing(file -> Phasing ()); 
		setPhase(file -> Phase ()); 
		setDetectors(file -> Detectors ()); 
		setMovements(file -> Movements ()); 
		setMovement(file -> Movement ()); 
		setLink(file -> Link ()); 
		setDir(file -> Dir ()); 
		setTo_Link(file -> To_Link ()); 
		setProtect(file -> Protection ());
	}
	//Accessors
	const shared_ptr<Signal>& getSignal () const {return signal;}
	void setSignal (const shared_ptr<Signal>& signal_){signal = signal_;}
	void setSignal (const int& signal_){/*TODO: imlement this setter*/;}
	const int& getPhasing () const {return phasing;}
	void setPhasing (const int& phasing_){phasing = phasing_;}
	const int& getPhase () const {return phase;}
	void setPhase (const int& phase_){phase = phase_;}
	const shared_ptr<Detector>& getDetectors () const {return detectors;}
	void setDetectors (const shared_ptr<Detector>& detectors_){detectors = detectors_;}
	void setDetectors (const string& detectors_){/*TODO: imlement this setter*/;}
	const int& getMovements () const {return movements;}
	void setMovements (const int& movements_){movements = movements_;}
	const int& getMovement () const {return movement;}
	void setMovement (const int& movement_){movement = movement_;}
	const shared_ptr<Link>& getLink () const {return link;}
	void setLink (const shared_ptr<Link>& link_){link = link_;}
	void setLink (const int& link_){/*TODO: imlement this setter*/;}
	const int& getDir () const {return dir;}
	void setDir (const int& dir_){dir = dir_;}
	const shared_ptr<Link>& getTo_Link () const {return to_link;}
	void setTo_Link (const shared_ptr<Link>& to_link_){to_link = to_link_;}
	void setTo_Link (const int& to_link_){/*TODO: imlement this setter*/;}
	const int& getProtect () const {return protect;}
	void setProtect (const int& protect_){protect = protect_;}

//Data Fields
private:
	friend class odb::access;
	Phasing () {}
	#pragma db id
	shared_ptr<Signal> signal;
	int phasing;
	int phase;
	shared_ptr<Detector> detectors;
	int movements;
	int movement;
	shared_ptr<Link> link;
	int dir;
	shared_ptr<Link> to_link;
	int protect;

};

	
#pragma db object
class Detector
{
public:
	//Contructor
	Detector ( int detector_, shared_ptr<Link> link_, int dir_, double offset_, double length_, int lanes_, int type_, int use_, int low_, int high_ )  
	: detector (detector_), link (link_), dir (dir_), offset (offset_), length (length_), lanes (lanes_), type (type_), use (use_), low (low_), high (high_)
	{
	}
	//ConverterConstructor
	
	 Detector( Detector_File *file) 
	{
		setDetector(file -> Detector ()); 
		setLink(file -> Link ()); 
		setDir(file -> Dir ()); 
		setOffset(file -> Offset ()); 
		setLength(file -> Length ()); 
		setLanes(file -> Lanes ()); 
		setType(file -> Type ()); 
		setUse(file -> Use ()); 
		setLow(file -> Low_Lane ()); 
		setHigh(file -> High_Lane ());
	}
	//Accessors
	const int& getDetector () const {return detector;}
	void setDetector (const int& detector_){detector = detector_;}
	const shared_ptr<Link>& getLink () const {return link;}
	void setLink (const shared_ptr<Link>& link_){link = link_;}
	void setLink (const int& link_){/*TODO: imlement this setter*/;}
	const int& getDir () const {return dir;}
	void setDir (const int& dir_){dir = dir_;}
	const double& getOffset () const {return offset;}
	void setOffset (const double& offset_){offset = offset_;}
	const double& getLength () const {return length;}
	void setLength (const double& length_){length = length_;}
	const int& getLanes () const {return lanes;}
	void setLanes (const int& lanes_){lanes = lanes_;}
	const int& getType () const {return type;}
	void setType (const int& type_){type = type_;}
	const int& getUse () const {return use;}
	void setUse (const int& use_){use = use_;}
	const int& getLow () const {return low;}
	void setLow (const int& low_){low = low_;}
	const int& getHigh () const {return high;}
	void setHigh (const int& high_){high = high_;}

//Data Fields
private:
	friend class odb::access;
	Detector () {}
	#pragma db id
	int detector;
	shared_ptr<Link> link;
	int dir;
	double offset;
	double length;
	int lanes;
	int type;
	int use;
	int low;
	int high;

};

	
#pragma db object
class Stop
{
public:
	//Contructor
	Stop ( int stop_, std::string name_, shared_ptr<Link> link_, int dir_, double offset_, int use_, int type_, int space_ )  
	: stop (stop_), name (name_), link (link_), dir (dir_), offset (offset_), use (use_), type (type_), space (space_)
	{
	}
	//ConverterConstructor
	
	 Stop( Stop_File *file) 
	{
		setStop(file -> Stop ()); 
		setName(file -> Name ()); 
		setLink(file -> Link ()); 
		setDir(file -> Dir ()); 
		setOffset(file -> Offset ()); 
		setUse(file -> Use ()); 
		setType(file -> Type ()); 
		setSpace(file -> Space ());
	}
	//Accessors
	const int& getStop () const {return stop;}
	void setStop (const int& stop_){stop = stop_;}
	const std::string& getName () const {return name;}
	void setName (const std::string& name_){name = name_;}
	const shared_ptr<Link>& getLink () const {return link;}
	void setLink (const shared_ptr<Link>& link_){link = link_;}
	void setLink (const int& link_){/*TODO: imlement this setter*/;}
	const int& getDir () const {return dir;}
	void setDir (const int& dir_){dir = dir_;}
	const double& getOffset () const {return offset;}
	void setOffset (const double& offset_){offset = offset_;}
	const int& getUse () const {return use;}
	void setUse (const int& use_){use = use_;}
	const int& getType () const {return type;}
	void setType (const int& type_){type = type_;}
	const int& getSpace () const {return space;}
	void setSpace (const int& space_){space = space_;}

//Data Fields
private:
	friend class odb::access;
	Stop () {}
	#pragma db id
	int stop;
	std::string name;
	shared_ptr<Link> link;
	int dir;
	double offset;
	int use;
	int type;
	int space;

};

	
#pragma db object
class Fare
{
public:
	//Contructor
	Fare ( shared_ptr<Zone> from_zone_, shared_ptr<Zone> to_zone_, int from_mode_, int to_mode_, int period_, int type_, int fare_ )  
	: from_zone (from_zone_), to_zone (to_zone_), from_mode (from_mode_), to_mode (to_mode_), period (period_), type (type_), fare (fare_)
	{
	}
	//ConverterConstructor
	
	 Fare( Fare_File *file) 
	{
		setFrom_Zone(file -> iFrom_Zone ()); 
		setTo_Zone(file -> iTo_Zone ()); 
		setFrom_Mode(file -> iFrom_Mode ()); 
		setTo_Mode(file -> iTo_Mode ()); 
		setPeriod(file -> iPeriod ()); 
		setType(file -> iClass ()); 
		setFare(file -> Fare ());
	}
	//Accessors
	const shared_ptr<Zone>& getFrom_Zone () const {return from_zone;}
	void setFrom_Zone (const shared_ptr<Zone>& from_zone_){from_zone = from_zone_;}
	void setFrom_Zone (const int& from_zone_){/*TODO: imlement this setter*/;}
	const shared_ptr<Zone>& getTo_Zone () const {return to_zone;}
	void setTo_Zone (const shared_ptr<Zone>& to_zone_){to_zone = to_zone_;}
	void setTo_Zone (const int& to_zone_){/*TODO: imlement this setter*/;}
	const int& getFrom_Mode () const {return from_mode;}
	void setFrom_Mode (const int& from_mode_){from_mode = from_mode_;}
	const int& getTo_Mode () const {return to_mode;}
	void setTo_Mode (const int& to_mode_){to_mode = to_mode_;}
	const int& getPeriod () const {return period;}
	void setPeriod (const int& period_){period = period_;}
	const int& getType () const {return type;}
	void setType (const int& type_){type = type_;}
	const int& getFare () const {return fare;}
	void setFare (const int& fare_){fare = fare_;}

//Data Fields
private:
	friend class odb::access;
	Fare () {}
	#pragma db id
	shared_ptr<Zone> from_zone;
	shared_ptr<Zone> to_zone;
	int from_mode;
	int to_mode;
	int period;
	int type;
	int fare;

};

	
#pragma db object
class Line
{
public:
	//Contructor
	Line ( int route_, shared_ptr<Stop> stops_, int mode_, int type_, std::string name_, shared_ptr<Stop> stop_, shared_ptr<Zone> zone_, int flag_ )  
	: route (route_), stops (stops_), mode (mode_), type (type_), name (name_), stop (stop_), zone (zone_), flag (flag_)
	{
	}
	//ConverterConstructor
	
	 Line( Line_File *file) 
	{
		setRoute(file -> Route ()); 
		setStops(file -> Stops ()); 
		setMode(file -> Mode ()); 
		setType(file -> Type ()); 
		setName(file -> Name ()); 
		setStop(file -> Stop ()); 
		setZone(file -> Zone ()); 
		setFlag(file -> Time_Flag ());
	}
	//Accessors
	const int& getRoute () const {return route;}
	void setRoute (const int& route_){route = route_;}
	const shared_ptr<Stop>& getStops () const {return stops;}
	void setStops (const shared_ptr<Stop>& stops_){stops = stops_;}
	void setStops (const int& stops_){/*TODO: imlement this setter*/;}
	const int& getMode () const {return mode;}
	void setMode (const int& mode_){mode = mode_;}
	const int& getType () const {return type;}
	void setType (const int& type_){type = type_;}
	const std::string& getName () const {return name;}
	void setName (const std::string& name_){name = name_;}
	const shared_ptr<Stop>& getStop () const {return stop;}
	void setStop (const shared_ptr<Stop>& stop_){stop = stop_;}
	void setStop (const int& stop_){/*TODO: imlement this setter*/;}
	const shared_ptr<Zone>& getZone () const {return zone;}
	void setZone (const shared_ptr<Zone>& zone_){zone = zone_;}
	void setZone (const int& zone_){/*TODO: imlement this setter*/;}
	const int& getFlag () const {return flag;}
	void setFlag (const int& flag_){flag = flag_;}

//Data Fields
private:
	friend class odb::access;
	Line () {}
	#pragma db id
	int route;
	shared_ptr<Stop> stops;
	int mode;
	int type;
	std::string name;
	shared_ptr<Stop> stop;
	shared_ptr<Zone> zone;
	int flag;

};

	
#pragma db object
class Schedule
{
public:
	//Contructor
	Schedule ( int route_, shared_ptr<Stop> stops_, shared_ptr<Stop> stop_ )  
	: route (route_), stops (stops_), stop (stop_)
	{
	}
	//ConverterConstructor
	
	 Schedule( Schedule_File *file) 
	{
		setRoute(file -> Route ()); 
		setStops(file -> Stops ()); 
		setStop(file -> Stop ());
	}
	//Accessors
	const int& getRoute () const {return route;}
	void setRoute (const int& route_){route = route_;}
	const shared_ptr<Stop>& getStops () const {return stops;}
	void setStops (const shared_ptr<Stop>& stops_){stops = stops_;}
	void setStops (const int& stops_){/*TODO: imlement this setter*/;}
	const shared_ptr<Stop>& getStop () const {return stop;}
	void setStop (const shared_ptr<Stop>& stop_){stop = stop_;}
	void setStop (const int& stop_){/*TODO: imlement this setter*/;}

//Data Fields
private:
	friend class odb::access;
	Schedule () {}
	#pragma db id
	int route;
	shared_ptr<Stop> stops;
	shared_ptr<Stop> stop;

};

	
#pragma db object
class Driver
{
public:
	//Contructor
	Driver ( int route_, shared_ptr<Link> links_, int type_, int subtype_, shared_ptr<Link> link_, int dir_ )  
	: route (route_), links (links_), type (type_), subtype (subtype_), link (link_), dir (dir_)
	{
	}
	//ConverterConstructor
	
	 Driver( Driver_File *file) 
	{
		setRoute(file -> Route ()); 
		setLinks(file -> Links ()); 
		setType(file -> Type ()); 
		setSubtype(file -> SubType ()); 
		setLink(file -> Link ()); 
		setDir(file -> Dir ());
	}
	//Accessors
	const int& getRoute () const {return route;}
	void setRoute (const int& route_){route = route_;}
	const shared_ptr<Link>& getLinks () const {return links;}
	void setLinks (const shared_ptr<Link>& links_){links = links_;}
	void setLinks (const int& links_){/*TODO: imlement this setter*/;}
	const int& getType () const {return type;}
	void setType (const int& type_){type = type_;}
	const int& getSubtype () const {return subtype;}
	void setSubtype (const int& subtype_){subtype = subtype_;}
	const shared_ptr<Link>& getLink () const {return link;}
	void setLink (const shared_ptr<Link>& link_){link = link_;}
	void setLink (const int& link_){/*TODO: imlement this setter*/;}
	const int& getDir () const {return dir;}
	void setDir (const int& dir_){dir = dir_;}

//Data Fields
private:
	friend class odb::access;
	Driver () {}
	#pragma db id
	int route;
	shared_ptr<Link> links;
	int type;
	int subtype;
	shared_ptr<Link> link;
	int dir;

};

	
#pragma db object
class Route_Nodes
{
public:
	//Contructor
	Route_Nodes ( int route_, int mode_, shared_ptr<Veh_Type> veh_type_, shared_ptr<Node> nodes_, std::string name_, shared_ptr<Node> node_, int type_, double speed_ )  
	: route (route_), mode (mode_), veh_type (veh_type_), nodes (nodes_), name (name_), node (node_), type (type_), speed (speed_)
	{
	}
	//ConverterConstructor
	
	 Route_Nodes( Route_Nodes_File *file) 
	{
		setRoute(file -> Route ()); 
		setMode(file -> Mode ()); 
		setVeh_Type(file -> Veh_Type ()); 
		setNodes(file -> Nodes ()); 
		setName(file -> Name ()); 
		setNode(file -> Node ()); 
		setType(file -> Type ()); 
		setSpeed(file -> Speed ());
	}
	//Accessors
	const int& getRoute () const {return route;}
	void setRoute (const int& route_){route = route_;}
	const int& getMode () const {return mode;}
	void setMode (const int& mode_){mode = mode_;}
	const shared_ptr<Veh_Type>& getVeh_Type () const {return veh_type;}
	void setVeh_Type (const shared_ptr<Veh_Type>& veh_type_){veh_type = veh_type_;}
	void setVeh_Type (const int& veh_type_){/*TODO: imlement this setter*/;}
	const shared_ptr<Node>& getNodes () const {return nodes;}
	void setNodes (const shared_ptr<Node>& nodes_){nodes = nodes_;}
	void setNodes (const int& nodes_){/*TODO: imlement this setter*/;}
	const std::string& getName () const {return name;}
	void setName (const std::string& name_){name = name_;}
	const shared_ptr<Node>& getNode () const {return node;}
	void setNode (const shared_ptr<Node>& node_){node = node_;}
	void setNode (const int& node_){/*TODO: imlement this setter*/;}
	const int& getType () const {return type;}
	void setType (const int& type_){type = type_;}
	const double& getSpeed () const {return speed;}
	void setSpeed (const double& speed_){speed = speed_;}

//Data Fields
private:
	friend class odb::access;
	Route_Nodes () {}
	#pragma db id
	int route;
	int mode;
	shared_ptr<Veh_Type> veh_type;
	shared_ptr<Node> nodes;
	std::string name;
	shared_ptr<Node> node;
	int type;
	double speed;

};

	
#pragma db object
class Selection
{
public:
	//Contructor
	Selection ( int hhold_, int person_, int tour_, shared_ptr<Trip> trip_, int type_, int partition_ )  
	: hhold (hhold_), person (person_), tour (tour_), trip (trip_), type (type_), partition (partition_)
	{
	}
	//ConverterConstructor
	
	 Selection( Selection_File *file) 
	{
		setHhold(file -> Household ()); 
		setPerson(file -> Person ()); 
		setTour(file -> Tour ()); 
		setTrip(file -> Trip ()); 
		setType(file -> Type ()); 
		setPartition(file -> Partition ());
	}
	//Accessors
	const int& getHhold () const {return hhold;}
	void setHhold (const int& hhold_){hhold = hhold_;}
	const int& getPerson () const {return person;}
	void setPerson (const int& person_){person = person_;}
	const int& getTour () const {return tour;}
	void setTour (const int& tour_){tour = tour_;}
	const shared_ptr<Trip>& getTrip () const {return trip;}
	void setTrip (const shared_ptr<Trip>& trip_){trip = trip_;}
	void setTrip (const int& trip_){/*TODO: imlement this setter*/;}
	const int& getType () const {return type;}
	void setType (const int& type_){type = type_;}
	const int& getPartition () const {return partition;}
	void setPartition (const int& partition_){partition = partition_;}

//Data Fields
private:
	friend class odb::access;
	Selection () {}
	#pragma db id
	int hhold;
	int person;
	int tour;
	shared_ptr<Trip> trip;
	int type;
	int partition;

};

	
#pragma db object
class Household
{
public:
	//Contructor
	Household ( int hhold_, shared_ptr<Location> location_, int persons_, int workers_, shared_ptr<Vehicle> vehicles_, int type_, int partition_, int person_, int age_, int relate_, int gender_, int work_, int drive_ )  
	: hhold (hhold_), location (location_), persons (persons_), workers (workers_), vehicles (vehicles_), type (type_), partition (partition_), person (person_), age (age_), relate (relate_), gender (gender_), work (work_), drive (drive_)
	{
	}
	//ConverterConstructor
	
	 Household( Household_File *file) 
	{
		setHhold(file -> Household ()); 
		setLocation(file -> Location ()); 
		setPersons(file -> Persons ()); 
		setWorkers(file -> Workers ()); 
		setVehicles(file -> Vehicles ()); 
		setType(file -> Type ()); 
		setPartition(file -> Partition ()); 
		setPerson(file -> Person ()); 
		setAge(file -> Age ()); 
		setRelate(file -> Relate ()); 
		setGender(file -> Gender ()); 
		setWork(file -> Work ()); 
		setDrive(file -> Drive ());
	}
	//Accessors
	const int& getHhold () const {return hhold;}
	void setHhold (const int& hhold_){hhold = hhold_;}
	const shared_ptr<Location>& getLocation () const {return location;}
	void setLocation (const shared_ptr<Location>& location_){location = location_;}
	void setLocation (const int& location_){/*TODO: imlement this setter*/;}
	const int& getPersons () const {return persons;}
	void setPersons (const int& persons_){persons = persons_;}
	const int& getWorkers () const {return workers;}
	void setWorkers (const int& workers_){workers = workers_;}
	const shared_ptr<Vehicle>& getVehicles () const {return vehicles;}
	void setVehicles (const shared_ptr<Vehicle>& vehicles_){vehicles = vehicles_;}
	void setVehicles (const int& vehicles_){/*TODO: imlement this setter*/;}
	const int& getType () const {return type;}
	void setType (const int& type_){type = type_;}
	const int& getPartition () const {return partition;}
	void setPartition (const int& partition_){partition = partition_;}
	const int& getPerson () const {return person;}
	void setPerson (const int& person_){person = person_;}
	const int& getAge () const {return age;}
	void setAge (const int& age_){age = age_;}
	const int& getRelate () const {return relate;}
	void setRelate (const int& relate_){relate = relate_;}
	const int& getGender () const {return gender;}
	void setGender (const int& gender_){gender = gender_;}
	const int& getWork () const {return work;}
	void setWork (const int& work_){work = work_;}
	const int& getDrive () const {return drive;}
	void setDrive (const int& drive_){drive = drive_;}

//Data Fields
private:
	friend class odb::access;
	Household () {}
	#pragma db id
	int hhold;
	shared_ptr<Location> location;
	int persons;
	int workers;
	shared_ptr<Vehicle> vehicles;
	int type;
	int partition;
	int person;
	int age;
	int relate;
	int gender;
	int work;
	int drive;

};

	
#pragma db object
class Link_Delay
{
public:
	//Contructor
	Link_Delay ( shared_ptr<Link> link_, int dir_, int type_, double flow_, shared_ptr<Link> out_link_, double out_flow_ )  
	: link (link_), dir (dir_), type (type_), flow (flow_), out_link (out_link_), out_flow (out_flow_)
	{
	}
	//ConverterConstructor
	
	 Link_Delay( Link_Delay_File *file) 
	{
		setLink(file -> Link ()); 
		setDir(file -> Dir ()); 
		setType(file -> Type ()); 
		setFlow(file -> Flow ()); 
		setOut_Link(file -> Out_Link ()); 
		setOut_Flow(file -> Out_Flow ());
	}
	//Accessors
	const shared_ptr<Link>& getLink () const {return link;}
	void setLink (const shared_ptr<Link>& link_){link = link_;}
	void setLink (const int& link_){/*TODO: imlement this setter*/;}
	const int& getDir () const {return dir;}
	void setDir (const int& dir_){dir = dir_;}
	const int& getType () const {return type;}
	void setType (const int& type_){type = type_;}
	const double& getFlow () const {return flow;}
	void setFlow (const double& flow_){flow = flow_;}
	const shared_ptr<Link>& getOut_Link () const {return out_link;}
	void setOut_Link (const shared_ptr<Link>& out_link_){out_link = out_link_;}
	void setOut_Link (const int& out_link_){/*TODO: imlement this setter*/;}
	const double& getOut_Flow () const {return out_flow;}
	void setOut_Flow (const double& out_flow_){out_flow = out_flow_;}

//Data Fields
private:
	friend class odb::access;
	Link_Delay () {}
	#pragma db id
	shared_ptr<Link> link;
	int dir;
	int type;
	double flow;
	shared_ptr<Link> out_link;
	double out_flow;

};

	
#pragma db object
class Performance
{
public:
	//Contructor
	Performance ( double speed_, double density_, double max_den_, double ratio_, double queue_, int max_que_, int fail_ )  
	: speed (speed_), density (density_), max_den (max_den_), ratio (ratio_), queue (queue_), max_que (max_que_), fail (fail_)
	{
	}
	//ConverterConstructor
	
	 Performance( Performance_File *file) 
	{
		setSpeed(file -> Speed ()); 
		setDensity(file -> Density ()); 
		setMax_Den(file -> Max_Density ()); 
		setRatio(file -> Time_Ratio ()); 
		setQueue(file -> Queue ()); 
		setMax_Que(file -> Max_Queue ()); 
		setFail(file -> Cycle_Failure ());
	}
	//Accessors
	const double& getSpeed () const {return speed;}
	void setSpeed (const double& speed_){speed = speed_;}
	const double& getDensity () const {return density;}
	void setDensity (const double& density_){density = density_;}
	const double& getMax_Den () const {return max_den;}
	void setMax_Den (const double& max_den_){max_den = max_den_;}
	const double& getRatio () const {return ratio;}
	void setRatio (const double& ratio_){ratio = ratio_;}
	const double& getQueue () const {return queue;}
	void setQueue (const double& queue_){queue = queue_;}
	const int& getMax_Que () const {return max_que;}
	void setMax_Que (const int& max_que_){max_que = max_que_;}
	const int& getFail () const {return fail;}
	void setFail (const int& fail_){fail = fail_;}

//Data Fields
private:
	friend class odb::access;
	Performance () {}
	#pragma db id
	double speed;
	double density;
	double max_den;
	double ratio;
	double queue;
	int max_que;
	int fail;

};

	
#pragma db object
class Ridership
{
public:
	//Contructor
	Ridership ( int mode_, int route_, int run_, shared_ptr<Stop> stop_, int board_, int alight_, int load_, double factor_ )  
	: mode (mode_), route (route_), run (run_), stop (stop_), board (board_), alight (alight_), load (load_), factor (factor_)
	{
	}
	//ConverterConstructor
	
	 Ridership( Ridership_File *file) 
	{
		setMode(file -> Mode ()); 
		setRoute(file -> Route ()); 
		setRun(file -> Run ()); 
		setStop(file -> Stop ()); 
		setBoard(file -> Board ()); 
		setAlight(file -> Alight ()); 
		setLoad(file -> Load ()); 
		setFactor(file -> Factor ());
	}
	//Accessors
	const int& getMode () const {return mode;}
	void setMode (const int& mode_){mode = mode_;}
	const int& getRoute () const {return route;}
	void setRoute (const int& route_){route = route_;}
	const int& getRun () const {return run;}
	void setRun (const int& run_){run = run_;}
	const shared_ptr<Stop>& getStop () const {return stop;}
	void setStop (const shared_ptr<Stop>& stop_){stop = stop_;}
	void setStop (const int& stop_){/*TODO: imlement this setter*/;}
	const int& getBoard () const {return board;}
	void setBoard (const int& board_){board = board_;}
	const int& getAlight () const {return alight;}
	void setAlight (const int& alight_){alight = alight_;}
	const int& getLoad () const {return load;}
	void setLoad (const int& load_){load = load_;}
	const double& getFactor () const {return factor;}
	void setFactor (const double& factor_){factor = factor_;}

//Data Fields
private:
	friend class odb::access;
	Ridership () {}
	#pragma db id
	int mode;
	int route;
	int run;
	shared_ptr<Stop> stop;
	int board;
	int alight;
	int load;
	double factor;

};

	
#pragma db object
class Veh_Type
{
public:
	//Contructor
	Veh_Type ( int type_, double length_, double max_speed_, double max_accel_, double max_decel_, double op_cost_, int use_, int capacity_, double load_, double unload_, int method_, int subtype_ )  
	: type (type_), length (length_), max_speed (max_speed_), max_accel (max_accel_), max_decel (max_decel_), op_cost (op_cost_), use (use_), capacity (capacity_), load (load_), unload (unload_), method (method_), subtype (subtype_)
	{
	}
	//ConverterConstructor
	
	 Veh_Type( Veh_Type_File *file) 
	{
		setType(file -> Type ()); 
		setLength(file -> Length ()); 
		setMax_Speed(file -> Max_Speed ()); 
		setMax_Accel(file -> Max_Accel ()); 
		setMax_Decel(file -> Max_Decel ()); 
		setOp_Cost(file -> Op_Cost ()); 
		setUse(file -> Use ()); 
		setCapacity(file -> Capacity ()); 
		setLoad(file -> Loading ()); 
		setUnload(file -> Unloading ()); 
		setMethod(file -> Method ()); 
		setSubtype(file -> SubType ());
	}
	//Accessors
	const int& getType () const {return type;}
	void setType (const int& type_){type = type_;}
	const double& getLength () const {return length;}
	void setLength (const double& length_){length = length_;}
	const double& getMax_Speed () const {return max_speed;}
	void setMax_Speed (const double& max_speed_){max_speed = max_speed_;}
	const double& getMax_Accel () const {return max_accel;}
	void setMax_Accel (const double& max_accel_){max_accel = max_accel_;}
	const double& getMax_Decel () const {return max_decel;}
	void setMax_Decel (const double& max_decel_){max_decel = max_decel_;}
	const double& getOp_Cost () const {return op_cost;}
	void setOp_Cost (const double& op_cost_){op_cost = op_cost_;}
	const int& getUse () const {return use;}
	void setUse (const int& use_){use = use_;}
	const int& getCapacity () const {return capacity;}
	void setCapacity (const int& capacity_){capacity = capacity_;}
	const double& getLoad () const {return load;}
	void setLoad (const double& load_){load = load_;}
	const double& getUnload () const {return unload;}
	void setUnload (const double& unload_){unload = unload_;}
	const int& getMethod () const {return method;}
	void setMethod (const int& method_){method = method_;}
	const int& getSubtype () const {return subtype;}
	void setSubtype (const int& subtype_){subtype = subtype_;}

//Data Fields
private:
	friend class odb::access;
	Veh_Type () {}
	#pragma db id
	int type;
	double length;
	double max_speed;
	double max_accel;
	double max_decel;
	double op_cost;
	int use;
	int capacity;
	double load;
	double unload;
	int method;
	int subtype;

};

	
#pragma db object
class Vehicle
{
public:
	//Contructor
	Vehicle ( int hhold_, int vehicle_, shared_ptr<Parking> parking_, int type_, int subtype_, int partition_ )  
	: hhold (hhold_), vehicle (vehicle_), parking (parking_), type (type_), subtype (subtype_), partition (partition_)
	{
	}
	//ConverterConstructor
	
	 Vehicle( Vehicle_File *file) 
	{
		setHhold(file -> Household ()); 
		setVehicle(file -> Vehicle ()); 
		setParking(file -> Parking ()); 
		setType(file -> Type ()); 
		setSubtype(file -> SubType ()); 
		setPartition(file -> Partition ());
	}
	//Accessors
	const int& getHhold () const {return hhold;}
	void setHhold (const int& hhold_){hhold = hhold_;}
	const int& getVehicle () const {return vehicle;}
	void setVehicle (const int& vehicle_){vehicle = vehicle_;}
	const shared_ptr<Parking>& getParking () const {return parking;}
	void setParking (const shared_ptr<Parking>& parking_){parking = parking_;}
	void setParking (const int& parking_){/*TODO: imlement this setter*/;}
	const int& getType () const {return type;}
	void setType (const int& type_){type = type_;}
	const int& getSubtype () const {return subtype;}
	void setSubtype (const int& subtype_){subtype = subtype_;}
	const int& getPartition () const {return partition;}
	void setPartition (const int& partition_){partition = partition_;}

//Data Fields
private:
	friend class odb::access;
	Vehicle () {}
	#pragma db id
	int hhold;
	int vehicle;
	shared_ptr<Parking> parking;
	int type;
	int subtype;
	int partition;

};

	
#pragma db object
class Trip
{
public:
	//Contructor
	Trip ( int hhold_, int person_, int tour_, int trip_, int origin_, int destination_, int purpose_, int mode_, int constraint_, int priority_, shared_ptr<Vehicle> vehicle_, int passengers_, int type_, int partition_ )  
	: hhold (hhold_), person (person_), tour (tour_), trip (trip_), origin (origin_), destination (destination_), purpose (purpose_), mode (mode_), constraint (constraint_), priority (priority_), vehicle (vehicle_), passengers (passengers_), type (type_), partition (partition_)
	{
	}
	//ConverterConstructor
	
	 Trip( Trip_File *file) 
	{
		setHhold(file -> Household ()); 
		setPerson(file -> Person ()); 
		setTour(file -> Tour ()); 
		setTrip(file -> Trip ()); 
		setOrigin(file -> Origin ()); 
		setDestination(file -> Destination ()); 
		setPurpose(file -> Purpose ()); 
		setMode(file -> Mode ()); 
		setConstraint(file -> Constraint ()); 
		setPriority(file -> Priority ()); 
		setVehicle(file -> Vehicle ()); 
		setPassengers(file -> Passengers ()); 
		setType(file -> Type ()); 
		setPartition(file -> Partition ());
	}
	//Accessors
	const int& getHhold () const {return hhold;}
	void setHhold (const int& hhold_){hhold = hhold_;}
	const int& getPerson () const {return person;}
	void setPerson (const int& person_){person = person_;}
	const int& getTour () const {return tour;}
	void setTour (const int& tour_){tour = tour_;}
	const int& getTrip () const {return trip;}
	void setTrip (const int& trip_){trip = trip_;}
	const int& getOrigin () const {return origin;}
	void setOrigin (const int& origin_){origin = origin_;}
	const int& getDestination () const {return destination;}
	void setDestination (const int& destination_){destination = destination_;}
	const int& getPurpose () const {return purpose;}
	void setPurpose (const int& purpose_){purpose = purpose_;}
	const int& getMode () const {return mode;}
	void setMode (const int& mode_){mode = mode_;}
	const int& getConstraint () const {return constraint;}
	void setConstraint (const int& constraint_){constraint = constraint_;}
	const int& getPriority () const {return priority;}
	void setPriority (const int& priority_){priority = priority_;}
	const shared_ptr<Vehicle>& getVehicle () const {return vehicle;}
	void setVehicle (const shared_ptr<Vehicle>& vehicle_){vehicle = vehicle_;}
	void setVehicle (const int& vehicle_){/*TODO: imlement this setter*/;}
	const int& getPassengers () const {return passengers;}
	void setPassengers (const int& passengers_){passengers = passengers_;}
	const int& getType () const {return type;}
	void setType (const int& type_){type = type_;}
	const int& getPartition () const {return partition;}
	void setPartition (const int& partition_){partition = partition_;}

//Data Fields
private:
	friend class odb::access;
	Trip () {}
	#pragma db id
	int hhold;
	int person;
	int tour;
	int trip;
	int origin;
	int destination;
	int purpose;
	int mode;
	int constraint;
	int priority;
	shared_ptr<Vehicle> vehicle;
	int passengers;
	int type;
	int partition;

};

	
#pragma db object
class Problem
{
public:
	//Contructor
	Problem ( int problem_, shared_ptr<Link> link_, int dir_, int lane_, double offset_, int route_, int survey_ )  
	: problem (problem_), link (link_), dir (dir_), lane (lane_), offset (offset_), route (route_), survey (survey_)
	{
	}
	//ConverterConstructor
	
	 Problem( Problem_File *file) 
	{
		setProblem(file -> Problem ()); 
		setLink(file -> Link ()); 
		setDir(file -> Dir ()); 
		setLane(file -> Lane ()); 
		setOffset(file -> Offset ()); 
		setRoute(file -> Route ()); 
		setSurvey(file -> Survey ());
	}
	//Accessors
	const int& getProblem () const {return problem;}
	void setProblem (const int& problem_){problem = problem_;}
	const shared_ptr<Link>& getLink () const {return link;}
	void setLink (const shared_ptr<Link>& link_){link = link_;}
	void setLink (const int& link_){/*TODO: imlement this setter*/;}
	const int& getDir () const {return dir;}
	void setDir (const int& dir_){dir = dir_;}
	const int& getLane () const {return lane;}
	void setLane (const int& lane_){lane = lane_;}
	const double& getOffset () const {return offset;}
	void setOffset (const double& offset_){offset = offset_;}
	const int& getRoute () const {return route;}
	void setRoute (const int& route_){route = route_;}
	const int& getSurvey () const {return survey;}
	void setSurvey (const int& survey_){survey = survey_;}

//Data Fields
private:
	friend class odb::access;
	Problem () {}
	#pragma db id
	int problem;
	shared_ptr<Link> link;
	int dir;
	int lane;
	double offset;
	int route;
	int survey;

};

	
#pragma db object
class Plan
{
public:
	//Contructor
	Plan ( double length_, double cost_, int impedance_, int leg_mode_, int leg_type_, int leg_id_, double leg_length_, double leg_cost_, int leg_imp_ )  
	: length (length_), cost (cost_), impedance (impedance_), leg_mode (leg_mode_), leg_type (leg_type_), leg_id (leg_id_), leg_length (leg_length_), leg_cost (leg_cost_), leg_imp (leg_imp_)
	{
	}
	//ConverterConstructor
	
	 Plan( Plan_File *file) 
	{
		setLength(file -> Length ()); 
		setCost(file -> Cost ()); 
		setImpedance(file -> Impedance ()); 
		setLeg_Mode(file -> Leg_Mode ()); 
		setLeg_Type(file -> Leg_Type ()); 
		setLeg_Id(file -> Leg_ID ()); 
		setLeg_Length(file -> Leg_Length ()); 
		setLeg_Cost(file -> Leg_Cost ()); 
		setLeg_Imp(file -> Leg_Impedance ());
	}
	//Accessors
	const double& getLength () const {return length;}
	void setLength (const double& length_){length = length_;}
	const double& getCost () const {return cost;}
	void setCost (const double& cost_){cost = cost_;}
	const int& getImpedance () const {return impedance;}
	void setImpedance (const int& impedance_){impedance = impedance_;}
	const int& getLeg_Mode () const {return leg_mode;}
	void setLeg_Mode (const int& leg_mode_){leg_mode = leg_mode_;}
	const int& getLeg_Type () const {return leg_type;}
	void setLeg_Type (const int& leg_type_){leg_type = leg_type_;}
	const int& getLeg_Id () const {return leg_id;}
	void setLeg_Id (const int& leg_id_){leg_id = leg_id_;}
	const double& getLeg_Length () const {return leg_length;}
	void setLeg_Length (const double& leg_length_){leg_length = leg_length_;}
	const double& getLeg_Cost () const {return leg_cost;}
	void setLeg_Cost (const double& leg_cost_){leg_cost = leg_cost_;}
	const int& getLeg_Imp () const {return leg_imp;}
	void setLeg_Imp (const int& leg_imp_){leg_imp = leg_imp_;}

//Data Fields
private:
	friend class odb::access;
	Plan () {}
	#pragma db id
	double length;
	double cost;
	int impedance;
	int leg_mode;
	int leg_type;
	int leg_id;
	double leg_length;
	double leg_cost;
	int leg_imp;

};

	
#pragma db object
class Skim
{
public:
	//Contructor
	Skim ( double length_, double cost_, int impedance_ )  
	: length (length_), cost (cost_), impedance (impedance_)
	{
	}
	//ConverterConstructor
	
	 Skim( Skim_File *file) 
	{
		setLength(file -> Length ()); 
		setCost(file -> Cost ()); 
		setImpedance(file -> Impedance ());
	}
	//Accessors
	const double& getLength () const {return length;}
	void setLength (const double& length_){length = length_;}
	const double& getCost () const {return cost;}
	void setCost (const double& cost_){cost = cost_;}
	const int& getImpedance () const {return impedance;}
	void setImpedance (const int& impedance_){impedance = impedance_;}

//Data Fields
private:
	friend class odb::access;
	Skim () {}
	#pragma db id
	double length;
	double cost;
	int impedance;

};

	
#pragma db object
class Event
{
public:
	//Contructor
	Event ( int hhold_, int person_, int tour_, shared_ptr<Trip> trip_, int mode_, int type_, shared_ptr<Link> link_, int dir_, int lane_, double offset_, int route_ )  
	: hhold (hhold_), person (person_), tour (tour_), trip (trip_), mode (mode_), type (type_), link (link_), dir (dir_), lane (lane_), offset (offset_), route (route_)
	{
	}
	//ConverterConstructor
	
	 Event( Event_File *file) 
	{
		setHhold(file -> Household ()); 
		setPerson(file -> Person ()); 
		setTour(file -> Tour ()); 
		setTrip(file -> Trip ()); 
		setMode(file -> Mode ()); 
		setType(file -> Event ()); 
		setLink(file -> Link ()); 
		setDir(file -> Dir ()); 
		setLane(file -> Lane ()); 
		setOffset(file -> Offset ()); 
		setRoute(file -> Route ());
	}
	//Accessors
	const int& getHhold () const {return hhold;}
	void setHhold (const int& hhold_){hhold = hhold_;}
	const int& getPerson () const {return person;}
	void setPerson (const int& person_){person = person_;}
	const int& getTour () const {return tour;}
	void setTour (const int& tour_){tour = tour_;}
	const shared_ptr<Trip>& getTrip () const {return trip;}
	void setTrip (const shared_ptr<Trip>& trip_){trip = trip_;}
	void setTrip (const int& trip_){/*TODO: imlement this setter*/;}
	const int& getMode () const {return mode;}
	void setMode (const int& mode_){mode = mode_;}
	const int& getType () const {return type;}
	void setType (const int& type_){type = type_;}
	const shared_ptr<Link>& getLink () const {return link;}
	void setLink (const shared_ptr<Link>& link_){link = link_;}
	void setLink (const int& link_){/*TODO: imlement this setter*/;}
	const int& getDir () const {return dir;}
	void setDir (const int& dir_){dir = dir_;}
	const int& getLane () const {return lane;}
	void setLane (const int& lane_){lane = lane_;}
	const double& getOffset () const {return offset;}
	void setOffset (const double& offset_){offset = offset_;}
	const int& getRoute () const {return route;}
	void setRoute (const int& route_){route = route_;}

//Data Fields
private:
	friend class odb::access;
	Event () {}
	#pragma db id
	int hhold;
	int person;
	int tour;
	shared_ptr<Trip> trip;
	int mode;
	int type;
	shared_ptr<Link> link;
	int dir;
	int lane;
	double offset;
	int route;

};

	
#pragma db object
class Traveler
{
public:
	//Contructor
	Traveler ( int hhold_, int person_, int tour_, shared_ptr<Trip> trip_, int mode_, double distance_, double speed_, shared_ptr<Link> link_, int dir_, int lane_, double offset_, int route_ )  
	: hhold (hhold_), person (person_), tour (tour_), trip (trip_), mode (mode_), distance (distance_), speed (speed_), link (link_), dir (dir_), lane (lane_), offset (offset_), route (route_)
	{
	}
	//ConverterConstructor
	
	 Traveler( Traveler_File *file) 
	{
		setHhold(file -> Household ()); 
		setPerson(file -> Person ()); 
		setTour(file -> Tour ()); 
		setTrip(file -> Trip ()); 
		setMode(file -> Mode ()); 
		setDistance(file -> Distance ()); 
		setSpeed(file -> Speed ()); 
		setLink(file -> Link ()); 
		setDir(file -> Dir ()); 
		setLane(file -> Lane ()); 
		setOffset(file -> Offset ()); 
		setRoute(file -> Route ());
	}
	//Accessors
	const int& getHhold () const {return hhold;}
	void setHhold (const int& hhold_){hhold = hhold_;}
	const int& getPerson () const {return person;}
	void setPerson (const int& person_){person = person_;}
	const int& getTour () const {return tour;}
	void setTour (const int& tour_){tour = tour_;}
	const shared_ptr<Trip>& getTrip () const {return trip;}
	void setTrip (const shared_ptr<Trip>& trip_){trip = trip_;}
	void setTrip (const int& trip_){/*TODO: imlement this setter*/;}
	const int& getMode () const {return mode;}
	void setMode (const int& mode_){mode = mode_;}
	const double& getDistance () const {return distance;}
	void setDistance (const double& distance_){distance = distance_;}
	const double& getSpeed () const {return speed;}
	void setSpeed (const double& speed_){speed = speed_;}
	const shared_ptr<Link>& getLink () const {return link;}
	void setLink (const shared_ptr<Link>& link_){link = link_;}
	void setLink (const int& link_){/*TODO: imlement this setter*/;}
	const int& getDir () const {return dir;}
	void setDir (const int& dir_){dir = dir_;}
	const int& getLane () const {return lane;}
	void setLane (const int& lane_){lane = lane_;}
	const double& getOffset () const {return offset;}
	void setOffset (const double& offset_){offset = offset_;}
	const int& getRoute () const {return route;}
	void setRoute (const int& route_){route = route_;}

//Data Fields
private:
	friend class odb::access;
	Traveler () {}
	#pragma db id
	int hhold;
	int person;
	int tour;
	shared_ptr<Trip> trip;
	int mode;
	double distance;
	double speed;
	shared_ptr<Link> link;
	int dir;
	int lane;
	double offset;
	int route;

};

	
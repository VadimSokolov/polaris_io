// file      : relationship/employee.hxx
// copyright : not copyrighted - public domain

#ifndef OutNetwork
#define OutNetwork

//#include "Data_Service.hpp"

#include <vector>
#include <string>

#include <odb/core.hxx>

// Include TR1 <memory> header in a compiler-specific fashion. Fall back
// on the Boost implementation if the compiler does not support TR1.
//
#include <odb/tr1/memory.hxx>

using std::tr1::shared_ptr;

// The "pointer architecture" in this object model is as follows: All
// object pointers are eager. The Link class holds shared pointers
// to anode and bnode.
//
// The following unidirectional relationships are used:
//
// to-one  : Link -> Node (anode)
// to-one  : Link -> Node (bnode)
//

// Forward declarations.
//
class Node;
class Link;

typedef std::vector<shared_ptr<Node> > nodes;

#pragma db object
class Node
{
public:
	Node ( int node_, double x_, double y_, double z_, int subarea_, int part_ )
	: node (node_), x (x_), y (y_), z (z_), subarea (subarea_), part (part_)
	{
	}
private:
	friend class odb::access;
	Node () {}
	#pragma db id
	int node;
	double x;
	double y;
	double z;
	int subarea;
	int part;
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
	
	// Link( Link_File *file) 
	//{
	//	setLink(file -> Link ()); 
	//	setName(file -> Name ()); 
	//	setNode_A(file -> Node_A ()); 
	//	setNode_B(file -> Node_B ()); 
	//	setLength(file -> Length ()); 
	//	setSetback_A(file -> Setback_A ()); 
	//	setSetback_B(file -> Setback_B ()); 
	//	setBearing_A(file -> Bearing_A ()); 
	//	setBearing_B(file -> Bearing_B ()); 
	//	setType(file -> Type ()); 
	//	setDivided(file -> Divided ()); 
	//	setArea_Type(file -> Area_Type ()); 
	//	setUse(file -> Use ()); 
	//	setGrade(file -> Grade ()); 
	//	setLanes_Ab(file -> Lanes_AB ()); 
	//	setSpeed_Ab(file -> Speed_AB ()); 
	//	setFspd_Ab(file -> Fspd_AB ()); 
	//	setCap_Ab(file -> Cap_AB ()); 
	//	setLanes_Ba(file -> Lanes_BA ()); 
	//	setSpeed_Ba(file -> Speed_BA ()); 
	//	setFspd_Ba(file -> Fspd_BA ()); 
	//	setCap_Ba(file -> Cap_BA ()); 
	//	setLeft_Ab(file -> Left_AB ()); 
	//	setRight_Ab(file -> Right_AB ()); 
	//	setLeft_Ba(file -> Left_BA ()); 
	//	setRight_Ba(file -> Right_BA ());
	//}
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

#endif // OutNetwork

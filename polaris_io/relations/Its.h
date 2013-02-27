#ifndef Its
#define Its
#pragma warning(disable:4068)    
#include <vector>
#include <string>
#include <odb/core.hxx>
// Include TR1 <memory> header in a compiler-specific fashion. Fall back
// on the Boost implementation if the compiler does not support TR1.
//
#include <odb/tr1/memory.hxx>
using std::tr1::shared_ptr;

namespace polaris {
//Forward declarations.
//
class Component;
class Component_Property_Keys;
class Instance;
class Instance_Property_Values;
class Action;
class Action_Keys;
class Action_Log;


#pragma db object
class Component
{
public:
    // Default Constructor
    Component () {}        
	Component (int id_, std::string name_, string icon_)
	: id (id_), name (name_), icon (icon_)
	{
	}
	//Accessors
	const int& getId () const {return id;}
	void setId (const int& id_) {id = id_;}
	const std::string& getName () const {return name;}
	void setName (const std::string& name_) {name = name_;}
	const string& getIcon () const {return icon;}
	void setIcon (const string& icon_) {icon = icon_;}
//Data Fields
private:
	friend class odb::access;
	#pragma db id
	int id;
	std::string name;
	string icon;
};

#pragma db object
class Component_Property_Keys
{
public:
    // Default Constructor
    Component_Property_Keys () {}        
	Component_Property_Keys (int id_, shared_ptr<Component> component_id_, std::string key_, std::string value_, std::string value_type_, std::string value_constraint_, bool is_state_, bool required_)
	: id (id_), component_id (component_id_), key (key_), value (value_), value_type (value_type_), value_constraint (value_constraint_), is_state (is_state_), required (required_)
	{
	}
	//Accessors
	const int& getId () const {return id;}
	void setId (const int& id_) {id = id_;}
	const shared_ptr<Component>& getComponent_Id () const {return component_id;}
	void setComponent_Id (const shared_ptr<Component>& component_id_) {component_id = component_id_;}
	const std::string& getKey () const {return key;}
	void setKey (const std::string& key_) {key = key_;}
	const std::string& getValue () const {return value;}
	void setValue (const std::string& value_) {value = value_;}
	const std::string& getValue_Type () const {return value_type;}
	void setValue_Type (const std::string& value_type_) {value_type = value_type_;}
	const std::string& getValue_Constraint () const {return value_constraint;}
	void setValue_Constraint (const std::string& value_constraint_) {value_constraint = value_constraint_;}
	const bool& getIs_State () const {return is_state;}
	void setIs_State (const bool& is_state_) {is_state = is_state_;}
	const bool& getRequired () const {return required;}
	void setRequired (const bool& required_) {required = required_;}
//Data Fields
private:
	friend class odb::access;
	#pragma db id
	int id;
	shared_ptr<Component> component_id;
	std::string key;
	std::string value;
	std::string value_type;
	std::string value_constraint;
	bool is_state;
	bool required;
};

#pragma db object
class Instance
{
public:
    // Default Constructor
    Instance () {}        
	Instance (int id_, shared_ptr<Component> component_id_, int location_link_, float location_offset_, float location_x_, float location_y_, std::string owner_, int operational_status_, std::string schedule_)
	: id (id_), component_id (component_id_), location_link (location_link_), location_offset (location_offset_), location_x (location_x_), location_y (location_y_), owner (owner_), operational_status (operational_status_), schedule (schedule_)
	{
	}
	//Accessors
	const int& getId () const {return id;}
	void setId (const int& id_) {id = id_;}
	const shared_ptr<Component>& getComponent_Id () const {return component_id;}
	void setComponent_Id (const shared_ptr<Component>& component_id_) {component_id = component_id_;}
	const int& getLocation_Link () const {return location_link;}
	void setLocation_Link (const int& location_link_) {location_link = location_link_;}
	const float& getLocation_Offset () const {return location_offset;}
	void setLocation_Offset (const float& location_offset_) {location_offset = location_offset_;}
	const float& getLocation_X () const {return location_x;}
	void setLocation_X (const float& location_x_) {location_x = location_x_;}
	const float& getLocation_Y () const {return location_y;}
	void setLocation_Y (const float& location_y_) {location_y = location_y_;}
	const std::string& getOwner () const {return owner;}
	void setOwner (const std::string& owner_) {owner = owner_;}
	const int& getOperational_Status () const {return operational_status;}
	void setOperational_Status (const int& operational_status_) {operational_status = operational_status_;}
	const std::string& getSchedule () const {return schedule;}
	void setSchedule (const std::string& schedule_) {schedule = schedule_;}
//Data Fields
private:
	friend class odb::access;
	#pragma db id
	int id;
	shared_ptr<Component> component_id;
	int location_link;
	float location_offset;
	float location_x;
	float location_y;
	std::string owner;
	int operational_status;
	std::string schedule;
};

#pragma db object
class Instance_Property_Values
{
public:
    // Default Constructor
    Instance_Property_Values () {}        
	Instance_Property_Values (int id_, shared_ptr<ITS_Instance> instatce_id_, int key_, std::string value_)
	: id (id_), instatce_id (instatce_id_), key (key_), value (value_)
	{
	}
	//Accessors
	const int& getId () const {return id;}
	void setId (const int& id_) {id = id_;}
	const shared_ptr<ITS_Instance>& getInstatce_Id () const {return instatce_id;}
	void setInstatce_Id (const shared_ptr<ITS_Instance>& instatce_id_) {instatce_id = instatce_id_;}
	const int& getKey () const {return key;}
	void setKey (const int& key_) {key = key_;}
	const std::string& getValue () const {return value;}
	void setValue (const std::string& value_) {value = value_;}
//Data Fields
private:
	friend class odb::access;
	#pragma db id
	int id;
	shared_ptr<ITS_Instance> instatce_id;
	int key;
	std::string value;
};

#pragma db object
class Action
{
public:
    // Default Constructor
    Action () {}        
	Action (int id_, shared_ptr<Component> component_id_, std::string name_, std::string Note_)
	: id (id_), component_id (component_id_), name (name_), Note (Note_)
	{
	}
	//Accessors
	const int& getId () const {return id;}
	void setId (const int& id_) {id = id_;}
	const shared_ptr<Component>& getComponent_Id () const {return component_id;}
	void setComponent_Id (const shared_ptr<Component>& component_id_) {component_id = component_id_;}
	const std::string& getName () const {return name;}
	void setName (const std::string& name_) {name = name_;}
	const std::string& getNote () const {return Note;}
	void setNote (const std::string& Note_) {Note = Note_;}
//Data Fields
private:
	friend class odb::access;
	#pragma db id
	int id;
	shared_ptr<Component> component_id;
	std::string name;
	std::string Note;
};

#pragma db object
class Action_Keys
{
public:
    // Default Constructor
    Action_Keys () {}        
	Action_Keys (int id_, shared_ptr<Action> action_id_, std::string key_, std::string Note_)
	: id (id_), action_id (action_id_), key (key_), Note (Note_)
	{
	}
	//Accessors
	const int& getId () const {return id;}
	void setId (const int& id_) {id = id_;}
	const shared_ptr<Action>& getAction_Id () const {return action_id;}
	void setAction_Id (const shared_ptr<Action>& action_id_) {action_id = action_id_;}
	const std::string& getKey () const {return key;}
	void setKey (const std::string& key_) {key = key_;}
	const std::string& getNote () const {return Note;}
	void setNote (const std::string& Note_) {Note = Note_;}
//Data Fields
private:
	friend class odb::access;
	#pragma db id
	int id;
	shared_ptr<Action> action_id;
	std::string key;
	std::string Note;
};

#pragma db object
class Action_Log
{
public:
    // Default Constructor
    Action_Log () {}        
	Action_Log (int id_, shared_ptr<Action> action_id_, int time_submission_, int time_delay_, std::string flag_, std::string message_)
	: id (id_), action_id (action_id_), time_submission (time_submission_), time_delay (time_delay_), flag (flag_), message (message_)
	{
	}
	//Accessors
	const int& getId () const {return id;}
	void setId (const int& id_) {id = id_;}
	const shared_ptr<Action>& getAction_Id () const {return action_id;}
	void setAction_Id (const shared_ptr<Action>& action_id_) {action_id = action_id_;}
	const int& getTime_Submission () const {return time_submission;}
	void setTime_Submission (const int& time_submission_) {time_submission = time_submission_;}
	const int& getTime_Delay () const {return time_delay;}
	void setTime_Delay (const int& time_delay_) {time_delay = time_delay_;}
	const std::string& getFlag () const {return flag;}
	void setFlag (const std::string& flag_) {flag = flag_;}
	const std::string& getMessage () const {return message;}
	void setMessage (const std::string& message_) {message = message_;}
//Data Fields
private:
	friend class odb::access;
	#pragma db id
	int id;
	shared_ptr<Action> action_id;
	int time_submission;
	int time_delay;
	std::string flag;
	std::string message;
};
#endif
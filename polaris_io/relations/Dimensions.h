#ifndef Dimensions
#define Dimensions
#pragma warning(disable:4068)    
#include <vector>
#include <string>
#include <odb/core.hxx>
// Include TR1 <memory> header in a compiler-specific fashion. Fall back
// on the Boost implementation if the compiler does not support TR1.
//
#include <odb/tr1/memory.hxx>
using std::tr1::shared_ptr;

namespace pio {
//Forward declarations.
//
class table_field;
class Quantity;
class Dimension;


#pragma db value
class table_field
{
public:
    // Default Constructor
    table_field () {}        
	table_field (std::string table_, std::string field_, int time_)
	: table (table_), field (field_), time (time_)
	{
	}
	//Accessors
	const std::string& getTable () const {return table;}
	void setTable (const std::string& table_) {table = table_;}
	const std::string& getField () const {return field;}
	void setField (const std::string& field_) {field = field_;}
	const int& getTime () const {return time;}
	void setTime (const int& time_) {time = time_;}
//Data Fields
private:
	friend class odb::access;
	std::string table;
	std::string field;
	int time;
};

#pragma db object
class Quantity
{
public:
    // Default Constructor
    Quantity () {}        
	Quantity (table_field tf_, shared_ptr<Dimension> quantity_)
	: tf (tf_), quantity (quantity_)
	{
	}
	//Accessors
	const table_field& getTf () const {return tf;}
	void setTf (const table_field& tf_) {tf = tf_;}
	const shared_ptr<Dimension>& getQuantity () const {return quantity;}
	void setQuantity (const shared_ptr<Dimension>& quantity_) {quantity = quantity_;}
//Data Fields
private:
	friend class odb::access;
	#pragma db id
	table_field tf;
	shared_ptr<Dimension> quantity;
};

#pragma db object
class Dimension
{
public:
    // Default Constructor
    Dimension () {}        
	Dimension (std::string quantity_, int mass_, int length_, int time_, int lane_, int usd_)
	: quantity (quantity_), mass (mass_), length (length_), time (time_), lane (lane_), usd (usd_)
	{
	}
	//Accessors
	const std::string& getQuantity () const {return quantity;}
	void setQuantity (const std::string& quantity_) {quantity = quantity_;}
	const int& getMass () const {return mass;}
	void setMass (const int& mass_) {mass = mass_;}
	const int& getLength () const {return length;}
	void setLength (const int& length_) {length = length_;}
	const int& getTime () const {return time;}
	void setTime (const int& time_) {time = time_;}
	const int& getLane () const {return lane;}
	void setLane (const int& lane_) {lane = lane_;}
	const int& getUsd () const {return usd;}
	void setUsd (const int& usd_) {usd = usd_;}
//Data Fields
private:
	friend class odb::access;
	#pragma db id
	std::string quantity;
	int mass;
	int length;
	int time;
	int lane;
	int usd;
};
#endif
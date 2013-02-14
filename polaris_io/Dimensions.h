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
class Dimension;


#pragma db object
class Dimension
{
public:
    // Default Constructor
    Dimension () {}        
	Dimension (std::string table-field_, std::string quantity_, int mass_, int length_, int time_)
	: table-field (table-field_), quantity (quantity_), mass (mass_), length (length_), time (time_)
	{
	}
	//Accessors
	const std::string& getTable-Field () const {return table-field;}
	void setTable-Field (const std::string& table-field_) {table-field = table-field_;}
	const std::string& getQuantity () const {return quantity;}
	void setQuantity (const std::string& quantity_) {quantity = quantity_;}
	const int& getMass () const {return mass;}
	void setMass (const int& mass_) {mass = mass_;}
	const int& getLength () const {return length;}
	void setLength (const int& length_) {length = length_;}
	const int& getTime () const {return time;}
	void setTime (const int& time_) {time = time_;}
//Data Fields
private:
	friend class odb::access;
	#pragma db id
	std::string table-field;
	std::string quantity;
	int mass;
	int length;
	int time;
};
#endif
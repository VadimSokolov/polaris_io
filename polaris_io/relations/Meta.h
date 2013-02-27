#ifndef Meta
#define Meta
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
class Meta;


#pragma db object
class Meta
{
public:
    // Default Constructor
    Meta () {}        
	Meta (int id_, std::string key_, std::string value_)
	: id (id_), key (key_), value (value_)
	{
	}
	//Accessors
	const int& getId () const {return id;}
	void setId (const int& id_) {id = id_;}
	const std::string& getKey () const {return key;}
	void setKey (const std::string& key_) {key = key_;}
	const std::string& getValue () const {return value;}
	void setValue (const std::string& value_) {value = value_;}
//Data Fields
private:
	friend class odb::access;
	#pragma db id
	int id;
	std::string key;
	std::string value;
};
#endif
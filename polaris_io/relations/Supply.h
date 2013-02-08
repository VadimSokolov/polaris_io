#ifndef Supply
#define Supply
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
class Area_Type;
class Link_Type;


#pragma db object
class Area_Type
{
public:
    // Default Constructor
    Area_Type () {}        
	Area_Type (int area_type_, std::string name_, std::string notes_)
	: area_type (area_type_), name (name_), notes (notes_)
	{
	}
	//Accessors
	const int& getArea_Type () const {return area_type;}
	void setArea_Type (const int& area_type_) {area_type = area_type_;}
	const std::string& getName () const {return name;}
	void setName (const std::string& name_) {name = name_;}
	const std::string& getNotes () const {return notes;}
	void setNotes (const std::string& notes_) {notes = notes_;}
//Data Fields
private:
	friend class odb::access;
	#pragma db id
	int area_type;
	std::string name;
	std::string notes;
};

#pragma db object
class Link_Type
{
public:
    // Default Constructor
    Link_Type () {}        
	Link_Type (std::string link_type_, int rank_, std::string use_codes_, std::string alternative_labels_, std::string notes_)
	: link_type (link_type_), rank (rank_), use_codes (use_codes_), alternative_labels (alternative_labels_), notes (notes_)
	{
	}
	//Accessors
	const std::string& getLink_Type () const {return link_type;}
	void setLink_Type (const std::string& link_type_) {link_type = link_type_;}
	const int& getRank () const {return rank;}
	void setRank (const int& rank_) {rank = rank_;}
	const std::string& getUse_Codes () const {return use_codes;}
	void setUse_Codes (const std::string& use_codes_) {use_codes = use_codes_;}
	const std::string& getAlternative_Labels () const {return alternative_labels;}
	void setAlternative_Labels (const std::string& alternative_labels_) {alternative_labels = alternative_labels_;}
	const std::string& getNotes () const {return notes;}
	void setNotes (const std::string& notes_) {notes = notes_;}
//Data Fields
private:
	friend class odb::access;
	#pragma db id
	std::string link_type;
	int rank;
	std::string use_codes;
	std::string alternative_labels;
	std::string notes;
};
#endif
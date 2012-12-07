#pragma once

#include <odb/core.hxx>
#include <odb/tr1/memory.hxx>
#include <string>
using std::tr1::shared_ptr;
namespace pio
{
class agency
{
public:
	// Default Constructor
	agency () {}
	std::string agency_id;
	std::string agency_name;
	std::string agency_url;
	std::string agency_timezone;
	std::string agency_phone;
	std::string agency_fare_url;
};
}
#ifndef _DATA_READER_H_
#define _DATA_READER_H_

#include <string>
#include <map>

namespace data {
	
	void getFile( const std::string& fileName, std::string& buffer );
	std::map<std::string, std::string> format_description_to_map( const std::string& buffer );
	std::map<std::string, std::string> format_viewid_to_map( const std::string& buffer );
	std::map<std::string, std::string> format_displayname_to_map( const std::string& buffer );
	std::map<std::string, std::string> format_slot_to_map(const std::string& buffer );
	
	
}

#endif
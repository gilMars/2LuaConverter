#ifndef DATAREADER_H
#define DATAREADER_H

#include <string>
#include <map>

namespace data {

    bool getFile( const std::string& fileName, std::string& buffer );
    std::map<std::string, std::string> format_description_to_map( const std::string& buffer );
    std::map<std::string, std::string> format_viewid_to_map( const std::string& buffer );
    std::map<std::string, std::string> format_displayname_to_map( const std::string& buffer );
    std::map<std::string, std::string> format_slot_to_map(const std::string& buffer );


}

#endif // DATAREADER_H

#include "header/datareader.h"
#include <regex>
#include <fstream>
#include <iostream>

bool data::getFile( const std::string& fileName, std::string& buffer ) {

    std::ifstream file(fileName);

    if ( file ) {

        buffer = std::string ( std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>() );

        std::regex comment("/{2}.*");
        buffer = std::regex_replace( buffer, comment, "" );

        comment = std::regex("/[*](?:\\s|.)*?[*]/");

        buffer = std::regex_replace( buffer, comment, "" );

        return true;

    }

    return false;

}


std::map<std::string, std::string> data::format_description_to_map( const std::string& buffer ) {

    std::regex pattern( "\\d+#(?:\\s|.)*?#" );
    std::string tmp = buffer;
    std::smatch sm;

    std::map<std::string,std::string> data;

    while ( std::regex_search ( tmp, sm, pattern )) {

        for ( auto i: sm ) {
            std::string txt = i.str();
            std::size_t pos = txt.find('#');
            std::string cor = std::regex_replace( txt.substr( pos+1,(txt.length()-(pos+2)) ), std::regex("\""), "\\\"$2");
            std::regex cform(".+");
            std::smatch smc;
            std::string btmp = "";
            while ( std::regex_search ( cor, smc, cform ) ) {
                for ( const auto& a: smc ) {
                    btmp += "\t\t\t\""+a.str()+ "\",\n";
                }
                cor = smc.suffix().str();
            }

            data[txt.substr(0,pos)] = btmp;
            tmp = sm.suffix().str();
        }

    }

    return data;

}

std::map<std::string, std::string> data::format_viewid_to_map( const std::string& buffer ) {

    std::regex pattern("\\{(?:\\s|.)*?\\},");
    std::string tmp = buffer;
    std::smatch sm;

    std::map<std::string,std::string> data;

    while ( std::regex_search ( tmp, sm, pattern )) {

        for ( auto i: sm ) {

            std::string txt = i.str();

            std::regex spattern("Id: ?\\d+");
            std::smatch ssm;
            std::regex_search ( txt, ssm, spattern );
            spattern = std::regex( "\\d+" );
            std::string id = ssm[0].str();
            std::regex_search ( id, ssm, spattern );
            id = ssm[0].str();
            spattern = std::regex("View: ?\\d+");
            if ( std::regex_search ( txt, ssm, spattern ) )
            {
                spattern = std::regex( "\\d+" );
                std::string view = ssm[0].str();
                std::regex_search ( view, ssm, spattern );
                data[id] = ssm[0].str();
            }else data[id] = "0";

            tmp = sm.suffix().str();
        }

    }

    return data;

}

std::map<std::string, std::string> data::format_displayname_to_map( const std::string& buffer ) {

    std::regex pattern( "\\d+#.*?#" );
    std::string tmp = buffer;
    std::smatch sm;


    std::map<std::string,std::string> data;

    while ( std::regex_search ( tmp, sm, pattern )) {

        for ( auto i: sm ) {
            std::string txt = i.str();
            std::size_t pos = txt.find('#');
            data[txt.substr(0,pos)] = std::regex_replace( txt.substr( pos+1,(txt.length()-(pos+2)) ), std::regex("\\s+"), "_$2");
            tmp = sm.suffix().str();
        }

    }

    return data;

}

std::map<std::string, std::string> data::format_slot_to_map(const std::string& buffer ) {

    std::regex pattern( "\\d+#\\d+#" );
    std::string tmp = buffer;
    std::smatch sm;

    std::map<std::string,std::string> data;

    while ( std::regex_search ( tmp, sm, pattern )) {

        for ( auto i: sm ) {
            std::string txt = i.str();
            std::size_t pos = txt.find('#');
            data[txt.substr(0,pos)] = txt.substr(pos+1,(txt.length()-(pos+2)));
            tmp = sm.suffix().str();
        }

    }

    return data;

}

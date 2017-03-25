#include "header/datareader.h"
#include <regex>
#include <fstream>
#include <iostream>

bool data::getFile( const std::string& fileName, std::string& buffer ) {

    std::ifstream file(fileName);

    // Caso a abertura do arquivo para leitura tenha sido um sucesso
    if ( file ) {

        // Carrega o arquivo completo para a memória utilizando iterator
        buffer = std::string ( std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>() );

        // Padrão que determina formato de comentário de uma única linha
        std::regex comment("/{2}.*");

        // Reescreve todos comentários com vazio
        buffer = std::regex_replace( buffer, comment, "" );

        // Padrão que determina formato de comentário de multiplas linhas
        comment = std::regex("/[*](?:\\s|.)*?[*]/");

        // Reescreve todos comentários de multiplas linhas com vazio
        buffer = std::regex_replace( buffer, comment, "" );

        return true;

    }

    return false;

}

std::map<std::string, std::string> data::format_displayname_to_map( const std::string& buffer ) {

    // Padrão para leitura do nome do item. Exemplo: (Id ∈ N)#Nome do Item#
    std::regex pattern( "\\d+#.*?#" );
    std::string tmp = buffer;
    std::smatch sm;

    // Map para guardar o id e seus respectivo nome
    std::map<std::string,std::string> data;

    while ( std::regex_search ( tmp, sm, pattern )) {

        for ( auto i: sm ) {
            std::string txt = i.str();
            std::size_t pos = txt.find('#');
            data[txt.substr(0,pos)] = std::regex_replace( txt.substr( pos+1,(txt.length()-(pos+2)) ), std::regex("_"), " ");
            tmp = sm.suffix().str();
        }

    }

    return data;

}

std::map<std::string, std::string> data::format_spritename_to_map( const std::string& buffer ) {

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

std::map<std::string, std::string> data::format_description_to_map( const std::string& buffer ) {

    // Padrão  para leitura da descrição do item
    std::regex pattern( "\\d+#(?:\\s|.)*?#" );

    // Copia do arquivo que foi salvo na memória, para evitar alterações inadequeadas
    std::string tmp = buffer;

    std::smatch sm;

    // Map utilizado para receber o id do item e sua descrição
    std::map<std::string,std::string> data;

    // Pesquisa por padrões
    while ( std::regex_search ( tmp, sm, pattern )) {

        for ( auto i: sm ) {
            std::string txt = i.str();
            std::size_t pos = txt.find('#');

            // Correção da descrição
            std::string cor = std::regex_replace( txt.substr( pos+1,(txt.length()-(pos+2)) ), std::regex("\""), "\\\"$2");
            std::regex cform(".+");
            std::smatch smc;
            std::string btmp = "";

            // Reescrita de ada linha para o formato da descrição do lua
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

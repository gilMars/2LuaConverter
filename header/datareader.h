/*
 * Arquivo de cabeçalho contendo o namespace responsável pela leitura de arquivos.
 * @author Gilmar B. Freitas.
 * @version 1.0
*/
#ifndef DATAREADER_H
#define DATAREADER_H

#include <string>
#include <map>

namespace data {

    /*
     * Método responsável por fazer a leitura completa do arquivo direto para a memória principal.
     * @param fileName nome do arquivo que será carregado na memória.
     * @param buffer variável que irá conter todos os dados do arquivo.
     * @return um valor booleano responsável por definir se o arquivo foi lido com sucesso ou não.
     */
    bool getFile( const std::string& fileName, std::string& buffer );

    /*
     * Método responsável por formatar os dados do arquivo de acordo com o formato da descrição do item.
     * @param buffer é a variável onde está contido os dados do arquivo.
     * @return um map<id,descrição> com o id do item e a descrição do respectivo item.
     */
    std::map<std::string, std::string> format_description_to_map( const std::string& buffer );

    /*
     * Método responsável por formatar os dados do arquivo de acordo com id e viewId de um determinado item.
     * @param buffer variável com os dados do arquivo.
     * @return map<id, viewId> respectivamente com o id do item e o seu viewId.
    */
    std::map<std::string, std::string> format_viewid_to_map( const std::string& buffer );

    /*
     * Método que irá formatar os dados do arquivo de acordo com o id e seu respectivo displayname.
     * @param buffer variável com os dados do arquivo.
     * @return map<id,displayname> é o map com o id e nome de cada item.
    */
    std::map<std::string, std::string> format_displayname_to_map( const std::string& buffer );

    /*
     * Método responsável por formatar os dados do arquivo de acordo com a sprite de cada item e seu respectivo id
     * @param buffer variável que armazena o arquivo completo.
     * @return map<id, sprite> é o map com o id do item e sua respectiva sprite.
    */
    std::map<std::string, std::string> format_spritename_to_map( const std::string& buffer );

    /*
     * Método responsável por formatar os dados do arquivo com o id e o slot do item.
     * @param buffer variável com os dados do arquivo que foi carregado na memória.
     * @return map<id,slot> é um map contendo o id de cada item e seu respectivo slot, caso tenha.
    */
    std::map<std::string, std::string> format_slot_to_map(const std::string& buffer );


}

#endif // DATAREADER_H

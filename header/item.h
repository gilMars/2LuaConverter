/*
 * Arquivo de cabeçalho com a classe Item, que é responsável por representar o item e suas devidas informações, juntamente com seus métodos de manipulação.
 * @author Gilmar B. Freitas.
 * @version 1.0
*/
#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {

    private:

        std::string id;           // Id do item que será lido

        std::string kDisplayName; // Nome do item identificado
        std::string kSpriteName;  // Sprite do item identificado
        std::string kDescription; // Descrição do item identificado

        std::string uDisplayName; // Nome do item não identificado
        std::string uSpriteName;  // Sprite do item não identificado
        std::string uDescription; // Descrição do item não identificado

        std::string viewId;       // ViewId do item, caso tenha
        std::string slotCount;    // Quantidade de slots do item, caso tenha

    public:

        Item( const std::string& id = 0, const std::string& kDisplayName = "",  const std::string& kSpriteName = "", const std::string& kDescription = "", const std::string& uDisplayName = "", const std::string& uSpriteName = "", const std::string& uDescription = "", const std::string& viewId = "0", const std::string& slotCount = "0" );

        std::string getItemId() const;
        std::string getItemDisplayName() const;
        std::string getItemSpriteName() const;
        std::string getItemDescription() const;
        std::string getUnknownDisplayName() const;
        std::string getUnknownSpriteName() const;
        std::string getUnknownDescription() const;
        std::string getItemViewId() const;
        std::string getItemSlotCount() const;

        void setItemId( const std::string& id );
        void setItemDisplayName( const std::string& kDisplayName );
        void setItemSpriteName( const std::string& kSpriteName );
        void setItemDescription( const std::string& kDescription );
        void setUnknownDisplayName( const std::string& uDisplayName );
        void setUnknownSpriteName( const std::string& uSpriteName );
        void setUnknownDescription( const std::string& uDescription );
        void setItemViewId( const std::string& viewId );
        void setItemSlotCount( const std::string& slotCount );

        /*
         * Método irá formatar os atributos do Item de acordo com a estrutura de uma lista em Lua
         * @return std::string será retornada com as informações do item, id, sprite, descrição e etc...
        */
        std::string toString();
};

#endif // ITEM_H

#ifndef _ITEM_H_
#define _ITEM_H_

#include <string>

class Item {
	
private:

    std::string itemId;
    
    std::string kDisplayName;
    std::string kSpriteName;
    std::string kItemDesc;
    
    std::string uDisplayName;
    std::string uSpriteName;
    std::string uItemDesc;
    
    std::string itemViewId;
    std::string itemSlotCount;
    
public:

    Item( const std::string& itemId = 0, const std::string& kDisplayName = "",  const std::string& kSpriteName = "", const std::string& kItemDesc = "", const std::string& uDisplayName = "", const std::string& uSpriteName = "", const std::string& uItemDesc = "", const std::string& itemViewId = "0", const std::string& itemSlotCount = "0" );
    ~Item(){}
    
    std::string getItemId() const;
    std::string getDisplayName() const;
    std::string getSpriteName() const;
    std::string getDesc() const;
    std::string getuDisplayName() const;
    std::string getuSpriteName() const;
    std::string getuDesc() const;
    std::string getViewId() const;
    std::string getSlotCount() const;
    
    void setId( const std::string& itemId );
    void setDisplayName( const std::string& itemDisplayName );
    void setSpriteName( const std::string& itemSpriteName );
    void setDesc( const std::string& itemDesc );
    void setuDisplayName( const std::string& uitemDisplayName );
    void setuSpriteName( const std::string& uitemSpriteName );
    void setuDesc( const std::string& uitemDesc );
    void setViewId( const std::string& itemViewId );
    void setSlotCount( const std::string& itemSlotCount );
    
    std::string toString();
	
};

#endif
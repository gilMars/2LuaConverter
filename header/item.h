#ifndef _ITEM_H_
#define _ITEM_H_

#include <string>

class Item {
	
	private:

		std::string id;
		
		std::string kDisplayName;
		std::string kSpriteName;
		std::string kDescription;
		
		std::string uDisplayName;
		std::string uSpriteName;
		std::string uDescription;
		
		std::string viewId;
		std::string slotCount;
    
	public:

		Item( const std::string& id = 0, const std::string& kDisplayName = "",  const std::string& kSpriteName = "", const std::string& kDescription = "", const std::string& uDisplayName = "", const std::string& uSpriteName = "", const std::string& uDescription = "", const std::string& viewId = "0", const std::string& slotCount = "0" );
		
		std::string getItemId() const;
		std::string getItemDisplayName() const;
		std::string getItemSpriteName() const;
		std::string getItemDescription() const;
		std::string getUnknownDisplayName() const;
		std::string getUnknownSpriteName() const;
		std::string getUnknownDescription() const;
		std::string getViewId() const;
		std::string getSlotCount() const;
		
		void setItemId( const std::string& itemId );
		void setItemDisplayName( const std::string& itemDisplayName );
		void setItemSpriteName( const std::string& itemSpriteName );
		void setItemDescription( const std::string& itemDesc );
		void setUnknownDisplayName( const std::string& uitemDisplayName );
		void setUnknownSpriteName( const std::string& uitemSpriteName );
		void setUnknownDescription( const std::string& uitemDesc );
		void setViewId( const std::string& itemViewId );
		void setSlotCount( const std::string& itemSlotCount );
		
		std::string toString();
};

#endif
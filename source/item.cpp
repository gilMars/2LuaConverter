#include <item.h>

Item::Item( const std::string& itemId, const std::string& itemName,  const std::string& sprName, const std::string& itemDesc, const std::string& uitemName, const std::string& usprName, const std::string& uitemDesc, const std::string& itemViewId, const std::string& itemSlotCount )
{
    id = itemId;
    
    displayName = itemName;
    spriteName = sprName;
    desc = itemDesc;
    
    udisplayName = uitemName;
    uspriteName = usprName;
    udesc = uitemDesc;
    
    viewId = itemViewId;
    
    slotCount = itemSlotCount;
}

		
std::string Item::getId() const {
	return id;
}

std::string Item::getDisplayName() const {
	return displayName;
}

std::string Item::getSpriteName() const {
	return spriteName;
}

std::string Item::getDesc() const {
	return desc;
}

std::string Item::getuDisplayName() const {
	return udisplayName;
}

std::string Item::getuSpriteName() const {
	return uspriteName;
}

std::string Item::getuDesc() const {
	return udesc;
}

std::string Item::getViewId() const {
	return viewId;
}

std::string Item::getSlotCount() const {
	return slotCount;
}

void Item::setId( const std::string& itemId ) {
	id = itemId;
}

void Item::setDisplayName( const std::string& itemDisplayName ) {
	displayName = itemDisplayName;
}

void Item::setSpriteName( const std::string& itemSpriteName ) {
	spriteName = itemSpriteName;
}

void Item::setDesc( const std::string& itemDesc ) {
	desc = itemDesc;
}

void Item::setuDisplayName( const std::string& uitemDisplayName ) {
	udisplayName = uitemDisplayName;
}

void Item::setuSpriteName( const std::string& uitemSpriteName ) {
	uspriteName = uitemSpriteName;
}

void Item::setuDesc( const std::string& uitemDesc ) {
	udesc = uitemDesc;
}

void Item::setViewId( const std::string& itemViewId ) {
	viewId = itemViewId;
}

void Item::setSlotCount( const std::string& itemSlotCount ) {
	slotCount = itemSlotCount;
}
	
std::string Item::toString() {
    
    return  "\t[" + id
    + "] = {\n\t\tunidentifiedDisplayName = \"" + udisplayName
    + "\",\n\t\tunidentifiedResourceName = \"" + uspriteName
    + "\",\n\t\tunidentifiedDescriptionName = {\n" + udesc
    + "\t\t},\n\t\tidentifiedDisplayName = \"" + displayName
    + "\",\n\t\tidentifiedResourceName = \"" + spriteName
    + "\",\n\t\tidentifiedDescriptionName = {\n" + desc
    + "\t\t},\n\t\tslotCount = " + slotCount
    + ",\n\t\tClassNum = " + viewId
    + "\n\t},\n";
    
}

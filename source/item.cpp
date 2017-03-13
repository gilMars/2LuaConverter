#include "header/item.h"

Item::Item( const std::string& id, const std::string& kDisplayName,  const std::string& kSpriteName, const std::string& kDescription, const std::string& uDisplayName, const std::string& uSpriteName, const std::string& uDescription, const std::string& viewId, const std::string& slotCount ) {


    this->id            = id;

    this->kDisplayName  = kDisplayName;
    this->kSpriteName   = kSpriteName;
    this->kDescription  = kDescription;

    this->uDisplayName  = uDisplayName;
    this->uSpriteName   = uSpriteName;
    this->uDescription  = uDescription;

    this->viewId        = viewId;

    this->slotCount     = slotCount;

}


std::string Item::getItemId() const {
    return id;
}

std::string Item::getItemDisplayName() const {
    return kDisplayName;
}

std::string Item::getItemSpriteName() const {
    return kSpriteName;
}

std::string Item::getItemDescription() const {
    return kDescription;
}

std::string Item::getUnknownDisplayName() const {
    return uDisplayName;
}

std::string Item::getUnknownSpriteName() const {
    return uSpriteName;
}

std::string Item::getUnknownDescription() const {
    return uDescription;
}

std::string Item::getItemViewId() const {
    return viewId;
}

std::string Item::getItemSlotCount() const {
    return slotCount;
}

void Item::setItemId( const std::string& id ) {
    this->id = id;
}

void Item::setItemDisplayName( const std::string& kDisplayName ) {
    this->kDisplayName = kDisplayName;
}

void Item::setItemSpriteName( const std::string& kSpriteName ) {
    this->kSpriteName = kSpriteName;
}

void Item::setItemDescription( const std::string& kDescription ) {
    this->kDescription = kDescription;
}

void Item::setUnknownDisplayName( const std::string& uDisplayName ) {
    this->uDisplayName = uDisplayName;
}

void Item::setUnknownSpriteName( const std::string& uSpriteName ) {
    this->uSpriteName = uSpriteName;
}

void Item::setUnknownDescription( const std::string& uDescription ) {
    this->uDescription = uDescription;
}

void Item::setItemViewId( const std::string& viewId ) {
    this->viewId = viewId;
}

void Item::setItemSlotCount( const std::string& slotCount ) {
    this->slotCount = slotCount;
}

std::string Item::toString() {

    return
    "\t[" + id
    + "] = {\n\t\tunidentifiedDisplayName = \"" + uDisplayName
    + "\",\n\t\tunidentifiedResourceName = \"" + uSpriteName
    + "\",\n\t\tunidentifiedDescriptionName = {\n" + uDescription
    + "\t\t},\n\t\tidentifiedDisplayName = \"" + kDisplayName
    + "\",\n\t\tidentifiedResourceName = \"" + kSpriteName
    + "\",\n\t\tidentifiedDescriptionName = {\n" + kDescription
    + "\t\t},\n\t\tslotCount = " + slotCount
    + ",\n\t\tClassNum = " + viewId
    + "\n\t},\n";

}

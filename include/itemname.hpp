#ifndef _ITEM_NAME_H_
#define _ITEM_NAME_H_

#include <string>
#include <map>

class ItemName {
	
	private:
	
		std::map< std::string, std::string> buffer;
		bool state;
		
	public:
	
		explicit ItemName( const std::string& fileName, unsigned int& count = 0 );
		void getBuffer() const;
		unsigned int length();
		void clear();
		bool read( std::string& fileName );
};

#endif
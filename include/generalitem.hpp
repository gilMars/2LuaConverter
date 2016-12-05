#ifndef _ITEM_ABSTRACT_H_
#define _ITEM_ABSTRACT_H_

#include <string>
#include <map>

class GeneralItem {
	
	private:
	
		std::map< std::string, std::string> buffer;
		
	public:
	
		virtual bool read( std::string& fileName ) = 0;
		std::map< std::string, std::string > getBuffer() const;
		unsigned int length();
		void clear();
		
};

#endif
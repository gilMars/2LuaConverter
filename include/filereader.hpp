#ifndef _FILE_READER_H_
#define _FILE_READER_H_

#include <map>
#include <string>

class FileReader {
	
	private:
		
		std::map < std::string, std::string > data;
		
		std::string fileBuffer;
		
		MODE mode;
		
		void readViewId();
		void readName();
		void readDescription();
		void readSlot();
		
	public:
		
		static enum MODE { VIEWID, NAME, DESCRIPTION, SLOT };
		
		bool open( const std::string& fileName, const MODE& mode );
		
		std::map < std::string, std::string > readData();
		
		std::map< std::string, std::string > getData() const;
		
		void clear();
		
};

#endif
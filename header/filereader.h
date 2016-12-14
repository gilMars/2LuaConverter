#ifndef _FILE_READER_H_
#define _FILE_READER_H_

#include <string>
#include <map>

enum MODE {
	DESC,
	DISP,
	VIEW,
	SLOT
};

class FileReader {
	
	private:
	
		std::string buffer;
		bool state;
		MODE mode;
		
	public:
		FileReader( const std::string& fileName, const MODE& mode );
		bool open( const std::string& fileName, const MODE& mode );
		std::map<std::string,std::string> readData();
};

#endif
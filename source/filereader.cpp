#include <filereader.h>
#include <regex>
#include <fstream>

FileReader::FileReader( const std::string& fileName, const MODE& mode ) {
	
	state = false;
	this->mode = mode;
	
	std::ifstream file(fileName);
	if ( file ) {

		file.seekg( 0, file.end );
		long length = file.tellg();
		file.seekg( 0, file.beg );
		char * tmp = new char[length+1];
		file.read( tmp, length );
		file.close();
		
		tmp[length+1] = '\0';
		
		std::regex comment("\\/\\/.*");
		buffer = std::regex_replace( tmp, comment, "$2" );
		delete [] tmp;

		comment = std::regex("\\/\\*(?:\\s|.)*?\\*\\/");
		buffer = std::regex_replace( buffer, comment, "$2" );
		
		
		state = true;
		
		
		
	}
	
}

std::map<std::string,std::string> FileReader::readData() {
	
	std::map<std::string,std::string> data;
	
	
	if ( state  == true ) {
		
		std::regex pattern;
		std::string tmp;
		std::smatch sm;
		
		switch ( mode ) {
			
			case DESC:
			
				pattern = std::regex( "\\d+#(?:\\s|.)*?#" );
				tmp = buffer;
				
				while ( std::regex_search ( tmp, sm, pattern )) {
					
					for ( auto i: sm ) {
						std::string txt = i.str();
						std::size_t pos = txt.find('#');
						std::string cor = std::regex_replace( txt.substr( pos+1,(txt.length()-(pos+2)) ), std::regex("\""), "\\\"$2");
						std::regex cform(".+");
						std::smatch smc;
						std::string btmp = "";
						while ( std::regex_search ( cor, smc, cform ) ) {
							for ( const auto& a: smc ) {
								btmp += "\t\t\t\""+a.str()+ "\",\n";
							}  
							cor = smc.suffix().str();                      
						}

						data[txt.substr(0,pos)] = btmp;
						tmp = sm.suffix().str();
					}
					
				}				
				break;
				
			case DISP:
				
				pattern  = std::regex( "\\d+#.*?#" );
				tmp = buffer;
				
				while ( std::regex_search ( tmp, sm, pattern )) {
					
					for ( auto i: sm ) {
						std::string txt = i.str();
						
						std::size_t pos = txt.find('#');
						data[txt.substr(0,pos)] = std::regex_replace( txt.substr( pos+1,(txt.length()-(pos+2)) ), std::regex("\\s+"), "_$2");
						tmp = sm.suffix().str();
					}
					
				}
				break;
				
			case VIEW:
			
				pattern = std::regex("\\{(?:\\s|.)*?\\},");
				tmp = buffer;
				
				while ( std::regex_search ( tmp, sm, pattern )) {
					
					for ( auto i: sm ) {
					
						std::string txt = i.str();
						
						std::regex spattern("Id: ?\\d+");
						std::smatch ssm;
						std::regex_search ( txt, ssm, spattern );
						spattern = std::regex( "\\d+" );
						std::string id = ssm[0].str();
						std::regex_search ( id, ssm, spattern );
						id = ssm[0].str();
						spattern = std::regex("View: ?\\d+");
						if ( std::regex_search ( txt, ssm, spattern ) )
						{
							spattern = std::regex( "\\d+" );
							std::string view = ssm[0].str();
							std::regex_search ( view, ssm, spattern );
							data[id] = ssm[0].str();
						}else data[id] = "0";
					   
						tmp = sm.suffix().str();
					}
					
				}
				break;
				
			case SLOT:
			
				pattern  = std::regex( "\\d+#\\d+#" );
				tmp = buffer;
				
				while ( std::regex_search ( tmp, sm, pattern )) {
					
					for ( auto i: sm ) {
						std::string txt = i.str();
						std::size_t pos = txt.find('#');
						data[txt.substr(0,pos)] = txt.substr(pos+1,(txt.length()-(pos+2)));
						tmp = sm.suffix().str();
					}
					
				}
				
		}
		
	}
	
	return data;
	
}
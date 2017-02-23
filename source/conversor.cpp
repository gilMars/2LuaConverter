#include <datareader.h>
#include <item.h>
#include <stdio.h>
#include <map>
#include <string>
#include <fstream>
#include <atomic>
#include <pthread.h>
#include <time.h>
#include <iostream>

//static const char* F_MAIN  = "}\nmain = function()\n\tfor ItemID,DESC in pairs(tbl) do\n\t\tresult, msg = AddItem(ItemID, DESC.unidentifiedDisplayName, DESC.unidentifiedResourceName, DESC.identifiedDisplayName, DESC.identifiedResourceName, DESC.slotCount, DESC.ClassNum)\n\t\tif not result then\n\t\t\treturn false, msg\n\t\tend\n\t\tfor k,v in pairs(DESC.unidentifiedDescriptionName) do\n\t\t\tresult, msg = AddItemUnidentifiedDesc(ItemID, v)\n\t\t\tif not result then\n\t\t\t\treturn false, msg\n\t\t\tend\n\t\tend\n\t\tfor k,v in pairs(DESC.identifiedDescriptionName) do\n\t\t\tresult, msg = AddItemIdentifiedDesc(ItemID, v)\n\t\t\tif not result then\n\t\t\t\treturn false, msg\n\t\t\tend\n\t\tend\n\tend\n\treturn true, \"good\"\nend";

using namespace std;
using namespace data;
typedef void* (*func)( void* );

void init_read( void* state ) {
	
	string file;
	getFile( "item_db.txt", file );
	//cout << file;
	map<string,string> view = format_viewid_to_map(file);
	//cout << view.size();
	/*
	FileReader display_name("idnum2itemdisplaynametable.txt",DISP);
	map<string,string> disp = display_name.readData();
	
	FileReader desctable("idnum2itemdesctable.txt",DESC);
	map<string,string> desc = desctable.readData();
	
	FileReader sprite_name("idnum2itemresnametable.txt",DISP);
	map<string,string> sprite = sprite_name.readData();
	
	FileReader unknown_display("num2itemdisplaynametable.txt",DISP);
	map<string,string> udisp = unknown_display.readData();
	
	FileReader unknown_desctable("num2itemdesctable.txt",DESC);
	map<string,string> udesc = unknown_desctable.readData();
	
	FileReader unknown_sprite("num2itemresnametable.txt",DISP);
	map<string,string> usprite = unknown_sprite.readData();
	
	FileReader slot_counttable("itemslotcounttable.txt",SLOT);
	map<string,string> slot = slot_counttable.readData();
	
	ofstream saida("itemInfo.lua");
	saida << "tbl = {" << endl;
	for ( const auto& item: disp ) {
		saida << Item( item.first, item.second,  sprite[item.first], desc[item.first], udisp[item.first], usprite[item.first], udesc[item.first], ((view[item.first].empty())? "0":view[item.first]), ((slot[item.first].empty())? "0":slot[item.first]) ).toString();
	}
	
	saida << F_MAIN;
	
	saida.close();	
	*/
	((atomic_bool*)state)->store(false);
	pthread_exit(NULL);
}

int main()
{
	
	pthread_t thread;
	atomic_bool state(true);
	printf("Tempo decorrido:\n");
	time_t start = time(0);
	pthread_create(&thread, NULL, (func)init_read, (void *) &state);
	while ( state.load() ) {
		time_t end = time(0);
		printf("%3d\r\r\r", (int)difftime(end, start));
	}

	
}
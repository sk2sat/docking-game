#include "Console.h"

using namespace std;

Console::Console(int x0, int y0, int x1, int y1){
	this->x0 = x0;
	this->y0 = y0;
	this->x1 = x1;
	this->y1 = y1;
}

Console::~Console(){

}

void Console::puts(unsigned int col, char *str){
	strtbl.push_back(string(str));
	coltbl.push_back(col);
}

void Console::printf(unsigned int col, char *fmt, ...){

}

void Console::draw(){
	for(int i=0;i<strtbl.size();i++){
		DrawString(x0,y0+(i*15),strtbl[i].c_str(),coltbl[i]);
	}
}

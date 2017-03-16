#ifndef CONSOLE_H_
#define CONSOLE_H_

#include "DxLib.h"
#include <vector>
#include <string>

class Console {
public:
	Console(int x0, int y0, int x1, int y1);
	~Console();

	void puts(unsigned int col, char *str);
	void printf(unsigned int col, char *fmt, ...);

	void draw();
private:
	std::vector<std::string> strtbl;
	std::vector<unsigned int> coltbl;
	int nline, line_max;
	int x0,y0,x1,y1;
};

#endif

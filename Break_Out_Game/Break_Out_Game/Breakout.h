#include "olcConsoleGameEngine.h"
#ifndef BREAKOUT
#define BREAKOUT

class Brekout : public olcConsoleGameEngine {

public:
	std::string level;
	int nWidth = 16;
	int nHeight = 15;
	int nBlock = 8;//size of drawing bloks

public:
	Brekout() {}
	~Brekout() {}
public:
	void DrawLevel(std::string level, const int nHeight, const int nWidth, const int nBlock);
	bool OnUserCreate();
	bool OnUserUpdate(float fElapsedTime);
private:

};

#endif
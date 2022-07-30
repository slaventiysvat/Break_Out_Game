#include "olcConsoleGameEngine.h"
#ifndef BREAKOUT
#define BREAKOUT

class Brekout : public olcConsoleGameEngine {

public:

public:
	Brekout() {}
	~Brekout() {}
public:
	bool OnUserCreate();
	bool OnUserUpdate(float fElapsedTime);
};

#endif
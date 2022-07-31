#include "olcConsoleGameEngine.h"
#ifndef BREAKOUT
#define BREAKOUT

struct ball_coordinates {

	float ball_x;
	float ball_y;
	float ball_dx;
	float ball_dy;
	float ball_old_dx;
	float ball_old_dy;

};



class Ball {

public:
	Ball();
	//Ball(float dx, float dy) : fBallDX{ dx }, fBallDY{ dy } {}
	ball_coordinates BallMove(float fElapsedTime, int nBlock, int nWidth, std::string level);
	~Ball() {};

private:

	//Ball Settings
	float fBallX = 64.0f;
	float fBallY = 64.0f;
	float fOldX = 0;
	float fOldY = 0;
	float fBallDX = 0, fBallDY = 0;
	const float PI = 3.14159265359;
	float fSpeed = 50.0f;//Speed Ball
	//Data for Ball
	int nCellOldX = 0;
	int nCellOldY = 0;
};


class Brekout : public olcConsoleGameEngine {

public:
	Ball Ball_Obj;
	std::string level;
	int nWidth = 16;
	int nHeight = 15;
	int nBlock = 8;//size of drawing bloks

	//bat settings
	float fBat = 64.0f;//central position
	int nBatWidth = 10;
	float fbatSpeed = 30.0f;

public:
	Brekout() {};
	~Brekout() {};
public:
	void DrawLevel(std::string level, const int nHeight, const int nWidth, const int nBlock);
	bool OnUserCreate();
	bool OnUserUpdate(float fElapsedTime);
private:

};





#endif
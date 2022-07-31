#include "GameBaseClass.h"
#ifndef BREAKOUT
#define BREAKOUT

//struct ball_coordinates {
//
//	float ball_x;
//	float ball_y;
//	float ball_dx;
//	float ball_dy;
//	float ball_old_dx;
//	float ball_old_dy;
//	std::string new_level_editet;
//};

class Ball {

public:
	Ball();
	//Ball(float dx, float dy) : fBallDX{ dx }, fBallDY{ dy } {}
	//void BallMove(float fElapsedTime, int nBlock, int nWidth, std::string &level);
	void Ball::BallMove(float fElapsedTime, int nBlock, int nWidth, int nHeight, float fBat, std::string& level);
	//void update_ball_state(ball_coordinates new_state);

	float get_fball_x() {return fBallX;}
	void  set_fball_x( float ball_x) {fBallX = ball_x;}
    float get_fball_y() {return fBallY;}
	void  set_fball_y(float ball_y) {fBallY = ball_y;}
	
	float get_fold_x(){ return fOldX; }
	void  set_fold_x(float old_x) {fOldX = old_x;}
	float get_fold_y(){ return fOldY; }
	void  set_fold_y(float old_y) { fOldY = old_y; }

	float get_fball_dy() { return fBallDY; }
	float get_fball_dx() { return fBallDX; }
	void  set_fball_dy(float dy) { fBallDY = dy; }
	void  set_fball_dx(float dx) { fBallDX = dx; }

	float get_ncell_dy() { return nCellOldY; }
	float get_ncell_dx() { return nCellOldX; }
	void  set_ncell_dy(float ncell_y) { nCellOldY = ncell_y; }
	void  set_ncell_dx(float ncell_x) { nCellOldX = ncell_x; }

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


class Breakout : public GameBaseClass{

public:
	Ball Ball_Obj;
	int nWidth = 16;
	int nHeight = 15;
	int nBlock = 8;//size of drawing bloks

	//bat settings
	float fBat = 64.0f;//central position
	int nBatWidth = 15;
	float fbatSpeed = 45.0f;

public:
	Breakout() {};
	Breakout(std::string input_level) : level{ input_level } { };
	~Breakout() {};
public:
	void DrawLevel(std::string level, const int nHeight, const int nWidth, const int nBlock);
	bool OnUserCreate();
	bool OnUserUpdate(float fElapsedTime);
private:
	std::string level;
	const float PI = 3.14159265359;
};



#endif
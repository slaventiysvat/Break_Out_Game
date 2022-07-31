#include "Breakout.h"
#include "engine_constants.h"
#include <string>

Ball::Ball() {
	float fAng = (static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) * PI * 2.0f;
	fAng = 0.6f;
	fBallDX = cosf(fAng);
	fBallDY = sinf(fAng);

}

 void Ball::BallMove(float fElapsedTime, int nBlock,int nWidth, int nHeight,float fBat, std::string &level) {


	int nBatWidth = 15;
	fOldX = fBallX;
	fOldY = fBallY;
	fBallX = fBallX + fBallDX * fElapsedTime * fSpeed;
	fBallY = fBallY + fBallDY * fElapsedTime * fSpeed;

    nCellOldX = static_cast<int>(fOldX) / nBlock;
	nCellOldY = static_cast<int>(fOldY) / nBlock;

	int nCellNewX = static_cast<int>(fBallX) / nBlock;
	int nCellNewY = static_cast<int>(fBallY) / nBlock;

	char newcell = level.at(nCellNewY * nWidth + nCellNewX);
	char oldcell = level.at(nCellOldY * nWidth + nCellOldX);
	//Testing Collision Ball and Level Border
	//if (newcell == '#') {

	//	if (nCellNewX != nCellOldX) {

	//		fBallDX = fBallDX * (-1.0f);

	//	}

	//	if (nCellNewY != nCellOldY) {

	//		fBallDY = fBallDY * (-1.0f);

	//	}

	//}

	if (newcell != '.') {

		if (newcell == '3') {
			level.at((static_cast<long long int>(nCellNewY) * nWidth) + nCellNewX) = '2';
			score_and_health.CurrentScore = score_and_health.CurrentScore + 15;
		}

		if (newcell == '2') {
			level.at((static_cast<long long int>(nCellNewY) * nWidth) + nCellNewX) = '1';
			score_and_health.CurrentScore = score_and_health.CurrentScore + 10;
		}

		if (newcell == '1') {
			level.at((static_cast<long long int>(nCellNewY) * nWidth) + nCellNewX) = '.';
			score_and_health.CurrentScore = score_and_health.CurrentScore + 5;
		}

		if (nCellNewX != nCellOldX) { fBallDX = fBallDX * (-1.0f); }
		if (nCellNewY != nCellOldY) { fBallDY = fBallDY * (-1.0f); }

	}


	//Ball with Platform 
	if (fBallY > (nHeight * nBlock - 3))
	{
		if ((fBallX > (fBat - nBatWidth)) && (fBallX < (fBat + nBatWidth))) {

			fBallDY = fBallDY * (-1.0f);
			//fBallDX = fBallDX * (-1.0f);
			//std::cout << "nice job" << std::endl;
		}
		else {

			//Life minus
			score_and_health.CurrenHealth = 1;
			//Ball Respawn on Middle of the Screen
			fBallX = (nWidth / 2.0f) * nBlock;
			fBallY = (nHeight / 2.0f) * nBlock;
			//Change random angle
			float fAng = (static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) * PI * 2.0f;//New angle after meeting each other
			//fAng = 0.6f;
			fBallDX = cosf(fAng);
			fBallDY = sinf(fAng);
			//std::cout << "you dead" << std::endl;
		}
	}

}

//void  Ball::update_ball_state(ball_coordinates new_state) {
//
//	Ball::fBallDX = new_state.ball_dx;
//	Ball::fBallDY = new_state.ball_dy;
//	Ball::fBallX = new_state.ball_x;
//	Ball::fBallY = new_state.ball_y;
//	//Ball::fOldX = new_state.ball_old_dx;
//	//Ball::fOldY = new_state.ball_old_dy;
//}

bool Breakout::OnUserCreate() {
	//	

	//Ball Ball_Obj;

	float fAng = (static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) * PI * 2.0f;
	fAng = 0.6f;
	Ball_Obj.set_fball_dx(cosf(fAng));
	Ball_Obj.set_fball_dy(sinf(fAng));

	return true;
}

bool Breakout::OnUserDestroy() {

	//GameBaseClass::CloseHandler(CTRL_CLOSE_EVENT);

	//Breakout::level = "################";
	//		  level += "#...Level Was...#";
	//		  level += "#...Finished....#";
	//		  level += "#..Your Score...#";
	//		  level += "#.."+ std::to_string(Score) +"..#";
	//		  level += "#...11111111...#";
	//		  level += "#...11111111...#";
	//		  level += "#..............#";
	//		  level += "#..............#";
	//		  level += "#..............#";
	//		  level += "#..............#";
	//		  level += "#..............#";
	//		  level += "#..............#";
	//		  level += "#..............#";
	//		  level += "................";


	return true;

}

bool Breakout::OnUserUpdate(float fElapsedTime) {

	Fill(0, 0, ScreenWidth(), ScreenHeight(), L' ');

	//Physics of Elements
	//---------------------------------------------------------------------
	//Platform Moving
	if (GetKey(VK_LEFT).bHeld) { fBat = fBat - fbatSpeed * fElapsedTime; }
	if (GetKey(VK_RIGHT).bHeld) { fBat = fBat + fbatSpeed * fElapsedTime; }

	//if ((fBat - nBatWidth) < nBlock) {

	//	fBat = nBlock + nBatWidth;

	//}

	//if ((fBat + nBatWidth) > (nWidth * nBlock)) {

	//	fBat = nWidth * nBlock - nBatWidth;

	//}
	//Ball Moving
	Ball_Obj.BallMove(fElapsedTime, nBlock,nWidth,nHeight, fBat, level);

	Health = Health - Ball_Obj.get_health();

	Score = Ball_Obj.get_score();

	//if (Health < 1)
	//{
	//	//CloseHandler(CTRL_CLOSE_EVENT);
	//	OnUserDestroy();
	//	return true;
	//}

	//Drawing Elements
	// -------------------------------------------------------------------
	//Draw Level;
	DrawLevel(Breakout::level, Breakout::nHeight, Breakout::nWidth, Breakout::nBlock);
	//DrawLevel(level_3, Breakout::nHeight, Breakout::nWidth, Breakout::nBlock);

	//BallDrawing
	FillCircle(Ball_Obj.get_fball_x(), Ball_Obj.get_fball_y(), 2.0f, PIXEL_SOLID, FG_BLUE);

	//Platform Drawing
	DrawLine(fBat - nBatWidth, nHeight * nBlock - 2, fBat + nBatWidth, nHeight * nBlock - 2, PIXEL_SOLID, FG_WHITE);

	return true;
}

void  Breakout::DrawLevel(std::string level,const int nHeight, const int nWidth, const int nBlock) {

	//Breakout::Fill(x * nBlock, y * nBlock, (x + 1) * nBlock, (y + 1) * nBlock, PIXEL_SOLID, FG_WHITE);

	for (int y = 0; y < nHeight; y++) {

		for (int x = 0; x < nWidth; x++) {

			char one_symbol = level.at((y * nWidth) + x);

			switch (one_symbol) {
			case '#':
				Fill(x * nBlock, y * nBlock, (x + 1) * nBlock, (y + 1) * nBlock, PIXEL_SOLID, FG_WHITE);
				break;

			case '1'://Block type 1
				Fill(x * nBlock, y * nBlock, (x + 1) * nBlock, (y + 1) * nBlock, PIXEL_SOLID, FG_DARK_YELLOW);
				break;

			case '2'://Block type 2
				Fill(x * nBlock, y * nBlock, (x + 1) * nBlock, (y + 1) * nBlock, PIXEL_SOLID, FG_DARK_CYAN);
				break;

			case '3'://Block type 3
				Fill(x * nBlock, y * nBlock, (x + 1) * nBlock, (y + 1) * nBlock, PIXEL_SOLID, FG_DARK_GREEN);
				break;

			case '.':
				Fill(x * nBlock, y * nBlock, (x + 1) * nBlock, (y + 1) * nBlock, PIXEL_SOLID, FG_BLACK);
				break;
			}

		}

	}

}


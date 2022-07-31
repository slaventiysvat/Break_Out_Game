#include "Breakout.h"
#include "engine_constants.h"

std::string level_test_bounce;
std::string level_1;
std::string level_2;
std::string level_3;


Ball::Ball() {
	float fAng = (static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) * PI * 2.0f;
	fAng = 0.6f;
	fBallDX = cosf(fAng);
	fBallDY = sinf(fAng);
}

ball_coordinates Ball::BallMove(float fElapsedTime, int nBlock,int nWidth, std::string level) {

	ball_coordinates out_coord;

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
	if (newcell == '#') {

		if (nCellNewX != nCellOldX) {

			fBallDX = fBallDX * (-1.0f);

		}

		if (nCellNewY != nCellOldY) {

			fBallDY = fBallDY * (-1.0f);

		}

	}

	out_coord.ball_x = fBallX;
	out_coord.ball_y = fBallY;

	return out_coord;
}


bool Brekout::OnUserCreate() {
	//	

	level_test_bounce = "################";
	level_test_bounce += "#..............#";
	level_test_bounce += "#..............#";
	level_test_bounce += "#..............#";
	level_test_bounce += "#..............#";
	level_test_bounce += "#..............#";
	level_test_bounce += "#..............#";
	level_test_bounce += "#..............#";
	level_test_bounce += "#..............#";
	level_test_bounce += "#..............#";
	level_test_bounce += "#..............#";
	level_test_bounce += "#..............#";
	level_test_bounce += "#..............#";
	level_test_bounce += "#..............#";
	level_test_bounce += "################";

	level_1 =  "################";
	level_1 += "#...11111111...#";
	level_1 += "#..............#";
	level_1 += "#...22222222...#";
	level_1 += "#..............#";
	level_1 += "#..............#";
	level_1 += "#...33333333...#";
	level_1 += "#..............#";
	level_1 += "#..............#";
	level_1 += "#..............#";
	level_1 += "#..............#";
	level_1 += "#..............#";
	level_1 += "#..............#";
	level_1 += "#..............#";
	level_1 += "#..............#";

	level_2 = "################";
	level_2 += "#...11111111...#";
	level_2 += "#..............#";
	level_2 += "#...12121212...#";
	level_2 += "#..............#";
	level_2 += "#..............#";
	level_2 += "#...13212313...#";
	level_2 += "#..............#";
	level_2 += "#..............#";
	level_2 += "#..............#";
	level_2 += "#..............#";
	level_2 += "#..............#";
	level_2 += "#..............#";
	level_2 += "#..............#";
	level_2 += "#..............#";

	level_3 = "################";
	level_3 += "#...33333333...#";
	level_3 += "#...11111111...#";
	level_3 += "#...32211223...#";
	level_3 += "#...11111111...#";
	level_3 += "#...11111111...#";
	level_3 += "#...11111111...#";
	level_3 += "#..............#";
	level_3 += "#..............#";
	level_3 += "#..............#";
	level_3 += "#..............#";
	level_3 += "#..............#";
	level_3 += "#..............#";
	level_3 += "#..............#";
	level_3 += "#..............#";

	//Ball Ball_Obj;

	return true;
}




bool Brekout::OnUserUpdate(float fElapsedTime) {

	Fill(0, 0, ScreenWidth(), ScreenHeight(), L' ');

	//Physics of Elements
	//---------------------------------------------------------------------
	//Platform Moving
	if (GetKey(VK_LEFT).bHeld) { fBat = fBat - fbatSpeed * fElapsedTime; }
	if (GetKey(VK_RIGHT).bHeld) { fBat = fBat + fbatSpeed * fElapsedTime; }

	//Ball Moving
	ball_coordinates coordinantes_ball = Ball_Obj.BallMove(fElapsedTime, nBlock, Brekout::nWidth,level_test_bounce);

	//Drawing Elements
	// -------------------------------------------------------------------
	//Draw Level;
	DrawLevel(level_test_bounce, Brekout::nHeight, Brekout::nWidth, Brekout::nBlock);
	//DrawLevel(level_3, Brekout::nHeight, Brekout::nWidth, Brekout::nBlock);

	//BallDrawing
	FillCircle(coordinantes_ball.ball_x, coordinantes_ball.ball_y, 2.0f, PIXEL_SOLID, FG_BLUE);

	//Platform Drawing
	DrawLine(fBat - nBatWidth, nHeight * nBlock - 2, fBat + nBatWidth, nHeight * nBlock - 2, PIXEL_SOLID, FG_WHITE);

	return true;
}

void  Brekout::DrawLevel(std::string level,const int nHeight, const int nWidth, const int nBlock) {

	//Brekout::Fill(x * nBlock, y * nBlock, (x + 1) * nBlock, (y + 1) * nBlock, PIXEL_SOLID, FG_WHITE);

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


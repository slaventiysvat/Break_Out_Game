#include "Breakout.h"
#include "engine_constants.h"

std::string level_1;
std::string level_2;
std::string level_3;

bool Brekout::OnUserCreate() {
	//	
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

	return true;
}

bool Brekout::OnUserUpdate(float fElapsedTime) {

	Fill(0, 0, ScreenWidth(), ScreenHeight(), L' ');
	//Draw Level;
	DrawLevel(level_3, Brekout::nHeight, Brekout::nWidth, Brekout::nBlock);

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


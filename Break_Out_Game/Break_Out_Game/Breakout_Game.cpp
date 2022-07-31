// Break_Out_Game.cpp: определяет точку входа для приложения.
//

#include "Breakout_Game.h"
#include "Breakout.h"
#include "GameBaseClass.h"
//#include ""
//using namespace std;

static const int Levels = 3;
static const int Lives = 5;

std::string level_test_bounce;
std::string level_1;
std::string level_2;
std::string level_3;

int main()
{

	level_test_bounce =  "################";
	level_test_bounce += "#..............#";
	level_test_bounce += "#...332111323..#";
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

	level_1 = "################";
	level_1 += "#...33111111...#";
	level_1 += "#...33122133...#";
	level_1 += "#..............#";
	level_1 += "#..............#";
	level_1 += "#..............#";
	level_1 += "#..............#";
	level_1 += "#..............#";
	level_1 += "#..............#";
	level_1 += "#..............#";
	level_1 += "#..............#";
	level_1 += "#..............#";
	level_1 += "#..............#";
	level_1 += "#..............#";
	level_1 += "................";

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
	level_2 += "................";

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
	level_3 += "................";

	std::cout << "Hello CMake." << std::endl;

	//Brekout Game_Breakout(level_test_bounce);
	Breakout Game_Breakout(level_1);
	Game_Breakout.ConstructConsole(256, 240, 4, 4);
	Game_Breakout.Start();



	return 0;
}

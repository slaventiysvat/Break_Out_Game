// Break_Out_Game.cpp: определяет точку входа для приложения.
//

#include "Break_Out_Game.h"
#include "Breakout.h"
#include "olcConsoleGameEngine.h"
//#include ""
//using namespace std;

static const int Levels = 3;
static const int Lives = 5;



int main()
{
	std::cout << "Hello CMake." << std::endl;

	Brekout Game_Breakout;
	Game_Breakout.ConstructConsole(256, 240, 4, 4);
	Game_Breakout.Start();



	return 0;
}

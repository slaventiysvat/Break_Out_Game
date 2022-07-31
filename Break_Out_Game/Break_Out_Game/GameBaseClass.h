/*
OneLoneCoder.com - Command Line Game Engine
"Who needs a frame buffer?" - @Javidx9

Disclaimer
~~~~~~~~~~
I don't care what you use this for. It's intended to be educational, and perhaps
to the oddly minded - a little bit of fun. Please hack this, change it and use it
in any way you see fit. BUT, you acknowledge that I am not responsible for anything
bad that happens as a result of your actions. However, if good stuff happens, I
would appreciate a shout out, or at least give the blog some publicity for me.
Cheers!

Background
~~~~~~~~~~
If you've seen any of my videos - I like to do things using the windows console. It's quick
and easy, and allows you to focus on just the code that matters - ideal when you're
experimenting. Thing is, I have to keep doing the same initialisation and display code
each time, so this class wraps that up.

Author
~~~~~~
Twitter: @javidx9 http://twitter.com/javidx9
Blog: http://www.onelonecoder.com
YouTube: http://www.youtube.com/javidx9

Videos:
~~~~~~
Original:				https://youtu.be/cWc0hgYwZyc
Added mouse support:	https://youtu.be/tdqc9hZhHxM
Beginners Guide:		https://youtu.be/u5BhrA8ED0o

Shout Outs!
~~~~~~~~~~~
Thanks to cool people who helped with testing, bug-finding and fixing!
wowLinh, JavaJack59, idkwid, kingtatgi, Return Null

Last Updated: 04/02/2018

Usage:
~~~~~~
This class is abstract, so you must inherit from it. Override the OnUserCreate() function
with all the stuff you need for your application (for thready reasons it's best to do
this in this function and not your class constructor). Override the OnUserUpdate(float fElapsedTime)
function with the good stuff, it gives you the elapsed time since the last call so you
can modify your stuff dynamically. Both functions should return true, unless you need
the application to close.

	int main()
	{
		// Use olcConsoleGameEngine derived app
		OneLoneCoder_Example game;

		// Create a console with resolution 160x100 characters
		// Each character occupies 8x8 pixels
		game.ConstructConsole(160, 100, 8, 8);

		// Start the engine!
		game.Start();

		return 0;
	}

Input is also handled for you - interrogate the m_keys[] array with the virtual
keycode you want to know about. bPressed is set for the frame the key is pressed down
in, bHeld is set if the key is held down, bReleased is set for the frame the key
is released in. The same applies to mouse! m_mousePosX and Y can be used to get
the current cursor position, and m_mouse[1..5] returns the mouse buttons.

The draw routines treat characters like pixels. By default they are set to white solid
blocks - but you can draw any unicode character, using any of the colours listed below.

There may be bugs!

See my other videos for examples!
http://www.youtube.com/javidx9

Lots of programs to try:
http://www.github.com/OneLoneCoder/videos

Chat on the Discord server:
https://discord.gg/WhwHUMV

Be bored by Twitch:
http://www.twitch.tv/javidx9

*/

//#pragma once

#ifndef UNICODE
#error Please enable UNICODE for your compiler! VS: Project Properties -> General -> \
Character Set -> Use Unicode. Thanks! - Javidx9
#endif

#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <thread>
#include <atomic>
#include <condition_variable>
using namespace std;

#include <windows.h>
#include "SpriteClass.h"
#include "engine_constants.h"


#ifndef CONSOLE_GAME_ENGINE
#define CONSOLE_GAME_ENGINE

class GameBaseClass
{
public:
	GameBaseClass();
	
	int ConstructConsole(int width, int height, int fontw, int fonth);
	
	virtual void Draw(int x, int y, wchar_t c = 0x2588, short col = 0x000F);
	
	void Fill(int x1, int y1, int x2, int y2, wchar_t c = 0x2588, short col = 0x000F);

	void DrawString(int x, int y, wstring c, short col = 0x000F);

	void DrawStringAlpha(int x, int y, wstring c, short col = 0x000F);

	void Clip(int& x, int& y);

	void DrawLine(int x1, int y1, int x2, int y2, wchar_t c = 0x2588, short col = 0x000F);

	void DrawCircle(int xc, int yc, int r, wchar_t c = 0x2588, short col = 0x000F);

	void FillCircle(int xc, int yc, int r, wchar_t c = 0x2588, short col = 0x000F);

	void DrawSprite(int x, int y, SpriteClass* sprite);

	void DrawPartialSprite(int x, int y, SpriteClass* sprite, int ox, int oy, int w, int h);

	void DrawWireFrameModel(const vector<pair<float, float>>& vecModelCoordinates, float x, float y, float r = 0.0f, float s = 1.0f, short col = FG_WHITE);

	~GameBaseClass();

public:
	void Start();

	int ScreenWidth();

	int ScreenHeight();

private:
	void GameThread();

public:
	// User MUST OVERRIDE THESE!!
	virtual bool OnUserCreate() = 0;
	virtual bool OnUserUpdate(float fElapsedTime) = 0;
	// Optional for clean up 
	virtual bool OnUserDestroy();

protected:

	struct sKeyState
	{
		bool bPressed;
		bool bReleased;
		bool bHeld;
	} m_keys[256], m_mouse[5];

	int m_mousePosX;
	int m_mousePosY;

public:
	sKeyState GetKey(int nKeyID);
	int GetMouseX();
	int GetMouseY();
	sKeyState GetMouse(int nMouseButtonID);
	bool IsFocused();


protected:
	int Error(const wchar_t* msg);
	static BOOL CloseHandler(DWORD evt);

protected:
	int m_nScreenWidth;
	int m_nScreenHeight;
	CHAR_INFO* m_bufScreen;
	wstring m_sAppName;
	HANDLE m_hOriginalConsole;
	CONSOLE_SCREEN_BUFFER_INFO m_OriginalConsoleInfo;
	HANDLE m_hConsole;
	HANDLE m_hConsoleIn;
	SMALL_RECT m_rectWindow;
	short m_keyOldState[256] = { 0 };
	short m_keyNewState[256] = { 0 };
	bool m_mouseOldState[5] = { 0 };
	bool m_mouseNewState[5] = { 0 };
	bool m_bConsoleInFocus = true;

};

#endif /*CONSILE_GAME_ENGINE*/
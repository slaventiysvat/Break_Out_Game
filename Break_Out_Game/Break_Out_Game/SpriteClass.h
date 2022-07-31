#pragma once
#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <thread>
#include <atomic>
#include <condition_variable>
using namespace std;

#include <windows.h>
#include "engine_constants.h"
class SpriteClass
{
public:
	SpriteClass();
	SpriteClass(int w, int h);

	SpriteClass(wstring sFile);

	int nWidth = 0;
	int nHeight = 0;

private:
	wchar_t* m_Glyphs = nullptr;
	short* m_Colours = nullptr;
	void Create(int w, int h);
	

public:
	void SetGlyph(int x, int y, wchar_t c);

	void SetColour(int x, int y, short c);

	wchar_t GetGlyph(int x, int y);

	short GetColour(int x, int y);

	wchar_t SampleGlyph(float x, float y);

	short SampleColour(float x, float y);

	bool Save(wstring sFile);

	bool Load(wstring sFile);
};
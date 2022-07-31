#include "SpriteClass.h"

SpriteClass::SpriteClass()
{

}

SpriteClass::SpriteClass(int w, int h)
{
	Create(w, h);
}

SpriteClass::SpriteClass(wstring sFile)
{
	if (!Load(sFile))
		Create(8, 8);
}


void SpriteClass::Create(int w, int h)
{
	nWidth = w;
	nHeight = h;
	m_Glyphs = new wchar_t[w * h];
	m_Colours = new short[w * h];
	for (int i = 0; i < w * h; i++)
	{
		m_Glyphs[i] = L' ';
		m_Colours[i] = FG_BLACK;
	}
}


void SpriteClass::SetGlyph(int x, int y, wchar_t c)
{
	if (x < 0 || x >= nWidth || y < 0 || y >= nHeight)
		return;
	else
		m_Glyphs[y * nWidth + x] = c;
}

void SpriteClass::SetColour(int x, int y, short c)
{
	if (x < 0 || x >= nWidth || y < 0 || y >= nHeight)
		return;
	else
		m_Colours[y * nWidth + x] = c;
}

wchar_t SpriteClass::GetGlyph(int x, int y)
{
	if (x < 0 || x >= nWidth || y < 0 || y >= nHeight)
		return L' ';
	else
		return m_Glyphs[y * nWidth + x];
}

short SpriteClass::GetColour(int x, int y)
{
	if (x < 0 || x >= nWidth || y < 0 || y >= nHeight)
		return FG_BLACK;
	else
		return m_Colours[y * nWidth + x];
}

wchar_t SpriteClass::SampleGlyph(float x, float y)
{
	int sx = (int)(x * (float)nWidth);
	int sy = (int)(y * (float)nHeight - 1.0f);
	if (sx < 0 || sx >= nWidth || sy < 0 || sy >= nHeight)
		return L' ';
	else
		return m_Glyphs[sy * nWidth + sx];
}

short SpriteClass::SampleColour(float x, float y)
{
	int sx = (int)(x * (float)nWidth);
	int sy = (int)(y * (float)nHeight - 1.0f);
	if (sx < 0 || sx >= nWidth || sy < 0 || sy >= nHeight)
		return FG_BLACK;
	else
		return m_Colours[sy * nWidth + sx];
}

bool SpriteClass::Save(wstring sFile)
{
	FILE* f = nullptr;
	_wfopen_s(&f, sFile.c_str(), L"wb");
	if (f == nullptr)
		return false;

	fwrite(&nWidth, sizeof(int), 1, f);
	fwrite(&nHeight, sizeof(int), 1, f);
	fwrite(m_Colours, sizeof(short), nWidth * nHeight, f);
	fwrite(m_Glyphs, sizeof(wchar_t), nWidth * nHeight, f);

	fclose(f);

	return true;
}

bool SpriteClass::Load(wstring sFile)
{
	delete[] m_Glyphs;
	delete[] m_Colours;
	nWidth = 0;
	nHeight = 0;

	FILE* f = nullptr;
	_wfopen_s(&f, sFile.c_str(), L"rb");
	if (f == nullptr)
		return false;

	fread(&nWidth, sizeof(int), 1, f);
	fread(&nHeight, sizeof(int), 1, f);

	Create(nWidth, nHeight);

	fread(m_Colours, sizeof(short), nWidth * nHeight, f);
	fread(m_Glyphs, sizeof(wchar_t), nWidth * nHeight, f);

	fclose(f);
	return true;
}
#pragma once

#include <Windows.h>
#include <d2d1.h>
#include <string>

class Graphics
{
public:
	Graphics();
	~Graphics();

	bool Init(HWND windowHandle);
	void BeginDraw();
	void EndDraw();

	void ClearScreen(float r, float g, float b);
	void DrawRectangle(float x, float y, float h, float w, float r, float g, float b, float a, float t);
	void FillRectangle(float x, float y, float h, float w, float r, float g, float b, float a);
	void DrawTextBox(float x, float y, std::string s);

private:
	ID2D1Factory* mFactory;
	ID2D1HwndRenderTarget* mRenderTarget;
};


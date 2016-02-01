#include "Graphics.h"
#include <dwrite.h>


Graphics::Graphics()
{
	mFactory = nullptr;
	mRenderTarget = nullptr;
}


Graphics::~Graphics()
{
	if (mFactory != nullptr)
	{
		mFactory->Release();
	}
	if (mRenderTarget != nullptr)
	{
		mRenderTarget->Release();
	}
}

bool Graphics::Init(HWND windowHandle)
{
	HRESULT result = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &mFactory);
	if (result != S_OK)
	{
		return false;
	}

	RECT rect;
	GetClientRect(windowHandle, &rect);

	result = mFactory->CreateHwndRenderTarget(D2D1::RenderTargetProperties(), D2D1::HwndRenderTargetProperties(windowHandle, D2D1::SizeU(rect.right, rect.bottom)), &mRenderTarget);

	if (result != S_OK)
	{
		return false;
	}

	return true;
}

void Graphics::BeginDraw()
{
	mRenderTarget->BeginDraw();
}

void Graphics::EndDraw()
{
	mRenderTarget->EndDraw();
}

void Graphics::ClearScreen(float r, float g, float b)
{
	mRenderTarget->Clear(D2D1::ColorF(r, g, b));
}


void Graphics::DrawRectangle(float x, float y, float h, float w, float r, float g, float b, float a, float t)
{
	ID2D1SolidColorBrush *brush;
	mRenderTarget->CreateSolidColorBrush(D2D1::ColorF(r, g, b, a), &brush);

	mRenderTarget->DrawRectangle(D2D1::Rect(x, y, x + w, y + h), brush, 2.0F);

	brush->Release();
}

void Graphics::FillRectangle(float x, float y, float h, float w, float r, float g, float b, float a)
{
	ID2D1SolidColorBrush *brush;
	mRenderTarget->CreateSolidColorBrush(D2D1::ColorF(r, g, b, a), &brush);

	mRenderTarget->FillRectangle(D2D1::Rect(x, y, x + w, y + h), brush);

	brush->Release();
}

void Graphics::DrawTextBox(float x, float y, std::string s)
{
	IDWriteTextFormat *format;
	IDWriteFactory* IDWriteFactory = NULL;
	IDWriteTextFormat* ITextFormat = NULL;
	ID2D1SolidColorBrush* brush = NULL;

	HRESULT result = DWriteCreateFactory(DWRITE_FACTORY_TYPE_ISOLATED, __uuidof(IDWriteFactory), reinterpret_cast<IUnknown**>(&IDWriteFactory));

	if (SUCCEEDED(result))
	{
		result = IDWriteFactory->CreateTextFormat(
			L"Arial",
			NULL,
			DWRITE_FONT_WEIGHT_NORMAL,
			DWRITE_FONT_STYLE_NORMAL,
			DWRITE_FONT_STRETCH_NORMAL,
			10.0f * 96.0f / 72.0f,
			L"en-US",
			&ITextFormat
			);
	}

	if (SUCCEEDED(result))
	{
		mRenderTarget->CreateSolidColorBrush(D2D1::ColorF(0.0f, 0.0f, 0.0f, 1.0f), &brush);
	}

	D2D1_RECT_F layoutRect = D2D1::RectF(x, y, x + 100, y + 100);

	// Actually draw the text at the origin.
	if (SUCCEEDED(result))
	{
		std::wstring widestr = std::wstring(s.begin(), s.end());

		mRenderTarget->DrawText(
			widestr.c_str(),
			s.size(),
			ITextFormat,
			layoutRect,
			brush
			);
	}
	// Clean up.
	brush->Release();
	ITextFormat->Release();
	IDWriteFactory->Release();


}

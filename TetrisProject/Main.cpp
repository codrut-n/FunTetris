#include <Windows.h>
#include "Graphics.h"
#include "GameController.h"
#include "GameConstants.cpp"
#include <ctime>

Graphics* graphics;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	srand(time(NULL));

	WNDCLASSEX windowClass;
	ZeroMemory(&windowClass, sizeof(WNDCLASSEX));
	windowClass.cbSize = sizeof(WNDCLASSEX);
	windowClass.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_WINDOW);
	windowClass.hInstance = hInstance;
	windowClass.lpfnWndProc = WindowProc;
	windowClass.lpszClassName = "MainWindow";
	windowClass.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClassEx(&windowClass);
	
	RECT rect = { 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT };
	AdjustWindowRectEx(&rect, WS_OVERLAPPEDWINDOW, false, WS_EX_OVERLAPPEDWINDOW);

	HWND windowHandle = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, windowClass.lpszClassName, "Codrut Niculescu's Tetris Project", WS_OVERLAPPEDWINDOW, 100, 100, (rect.right-rect.left), (rect.bottom-rect.top), NULL, NULL, hInstance, NULL);

	if (windowHandle == NULL)
	{
		return -1;
	}

	graphics = new Graphics();

	if (graphics->Init(windowHandle) == false)
	{
		delete graphics;
		return -1;
	}


	ShowWindow(windowHandle, nCmdShow);

	MSG message;
	message.message = WM_NULL;

	GameController::Init();

	while (message.message != WM_QUIT)
	{
		if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
		{
			DispatchMessage(&message);
		}
		else
		{
			GameController::Update();
			// Render!
			graphics->BeginDraw();

			GameController::Render(graphics);

			graphics->EndDraw();

			GameController::FinishedBlock();

			
		}
	}
	delete graphics;

	return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if (uMsg == WM_DESTROY)
	{
		PostQuitMessage(0);
		return 0;
	}
	else if (uMsg == WM_KEYDOWN)
	{
		if (wParam == VK_LEFT)
		{
			GameController::Left();
		}
		else if (wParam == VK_RIGHT)
		{
			GameController::Right();
		}
		else if (wParam == VK_DOWN)
		{
			GameController::Drop();
		}
		else if (wParam == VK_UP)
		{
			GameController::Up();
		}
		else if (wParam == VK_SPACE)
		{
			//GameController::Pause();
		}
	}
	
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
	
}
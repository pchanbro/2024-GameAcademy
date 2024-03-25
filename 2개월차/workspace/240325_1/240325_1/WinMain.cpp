#include "pch.h"

HINSTANCE _hInstance;
HWND _hWnd;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
void SetWindowSize(int x, int y, int width, int hight);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	_hInstance = hInstance;
	
	WNDCLASS wndClass = {};

	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hbrBackground = (HBRUSH)GetStockObject(DKGRAY_BRUSH);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hInstance = _hInstance;
	wndClass.lpfnWndProc = (WNDPROC)WndProc;
	wndClass.lpszClassName = _T("SBS Academy");
	wndClass.lpszMenuName = NULL;
	wndClass.style = CS_HREDRAW | CS_VREDRAW;

	::RegisterClass(&wndClass);

	_hWnd = CreateWindow(
		_T("SBS Academy")
		, _T("SBS Academy")
		, WS_CAPTION | WS_SYSMENU
		, 0
		, 0
		, 800
		, 600
		, NULL
		, NULL
		, _hInstance
		, NULL
	);

	SetWindowSize(0, 0, 800, 600);

	::ShowWindow(_hWnd, nCmdShow);

	MSG message;
	while (true)
	{
		if (::PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
		{
			::TranslateMessage(&message);
			::DispatchMessage(&message);
		}
		else
		{

		}
	}

	return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}

	return 0;
}

void SetWindowSize(int x, int y, int width, int hight)
{
	RECT rc;
	rc.left = 0;
	rc.right = width;
	rc.top = 0;
	rc.bottom = hight;

	AdjustWindowRect(&rc, WS_CAPTION | WS_SYSMENU, false);

	SetWindowPos(_hWnd, NULL, x, y, rc.right - rc.left, rc.bottom - rc.top, SWP_NOZORDER | SWP_NOMOVE);
}

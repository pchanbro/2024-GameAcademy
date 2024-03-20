//=========================================
//		## 헤더파일 선언 ##
//=========================================

#include "pch.h"

//=========================================
//		## 전역변수 선언 ##
//=========================================

HINSTANCE _hInstance;
HWND _hWnd;

//=========================================
//		## 함수 전방 선언 ##
//=========================================
LRESULT CALLBACK Wnproc(HWND hWnd, UNIT message, WPARAM wParam LPARAM lParam);
void SetWindowSize(int x, int y, int width, int height);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, char* lpszCmParam, int nCmdShow)
{
	return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UNIT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{

	}
}
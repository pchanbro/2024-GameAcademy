//=========================================
//		## ������� ���� ##
//=========================================

#include "pch.h"

//=========================================
//		## �������� ���� ##
//=========================================

HINSTANCE _hInstance;
HWND _hWnd;

//=========================================
//		## �Լ� ���� ���� ##
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
#pragma once
//���� ���������, ���ֺ������ �ʴ� ������� ���ԵǴ� ���

//Windows API ��� �ϴ°�, 
//Windows �Լ��� ����Ѵٶ�� �ǹ̿���
//<windowsx.h> ,  <Windows.h> ���⿡ ����ִ� �Լ�����
// Windows API �Լ��Դϴ�.
#include <Windows.h>
#include <windowsx.h>

//===========================================
//		## C++ ���� �Լ� ##
//===========================================
#include <iostream>
#include <algorithm>

#include <string>
#include <tchar.h>

//===========================================
//		## �ڷ� ���� ##
//===========================================
#include <vector>
#include <unordered_map>
#include <map>

//===========================================
//		## NAMESPACE ##
//===========================================
using namespace std;


//===========================================
//		## ���� ���� ���� ##
//===========================================
extern HINSTANCE _hInstance;	// instance => ���α׷�(�ν��Ͻ�) ��ü
extern HWND _hWnd;				// wnd => ������ ��ü

#pragma once

#include "framework.h"

//===========================================
//		## WindowsGame Ŀ���� ��� ##
//===========================================
#include "Defines.h"
#include "Types.h"
#include "Enums.h"
#include "CommonFunction.h"


#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")

//===========================================
//		## C++ ���� �Լ� ##
//===========================================
#include <iostream>
#include <algorithm>

#include <string>
#include <tchar.h>
#include <format>

//===========================================
//		## �ڷ� ���� ##
//===========================================
#include <vector>
#include <unordered_map> // Map�� c#���� Dictionary, Map�� (key, value) ���� �̷�� ���� ���, binary tree���� Ʈ�����¸� ����ϴµ�, key�� ��ü�Ѵ�. 
#include <unordered_set> // binary tree�� ����, Map���� key, value�� �ϳ����� �ִ°� �� key�� value�ΰ�
#include <map>
#include <set>

//===========================================
//		## NAMESPACE ##
//===========================================
using namespace std;

//===========================================
//		## �̱��� ##
//===========================================
#include "TimeManager.h"	// Time
#include "InputManager.h"	// Input
#include "SceneManager.h"	// ��� ���� 2��ó�� define�� ������ �ʾҴ�.

//===========================================
//		## ���� ���� ���� ##
//===========================================
extern HINSTANCE _hInstance;	// instance => ���α׷�(�ν��Ͻ�) ��ü
extern HWND _hWnd;				// wnd => ������ ��ü
// extern POINT _moustPos;			// ���콺 ��ǥ 240401 InputManager�� �߰��� �̺κ��� �Ⱦ���
// �� �ȿ� ���콺�� �ٷ�°� �־ ����
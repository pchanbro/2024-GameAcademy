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
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>

//===========================================
//		## NAMESPACE ##
//===========================================
using namespace std;


//===========================================
//		## �̱��� ##
//===========================================
#include "TimeManager.h"	//Time
#include "InputManager.h"	//Input
#include "SceneManager.h"
#include "CollisionManager.h"
#include "ResourceManager.h"
#include "RandomManager.h"

//===========================================
//		## ������ ������ ##
//===========================================
#define WIN_SIZE_X 850
#define WIN_SIZE_Y 567

//===========================================
//		## ���� ���� ���� ##
//===========================================
extern HINSTANCE _hInstance;	// instance => ���α׷�(�ν��Ͻ�) ��ü
extern HWND _hWnd;				// wnd => ������ ��ü

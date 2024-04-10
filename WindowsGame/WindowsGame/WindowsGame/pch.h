#pragma once

#include "framework.h"

//===========================================
//		## WindowsGame 커스텀 헤더 ##
//===========================================
#include "Defines.h"
#include "Types.h"
#include "Enums.h"
#include "CommonFunction.h"


#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")

//===========================================
//		## C++ 관련 함수 ##
//===========================================
#include <iostream>
#include <algorithm>

#include <string>
#include <tchar.h>
#include <format>

//===========================================
//		## 자료 구조 ##
//===========================================
#include <vector>
#include <unordered_map> // Map은 c#에선 Dictionary, Map은 (key, value) 쌍을 이루어 만든 노드, binary tree같은 트리형태를 사용하는데, key로 대체한다. 
#include <unordered_set> // binary tree와 같다, Map에서 key, value가 하나씩만 있는것 즉 key가 value인것
#include <map>
#include <set>

//===========================================
//		## NAMESPACE ##
//===========================================
using namespace std;

//===========================================
//		## 싱글톤 ##
//===========================================
#include "TimeManager.h"	// Time
#include "InputManager.h"	// Input
#include "SceneManager.h"	// 얘는 위의 2개처럼 define을 만들진 않았다.

//===========================================
//		## 전역 변수 선언 ##
//===========================================
extern HINSTANCE _hInstance;	// instance => 프로그램(인스턴스) 객체
extern HWND _hWnd;				// wnd => 윈도우 객체
// extern POINT _moustPos;			// 마우스 좌표 240401 InputManager의 추가로 이부분은 안쓴다
// 그 안에 마우스를 다루는게 있어서 제거
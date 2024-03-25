#pragma once
//자주 사용하지만, 자주변경되지 않는 내용들이 포함되는 헤더

//Windows API 라고 하는게, 
//Windows 함수를 사용한다라는 의미에요
//<windowsx.h> ,  <Windows.h> 여기에 들어있는 함수들이
// Windows API 함수입니다.
#include <Windows.h>
#include <windowsx.h>

//===========================================
//		## C++ 관련 함수 ##
//===========================================
#include <iostream>
#include <algorithm>

#include <string>
#include <tchar.h>

//===========================================
//		## 자료 구조 ##
//===========================================
#include <vector>
#include <unordered_map>
#include <map>

//===========================================
//		## NAMESPACE ##
//===========================================
using namespace std;


//===========================================
//		## 전역 변수 선언 ##
//===========================================
extern HINSTANCE _hInstance;	// instance => 프로그램(인스턴스) 객체
extern HWND _hWnd;				// wnd => 윈도우 객체

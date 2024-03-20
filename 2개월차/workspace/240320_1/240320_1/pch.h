#pragma once

// pch.h에 주로 쓰이는 내용들 적어줍니다.

// 프로젝트 - 속성 - C/C++ - 미리 컴파일된 헤더
// 사용으로 변경
// pch.h 

// pch.cpp - 속성 - C/C++ - 미리 컴파일된 헤더
// 만들기로 변경

//자주 사용하지만, 자주 변경되지 않는 내용들이 포함되는 헤더
#include <Windows.h>
#include <windowsx.h>

// c++ 관련 함수
#include <iostream>
#include <algorithm>

#include <string>
#include <tchar.h>

//===============================
//		## 자료구조 선언 ##
//===============================
#include <vector>
#include <string>
#include <unordered_map>

//===============================
//		## NAMESPACE  ##
//===============================
using namespace std;
//===============================
//		## 모듈 선언 ##
//===============================
#include "RandomModule.h"

//===============================
//		## 전역 변수 선언 ##
//===============================
extern HINSTANCE _hInstance; // instance란 프로그램 객체 그 자체다 -> 작업관리자 하나하나가 
extern HWND _hWnd; // 
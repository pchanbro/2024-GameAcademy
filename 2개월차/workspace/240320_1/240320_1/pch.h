#pragma once

// pch.h�� �ַ� ���̴� ����� �����ݴϴ�.

// ������Ʈ - �Ӽ� - C/C++ - �̸� �����ϵ� ���
// ������� ����
// pch.h 

// pch.cpp - �Ӽ� - C/C++ - �̸� �����ϵ� ���
// ������ ����

//���� ���������, ���� ������� �ʴ� ������� ���ԵǴ� ���
#include <Windows.h>
#include <windowsx.h>

// c++ ���� �Լ�
#include <iostream>
#include <algorithm>

#include <string>
#include <tchar.h>

//===============================
//		## �ڷᱸ�� ���� ##
//===============================
#include <vector>
#include <string>
#include <unordered_map>

//===============================
//		## NAMESPACE  ##
//===============================
using namespace std;
//===============================
//		## ��� ���� ##
//===============================
#include "RandomModule.h"

//===============================
//		## ���� ���� ���� ##
//===============================
extern HINSTANCE _hInstance; // instance�� ���α׷� ��ü �� ��ü�� -> �۾������� �ϳ��ϳ��� 
extern HWND _hWnd; // 
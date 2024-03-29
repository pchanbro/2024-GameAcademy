// WindowsGame.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "pch.h"
#include "WindowsGame.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE   _hInstance;	// instance => 프로그램(인스턴스) 객체
HWND        _hWnd;	    // wnd => 윈도우 객체
POINT       _mousePos;  // 마우스좌표

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    //1. 클래스 등록
    MyRegisterClass(hInstance);

    //2. 윈도우 생성
    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }


    MSG msg;

    //3. 메세지 루프
    // 마우스를 움직였냐?
    // 키보드를 눌렀냐?
    // 다른 시스템적인 무언가가 왔냐? 
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSGAME));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = nullptr;
    wcex.lpszClassName  = _T("GameClient");
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    _hInstance = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   HWND hWnd = CreateWindowW(_T("GameClient"), _T("GameClient"), WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   _hWnd = hWnd;

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
int gugudan = 1;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(_hInstance, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;


        //마우스가 움직였을때.
    case WM_MOUSEMOVE:
        _mousePos.x = GET_X_LPARAM(lParam);
        _mousePos.y = GET_Y_LPARAM(lParam);

        //_hWnd를 Rect영역(NULL이면 전체) 를 erase하고 다시 그리겠다.
        ::InvalidateRect(_hWnd, NULL, true);
        break;

    case WM_KEYDOWN:
        //VK_ 키보드 LEFT 왼쪽화살표
        if (wParam == 'A')
        {
            //1단 2단 3단
            //4단 5단 6단
            //7단 8단 9단
            printf("A를 눌렀다\n");
        }

        //최대 9단
        if (wParam == VK_RIGHT)
        {
            gugudan++;
            printf("현재 단 : %d\n", gugudan);
        }
        //최대 1단
        else if (wParam == VK_LEFT)
        {
            gugudan--;
            printf("현재 단 : %d\n", gugudan);
        }

        break;

        // 호출시점이
        // 1. 게임 시작했을떄.
        // 2. InvalidateRect를 호출하였을떄.
        //화면을 그려라.라는 메세지가 왔을때 처리하는 곳
    case WM_PAINT:
        {
            //PAINTSTRUCT : 그림도구
            //HDC : 도화지

            PAINTSTRUCT ps; 
            HDC hdc = BeginPaint(hWnd, &ps);
            
            //가장 간단한 함수
            //사각형그리기
            ::Rectangle(hdc, 100, 100, 200, 200);

            //원그리기
            ::Ellipse(hdc, 250, 250, 350, 350);

            //구구단 적기
            //Text 적기
            //strlen => _tcsclen

            //실습
            //TextOut을 한번사용해서 
            //아래처럼 출력되도록
            //2중 or 3중포문 사용
            
            //1단 2단 3단
            //4단 5단 6단
            //7단 8단 9단
            //for (int i = 0; i < 10; i++)
            {
                wchar_t str[128];
                wsprintf(str, L"%d, %d", _mousePos.x, _mousePos.y);
                ::TextOut(hdc, _mousePos.x, _mousePos.y, str, _tcsclen(str));
            }
            
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

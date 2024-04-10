#include "pch.h"
#include "Game.h"

Game::Game()
{

}
Game::~Game()
{

}

void Game::Init(HWND hwnd)
{
	this->_hwnd = hwnd;
	this->_hdc = ::GetDC(this->_hwnd);

	// 더블버퍼링
	::GetClientRect(_hwnd, &_rect);		// 윈도우핸들의 크기를 반환하겠다.

	_hdcBack = ::CreateCompatibleDC(_hdc);  // 유저에게 보이는 화면이랑 최대한 비슷하게 화면을 구성해라.
	_bmpBack = ::CreateCompatibleBitmap(_hdc, _rect.right, _rect.bottom);  // _hdc와 호환되는 비트맵 생성
	HBITMAP prev = (HBITMAP)::SelectObject(_hdcBack, _bmpBack);  // _hdcBack에 _bmp 연결
	::DeleteObject(prev);
	// 여기까지가 화면 두 개를 준비한 상태
	// 앞으로 할 것은 
	// 뒤에 있을 화면에 그림을 그리고
	// 그걸 앞에 화면에 고속복사 할 것


	// 싱글톤 초기화
	Time->Init();
	Input->Init(_hwnd);
	GET_SINGLE(SceneManager)->Init();


	GET_SINGLE(SceneManager)->ChangeScene(SceneType::Homework1Scene);
}

void Game::Updata()
{
	// 싱글톤 업데이트
	Time->Updata();
	Input->Updata();
	GET_SINGLE(SceneManager)->Update();
}

void Game::Render()
{
	//FPS 출력
	{
		uint32 fps = Time->GetFps();
		float deltaTime = Time->GetDeltaTime();

		wstring timeStr = format(L"FPS({0}), DT({1} ms)", fps, static_cast<int32>(deltaTime * 1000));
		::TextOut(_hdcBack, 0, 0, timeStr.c_str(), timeStr.length());
	}


	// 마우스좌표 출력
	{
		POINT mousePos = Input->GetMousePos();
		wstring timeStr = format(L"mouse({0}, {1})", mousePos.x, mousePos.y);
		::TextOut(_hdcBack, 0, 20, timeStr.c_str(), timeStr.length());
	}

	GET_SINGLE(SceneManager)->Render(_hdcBack);


	// 비트블릿 : 고속 복사
	// 복사 해줬으면 뒤의 화면의 내용은 지워줘야 한다. 그거까지 한 사이클!
	::BitBlt(_hdc, 0, 0, _rect.right, _rect.bottom, _hdcBack, 0, 0, SRCCOPY); // SRCCOPY = source copy
	::PatBlt(_hdcBack, 0, 0, _rect.right, _rect.bottom, WHITENESS);
	
}
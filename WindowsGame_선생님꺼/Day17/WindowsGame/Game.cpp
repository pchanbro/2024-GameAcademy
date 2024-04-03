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

	//더블버퍼링
	::GetClientRect(_hwnd, &_rect);		//윈도우핸들의 크기를 반환하겠다.

	_hdcBack = ::CreateCompatibleDC(_hdc);	//_hdc와 호환되는 화면 생성
	_bmpBack = ::CreateCompatibleBitmap(_hdc, _rect.right, _rect.bottom);	//_hdc와 호환되는 비트맵 생성
	HBITMAP prev = (HBITMAP)::SelectObject(_hdcBack, _bmpBack);	//_hdcBack에 _bmp 연결
	::DeleteObject(prev);


	//싱글톤 초기화
	GET_SINGLE(TimeManager)->Init();

}
void Game::Update()
{
	//싱글톤 업데이트
	GET_SINGLE(TimeManager)->Update();


	_x++;
}
void Game::Render()
{
	//FPS 출력
	{
		uint32 fps = GET_SINGLE(TimeManager)->GetFps();
		float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();

		wstring timeStr = format(L"FPS({0}), DT({1} ms)", fps, static_cast<int32>(deltaTime * 1000));
		::TextOut(_hdcBack, 0, 0, timeStr.c_str(), timeStr.length());
	}



	//유저에게 보이지 않는 화면에 애국가 1절 적기
	wstring str = L"동해물과 백두산이";
	::TextOut(_hdcBack, 100 + _x % 700, 100, str.c_str(), str.length());


	//비트블릿 : 고속 복사
	::BitBlt(_hdc, 0, 0, _rect.right, _rect.bottom, _hdcBack, 0, 0, SRCCOPY);
	::PatBlt(_hdcBack, 0, 0, _rect.right, _rect.bottom, WHITENESS);
}
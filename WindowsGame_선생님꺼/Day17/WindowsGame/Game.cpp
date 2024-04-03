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

	//������۸�
	::GetClientRect(_hwnd, &_rect);		//�������ڵ��� ũ�⸦ ��ȯ�ϰڴ�.

	_hdcBack = ::CreateCompatibleDC(_hdc);	//_hdc�� ȣȯ�Ǵ� ȭ�� ����
	_bmpBack = ::CreateCompatibleBitmap(_hdc, _rect.right, _rect.bottom);	//_hdc�� ȣȯ�Ǵ� ��Ʈ�� ����
	HBITMAP prev = (HBITMAP)::SelectObject(_hdcBack, _bmpBack);	//_hdcBack�� _bmp ����
	::DeleteObject(prev);


	//�̱��� �ʱ�ȭ
	GET_SINGLE(TimeManager)->Init();

}
void Game::Update()
{
	//�̱��� ������Ʈ
	GET_SINGLE(TimeManager)->Update();


	_x++;
}
void Game::Render()
{
	//FPS ���
	{
		uint32 fps = GET_SINGLE(TimeManager)->GetFps();
		float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();

		wstring timeStr = format(L"FPS({0}), DT({1} ms)", fps, static_cast<int32>(deltaTime * 1000));
		::TextOut(_hdcBack, 0, 0, timeStr.c_str(), timeStr.length());
	}



	//�������� ������ �ʴ� ȭ�鿡 �ֱ��� 1�� ����
	wstring str = L"���ع��� ��λ���";
	::TextOut(_hdcBack, 100 + _x % 700, 100, str.c_str(), str.length());


	//��Ʈ�� : ��� ����
	::BitBlt(_hdc, 0, 0, _rect.right, _rect.bottom, _hdcBack, 0, 0, SRCCOPY);
	::PatBlt(_hdcBack, 0, 0, _rect.right, _rect.bottom, WHITENESS);
}
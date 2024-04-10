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

	// ������۸�
	::GetClientRect(_hwnd, &_rect);		// �������ڵ��� ũ�⸦ ��ȯ�ϰڴ�.

	_hdcBack = ::CreateCompatibleDC(_hdc);  // �������� ���̴� ȭ���̶� �ִ��� ����ϰ� ȭ���� �����ض�.
	_bmpBack = ::CreateCompatibleBitmap(_hdc, _rect.right, _rect.bottom);  // _hdc�� ȣȯ�Ǵ� ��Ʈ�� ����
	HBITMAP prev = (HBITMAP)::SelectObject(_hdcBack, _bmpBack);  // _hdcBack�� _bmp ����
	::DeleteObject(prev);
	// ��������� ȭ�� �� ���� �غ��� ����
	// ������ �� ���� 
	// �ڿ� ���� ȭ�鿡 �׸��� �׸���
	// �װ� �տ� ȭ�鿡 ��Ӻ��� �� ��


	// �̱��� �ʱ�ȭ
	Time->Init();
	Input->Init(_hwnd);
	GET_SINGLE(SceneManager)->Init();


	GET_SINGLE(SceneManager)->ChangeScene(SceneType::Homework1Scene);
}

void Game::Updata()
{
	// �̱��� ������Ʈ
	Time->Updata();
	Input->Updata();
	GET_SINGLE(SceneManager)->Update();
}

void Game::Render()
{
	//FPS ���
	{
		uint32 fps = Time->GetFps();
		float deltaTime = Time->GetDeltaTime();

		wstring timeStr = format(L"FPS({0}), DT({1} ms)", fps, static_cast<int32>(deltaTime * 1000));
		::TextOut(_hdcBack, 0, 0, timeStr.c_str(), timeStr.length());
	}


	// ���콺��ǥ ���
	{
		POINT mousePos = Input->GetMousePos();
		wstring timeStr = format(L"mouse({0}, {1})", mousePos.x, mousePos.y);
		::TextOut(_hdcBack, 0, 20, timeStr.c_str(), timeStr.length());
	}

	GET_SINGLE(SceneManager)->Render(_hdcBack);


	// ��Ʈ�� : ��� ����
	// ���� �������� ���� ȭ���� ������ ������� �Ѵ�. �װű��� �� ����Ŭ!
	::BitBlt(_hdc, 0, 0, _rect.right, _rect.bottom, _hdcBack, 0, 0, SRCCOPY); // SRCCOPY = source copy
	::PatBlt(_hdcBack, 0, 0, _rect.right, _rect.bottom, WHITENESS);
	
}
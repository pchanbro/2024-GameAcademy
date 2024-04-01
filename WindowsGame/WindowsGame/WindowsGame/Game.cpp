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

	//---------------------------------
	// ## �ڵ� ¥�� ��
	//---------------------------------
	_player.left = 100;
	_player.right = 200;
	_player.top = 100;
	_player.bottom = 200;

	_enemy.left = 250;
	_enemy.right = 300;
	_enemy.top = 200;
	_enemy.bottom = 250;
}

void Game::Updata()
{
	// �̱��� ������Ʈ
	Time->Updata();
	Input->Updata();

	//---------------------------------
	// ## �ڵ� ¥�� ��
	//---------------------------------


	//--------------------------------
	// �ǽ�
	// 1. wasd �� ����Ű��,
	//	  _player�� ������ �� �ְ��Ѵ�.
	// 2. _player�� _enemy�� �ε�����
	//	  ::MessageBox(_hwnd, L"�˸�", L"�浹�Ǿ����ϴ�", 0);
	//  �� �����Ѵ�.
	// 3. _player�� ���콺�� Ŭ���ϸ�
	//	  ::MessageBox(_hwnd, L"�˸�", L"�÷��̾ �����Ͽ����ϴ�", 0);
	// �� �����Ѵ�.
	// 
	//--------------------------------
	if (Input->GetKeyDown(KeyCode::Right))
	{
		_player.left += 5;
		_player.right += 5;
	}

	if (Input->GetKeyDown(KeyCode::Left))
	{
		_player.left -= 5;
		_player.right -= 5;
	}

	if (Input->GetKeyDown(KeyCode::Down))
	{
		_player.top += 5;
		_player.bottom += 5;
	}

	if (Input->GetKeyDown(KeyCode::Up))
	{
		_player.top -= 5;
		_player.bottom -= 5;
	}

	if (Input->GetKeyDown(KeyCode::A))
	{
		::MessageBox(_hwnd, L"�浹�Ǿ����ϴ�", L"�˸�", 0);
	}

	if ((_player.left <= _enemy.left && _enemy.left <= _player.right && _player.top <= _enemy.top && _enemy.top <= _player.bottom) ||
		(_player.left <= _enemy.right && _enemy.right <= _player.right && _player.top <= _enemy.top && _enemy.top <= _player.bottom) ||
		(_player.left <= _enemy.left && _enemy.left <= _player.right && _player.top <= _enemy.bottom && _enemy.bottom <= _player.bottom) ||
		(_player.left <= _enemy.right && _enemy.right <= _player.right && _player.top <= _enemy.bottom && _enemy.bottom <= _player.bottom))
	{
		::MessageBox(_hwnd, L"�浹�Ǿ����ϴ�", L"�˸�", 0);
	}

	
	// �Լ�ȭ�� �ؾ��ϴ� ���� -> ����� �дµ� �о��� �� �� �ǹ̸� ������ �� �ֱ� ������ �Լ�ȭ�� �ϰ� �װ� �� ���� �ڵ��.
	{
		POINT mousePos = Input->GetMousePos();
		if (_player.left < mousePos.x && mousePos.x < _player.right &&
			_player.top < mousePos.y && mousePos.y < _player.bottom)
		{
			if (Input->GetKeyDown(KeyCode::LeftMouse))
			{
				::MessageBox(_hwnd, L"�浹�Ǿ����ϴ�", L"�˸�", 0);
			}
		}
	}
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


	//---------------------------------
	// ## �ڵ� ¥�� ��
	//---------------------------------
	::Rectangle(_hdcBack, _player.left, _player.top, _player.right, _player.bottom);
	::Rectangle(_hdcBack, _enemy.left, _enemy.top, _enemy.right, _enemy.bottom);


	// ��Ʈ�� : ��� ����
	// ���� �������� ���� ȭ���� ������ ������� �Ѵ�. �װű��� �� ����Ŭ!
	::BitBlt(_hdc, 0, 0, _rect.right, _rect.bottom, _hdcBack, 0, 0, SRCCOPY); // SRCCOPY = source copy
	::PatBlt(_hdcBack, 0, 0, _rect.right, _rect.bottom, WHITENESS);
	
}
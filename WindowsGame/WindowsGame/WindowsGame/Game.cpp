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

	_enemy.left = 300;
	_enemy.right = 450;
	_enemy.top = 100;
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

	/* ������ 
	if (Input->GetKeyDown(KeyCode::LeftMouse))
	{
		POINT mousePos = Input->GetMousePos();
		gugudan = 0;
		wchar_t str[128];
		for (int i = 1; i <= line; i++)
		{
			for (int j = 1; j <= row; j++)
			{
				if (_player.left + (j - 1) * 200 < mousePos.x && mousePos.x < _player.right + (j - 1) * 200 &&
					_player.top + (i - 1) * 200 < mousePos.y && mousePos.y < _player.bottom + (i - 1) * 200)
				{
					gugudan = gugudan + i + j;
					if (i == 1)
					{
						gugudan -= 1;
					}
					else if (i == 2)
					{
						gugudan += 1;
					}
					else if (i == 3)
					{
						gugudan += 3;
					}
				}
			}
		}
	}*/

	if (Input->GetKeyDown(KeyCode::Right))
	{
		_player.left += 10;
		_player.right += 10;
		if ((Collision::RectInRect(_player, _enemy) && (_player.right == _enemy.left)))
		{
			_enemy.left += 10;
			_enemy.right += 10;
		}
	}

	if (Input->GetKeyDown(KeyCode::Left))
	{
		_player.left -= 10;
		_player.right -= 10;
		if ((Collision::RectInRect(_player, _enemy) && (_player.left == _enemy.right)))
		{
			_enemy.left -= 10;
			_enemy.right -= 10;
		}
	}

	if (Input->GetKeyDown(KeyCode::Down))
	{
		_player.top += 10;
		_player.bottom += 10;
		if ((Collision::RectInRect(_player, _enemy) && (_player.bottom == _enemy.top)))
		{
			_enemy.top += 10;
			_enemy.bottom += 10;
		}
	}

	if (Input->GetKeyDown(KeyCode::Up))
	{
		_player.top -= 10;
		_player.bottom -= 10;
		if ((Collision::RectInRect(_player, _enemy) && (_player.top == _enemy.bottom)))
		{
			_enemy.top -= 10;
			_enemy.bottom -= 10;
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
	
	/* ������
	for (int i = 1; i <= line; i++)
	{
		for (int j = 1; j <= row; j++)
		{
			::Rectangle(_hdcBack, _player.left + (j - 1) * 200, _player.top + (i - 1) * 200, _player.right + (j - 1) * 200, _player.bottom + (i - 1) * 200);
		}
	}

	{
		POINT mousePos = Input->GetMousePos();
		wchar_t str[128];
		
		for (int i = 1; i <= 9; i++)
		{
			wsprintf(str, L"%d X %d = %d", gugudan, i, gugudan * i);
			::TextOut(_hdc, mousePos.x, mousePos.y + i * 20, str, _tcslen(str));
		}
	}*/
	

	::Rectangle(_hdcBack, _player.left, _player.top, _player.right, _player.bottom);
	::Rectangle(_hdcBack, _enemy.left, _enemy.top, _enemy.right, _enemy.bottom);


	// ��Ʈ�� : ��� ����
	// ���� �������� ���� ȭ���� ������ ������� �Ѵ�. �װű��� �� ����Ŭ!
	::BitBlt(_hdc, 0, 0, _rect.right, _rect.bottom, _hdcBack, 0, 0, SRCCOPY); // SRCCOPY = source copy
	::PatBlt(_hdcBack, 0, 0, _rect.right, _rect.bottom, WHITENESS);
	
}
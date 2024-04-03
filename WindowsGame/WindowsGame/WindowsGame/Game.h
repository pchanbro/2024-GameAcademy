#pragma once
class Game
{
public:
	Game();
	~Game();

public:
	void Init(HWND hwnd);
	void Updata();
	void Render();

private:
	HWND _hwnd;
	HDC _hdc;		// 유저에게 보여줄 화면

private:
	// 더블버퍼링 변수
	RECT _rect = {};	// 크기 담당
	HDC _hdcBack = {};	// 유저에게 보이지 않는 화면
	HBITMAP _bmpBack = {};
	

private:
	RECT _player = {};
	RECT _enemy = {};
	int line = 3;
	int row = 3;
	int gugudan = 0;
};


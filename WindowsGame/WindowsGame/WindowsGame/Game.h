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
	HDC _hdc;		// �������� ������ ȭ��

private:
	// ������۸� ����
	RECT _rect = {};	// ũ�� ���
	HDC _hdcBack = {};	// �������� ������ �ʴ� ȭ��
	HBITMAP _bmpBack = {};

private:
	int _x;
};


#pragma once
class UI
{
public:
	UI() {}
	virtual ~UI() {}
public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();
public:
	virtual void Show();
	virtual void Hide();

public:
	void SetRect(CenterRect rect);
	CenterRect GetRect();
	bool isInMouse(); // UI라면 필수적으로 가지고 있어야 하는 함수

protected:
	Vector2 _pos = {};
	Vector2Int _size = {};
	bool _isShow = true;
};


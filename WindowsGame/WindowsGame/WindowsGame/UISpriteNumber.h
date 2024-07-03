#pragma once
#include "UI.h"

class Sprite;
// _number�� TextOut�� �ƴ϶�, Sprite �̹����� �̻ڰ� ����� �� �ִ� Ŭ����
class UISpriteNumber : public UI
{
	DECLARE_CHILD(UISpriteNumber, UI);

protected:
	int _number = 0;

	// ���� ��������Ʈ 0 ~ 9, �̹��� 10�� �������� ����
	Sprite* _sprites[10] = {};

public:
	void SetNumber(int number);
	void SetSprites(wstring resourceName);
	void SetSprite(Sprite* sprite, int number);

public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

};


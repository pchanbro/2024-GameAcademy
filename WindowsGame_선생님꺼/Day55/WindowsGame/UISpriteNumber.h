#pragma once
#include "UI.h"

class Sprite;
// _number�� TextOut�� �ƴ϶�, Sprite�̹����� �̻ڰ� ����Ҽ��ִ� Ŭ����
class UISpriteNumber : public UI
{
	DECLARE_CHILD(UISpriteNumber, UI);

protected:
	int _number = 0;

	// ���� ��������Ʈ 0 ~ 9  10�� �������� ����
	Sprite* _sprites[10] = {};


public:
	void SetNumber(int number);

	//resourceName : S_SpriteNumber
	//_sprites[0] : S_SpriteNumber_0
	//_sprites[1] : S_SpriteNumber_1
	// ...
	void SetSprites(wstring resourceName);
	void SetSprite(Sprite* sprite, int number);

public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();
};


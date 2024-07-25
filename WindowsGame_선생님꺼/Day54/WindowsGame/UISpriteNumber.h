#pragma once
#include "UI.h"

class Sprite;
// _number를 TextOut이 아니라, Sprite이미지로 이쁘게 출력할수있는 클래스
class UISpriteNumber : public UI
{
	DECLARE_CHILD(UISpriteNumber, UI);

protected:
	int _number = 0;

	// 숫자 스프라이트 0 ~ 9  10장 들어가기위한 변수
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


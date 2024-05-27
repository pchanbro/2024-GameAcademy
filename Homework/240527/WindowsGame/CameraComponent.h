#pragma once
#include "Component.h"
class Sprite;
class CenterRect;
class CameraComponent : public Component
{
public:
	using Super = Component;
public:

	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

public:
	CameraComponent() {}
	virtual ~CameraComponent() {}

public:
	// 배경의 정보를 넣어준다.
	void SetLTWH(int left, int top, int width, int height);
	void SetLTWH(Sprite* backgroundSprite);
	void SetLTWH(CenterRect backgroundBody);

protected:
	int _minX = 0;
	int _maxX = 0;
	int _minY = 0;
	int _maxY = 0;

	float _sumTime = 0.0f; // 현재 연출이 얼마 진행중인지 확인하는 시간
	float _duration = 0.5f; // 연출 완료하는데 걸린 시간 // duration은 너무 보편적인 이름이라 웬만하면 쓰지마라
	Vector2 _endPos = Vector2::Zero();
	Vector2 _startPos;
};


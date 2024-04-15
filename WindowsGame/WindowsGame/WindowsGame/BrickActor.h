#pragma once
#include "Actor.h"
class BrickActor : public Actor
{
public:
	using Super = Actor;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

	virtual void OnTriggerEnter(Collider* collider, Collider* other) override;

	// 아래와 같은 요소는 private로 받아서 get set으로 받아주는게 좋다 웬만하면 변수를 노출시키지 마라
public:
	int x = 0;
	int y = 0;
};


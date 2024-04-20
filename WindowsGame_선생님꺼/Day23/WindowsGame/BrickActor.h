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
};


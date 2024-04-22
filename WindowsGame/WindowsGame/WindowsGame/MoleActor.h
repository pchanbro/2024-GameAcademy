#pragma once
#include "Actor.h"
class MoleActor : public Actor
{
public:
	using Super = Actor;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

public:
	virtual void OnTriggerEnter(Collider* collider, Collider* other) override;

private:
	bool existence = false;
};


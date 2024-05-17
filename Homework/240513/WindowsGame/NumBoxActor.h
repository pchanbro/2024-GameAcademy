#pragma once
#include "Actor.h"
class NumBoxActor : public Actor
{
	DECLARE_CHILD(NumBoxActor, Actor);
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

public:
	virtual void OnTriggerEnter(Collider* collider, Collider* other) override;
	void Move();
	int GetNumber() { return _number; }

protected:
	int _number = 2;
};


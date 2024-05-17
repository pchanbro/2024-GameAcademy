#pragma once
#include "Actor.h"
class Game2048BoardActor : public Actor
{
	DECLARE_CHILD(Game2048BoardActor, Actor);
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
};


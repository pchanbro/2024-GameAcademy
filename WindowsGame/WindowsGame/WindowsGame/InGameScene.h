#pragma once
#include "Scene.h"

class BrickActor;
class BallActor;
class PaddleActor;
class PlayerController;

class InGameScene : public Scene
{
	using Super = Scene;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

private:
	PaddleActor* _paddle = nullptr;
	BallActor* _ball = nullptr;
};


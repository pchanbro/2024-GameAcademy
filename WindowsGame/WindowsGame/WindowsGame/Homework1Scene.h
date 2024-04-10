#pragma once
#include "Scene.h"
class Homework1Scene : public Scene
{
	using Super = Scene;
public :
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;


private:
	CenterRect _ball;
	CenterRect _bar;
	CenterRect *_wall = new CenterRect[4];
	CenterRect *_brick = new CenterRect[30];
	
	Vector2 _playerDir;
	Vector2 _targetPos = { -1, -1 };
};


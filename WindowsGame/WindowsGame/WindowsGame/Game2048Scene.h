#pragma once
#include "Scene.h"
class BoxCollider;
class NumBoxActor;
struct Section {
	bool Existence = false;
	float X = 0;
	float Y = 0;
};

class Game2048Scene : public Scene
{
	DECLARE_CHILD(Game2048Scene, Scene);
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

public:
	Section GetSection(int num) { return _section[num]; }
	bool IsBoxesMove();
	bool IsSectionNotFull();

protected:
	Section _section[16];
	vector<NumBoxActor*> _boxes;
	Vector2 _targetPos = { -1, -1 };
	Vector2 _tempPos;
	Vector2 _playerDir;
	bool _numBoxMoving = false;
};


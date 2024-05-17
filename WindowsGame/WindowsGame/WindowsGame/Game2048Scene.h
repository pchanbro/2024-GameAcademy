#pragma once
#include "Scene.h"
class BoxCollider;
class Game2048Scene : public Scene
{
	DECLARE_CHILD(Game2048Scene, Scene);
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

protected:
	
};


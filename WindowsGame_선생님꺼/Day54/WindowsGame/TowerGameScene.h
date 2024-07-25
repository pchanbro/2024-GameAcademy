#pragma once
#include "Scene.h"
class TilemapActor;
class TowerBuildController;
class TowerGameScene : public Scene
{
	using Super = Scene;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

public:
	void LoadResource();

private:
	TilemapActor* _tilemapActor = nullptr;
	TowerBuildController* _towerBuildController = nullptr;
};


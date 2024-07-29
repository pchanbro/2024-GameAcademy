#pragma once
#include "Scene.h"
class TowerGameTilemapActor;
class TowerBuildController;
class WaveController;
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
	Vector2Int GetCellPos(Vector2 pos);
	Vector2 GetTilemapPos(Vector2Int cellPos);
	Tile* GetTile(Vector2Int cellPos);

	void AddCellData(Vector2Int cellPos, int64 data);
	int64 GetCellPos(Vector2Int cellPos);

	void BuildTower(Vector2Int cellPos, int64 towerId);

private:
	TowerGameTilemapActor* _tilemapActor = nullptr;
	TowerBuildController* _towerBuildController = nullptr;
	WaveController* _waveController = nullptr;
};


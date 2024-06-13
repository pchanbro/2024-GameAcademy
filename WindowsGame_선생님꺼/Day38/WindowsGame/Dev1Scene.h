#pragma once
#include "TilemapScene.h"
class Panel;
class MapToolController;
class CreatureController;
class TilemapActor;
class Dev1Scene : public TilemapScene
{
	using Super = Scene;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;


public:
	virtual Vector2 GetTilemapPos(Vector2Int cellPos) override;
	virtual bool CanGo(Actor* actor, Vector2Int cellPos) override;
private:
	void LoadResource();

protected:
	TilemapActor* _tilemapActor = nullptr;
	MapToolController* _mapToolController = nullptr;
	CreatureController* _creatureController = nullptr;
};


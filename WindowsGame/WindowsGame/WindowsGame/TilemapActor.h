#pragma once
#include "Actor.h"
class Tilemap;
class TilemapActor : public Actor
{
	DECLARE_CHILD(TilemapActor, Actor);

public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

public:
	Tilemap* GetTileMap() { return _tilemap; }
	void SetTileMap(Tilemap* tilemap) { _tilemap = tilemap; }

protected:
	Tilemap* _tilemap = nullptr;
};


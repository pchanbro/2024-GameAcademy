#pragma once
#include "Actor.h"
class Tilemap;
class Sprite;
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
	void SetTileSprites(vector<Sprite*> sprites) { _sprites = sprites; }
	vector<Sprite*>& GetTileSprites() { return _sprites; }

protected:
	Tilemap* _tilemap = nullptr;
	vector<Sprite*> _sprites;
};


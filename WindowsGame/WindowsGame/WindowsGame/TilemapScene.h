#pragma once
#include "Scene.h"
class Actor;
class TilemapActor;
class TilemapScene : public Scene
{
	DECLARE_CHILD(TilemapScene, Scene);

	// 이거는 상속용으로만 쓰려고 해서 굳이 Init ~ Release는 만들필요 없다.
public:
	virtual Vector2 GetTilemapPos(Vector2Int cellPos) = 0;
	virtual Tilemap* GetTilemap() = 0;
	virtual TilemapActor* GetTilemapActor() = 0;
	virtual bool CanGo(Actor* actor, Vector2Int cellPos) = 0;
};


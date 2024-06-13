#pragma once
#include "TilemapScene.h" // 헤더 파일에는 왜 include 하지 말라했는데 이건 상속하기 위해 include했다.
class Panel;
class BoxCollider;
class FlipbookActor;
class MapToolController;
class CreatureController;
class TilemapActor;
class Tilemap;
class Dev1Scene : public TilemapScene
{
	using Super = Scene;
public:
	virtual void Init() override; // override는 보여주기용, 코멘트용, 딱히 효과는 없다.
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

public:
	virtual Vector2 GetTilemapPos(Vector2Int cellPos) override;
	virtual Tilemap* GetTilemap() override;
	virtual TilemapActor* GetTilemapActor() override;
	virtual bool CanGo(Actor* actor, Vector2Int cellPos) override;


private:
	void LoadResource();

protected:
	TilemapActor* _tilemapActor = nullptr;
	MapToolController* _mapToolController = nullptr;
	CreatureController* _creatureController = nullptr;
};


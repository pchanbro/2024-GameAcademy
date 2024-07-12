#include "pch.h"
#include "TowerDefenseScene.h"
#include "assert.h"
#include "Tilemap.h"
#include "TilemapActor.h"

void TowerDefenseScene::Init()
{


	Super::Init();
}
void TowerDefenseScene::Render(HDC hdc)
{
	Super::Render(hdc);
}
void TowerDefenseScene::Update()
{
	Super::Update();
}
void TowerDefenseScene::Release()
{
	Super::Release();
}

Vector2 TowerDefenseScene::GetTilemapPos(Vector2Int cellPos)
{
	// 1. Ÿ�ϸ��� �����´�.
	assert(_tilemapActor != nullptr);
	if (_tilemapActor == nullptr)
	{
		return Vector2::Zero();
	}

	Tilemap* tilemap = _tilemapActor->GetTileMap();
	assert(tilemap != nullptr);
	if (tilemap == nullptr)
	{
		return Vector2::Zero();
	}

	int tileSize = tilemap->GetTileSize();
	Vector2 pos = _tilemapActor->GetPos();

	Vector2 rv;

	rv.x = pos.x + cellPos.x * tileSize/*������� �»���� ǥ����*/ + (tileSize / 2) /* ���Ⱑ �߾����� ������ �߰��� �����ִ� �κ�*/;
	rv.y = pos.y + cellPos.y * tileSize + (tileSize / 2);

	return rv;
}

bool TowerDefenseScene::CanGo(Actor* actor, Vector2Int cellPos)
{
	assert(actor != nullptr);
	if (actor == nullptr)
	{
		return false;
	}

	assert(_tilemapActor != nullptr);
	if (_tilemapActor == nullptr)
	{
		return false;
	}

	Tilemap* tilemap = _tilemapActor->GetTileMap();
	assert(tilemap != nullptr);
	if (tilemap == nullptr)
	{
		return false;
	}

	Tile* tile = tilemap->GetTileAt(cellPos);
	if (tile == nullptr)
	{
		return false;
	}


	if (tile->value == 0)
	{
		return true;
	}

	return false;
}

Tilemap* TowerDefenseScene::GetTilemap()
{
	assert(_tilemapActor != nullptr);
	if (_tilemapActor == nullptr)
	{
		return nullptr;
	}

	Tilemap* tilemap = _tilemapActor->GetTileMap();
	assert(tilemap != nullptr);
	if (tilemap == nullptr)
	{
		return nullptr;
	}

	return tilemap;
}

TilemapActor* TowerDefenseScene::GetTilemapActor()
{
	assert(_tilemapActor != nullptr);
	if (_tilemapActor == nullptr)
	{
		return nullptr;
	}

	return _tilemapActor;
}
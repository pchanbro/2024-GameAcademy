#include "pch.h"
#include "MapToolTilemapActor.h"
#include "Tilemap.h"
void MapToolTilemapActor::Update_Picking()
{
	if (Input->GetKeyDown(KeyCode::LeftMouse))
	{
		// 타일이 클릭되었는지?
		// 타일이 클릭되었으면

		// 해당 타일의 value + 1

		int x = 0;
		int y = 0;
		Tilemap* tileMap = this->GetTileMap();
		int tileSize = tileMap->GetTileSize();

		Vector2Int mousePos = Input->GetMousePos();

		x = (mousePos.x - static_cast<int>(this->_body.pos.x)) / tileSize;
		y = (mousePos.y - static_cast<int>(this->_body.pos.y)) / tileSize;

		Tile* tile = tileMap->GetTileAt({ x, y });
		if (tile)
		{
			tile->value++;
			tile->value %= this->_sprites.size();
		}
	}
}

void MapToolTilemapActor::Save()
{
	Tilemap* tileMap = this->GetTileMap();
	if (tileMap == nullptr) return;

	tileMap->SaveFile(L"../Resources/Data/MapData.txt");

	printf("Save!");
}
void MapToolTilemapActor::Load()
{
	Tilemap* tileMap = this->GetTileMap();
	tileMap->LoadFile(L"../Resources/Data/MapData.txt");
	printf("Load!");
}

void MapToolTilemapActor::Init()
{
	Super::Init();
}
void MapToolTilemapActor::Render(HDC hdc)
{
	Super::Render(hdc);
}
void MapToolTilemapActor::Update()
{
	Super::Update();

	Update_Picking();
}
void MapToolTilemapActor::Release()
{
	Super::Release();
}
#include "pch.h"
#include "MapToolTilemapActor.h"
#include "Tilemap.h"

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
	// 여기의 키를 눌러서 뭔가 액션을 취하는건
	// 액터의 몫이 아니라 Controller의 몫이다.
	
}
void MapToolTilemapActor::Release()
{
	Super::Release();
}
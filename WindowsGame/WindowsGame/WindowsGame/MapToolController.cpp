#include "pch.h"
#include "MapToolController.h"
#include "MapToolTilemapActor.h"
#include "Tilemap.h"
#include "Dev1Scene.h"

void MapToolController::SetLink(MapToolTilemapActor* mapToolActor)
{
	assert(mapToolActor != nullptr);

	_mapToolActor = mapToolActor;
}
void MapToolController::Update()
{
	if (Input->GetKeyDown(KeyCode::S))
	{
		_mapToolActor->Save();
	}

	if (Input->GetKeyDown(KeyCode::L))
	{
		_mapToolActor->Load();
	}

	if (Input->GetKeyDown(KeyCode::LeftMouse))
	{
		// 타일이 클릭되었는지?
		// 타일이 클릭되었으면

		// 해당 타일의 value + 1

		int x = 0;
		int y = 0;
		Tilemap* tileMap = _mapToolActor->GetTileMap();
		int tileSize = tileMap->GetTileSize();

		Vector2Int mousePos = Input->GetMousePos();

		Vector2 pos = _mapToolActor->GetBody().pos; // 여기서 _mapToolActor의 _body.pos 는 0,0 이다
		int spriteSize = _mapToolActor->GetTileSprites().size();
		x = (mousePos.x - static_cast<int>(pos.x)) / tileSize;
		y = (mousePos.y - static_cast<int>(pos.y)) / tileSize;

		Tile* tile = tileMap->GetTileAt({ x, y });
		if (tile)
		{
			tile->value++;
			tile->value %= spriteSize;
		}
	}

	{
		/*Scene* scene = GET_SINGLE(SceneManager)->GetCurrentScene();
		

		if (Input->GetKey(KeyCode::Left))
		{
			Vector2Int newPos = scene->GetCameraPos();
			newPos.x -= Time->GetDeltaTime() * 300;
			scene->SetCameraPos(newPos);
		}

		if (Input->GetKey(KeyCode::Up))
		{
			Vector2Int newPos = scene->GetCameraPos();
			newPos.y -= Time->GetDeltaTime() * 300;
			scene->SetCameraPos(newPos);
		}

		if (Input->GetKey(KeyCode::Right))
		{
			Vector2Int newPos = scene->GetCameraPos();
			newPos.x += Time->GetDeltaTime() * 300;
			scene->SetCameraPos(newPos);
		}

		if (Input->GetKey(KeyCode::Down))
		{
			Vector2Int newPos = scene->GetCameraPos();
			newPos.y += Time->GetDeltaTime() * 300;
			scene->SetCameraPos(newPos);
		}*/
	}
}
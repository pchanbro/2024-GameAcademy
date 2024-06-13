#include "pch.h"
#include "Dev1Scene.h"
#include "PlayerActor.h"
#include "BoxCollider.h"
#include "Sprite.h"
#include "SpriteActor.h"
#include "FlipbookActor.h"
#include "Flipbook.h"
#include "CreatureActor.h"
#include "CameraComponent.h"
#include "Texture.h"
#include "CircleCollider.h"
#include "TestPanel.h"
#include "Panel.h"
#include "Image.h"
#include "TilemapActor.h"
#include "Tilemap.h"
#include "MapToolTilemapActor.h"
#include "MapToolController.h"
#include "CreatureController.h"

void Dev1Scene::Init()
{
	LoadResource();

	{
		for (int i = 0; i <= 12; i++)
		{
			{
				wchar_t keyName[128];
				swprintf_s(keyName, L"T_Pocket%d", i);

				wchar_t valueName[128];
				swprintf_s(valueName, L"TileStudy/pocket_%d.bmp", i);

				Resource->LoadTexture(keyName, valueName);
			}

			{
				wchar_t keyName[128];
				swprintf_s(keyName, L"S_Pocket%d", i);

				wchar_t textureKeyName[128];
				swprintf_s(textureKeyName, L"T_Pocket%d", i);

				Resource->CreateSprite(keyName, Resource->GetTexture(textureKeyName));
			}
		}

	}

	{
		Vector2Int mapSize = Vector2Int(10, 10);
		vector<vector<Tile>> tiles;
		for (int height = 0; height < mapSize.y; height++)
		{
			vector<Tile> tilesDummy;
			for (int width = 0; width < mapSize.x; width++)
			{
				Tile tile;
				tile.value = 0;
				tilesDummy.push_back(tile);
			}
			tiles.push_back(tilesDummy);
		}

		Resource->CreateTileMap(L"TM_Test", mapSize, 88, tiles);
	}

	_mapToolController = new MapToolController();

	{
		MapToolTilemapActor* actor = new MapToolTilemapActor();
		actor->SetTileMap(Resource->GetTileMap(L"TM_Test"));
		{
			vector<Sprite*> sprites;
			for (int i = 0; i <= 12; i++)
			{
				wchar_t keyName[128];
				swprintf_s(keyName, L"S_Pocket%d", i);
				sprites.push_back(Resource->GetSprite(keyName));
			}

			actor->SetTileSprites(sprites);
		}
		actor->SetLayer(LayerType::BackGround);
		actor->Init();

		// 이 액터를 조종하겠다.
		_mapToolController->SetLink(actor);

		this->SpawnActor(actor);
		_tilemapActor = actor;
	}

	_creatureController = new CreatureController();

	{
		CreatureActor* actor = new CreatureActor();
		actor->SetLayer(LayerType::Character);
		actor->SetName("Player");
		actor->SetBody(Shape::MakeCenterRect(300, 300, 0, 0));
		actor->Init();
		_creatureController->SetLink(actor);
		this->SpawnActor(actor);
		actor->SetCellPos({ 0,0 }, true);
	}

	{
		CreatureActor* actor = new CreatureActor();
		actor->SetLayer(LayerType::Character);
		actor->SetName("Friend");
		actor->SetBody(Shape::MakeCenterRect(300, 300, 0, 0));
		actor->Init();
		this->SpawnActor(actor);
		actor->SetCellPos({ 2,0 }, true);
	}

	this->SetCameraPos(Vector2(WIN_SIZE_X / 2, WIN_SIZE_Y / 2));

	Super::Init();
}

void Dev1Scene::Render(HDC hdc)
{
	// 부모함수 먼저 실행하고 자신의 함수를 실행하는것이 일반적이다.
	Super::Render(hdc);

	wstring str = L"Dev1Scene";
	::TextOut(hdc, 0, 45, str.c_str(), str.length());

}

void Dev1Scene::Update()
{
	Super::Update();

	_mapToolController->Update();
	_creatureController->Update();
}
void Dev1Scene::Release()
{
	Super::Release();
}

void Dev1Scene::LoadResource()
{
	//----------------------------------
	//  ## Background
	//----------------------------------
	{
		Texture* texture = Resource->LoadTexture(L"T_Background", L"CameraStudy/background_supermario.bmp");
		Resource->CreateSprite(L"S_Background", texture);
	}

	//----------------------------------
	//  ## PlayerDown Texture
	//----------------------------------
	{
		Texture* texture = Resource->LoadTexture(L"T_PlayerDown"
			, L"FlipbookTest/PlayerDown.bmp"
			, RGB(128, 128, 128));

		{
			FlipbookInfo flipbookInfo = {};
			flipbookInfo.duration = 1.0;
			flipbookInfo.loop = true;
			flipbookInfo.line = 0;
			flipbookInfo.start = 0;
			flipbookInfo.end = 9;
			flipbookInfo.size = { 200,200 };
			flipbookInfo.texture = texture;
			Resource->CreateFlipbook(L"FB_PlayerDownIdle", flipbookInfo);
		}
		{
			FlipbookInfo flipbookInfo = {};
			flipbookInfo.duration = 1.0;
			flipbookInfo.loop = true;
			flipbookInfo.line = 1;
			flipbookInfo.start = 0;
			flipbookInfo.end = 9;
			flipbookInfo.size = { 200,200 };
			flipbookInfo.texture = texture;
			Resource->CreateFlipbook(L"FB_PlayerDownMove", flipbookInfo);
		}
		{
			FlipbookInfo flipbookInfo = {};
			flipbookInfo.duration = 1.0;
			flipbookInfo.loop = true;
			flipbookInfo.line = 3;
			flipbookInfo.start = 0;
			flipbookInfo.end = 7;
			flipbookInfo.size = { 200,200 };
			flipbookInfo.texture = texture;
			Resource->CreateFlipbook(L"FB_PlayerDownAttack", flipbookInfo);
		}

	}


	//----------------------------------
	//  ## PlayerUp Texture
	//----------------------------------
	{
		Texture* texture = Resource->LoadTexture(L"T_PlayerUp"
			, L"FlipbookTest/PlayerUp.bmp"
			, RGB(128, 128, 128));

		{
			FlipbookInfo flipbookInfo = {};
			flipbookInfo.duration = 1.0;
			flipbookInfo.loop = true;
			flipbookInfo.line = 0;
			flipbookInfo.start = 0;
			flipbookInfo.end = 9;
			flipbookInfo.size = { 200,200 };
			flipbookInfo.texture = texture;
			Resource->CreateFlipbook(L"FB_PlayerUpIdle", flipbookInfo);
		}
		{
			FlipbookInfo flipbookInfo = {};
			flipbookInfo.duration = 1.0;
			flipbookInfo.loop = true;
			flipbookInfo.line = 1;
			flipbookInfo.start = 0;
			flipbookInfo.end = 9;
			flipbookInfo.size = { 200,200 };
			flipbookInfo.texture = texture;
			Resource->CreateFlipbook(L"FB_PlayerUpMove", flipbookInfo);
		}
		{
			FlipbookInfo flipbookInfo = {};
			flipbookInfo.duration = 1.0;
			flipbookInfo.loop = true;
			flipbookInfo.line = 3;
			flipbookInfo.start = 0;
			flipbookInfo.end = 7;
			flipbookInfo.size = { 200,200 };
			flipbookInfo.texture = texture;
			Resource->CreateFlipbook(L"FB_PlayerUpAttack", flipbookInfo);
		}
	}


	//----------------------------------
	//  ## PlayerLeft Texture
	//----------------------------------
	{
		Texture* texture = Resource->LoadTexture(L"T_PlayerLeft"
			, L"FlipbookTest/PlayerLeft.bmp"
			, RGB(128, 128, 128));

		{
			FlipbookInfo flipbookInfo = {};
			flipbookInfo.duration = 1.0;
			flipbookInfo.loop = true;
			flipbookInfo.line = 0;
			flipbookInfo.start = 0;
			flipbookInfo.end = 9;
			flipbookInfo.size = { 200,200 };
			flipbookInfo.texture = texture;
			Resource->CreateFlipbook(L"FB_PlayerLeftIdle", flipbookInfo);
		}
		{
			FlipbookInfo flipbookInfo = {};
			flipbookInfo.duration = 1.0;
			flipbookInfo.loop = true;
			flipbookInfo.line = 1;
			flipbookInfo.start = 0;
			flipbookInfo.end = 9;
			flipbookInfo.size = { 200,200 };
			flipbookInfo.texture = texture;
			Resource->CreateFlipbook(L"FB_PlayerLeftMove", flipbookInfo);
		}
		{
			FlipbookInfo flipbookInfo = {};
			flipbookInfo.duration = 1.0;
			flipbookInfo.loop = true;
			flipbookInfo.line = 3;
			flipbookInfo.start = 0;
			flipbookInfo.end = 7;
			flipbookInfo.size = { 200,200 };
			flipbookInfo.texture = texture;
			Resource->CreateFlipbook(L"FB_PlayerLeftAttack", flipbookInfo);
		}
	}

	//----------------------------------
	//  ## PlayerRight Texture
	//----------------------------------
	{
		Texture* texture = Resource->LoadTexture(L"T_PlayerRight"
			, L"FlipbookTest/PlayerRight.bmp"
			, RGB(128, 128, 128));

		{
			FlipbookInfo flipbookInfo = {};
			flipbookInfo.duration = 1.0;
			flipbookInfo.loop = true;
			flipbookInfo.line = 0;
			flipbookInfo.start = 0;
			flipbookInfo.end = 9;
			flipbookInfo.size = { 200,200 };
			flipbookInfo.texture = texture;
			Resource->CreateFlipbook(L"FB_PlayerRightIdle", flipbookInfo);
		}
		{
			FlipbookInfo flipbookInfo = {};
			flipbookInfo.duration = 1.0;
			flipbookInfo.loop = true;
			flipbookInfo.line = 1;
			flipbookInfo.start = 0;
			flipbookInfo.end = 9;
			flipbookInfo.size = { 200,200 };
			flipbookInfo.texture = texture;
			Resource->CreateFlipbook(L"FB_PlayerRightMove", flipbookInfo);
		}
		{
			FlipbookInfo flipbookInfo = {};
			flipbookInfo.duration = 1.0;
			flipbookInfo.loop = true;
			flipbookInfo.line = 3;
			flipbookInfo.start = 0;
			flipbookInfo.end = 7;
			flipbookInfo.size = { 200,200 };
			flipbookInfo.texture = texture;
			Resource->CreateFlipbook(L"FB_PlayerRightAttack", flipbookInfo);
		}
	}

	{
		Texture* texture = Resource->LoadTexture(L"T_Monster", L"FlipbookTest/Monster.bmp");
		{
			FlipbookInfo flipbookInfo = {};
			flipbookInfo.duration = 1.0;
			flipbookInfo.line = 0;
			flipbookInfo.start = 0;
			flipbookInfo.end = 5;
			flipbookInfo.size = { 68,80 };
			flipbookInfo.texture = texture;
			flipbookInfo.loop = true;
			Resource->CreateFlipbook(L"FB_MonsterIdle", flipbookInfo);
		}

		{
			FlipbookInfo flipbookInfo = {};
			flipbookInfo.duration = 1.0;
			flipbookInfo.line = 9;
			flipbookInfo.start = 0;
			flipbookInfo.end = 4;
			flipbookInfo.size = { 80,65 };
			flipbookInfo.texture = texture;
			flipbookInfo.loop = false;
			Resource->CreateFlipbook(L"FB_MonsterDie", flipbookInfo);
		}
	}

	//----------------------------------
	//  ## Sound
	//----------------------------------
	Resource->LoadSound(L"BGM_Dev1Scene", L"Sounds/SoundStudy/BGM.wav");


	//----------------------------------
	//  ## UI
	//----------------------------------

}

Vector2 Dev1Scene::GetTilemapPos(Vector2Int cellPos)
{
	// 1. 타일맵을 가져온다.
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

	rv.x = pos.x + cellPos.x * tileSize/*여기까지 좌상단을 표시함*/ + (tileSize / 2) /* 여기가 중앙으로 가도록 추가로 더해주는 부분*/;
	rv.y = pos.y + cellPos.y * tileSize + (tileSize / 2);

	return rv;
}

bool Dev1Scene::CanGo(Actor* actor, Vector2Int cellPos)
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

Tilemap* Dev1Scene::GetTilemap()
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

TilemapActor* Dev1Scene::GetTilemapActor()
{
	assert(_tilemapActor != nullptr);
	if (_tilemapActor == nullptr)
	{
		return nullptr;
	}

	return _tilemapActor;
}

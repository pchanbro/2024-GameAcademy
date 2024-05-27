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
		actor->Init();
		this->SpawnActor(actor);
	}

	//{
	//	for (int i = 0; i <= 12; i++)
	//	{
	//		wchar_t keyName[128];
	//		swprintf_s(keyName, L"T_Pocket%d",i);

	//		wchar_t valueName[128];
	//		swprintf_s(valueName, L"TileStudy/pocket_%d.bmp",i);

	//		Resource->LoadTexture(keyName, valueName);
	//	}
	//}

	//{
	//	Vector2Int mapSize = Vector2Int(10, 10);
	//	vector<vector<Tile>> tiles;
	//	{
	//		vector<Tile> tilesDummy;
	//		for (int width = 0; width < mapSize.x; width++)
	//		{
	//			Tile tile;
	//			tile.value = GET_SINGLE(RandomManager)->GetRandomInt(0,2);
	//			tilesDummy.push_back(tile);
	//		}
	//		tiles.push_back(tilesDummy);
	//	}

	//	{
	//		vector<Tile> tilesDummy;
	//		Tile tile;
	//		tile.value = 1;
	//		tilesDummy.push_back(tile);
	//		tiles.push_back(tilesDummy);
	//	}

	//	{
	//		vector<Tile> tilesDummy;
	//		Tile tile;
	//		tile.value = 2;
	//			tilesDummy.push_back(tile);
	//		tiles.push_back(tilesDummy);
	//	}

	//	{
	//		vector<Tile> tilesDummy;
	//		for (int i = 0; i < 5; i++)
	//		{
	//			Tile tile;
	//			tile.value = 3;
	//			tilesDummy.push_back(tile);
	//		}
	//		tiles.push_back(tilesDummy);
	//	}

	//	{
	//		vector<Tile> tilesDummy;
	//		Tile tile;
	//		tile.value = 4;
	//		tilesDummy.push_back(tile);
	//		tiles.push_back(tilesDummy);
	//	}

	//	Resource->CreateTileMap(L"TM_Test", mapSize, 48, tiles);
	//}


	//{
	//	TilemapActor* actor = new TilemapActor();
	//	actor->SetTileMap(Resource->GetTileMap(L"TM_Test"));

	//	actor->Init();
	//	this->SpawnActor(actor);
	//}



	Super::Init();
}

void Dev1Scene::Render(HDC hdc)
{
	// �θ��Լ� ���� �����ϰ� �ڽ��� �Լ��� �����ϴ°��� �Ϲ����̴�.
	Super::Render(hdc);

	wstring str = L"Dev1Scene";
	::TextOut(hdc, 0, 45, str.c_str(), str.length());

}

void Dev1Scene::Update()
{
	Super::Update();

	//if (!_flipbook) return;
	for (BoxCollider* collider : _colliders)
	{
		RECT rc1 = collider->GetCollision().ToRect();
		// GetComponent�� ���� GetCollision �ޱ�
		RECT rc2 = _monster->GetComponent<BoxCollider>()->GetCollision().ToRect();
		if (Collision::RectInRect(rc1, rc2))
		{
			_monster->SetFlipbook(Resource->GetFlipbook(L"FB_MonsterDie"));
		}
	}

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

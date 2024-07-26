#include "pch.h"
#include "TowerGameScene.h"
#include "Tilemap.h"
#include "Flipbook.h"
#include "TilemapActor.h"
#include "TowerBuildController.h"
#include "TowerGameTilemapActor.h"
void TowerGameScene::Init()
{
	Super::Init();

	this->LoadResource();


	//타일맵
	{
		_tilemapActor = new TowerGameTilemapActor();
		_tilemapActor->SetTileMap(Resource->GetTileMap(L"TM_Background"));

		{
			vector<Sprite*> sprites;
			for (int i = 6; i <= 67; i++)
			{
				wchar_t keyName[128];
				swprintf_s(keyName, L"S_BeachTileset%d", i);
				sprites.push_back(Resource->GetSprite(keyName));
			}
			_tilemapActor->SetTileSprites(sprites);
		}

		_tilemapActor->Init();
		_tilemapActor->LoadTilemap(L"../Resources/Data/MapData.txt");
		
		this->SpawnActor(_tilemapActor);
	}


	_towerBuildController = new TowerBuildController();
	_towerBuildController->Init();

	this->SetCameraPos(Vector2(WIN_SIZE_X / 2, WIN_SIZE_Y / 2));


	//------------------------------
	// 이벤트 세팅 
	//------------------------------
	GET_SINGLE(GameEventManager)->AddEvent("TowerBuild", new GameEvent<Vector2Int, int64>());
	GET_SINGLE(GameEventManager)->GetEvent<Vector2Int, int64>("TowerBuild")
		->AddListen(this, &TowerGameScene::BuildTower);
}


void TowerGameScene::Render(HDC hdc)
{
	Super::Render(hdc);

	wstring str = L"TowerGameScene";
	::TextOut(hdc, 0, 45, str.c_str(), str.length());
}
void TowerGameScene::Update()
{
	Super::Update();

	_towerBuildController->Update();

}
void TowerGameScene::Release()
{
	Super::Release();

}

void TowerGameScene::BuildTower(Vector2Int cellPos, int64 towerId)
{
	_tilemapActor->AddData(cellPos, towerId);

	printf("BuildTower [%d, %d], towerId : %lld\n", cellPos.x, cellPos.y, towerId);
}

Vector2Int TowerGameScene::GetCellPos(Vector2 pos)
{
	assert(_tilemapActor != nullptr);
	if (_tilemapActor == nullptr)
	{
		return Vector2Int(0, 0);
	}

	return _tilemapActor->GetTileIndexByPos(pos);
}

Vector2 TowerGameScene::GetTilemapPos(Vector2Int cellPos)
{
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

	rv.x = pos.x + cellPos.x * tileSize + (tileSize / 2);
	rv.y = pos.y + cellPos.y * tileSize + (tileSize / 2);

	return rv;
}

Tile* TowerGameScene::GetTile(Vector2Int cellPos)
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

	Tile* tile = tilemap->GetTileAt(cellPos);
	return tile;
}

void TowerGameScene::AddCellData(Vector2Int cellPos, int64 data)
{
	assert(_tilemapActor);
	if (_tilemapActor == nullptr)
	{
		return;
	}

	_tilemapActor->AddData(cellPos, data);
}

int64 TowerGameScene::GetCellPos(Vector2Int cellPos)
{
	assert(_tilemapActor);
	if (_tilemapActor == nullptr)
	{
		return -1;
	}

	return _tilemapActor->GetCellData(cellPos);
}

void TowerGameScene::LoadResource()
{
	// -------------------------------------
	//			BOAT RESOURCE
	// ------------------------------------- 
//direction
	wstring direction[8] = { L"Down", L"Left", L"Right", L"Up", L"DownNLeft", L"DownNRight", L"UpNLeft", L"UpNRight" };
	//EnemyBoat1
	{
		Resource->LoadTexture(L"T_EnemyBoat1", L"Textures/enemyBoat1.bmp", RGB(255, 0, 255));
		FlipbookInfo info_enemyBoat1 = {};
		info_enemyBoat1.start = 0;
		info_enemyBoat1.end = 2;
		info_enemyBoat1.line = 0;
		info_enemyBoat1.size = Vector2Int(32, 32);
		info_enemyBoat1.duration = 0.6f;
		info_enemyBoat1.loop = true;
		info_enemyBoat1.texture = Resource->GetTexture(L"T_EnemyBoat1");

		for (int i = 0; i < 8; i++)
		{
			wstring fullName = L"FB_EnemyBoat1_" + direction[i];
			info_enemyBoat1.line = i;
			Resource->CreateFlipbook(fullName, info_enemyBoat1);
		}
	}

	//EnemyBoat2
	{
		Resource->LoadTexture(L"T_EnemyBoat2", L"Textures/enemyBoat2.bmp", RGB(255, 0, 255));
		FlipbookInfo info_enemyBoat2 = {};
		info_enemyBoat2.start = 0;
		info_enemyBoat2.end = 2;
		info_enemyBoat2.line = 0;
		info_enemyBoat2.size = Vector2Int(32, 32);
		info_enemyBoat2.duration = 0.6f;
		info_enemyBoat2.loop = true;
		info_enemyBoat2.texture = Resource->GetTexture(L"T_EnemyBoat2");

		for (int i = 0; i < 8; i++)
		{
			wstring fullName = L"FB_EnemyBoat2_" + direction[i];
			info_enemyBoat2.line = i;
			Resource->CreateFlipbook(fullName, info_enemyBoat2);
		}
	}

	//EnemyShip1
	{
		Resource->LoadTexture(L"T_EnemyShip1", L"Textures/enemyShip1.bmp", RGB(255, 0, 255));
		FlipbookInfo info_enemyship1 = {};
		info_enemyship1.start = 0;
		info_enemyship1.end = 2;
		info_enemyship1.line = 0;
		info_enemyship1.size = Vector2Int(32, 32);
		info_enemyship1.duration = 0.6f;
		info_enemyship1.loop = true;
		info_enemyship1.texture = Resource->GetTexture(L"T_EnemyShip1");

		for (int i = 0; i < 8; i++)
		{
			wstring fullName = L"FB_EnemyShip1_" + direction[i];
			info_enemyship1.line = i;
			Resource->CreateFlipbook(fullName, info_enemyship1);
		}
	}

	//EnemyShip2
	{
		Resource->LoadTexture(L"T_EnemyShip2", L"Textures/enemyShip2.bmp", RGB(255, 0, 255));
		FlipbookInfo info_enemyship2 = {};
		info_enemyship2.start = 0;
		info_enemyship2.end = 2;
		info_enemyship2.line = 0;
		info_enemyship2.size = Vector2Int(32, 32);
		info_enemyship2.duration = 0.6f;
		info_enemyship2.loop = true;
		info_enemyship2.texture = Resource->GetTexture(L"T_EnemyShip2");

		for (int i = 0; i < 8; i++)
		{
			wstring fullName = L"FB_EnemyShip2_" + direction[i];
			info_enemyship2.line = i;
			Resource->CreateFlipbook(fullName, info_enemyship2);
		}
	}

	//EnemyShip3
	{
		Resource->LoadTexture(L"T_EnemyShip3", L"Textures/enemyShip3.bmp", RGB(255, 0, 255));
		FlipbookInfo info_enemyship3 = {};
		info_enemyship3.start = 0;
		info_enemyship3.end = 2;
		info_enemyship3.line = 0;
		info_enemyship3.size = Vector2Int(32, 32);
		info_enemyship3.duration = 0.6f;
		info_enemyship3.loop = true;
		info_enemyship3.texture = Resource->GetTexture(L"T_EnemyShip3");

		for (int i = 0; i < 8; i++)
		{
			wstring fullName = L"FB_EnemyShip3_" + direction[i];
			info_enemyship3.line = i;
			Resource->CreateFlipbook(fullName, info_enemyship3);
		}
	}

	// -------------------------------------
	//			Tower Resource
	// ------------------------------------- 
	//DrillTank1
	{
		Resource->LoadTexture(L"T_DrillTank1", L"Textures/drillTank1.bmp", RGB(255, 0, 255));
		FlipbookInfo info_drillTank1 = {};
		info_drillTank1.start = 0;
		info_drillTank1.end = 2;
		info_drillTank1.line = 0;
		info_drillTank1.size = Vector2Int(32, 32);
		info_drillTank1.duration = 0.6f;
		info_drillTank1.loop = true;
		info_drillTank1.texture = Resource->GetTexture(L"T_DrillTank1");

		for (int i = 0; i < 8; i++)
		{
			wstring fullName = L"FB_DrillTank1_" + direction[i];
			info_drillTank1.line = i;
			Resource->CreateFlipbook(fullName, info_drillTank1);
		}
	}

	//DrillTank2
	{
		Resource->LoadTexture(L"T_DrillTank2", L"Textures/drillTank2.bmp", RGB(255, 0, 255));
		FlipbookInfo info_drillTank2 = {};
		info_drillTank2.start = 0;
		info_drillTank2.end = 2;
		info_drillTank2.line = 0;
		info_drillTank2.size = Vector2Int(32, 32);
		info_drillTank2.duration = 0.6f;
		info_drillTank2.loop = true;
		info_drillTank2.texture = Resource->GetTexture(L"T_DrillTank2");

		for (int i = 0; i < 8; i++)
		{
			wstring fullName = L"FB_DrillTank2_" + direction[i];
			info_drillTank2.line = i;
			Resource->CreateFlipbook(fullName, info_drillTank2);
		}
	}

	//DrillTank3
	{
		Resource->LoadTexture(L"T_DrillTank3", L"Textures/drillTank3.bmp", RGB(255, 0, 255));
		FlipbookInfo info_drillTank3 = {};
		info_drillTank3.start = 0;
		info_drillTank3.end = 2;
		info_drillTank3.line = 0;
		info_drillTank3.size = Vector2Int(32, 32);
		info_drillTank3.duration = 0.6f;
		info_drillTank3.loop = true;
		info_drillTank3.texture = Resource->GetTexture(L"T_DrillTank3");

		for (int i = 0; i < 8; i++)
		{
			wstring fullName = L"FB_DrillTank3_" + direction[i];
			info_drillTank3.line = i;
			Resource->CreateFlipbook(fullName, info_drillTank3);
		}
	}

	//Tank1
	{
		Resource->LoadTexture(L"T_Tank1", L"Textures/tank1.bmp", RGB(255, 0, 255));
		FlipbookInfo info_tank1 = {};
		info_tank1.start = 0;
		info_tank1.end = 2;
		info_tank1.line = 0;
		info_tank1.size = Vector2Int(32, 32);
		info_tank1.duration = 0.6f;
		info_tank1.loop = true;
		info_tank1.texture = Resource->GetTexture(L"T_Tank1");

		for (int i = 0; i < 8; i++)
		{
			wstring fullName = L"FB_Tank1_" + direction[i];
			info_tank1.line = i;
			Resource->CreateFlipbook(fullName, info_tank1);
		}
	}

	//Tank2
	{
		Resource->LoadTexture(L"T_Tank2", L"Textures/tank2.bmp", RGB(255, 0, 255));
		FlipbookInfo info_tank2 = {};
		info_tank2.start = 0;
		info_tank2.end = 2;
		info_tank2.line = 0;
		info_tank2.size = Vector2Int(32, 32);
		info_tank2.duration = 0.6f;
		info_tank2.loop = true;
		info_tank2.texture = Resource->GetTexture(L"T_Tank2");

		for (int i = 0; i < 8; i++)
		{
			wstring fullName = L"FB_Tank2_" + direction[i];
			info_tank2.line = i;
			Resource->CreateFlipbook(fullName, info_tank2);
		}
	}

	//Tank3
	{
		Resource->LoadTexture(L"T_Tank3", L"Textures/tank3.bmp", RGB(255, 0, 255));
		FlipbookInfo info_tank3 = {};
		info_tank3.start = 0;
		info_tank3.end = 2;
		info_tank3.line = 0;
		info_tank3.size = Vector2Int(32, 32);
		info_tank3.duration = 0.6f;
		info_tank3.loop = true;
		info_tank3.texture = Resource->GetTexture(L"T_Tank3");

		for (int i = 0; i < 8; i++)
		{
			wstring fullName = L"FB_Tank3_" + direction[i];
			info_tank3.line = i;
			Resource->CreateFlipbook(fullName, info_tank3);
		}
	}
	/*
	//Balloon1
	{
		Resource->LoadTexture(L"T_Balloon1", L"Textures/balloon1.bmp", RGB(255, 0, 255));
		FlipbookInfo info_balloon1 = {};
		info_balloon1.start = 0;
		info_balloon1.end = 2;
		info_balloon1.line = 0;
		info_balloon1.size = Vector2Int(32, 32);
		info_balloon1.duration = 0.6f;
		info_balloon1.loop = true;
		info_balloon1.texture = Resource->GetTexture(L"T_Balloon1");

		for (int i = 0; i < 8; i++)
		{
			wstring fullName = L"FB_Balloon1_" + direction[i];
			info_balloon1.line = i;
			Resource->CreateFlipbook(fullName, info_balloon1);
		}
	}

	//Balloon2
	{
		Resource->LoadTexture(L"T_Balloon2", L"Textures/balloon2.bmp", RGB(255, 0, 255));
		FlipbookInfo info_balloon2 = {};
		info_balloon2.start = 0;
		info_balloon2.end = 2;
		info_balloon2.line = 0;
		info_balloon2.size = Vector2Int(32, 32);
		info_balloon2.duration = 0.6f;
		info_balloon2.loop = true;
		info_balloon2.texture = Resource->GetTexture(L"T_Balloon2");

		for (int i = 0; i < 8; i++)
		{
			wstring fullName = L"FB_Balloon2_" + direction[i];
			info_balloon2.line = i;
			Resource->CreateFlipbook(fullName, info_balloon2);
		}
	}
	*/
	//Submarine
	{
		Resource->LoadTexture(L"T_Submarine", L"Textures/submarine.bmp", RGB(255, 0, 255));
		FlipbookInfo info_submarine = {};
		info_submarine.start = 0;
		info_submarine.end = 2;
		info_submarine.line = 0;
		info_submarine.size = Vector2Int(32, 32);
		info_submarine.duration = 0.6f;
		info_submarine.loop = true;
		info_submarine.texture = Resource->GetTexture(L"T_Submarine");

		for (int i = 0; i < 8; i++)
		{
			wstring fullName = L"FB_Submarine_" + direction[i];
			info_submarine.line = i;
			Resource->CreateFlipbook(fullName, info_submarine);
		}
	}

	//Tank3
	{
		Resource->LoadTexture(L"T_Target", L"Textures/target.bmp", RGB(255, 0, 255));
		FlipbookInfo target = {};
		target.start = 0;
		target.end = 3;
		target.line = 0;
		target.size = Vector2Int(40, 40);
		target.duration = 1.0f;
		target.loop = true;
		target.texture = Resource->GetTexture(L"T_Target");

		Resource->CreateFlipbook(L"FB_Target", target);
	}

	//----------------------------------
	//  ## Sprite
	//----------------------------------
	Texture* redTile = Resource->LoadTexture(L"T_RedTile", L"UIs/RedTile.bmp", RGB(255, 0, 255));
	Resource->CreateSprite(L"S_RedTile", redTile);

	Texture* dock = Resource->LoadTexture(L"T_BeachTileset_2", L"BeachTileset/BeachTileset_2.bmp", RGB(255, 0, 255));
	Resource->CreateSprite(L"S_BeachTileset_2", dock);

	Texture* hpBackground = Resource->LoadTexture(L"T_HP_Background", L"UIs/HP_Background.bmp");
	Resource->CreateSprite(L"S_HP_Background", hpBackground);

	Texture* hpBar = Resource->LoadTexture(L"T_HP_Bar", L"UIs/HP_Bar.bmp", RGB(255, 0, 255));
	Resource->CreateSprite(L"S_HP_Bar", hpBar);

	Texture* bullet = Resource->LoadTexture(L"T_Bullet", L"UIs/Bullet.bmp", RGB(255, 0, 255));
	Resource->CreateSprite(L"S_Bullet", bullet);


	{
		for (int i = 6; i <= 67; i++)
		{
			{
				wchar_t keyName[128];
				swprintf_s(keyName, L"T_BeachTileset%d", i);

				wchar_t valueName[128];
				swprintf_s(valueName, L"BeachTileset/BeachTileset_%d.bmp", i);

				Resource->LoadTexture(keyName, valueName);
			}

			{
				wchar_t keyName[128];
				swprintf_s(keyName, L"S_BeachTileset%d", i);

				wchar_t textureKeyName[128];
				swprintf_s(textureKeyName, L"T_BeachTileset%d", i);

				Resource->CreateSprite(keyName, Resource->GetTexture(textureKeyName));
			}
		}

	}



	{
		Vector2Int mapSize = Vector2Int(55, 26);
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
		Resource->CreateTileMap(L"TM_Background", mapSize, 32, tiles);
	}
}
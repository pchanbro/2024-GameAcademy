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

void Dev1Scene::Init()
{
	LoadResource();

	GET_SINGLE(SoundManager)->Play(L"BGM_Dev1Scene", true);


	SpriteActor* background = nullptr;
	{
		background = new SpriteActor();
		Sprite* sprite = Resource->GetSprite(L"S_Background");
		background->SetSprite(sprite);
		background->SetBody(Shape::MakeCenterRectLTWH(0, 0, sprite->GetSize().x, sprite->GetSize().y));
		background->Init();
		this->SpawnActor(background);
	}

	{
		CreatureActor* actor = new CreatureActor();

		actor->SetName("Player");
		actor->SetFlipbook(Resource->GetFlipbook(L"FB_PlayerDownIdle"));
		actor->SetPos(Vector2(WIN_SIZE_X / 2, WIN_SIZE_Y / 2));

		{
			CameraComponent* component = new CameraComponent();
			component->SetLTWH(background->GetSprite());
			component->Init();
			actor->AddComponent(component);
		}

		{
			CircleCollider* component = new CircleCollider();
			component->SetCollision(Vector2::Zero(), 50);
			component->Init();
			component->SetCollisionLayer(CollisionLayerType::CLT_CREATURE);
			component->ResetCollisionFlag();
			component->AddCollisionFlagLayer(CollisionLayerType::CLT_ITEM);
			actor->AddComponent(component);
		}
		/*BoxCollider* collider = new BoxCollider();
		collider->SetCollision(Shape::MakeCenterRect(100, 0, 10, 50));
		actor->AddComponent(collider);

		_colliders.push_back(collider);*/
		
		actor->Init();
		this->SpawnActor(actor);

	}


	{
		FlipbookActor* actor = new FlipbookActor();

		actor->SetName("Dummy1");
		{
			BoxCollider* component = new BoxCollider();
			component->SetCollision(Shape::MakeCenterRect(0,0, 50, 50));
			component->Init();
			component->SetCollisionLayer(CollisionLayerType::CLT_ITEM);
			component->ResetCollisionFlag();
			component->AddCollisionFlagLayer(CollisionLayerType::CLT_CREATURE);
			actor->AddComponent(component);
		}

		actor->SetFlipbook(Resource->GetFlipbook(L"FB_PlayerDownIdle"));
		actor->SetPos(Vector2(WIN_SIZE_X / 2 + 100 , WIN_SIZE_Y / 2));

		actor->Init();
		this->SpawnActor(actor);
	}

	{
		FlipbookActor* actor = new FlipbookActor();

		actor->SetName("Dummy2");
		{
			BoxCollider* component = new BoxCollider();
			component->SetCollision(Shape::MakeCenterRect(0, 0, 50, 50));
			component->Init();
			component->SetCollisionLayer(CollisionLayerType::CLT_DEFAULT);
			component->ResetCollisionFlag();
			actor->AddComponent(component);
		}

		actor->SetFlipbook(Resource->GetFlipbook(L"FB_PlayerDownIdle"));
		actor->SetPos(Vector2(WIN_SIZE_X / 2 - 100, WIN_SIZE_Y / 2));

		actor->Init();
		this->SpawnActor(actor);
	}

	{
		TilemapActor* actor = new TilemapActor();
		actor->Init();
		this->SpawnActor(actor);
	}

	// 보통 패널은 _uis에 추가해준다(push_back으로) , 이미지는 추가 안함
	/*{
		TestPanel* testPanel = new TestPanel();
		_uis.push_back(testPanel);
	}*/
	

	_monster = new FlipbookActor();

	{
		_monster->SetFlipbook(Resource->GetFlipbook(L"FB_MonsterIdle"));
		_monster->SetPos(Vector2(WIN_SIZE_X / 2 + 300, WIN_SIZE_Y / 2 ));

		{
			BoxCollider* collider = new BoxCollider();
			collider->SetCollision(Shape::MakeCenterRect(0, 0, 68, 80));
			_monster->AddComponent(collider);
		}

		_monster->Init();
		this->SpawnActor(_monster);
	}

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

	//if (!_flipbook) return;
	for (BoxCollider* collider : _colliders)
	{
		RECT rc1 = collider->GetCollision().ToRect();
		// GetComponent를 통한 GetCollision 받기
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

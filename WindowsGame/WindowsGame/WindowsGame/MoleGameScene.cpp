#include "pch.h"
#include "MoleGameScene.h"
#include "SpriteActor.h"
#include "MoleActor.h"
#include "BoxCollider.h"
#include "HammerActor.h"

void MoleGameScene::Init()
{
	Super::Init();

	{
		Resource->LoadTexture(L"T_MoleBackground", L"Mole/background.bmp");
		Resource->CreateSprite(L"S_MoleBackground", Resource->GetTexture(L"T_MoleBackground"));

		SpriteActor* background = new SpriteActor();
		background->SetName("Background");
		background->SetSprite(Resource->GetSprite(L"S_MoleBackground"));
		background->SetBody(Shape::MakeCenterRectLTWH(0, 0, WIN_SIZE_X, WIN_SIZE_Y));
		background->Init();

		this->SpawnActor(background);
	}

	Resource->LoadTexture(L"T_Mole", L"Mole/mole.bmp");
	Resource->CreateSprite(L"S_Mole_Idle", Resource->GetTexture(L"T_Mole"), 0, 0, 85, 113);
	Resource->CreateSprite(L"S_Mole_Die", Resource->GetTexture(L"T_Mole"), 85, 0, 85, 113);
	{
		MoleActor* mole = new MoleActor();
		mole->SetBody(Shape::MakeCenterRect(219, 86, 85, 113));

		{
			BoxCollider* collider = new BoxCollider();
			collider->SetCollision(Shape::MakeCenterRect(0, 0, 85, 85));
			mole->AddComponent(collider);
		}

		mole->Init();
		_moles.push_back(mole);
		this->SpawnActor(mole);
	}

	{
		MoleActor* mole = new MoleActor();
		mole->SetBody(Shape::MakeCenterRect(219, 237, 85, 113));

		{
			BoxCollider* collider = new BoxCollider();
			collider->SetCollision(Shape::MakeCenterRect(0, 0, 85, 85));
			mole->AddComponent(collider);
		}

		mole->Init();
		_moles.push_back(mole);
		this->SpawnActor(mole);
	}

	{
		MoleActor* mole = new MoleActor();
		mole->SetBody(Shape::MakeCenterRect(223, 405, 85, 113));

		{
			BoxCollider* collider = new BoxCollider();
			collider->SetCollision(Shape::MakeCenterRect(0, 0, 85, 85));
			mole->AddComponent(collider);
		}

		mole->Init();
		_moles.push_back(mole);
		this->SpawnActor(mole);
	}


	{
		MoleActor* mole = new MoleActor();
		mole->SetBody(Shape::MakeCenterRect(620, 86, 85, 113));

		{
			BoxCollider* collider = new BoxCollider();
			collider->SetCollision(Shape::MakeCenterRect(0, 0, 85, 85));
			mole->AddComponent(collider);
		}

		mole->Init();
		_moles.push_back(mole);
		this->SpawnActor(mole);
	}

	{
		MoleActor* mole = new MoleActor();
		mole->SetBody(Shape::MakeCenterRect(620, 237, 85, 113));

		{
			BoxCollider* collider = new BoxCollider();
			collider->SetCollision(Shape::MakeCenterRect(0, 0, 85, 85));
			mole->AddComponent(collider);
		}

		mole->Init();
		_moles.push_back(mole);
		this->SpawnActor(mole);
	}

	{
		MoleActor* mole = new MoleActor();
		mole->SetBody(Shape::MakeCenterRect(620, 405, 85, 113));

		{
			BoxCollider* collider = new BoxCollider();
			collider->SetCollision(Shape::MakeCenterRect(0, 0, 85, 85));
			mole->AddComponent(collider);
		}

		mole->Init();
		_moles.push_back(mole);
		this->SpawnActor(mole);
	}

	{
		MoleActor* mole = new MoleActor();
		mole->SetBody(Shape::MakeCenterRect(427, 162, 85, 113));

		{
			BoxCollider* collider = new BoxCollider();
			collider->SetCollision(Shape::MakeCenterRect(0, 0, 85, 85));
			mole->AddComponent(collider);
		}

		mole->Init();
		_moles.push_back(mole);
		this->SpawnActor(mole);
	}

	{
		MoleActor* mole = new MoleActor();
		mole->SetBody(Shape::MakeCenterRect(427, 312, 85, 113));

		{
			BoxCollider* collider = new BoxCollider();
			collider->SetCollision(Shape::MakeCenterRect(0, 0, 85, 85));
			mole->AddComponent(collider);
		}

		mole->Init();
		_moles.push_back(mole);
		this->SpawnActor(mole);
	}


	{
		Resource->LoadTexture(L"T_Hammer", L"Mole/hammer.bmp");
		Resource->CreateSprite(L"S_Hammer_Idle", Resource->GetTexture(L"T_Hammer"), 0, 0, 51, 51);
		Resource->CreateSprite(L"S_Hammer_Hit", Resource->GetTexture(L"T_Hammer"), 51, 0, 51, 51);

		HammerActor* _hammer = new HammerActor();
		Sprite* sprite = Resource->GetSprite(L"S_Hammer_Hit");
		_hammer->SetSprite(sprite);
		_hammer->Init();
		this->SpawnActor(_hammer);
	}



	_regenTimer = 0.5f;

}
void MoleGameScene::Render(HDC hdc)
{
	Super::Render(hdc);


	wstring str = L"MoleGameScene";
	::TextOut(hdc, 0, 45, str.c_str(), str.length());


	wstring scoreStr = format(L"score : {0}", score);
	::TextOut(hdc, 390, 20, scoreStr.c_str(), scoreStr.length());
}
void MoleGameScene::Update()
{
	Super::Update();

	//------------------------------------
	//	# 해머 작동 #
	//------------------------------------
	

	//------------------------------------
	//	# 두더지 나오게 하기 #
	//------------------------------------

	// N초마다 랜덤한 두더지가 ChangeState(In) 으로 변한다.


	// n초가 지난다. 델타타임 가져와서 n초가 되면 초기화 되도록 한다.
	// if (0.0f <= _timer)
	/*{
		_timer -= Time->GetDeltaTime();

		if (_timer < 0.0f)
		{
			ChangeState(MoleActorState::In);
		}
	}*/
	// 임의의 두더지를 가져온다
	// 두더지의 상태를 확인한다.
	// 두더지의 상태가 Out인 경우에만 In으로 변경한다.


	// -------선생님 수도코드------
	// 1. n초를 측정한다.
	// -> Timer 사용
	// 1. float timer 선언
	// 2. Init에서 timer = 0.5f;
	// 3. timer -= Time->GetDeltaTime();
	// if(timer <= 0.0f)
	//		if( 두더지상태 == Out)
	//		두더지가 ChangeState(In)으로 변한다
	//	------------------------------------

	_regenTimer -= Time->GetDeltaTime();
	if (_regenTimer <= 0.0f)
	{
		_regenTimer = 0.5f;
		// 랜덤한 두더지가 ChangeState(In)으로 변한다
		// 랜덤한 두더지를 가져오려면 벡터로 두더지들을 받아주어야 한다.
		MoleActor* randomMoleActor = _moles[Random->GetRandomInt(0, _moles.size() - 1)];
		if (randomMoleActor->GetState() == MoleActorState::In)
		{
			randomMoleActor->ChangeState(MoleActorState::Out);
		}
	}



}
void MoleGameScene::Release()
{
	Super::Release();
}
void MoleGameScene::ChangeGameState(MoleGameState state)
{

}
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
	//	# �ظ� �۵� #
	//------------------------------------
	

	//------------------------------------
	//	# �δ��� ������ �ϱ� #
	//------------------------------------

	// N�ʸ��� ������ �δ����� ChangeState(In) ���� ���Ѵ�.


	// n�ʰ� ������. ��ŸŸ�� �����ͼ� n�ʰ� �Ǹ� �ʱ�ȭ �ǵ��� �Ѵ�.
	// if (0.0f <= _timer)
	/*{
		_timer -= Time->GetDeltaTime();

		if (_timer < 0.0f)
		{
			ChangeState(MoleActorState::In);
		}
	}*/
	// ������ �δ����� �����´�
	// �δ����� ���¸� Ȯ���Ѵ�.
	// �δ����� ���°� Out�� ��쿡�� In���� �����Ѵ�.


	// -------������ �����ڵ�------
	// 1. n�ʸ� �����Ѵ�.
	// -> Timer ���
	// 1. float timer ����
	// 2. Init���� timer = 0.5f;
	// 3. timer -= Time->GetDeltaTime();
	// if(timer <= 0.0f)
	//		if( �δ������� == Out)
	//		�δ����� ChangeState(In)���� ���Ѵ�
	//	------------------------------------

	_regenTimer -= Time->GetDeltaTime();
	if (_regenTimer <= 0.0f)
	{
		_regenTimer = 0.5f;
		// ������ �δ����� ChangeState(In)���� ���Ѵ�
		// ������ �δ����� ���������� ���ͷ� �δ������� �޾��־�� �Ѵ�.
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
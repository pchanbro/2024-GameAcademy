#include "pch.h"
#include "PaddleActor.h"

#include "BoxCollider.h"

void PaddleActor::Init()
{
	Super::Init();

	Resource->LoadTexture(L"T_paddle", L"BrickGame/paddle.bmp");
	Resource->CreateSprite(L"S_paddle", Resource->GetTexture(L"T_paddle"));


	this->SetSprite(Resource->GetSprite(L"S_paddle"));

	this->SetName("Paddle");

	BoxCollider* collider = new BoxCollider();
	collider->SetCollision(Shape::MakeCenterRect(0, 0, 108, 21)); // 가운데 기준이기 때문에 
	this->AddComponent(collider);
	this->SetBody(Shape::MakeCenterRect(WIN_SIZE_X / 2, WIN_SIZE_Y - 70, 108, 21));

	_speed = 500;
}

void PaddleActor::Render(HDC hdc)
{
	Super::Render(hdc);

	//_body.Draw(hdc);
}

void PaddleActor::Update()
{
	Super::Update();

	// 굳이 여기에 패들 움직임을 만들지 않고 PlayerController에 만든 이유
	
	// 나중에 네트워크가 추가하게 되면,
	// Paddle이 여러개가 생길수 있습니다.

	// 아니면 나중에 기획적인 요소로 가만히 있어야하는 패들을 추가하게 되면
	// Paddle이 여러개가 생길수 있습니다.

	// 그 패들은 모두 사용자의 입력으로 이동하지 않아요.
	// 그려면 그런 종류의 패들을 새롭게 만들거나 IF로 그 로직을 막으면 되잖아요.

	// 그러면 점점 코드가 더러워져요.

	// 거기에서 이제 따르는 것이 바로 SRP

	// SRP (단일책임원칙)
	// 하나의클래스에는 하나의 기능만하게하는것이 좋다.
}

void PaddleActor::Release()
{
	Super::Release();
}

void PaddleActor::Move(Vector2 moveDir)
{
	if (moveDir.Length() == 0.0f)
	{
		return;
	}

	if (moveDir.y != 0)
	{
		moveDir.y = 0;
		moveDir = moveDir.Normalize();
	}


	_body.pos += moveDir * Time->GetDeltaTime() * _speed;
}
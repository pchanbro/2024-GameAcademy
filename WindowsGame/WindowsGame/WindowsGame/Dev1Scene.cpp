#include "pch.h"
#include "Dev1Scene.h"
#include "PlayerActor.h"
#include "BoxCollider.h"

void Dev1Scene::Init()
{
	// 부모 함수 호출하려면
	// super.Init(); 혹은
	// base.Init();
	// 지금은 헤더파일에 Super 변수 만들어줬으니 이렇게 쓴다.
	Super::Init();

	{
		PlayerActor* player = new PlayerActor();
		player->Init();
		player->SetName("플레이어1");

		BoxCollider* collider = new BoxCollider();
		collider->SetCollision(Shape::MakeCenterRect(0, 0, 100, 100));
		player->AddComponent(collider);
		player->SetBody(Shape::MakeCenterRect(100, 100, 100, 100));
		this->SpawnActor(player);
	}

	{
		PlayerActor* player = new PlayerActor();
		player->Init();
		player->SetName("플레이어2");

		BoxCollider* collider = new BoxCollider();
		collider->SetCollision(Shape::MakeCenterRect(0, 0, 100, 100));
		player->AddComponent(collider);
		player->SetBody(Shape::MakeCenterRect(500, 500, 100, 100));
		this->SpawnActor(player);
	}
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

	
}
void Dev1Scene::Release()
{
	Super::Release();
}
#include "pch.h"
#include "Dev1Scene.h"
#include "PlayerActor.h"
#include "BoxCollider.h"
void Dev1Scene::Init()
{
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
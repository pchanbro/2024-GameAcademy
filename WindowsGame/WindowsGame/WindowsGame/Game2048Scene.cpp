#include "pch.h"
#include "Game2048Scene.h"
#include "BoxCollider.h"
#include "NumBoxActor.h"
#include "Game2048BoardActor.h"

void Game2048Scene::Init()
{
	Super::Init();

	{
		Game2048BoardActor* board = new Game2048BoardActor();
		BoxCollider* collider = new BoxCollider();
		collider->SetCollision(Shape::MakeCenterRect(0, 0, 420, 10));
		board->AddComponent(collider);

		board->SetBody(Shape::MakeCenterRect(WIN_SIZE_X / 2, WIN_SIZE_Y / 2 + 205, 0, 0));
		board->Init();
		this->SpawnActor(board);
	}

	{
		Game2048BoardActor* board = new Game2048BoardActor();
		BoxCollider* collider = new BoxCollider();
		collider->SetCollision(Shape::MakeCenterRect(0, 0, 420, 10));
		board->AddComponent(collider);

		board->SetBody(Shape::MakeCenterRect(WIN_SIZE_X / 2, WIN_SIZE_Y / 2 - 205, 0, 0));
		board->Init();
		this->SpawnActor(board);
	}

	{
		Game2048BoardActor* board = new Game2048BoardActor();
		BoxCollider* collider = new BoxCollider();
		collider->SetCollision(Shape::MakeCenterRect(0, 0, 10, 400));
		board->AddComponent(collider);

		board->SetBody(Shape::MakeCenterRect(WIN_SIZE_X / 2 + 205, WIN_SIZE_Y / 2, 0, 0));
		board->Init();
		this->SpawnActor(board);
	}

	{
		Game2048BoardActor* board = new Game2048BoardActor();
		BoxCollider* collider = new BoxCollider();
		collider->SetCollision(Shape::MakeCenterRect(0, 0, 10, 400));
		board->AddComponent(collider);

		board->SetBody(Shape::MakeCenterRect(WIN_SIZE_X / 2 - 205, WIN_SIZE_Y / 2, 0, 0));
		board->Init();
		this->SpawnActor(board);
	}

	{
		NumBoxActor* box = new NumBoxActor();
		box->Init();
		this->SpawnActor(box);
		box->SetBody(Shape::MakeCenterRect(WIN_SIZE_X / 2 - 150, WIN_SIZE_X / 2 - 150, 0, 0));
	}

	{
		NumBoxActor* box = new NumBoxActor();
		box->Init();
		this->SpawnActor(box);
		box->SetBody(Shape::MakeCenterRect(WIN_SIZE_X / 2 - 50, WIN_SIZE_X / 2 - 150, 0, 0));
	}
}
void Game2048Scene::Render(HDC hdc)
{
	Super::Render(hdc);
}
void Game2048Scene::Update()
{
	Super::Update();
}
void Game2048Scene::Release()
{
	Super::Release();
}
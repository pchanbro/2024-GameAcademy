#include "pch.h"
#include "Game2048Scene.h"
#include "BoxCollider.h"
#include "NumBoxActor.h"

void Game2048Scene::Init()
{
	Super::Init();

	for (int i = 0; i < 16; i++)
	{
		_section[i].X = WIN_SIZE_X / 2 - 200 + ((i % 4) * 100);
		_section[i].Y = WIN_SIZE_Y / 2 - 200 + ((i / 4) * 100);
	}


	{
		NumBoxActor* box = new NumBoxActor();
		box->Init();
		int num = Random->GetRandomInt(0, 15);
		box->SetSectionNum(num);
		_section[num].Existence = true;
		box->SetBody(Shape::MakeCenterRect(_section[num].X, _section[num].Y, 0, 0));
		_boxes.push_back(box);
		this->SpawnActor(box);
	}

}
void Game2048Scene::Render(HDC hdc)
{
	Super::Render(hdc);
}
void Game2048Scene::Update()
{
	Super::Update();

	for (NumBoxActor* box : _boxes)
	{
		_section[box->GetSectionNum()].Existence = true;
		_targetPos = Vector2(_section[box->GetSectionNum()].X, _section[box->GetSectionNum()].Y);
		_tempPos = box->GetPos();
		_playerDir = (_targetPos - _tempPos).Normalize();

		if (0.1 < (_targetPos - _tempPos).Length())
		{
			_tempPos += _playerDir * (Time->GetDeltaTime() * 1000);
			box->SetBody(Shape::MakeCenterRect(_tempPos.x, _tempPos.y, 0, 0));
		}
	}
}
void Game2048Scene::Release()
{
	Super::Release();
}

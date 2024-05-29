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

	//Controller
	// Controller << _boxes 를 참조
	// Controller ->
	// 키보드 입력에따라서
	// NumBoxActor를 어디로 이동해라!

	{
		NumBoxActor* box = new NumBoxActor();
		box->Init();
		int num = Random->GetRandomInt(0, 15);
		box->SetSectionNum(num);
		box->SetPrevSectionNum(num);
		_section[num].Existence = true;
		box->SetBody(Shape::MakeCenterRect(_section[num].X, _section[num].Y, 0, 0));
		_boxes.push_back(box);
		this->SpawnActor(box);
	}

	{
		NumBoxActor* box = new NumBoxActor();
		box->Init();
		int num = Random->GetRandomInt(0, 15);
		while (_section[num].Existence == true)
		{
			num = Random->GetRandomInt(0, 15);
		}
		box->SetSectionNum(num);
		box->SetPrevSectionNum(num);
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
		_section[box->GetPrevSectionNum()].Existence = false;
		_targetPos = Vector2(_section[box->GetSectionNum()].X, _section[box->GetSectionNum()].Y);
		_section[box->GetSectionNum()].Existence = true;
		_tempPos = box->GetPos();
		_playerDir = (_targetPos - _tempPos).Normalize();
		
		if (0.1 < (_targetPos - _tempPos).Length())
		{
			box->SetMoving(true);
			_tempPos += _playerDir * (Time->GetDeltaTime() * 1000);
			box->SetBody(Shape::MakeCenterRect(_tempPos.x, _tempPos.y, 0, 0));
		}
		else
		{
			box->SetMoving(false);
		}
	}

	if (Input->GetKeyDown(KeyCode::Right))
	{
		for (NumBoxActor* box1 : _boxes)
		{
			for (NumBoxActor* box2 : _boxes)
			{
				if (box1->GetSectionNum() == box2->GetSectionNum())
				{
					if (box2->GetPrevSectionNum() < box1->GetPrevSectionNum())
					{
						if (box1->GetNumber() == box2->GetNumber())
						{
							_section[box2->GetSectionNum()].Existence = false;
							this->DespawnActor(box2);
							auto findIt = find(_boxes.begin(), _boxes.end(), box2); 
							if (findIt != _boxes.end())
							{
								_boxes.erase(findIt);
							}
							box1->SetNumber(box1->GetNumber() * 2);
						}
						else if (box2->DoLeftMove())
						{
							box2->SetSectionNum(box2->GetSectionNum() - 1);
							_section[box2->GetPrevSectionNum()].Existence = false;
							_section[box2->GetSectionNum()].Existence = true;
						}
					}
				}
			}
		}
	}

	if (Input->GetKeyDown(KeyCode::Left))
	{
		for (NumBoxActor* box1 : _boxes)
		{
			for (NumBoxActor* box2 : _boxes)
			{
				if (box1->GetSectionNum() == box2->GetSectionNum())
				{
					if (box1->GetPrevSectionNum() < box2->GetPrevSectionNum())
					{
						if (box1->GetNumber() == box2->GetNumber())
						{
							_section[box2->GetSectionNum()].Existence = false;
							this->DespawnActor(box2);
							auto findIt = find(_boxes.begin(), _boxes.end(), box2);
							if (findIt != _boxes.end())
							{
								_boxes.erase(findIt);
							}
							box2->SetNumber(box1->GetNumber() * 2);
						}
						else if (box2->DoRightMove())
						{
							box2->SetSectionNum(box2->GetSectionNum() + 1);
							_section[box2->GetPrevSectionNum()].Existence = false;
							_section[box2->GetSectionNum()].Existence = true;
						}
					}
				}
			}
		}
	}

	if (Input->GetKeyDown(KeyCode::Down))
	{
		for (NumBoxActor* box1 : _boxes)
		{
			for (NumBoxActor* box2 : _boxes)
			{
				if (box1->GetSectionNum() == box2->GetSectionNum())
				{
					if (box2->GetPrevSectionNum() < box1->GetPrevSectionNum())
					{
						if (box1->GetNumber() == box2->GetNumber())
						{
							_section[box2->GetSectionNum()].Existence = false;
							this->DespawnActor(box2);
							auto findIt = find(_boxes.begin(), _boxes.end(), box2);
							if (findIt != _boxes.end())
							{
								_boxes.erase(findIt);
							}
							box1->SetNumber(box1->GetNumber() * 2);
						}
						else if (box2->DoUpMove())
						{
							box2->SetSectionNum(box2->GetSectionNum() - 4);
							_section[box2->GetPrevSectionNum()].Existence = false;
							_section[box2->GetSectionNum()].Existence = true;
						}
					}
				}
			}
		}
	}

	if (Input->GetKeyDown(KeyCode::Up))
	{
		for (NumBoxActor* box1 : _boxes)
		{
			for (NumBoxActor* box2 : _boxes)
			{
				if (box1->GetSectionNum() == box2->GetSectionNum())
				{
					if (box1->GetPrevSectionNum() < box2->GetPrevSectionNum())
					{
						if (box1->GetNumber() == box2->GetNumber())
						{
							_section[box2->GetSectionNum()].Existence = false;
							this->DespawnActor(box2);
							auto findIt = find(_boxes.begin(), _boxes.end(), box2);
							if (findIt != _boxes.end())
							{
								_boxes.erase(findIt);
							}
							box1->SetNumber(box1->GetNumber() * 2);
						}
						else if (box2->DoUpMove())
						{
							box2->SetSectionNum(box2->GetSectionNum() + 4);
							_section[box2->GetPrevSectionNum()].Existence = false;
							_section[box2->GetSectionNum()].Existence = true;
						}
					}
				}
			}
		}
	}

	if (IsBoxesMove() && IsSectionNotFull())
	{
		NumBoxActor* box = new NumBoxActor();
		box->Init();
		int num = Random->GetRandomInt(0, 15);
		while (_section[num].Existence == true)
		{
			num = Random->GetRandomInt(0, 15);
		}
		box->SetSectionNum(num);
		box->SetPrevSectionNum(num);
		_section[num].Existence = true;
		box->SetBody(Shape::MakeCenterRect(_section[num].X, _section[num].Y, 0, 0));
		_boxes.push_back(box);
		this->SpawnActor(box);
	}
}
void Game2048Scene::Release()
{
	Super::Release();
}

bool Game2048Scene::IsBoxesMove()
{
	if (Input->GetKeyDown(KeyCode::Down) ||
		Input->GetKeyDown(KeyCode::Up) ||
		Input->GetKeyDown(KeyCode::Left) ||
		Input->GetKeyDown(KeyCode::Right))
	{
		return true;
	}

	return false;
}

bool Game2048Scene::IsSectionNotFull()
{
	for (int i = 0; i < 16; i++)
	{
		if (_section[i].Existence == false)
		{
			return true;
		}
	}

	return false;
}
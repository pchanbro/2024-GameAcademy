#include "pch.h"
#include "NumBoxActor.h"
#include "BoxCollider.h"
#include "Game2048Scene.h"

void NumBoxActor::Init()
{
	Super::Init();

	BoxCollider* collider = new BoxCollider();
	collider->SetCollision(Shape::MakeCenterRect(0, 0, 90, 90));
	this->AddComponent(collider);

}
void NumBoxActor::Render(HDC hdc)
{
	Super::Render(hdc);

	wstring timeStr = format(L"{0}", this->_number);
	::TextOut(hdc, this->GetBody().pos.x - 5, this->GetBody().pos.y - 5, timeStr.c_str(), timeStr.length());
}
void NumBoxActor::Update()
{
	Super::Update();

	this->Move();
}
void NumBoxActor::Release()
{
	Super::Release();
}

void NumBoxActor::Move()
{
	if (Input->GetKeyDown(KeyCode::Right))
	{
		for (int i = 0; i < 3; i++)
		{
			if (IsRightMove())
			{
				_sectionNum++;
			}
		}
	}

	if (Input->GetKeyDown(KeyCode::Left))
	{
		for (int i = 0; i < 3; i++)
		{
			if (IsLeftMove())
			{
				_sectionNum--;
			}
		}
	}

	if (Input->GetKeyDown(KeyCode::Down))
	{
		for (int i = 0; i < 3; i++)
		{
			if (IsDownMove())
			{
				_sectionNum += 4;
			}
		}
	}

	if (Input->GetKeyDown(KeyCode::Up))
	{
		for (int i = 0; i < 3; i++)
		{
			if (IsUpMove())
			{
				_sectionNum -= 4;
			}
		}
	}
}

bool NumBoxActor::IsRightMove()
{
	if ((_sectionNum % 4) < 3)
	{
		return true;
	}

	return false;
}

bool NumBoxActor::IsLeftMove()
{
	if ( 0 < (_sectionNum % 4))
	{
		return true;
	}

	return false;
}

bool NumBoxActor::IsDownMove()
{
	if ((_sectionNum / 4) < 3)
	{
		return true;
	}

	return false;
}

bool NumBoxActor::IsUpMove()
{
	if (0 < (_sectionNum / 4))
	{
		return true;
	}

	return false;
}
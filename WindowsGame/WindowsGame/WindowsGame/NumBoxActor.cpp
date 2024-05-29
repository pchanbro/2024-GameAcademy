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

	if (!_moving)
	{
		if (Input->GetKeyDown(KeyCode::Right))
		{
			_prevSectionNum = _sectionNum;
			for (int i = 0; i < 3; i++)
			{
				if (DoRightMove())
				{
					_sectionNum++;
				}
			}
		}

		if (Input->GetKeyDown(KeyCode::Left))
		{
			_prevSectionNum = _sectionNum;
			for (int i = 0; i < 3; i++)
			{
				if (DoLeftMove())
				{
					_sectionNum--;
				}
			}
		}

		if (Input->GetKeyDown(KeyCode::Down))
		{
			_prevSectionNum = _sectionNum;
			for (int i = 0; i < 3; i++)
			{
				if (DoDownMove())
				{
					_sectionNum += 4;
				}
			}
		}

		if (Input->GetKeyDown(KeyCode::Up))
		{
			_prevSectionNum = _sectionNum;
			for (int i = 0; i < 3; i++)
			{
				if (DoUpMove())
				{
					_sectionNum -= 4;
				}
			}
		}
	}
}

bool NumBoxActor::DoRightMove()
{
	if ((_sectionNum % 4) < 3)
	{
		return true;
	}

	return false;
}

bool NumBoxActor::DoLeftMove()
{
	if ( 0 < (_sectionNum % 4))
	{
		return true;
	}

	return false;
}

bool NumBoxActor::DoDownMove()
{
	if ((_sectionNum / 4) < 3)
	{
		return true;
	}

	return false;
}

bool NumBoxActor::DoUpMove()
{
	if (0 < (_sectionNum / 4))
	{
		return true;
	}

	return false;
}

//void NumBoxActor::IsAlreadyExist(NumBoxActor* other)
//{
//
//	if (Input->GetKeyDown(KeyCode::Right))
//	{
//		if (_sectionNum == other->GetSectionNum())
//		{
//			if (_prevSectionNum < other->GetPrevSectionNum())
//			{
//				if (_number == other->GetNumber())
//				{
//					other->SetNumber(other->GetNumber() + _number);
//					Scene* scene = CurrentScene;
//					scene->DespawnActor(this);
//				}
//
//				if (DoLeftMove())
//				{
//					_sectionNum--;
//				}
//			}
//		}
//	}
//
//	if (Input->GetKeyDown(KeyCode::Left))
//	{
//		if (_sectionNum == other->GetSectionNum())
//		{
//			if (other->GetPrevSectionNum() < _prevSectionNum)
//			{
//				if (_number == other->GetNumber())
//				{
//					other->SetNumber(other->GetNumber() + _number);
//					Scene* scene = CurrentScene;
//					scene->DespawnActor(this);
//				}
//
//				if (DoRightMove())
//				{
//					_sectionNum++;
//				}
//			}
//		}
//	}
//
//	if (Input->GetKeyDown(KeyCode::Down))
//	{
//		if (_sectionNum == other->GetSectionNum())
//		{
//			if (_prevSectionNum < other->GetPrevSectionNum())
//			{
//				if (_number == other->GetNumber())
//				{
//					other->SetNumber(other->GetNumber() + _number);
//					Scene* scene = CurrentScene;
//					scene->DespawnActor(this);
//				}
//
//				if (DoUpMove())
//				{
//					_sectionNum -= 4;
//				}
//			}
//		}
//	}
//
//	if (Input->GetKeyDown(KeyCode::Up))
//	{
//		if (_sectionNum == other->GetSectionNum())
//		{
//			if (other->GetPrevSectionNum() < _prevSectionNum)
//			{
//				if (_number == other->GetNumber())
//				{
//					other->SetNumber(other->GetNumber() + _number);
//					Scene* scene = CurrentScene;
//					scene->DespawnActor(this);
//				}
//
//				if (DoDownMove())
//				{
//					_sectionNum += 4;
//				}
//			}
//		}
//	}
//}

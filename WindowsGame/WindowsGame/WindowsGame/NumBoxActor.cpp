#include "pch.h"
#include "NumBoxActor.h"
#include "BoxCollider.h"

void NumBoxActor::Init()
{
	Super::Init();

	this->SetName("NumBox");

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
void NumBoxActor::OnTriggerEnter(Collider* collider, Collider* other)
{
	Super::OnTriggerEnter(collider, other);

	if (other->GetOwner()->GetName() == "Board")
	{
		if (Input->GetKeyDown(KeyCode::Right))
		{
			_body.pos.x -= 10;
		}

		if (Input->GetKeyDown(KeyCode::Left))
		{
			_body.pos.x += 10;
		}

		if (Input->GetKeyDown(KeyCode::Down))
		{
			_body.pos.y -= 10;
		}

		if (Input->GetKeyDown(KeyCode::Up))
		{
			_body.pos.y += 10;
		}
	}

	if (other->GetOwner()->GetName() == "NumBox")
	{
		if (Input->GetKeyDown(KeyCode::Right))
		{
			//if(other->GetOwner()->)
			_body.pos.x -= 10;
		}

		if (Input->GetKeyDown(KeyCode::Left))
		{
			_body.pos.x += 10;
		}

		if (Input->GetKeyDown(KeyCode::Down))
		{
			_body.pos.y -= 10;
		}

		if (Input->GetKeyDown(KeyCode::Up))
		{
			_body.pos.y += 10;
		}
	}
}

void NumBoxActor::Move()
{
	if (Input->GetKeyDown(KeyCode::Right))
	{
		_body.pos.x += 400;
	}
	
	if (Input->GetKeyDown(KeyCode::Left))
	{
		_body.pos.x -= 400;
	}

	if (Input->GetKeyDown(KeyCode::Down))
	{
		_body.pos.y += 400;
	}

	if (Input->GetKeyDown(KeyCode::Up))
	{
		_body.pos.y -= 400;
	}
}

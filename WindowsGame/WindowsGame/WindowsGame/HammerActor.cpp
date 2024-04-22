#include "pch.h"
#include "HammerActor.h"
#include "BoxCollider.h"
#include "Dev2Scene.h"

void HammerActor::Init()
{
	Super::Init();

	this->SetName("Hammer");
	BoxCollider* collider = new BoxCollider();
	collider->SetCollision(Shape::MakeCenterRect(0, 0, 100, 100));
	this->AddComponent(collider);
	this->SetBody(Shape::MakeCenterRect(500, 500, 100, 100));
}
void HammerActor::Render(HDC hdc)
{
	Super::Render(hdc);

	_body.Draw(hdc);
}
void HammerActor::Update()
{
	Super::Update();

	{
		POINT mousePos = Input->GetMousePos();
		_body.pos.x = mousePos.x;
		_body.pos.y = mousePos.y;
	}
}
void HammerActor::Release()
{
	Super::Release();

}

void HammerActor::CrushMole()
{

}
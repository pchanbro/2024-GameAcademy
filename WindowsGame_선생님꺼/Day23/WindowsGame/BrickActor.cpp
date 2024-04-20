#include "pch.h"
#include "BrickActor.h"
#include "BoxCollider.h"

void BrickActor::Init()
{
	Super::Init();

	this->SetName("Brick");

	BoxCollider* collider = new BoxCollider();
	collider->SetCollision(Shape::MakeCenterRect(0, 0, 150, 30));
	this->AddComponent(collider);

}

void BrickActor::Render(HDC hdc)
{
	Super::Render(hdc);
	_body.Draw(hdc);
}

void BrickActor::Update()
{
	Super::Update();
}

void BrickActor::Release()
{
	Super::Release();
}
void BrickActor::OnTriggerEnter(Collider* collider, Collider* other)
{
	Super::OnTriggerEnter(collider, other);

}
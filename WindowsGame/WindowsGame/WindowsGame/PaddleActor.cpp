#include "pch.h"
#include "PaddleActor.h"

#include "BoxCollider.h"

#include "BoxCollider.h"

void PaddleActor::Init()
{
	Super::Init();

	this->SetName("Paddle");

	BoxCollider* collider = new BoxCollider();
	collider->SetCollision(Shape::MakeCenterRect(0, 0, 100, 100));
	this->AddComponent(collider);
	this->SetBody(Shape::MakeCenterRect(100, 100, 100, 100));
}

void PaddleActor::Render(HDC hdc)
{
	Super::Render(hdc);

	_body.Draw(hdc);
}

void PaddleActor::Update()
{
	Super::Update();
}

void PaddleActor::Release()
{
	Super::Release();
}
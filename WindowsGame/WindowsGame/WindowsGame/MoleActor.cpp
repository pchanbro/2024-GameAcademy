#include "pch.h"
#include "MoleActor.h"
#include "BoxCollider.h"
#include "Dev2Scene.h"

void MoleActor::Init()
{
	Super::Init();

	this->SetName("Mole");
	BoxCollider* collider = new BoxCollider();
	collider->SetCollision(Shape::MakeCenterRect(0, 0, 200, 200));
	this->AddComponent(collider);
}
void MoleActor::Render(HDC hdc)
{
	Super::Render(hdc);

	_body.Draw(hdc);
}
void MoleActor::Update()
{
	Super::Update();

	if (Input->GetKeyDown(KeyCode::RightMouse))
	{
		
	}

}
void MoleActor::Release()
{
	Super::Release();

}

void MoleActor::OnTriggerEnter(Collider* collider, Collider* other)
{
	Super::OnTriggerEnter(collider, other);

	if ((other->GetOwner()->GetName() == "Hammer") && (Input->GetKeyDown(KeyCode::RightMouse)))
	{
		GET_SINGLE(SceneManager)->GetCurrentScene()->DespawnActor(this);
		this->existence = false;
	}
}
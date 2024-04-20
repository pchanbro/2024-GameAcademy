#include "pch.h"
#include "BrickActor.h"
#include "BoxCollider.h"
#include "InGameScene.h"


void BrickActor::Init()
{
	Super::Init();

	this->SetName("Brick");

	BoxCollider* collider = new BoxCollider();
	collider->SetCollision(Shape::MakeCenterRect(0, 0, WIN_SIZE_X / 10 - 1, 25));
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

// ���� �ۿ��� �Ͼ�°� ���ϴ� �ʿ��� �߻���Ű�°� ����.
void BrickActor::OnTriggerEnter(Collider* collider, Collider* other)
{
	Super::OnTriggerEnter(collider, other);

	if (other->GetOwner()->GetName() == "Ball")
	{
		GET_SINGLE(SceneManager)->GetCurrentScene()->DespawnActor(this);
	}
}
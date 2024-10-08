#include "pch.h"
#include "BrickActor.h"
#include "BoxCollider.h"
#include "InGameScene.h"


void BrickActor::Init()
{
	Super::Init();


	for (int i = 0; i < 4; i++)
	{
		wstring textureKey = ::format(L"T_brick_{0}", i);
		wstring texturePath = ::format(L"BrickGame/brick_{0}.bmp", i);
		wstring spriteKey = ::format(L"S_brick_{0}", i);
		Resource->LoadTexture(textureKey, texturePath);
		Resource->CreateSprite(spriteKey, Resource->GetTexture(textureKey));
	}

	wstring spriteKey = ::format(L"S_brick_{0}", Random->GetRandomInt(0, 3));
	this->SetSprite(Resource->GetSprite(spriteKey));


	this->SetName("Brick");
	BoxCollider* collider = new BoxCollider();
	collider->SetCollision(Shape::MakeCenterRect(0, 0, 45, 22));
	this->AddComponent(collider);
}

void BrickActor::Render(HDC hdc)
{
	Super::Render(hdc);

	//_body.Draw(hdc);
}

void BrickActor::Update()
{
	Super::Update();
}

void BrickActor::Release()
{
	Super::Release();
}

// 뭔가 작용이 일어나는건 당하는 쪽에서 발생시키는게 좋다.
void BrickActor::OnTriggerEnter(Collider* collider, Collider* other)
{
	Super::OnTriggerEnter(collider, other);

	if (other->GetOwner()->GetName() == "Ball")
	{
		GET_SINGLE(SceneManager)->GetCurrentScene()->DespawnActor(this);
	}
}
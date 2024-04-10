#include "pch.h"
#include "BoxCollider.h"

void BoxCollider::Init()
{
	Super::Init();
}
void BoxCollider::Render(HDC hdc)
{
	Super::Render(hdc);

}
void BoxCollider::Update()
{
	Super::Update();

}
void BoxCollider::Release()
{
	Super::Release();

}
bool BoxCollider::CheckCollision(Collider* other)
{
	switch (other->GetColliderType())
	{
	case ColliderType::Circle:
		return false;
		break;
	case ColliderType::Box:
	{
		BoxCollider* otherCollider = static_cast<BoxCollider*>(other);
		CenterRect otherCollision = otherCollider->GetCollision();
		return Collision::RectInRect(this->GetCollision().ToRect(), otherCollision.ToRect());
	}


		break;
	default:
		return false;
		break;
	}
	return false;
}

BoxCollider::BoxCollider() : Collider(ColliderType::Box)
{
	_collision = {};
}
BoxCollider::~BoxCollider()
{

}
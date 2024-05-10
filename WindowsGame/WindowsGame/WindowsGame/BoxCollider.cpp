#include "pch.h"
#include "BoxCollider.h"
#include "Actor.h"
#include "CircleCollider.h"
#include "Scene.h"

void BoxCollider::Init()
{
	Super::Init();
}
void BoxCollider::Render(HDC hdc)
{
	Super::Render(hdc);

	// 아래서 this->GetCollision().Draw(hdc); 이거 하면서 만든 네모를 투명하게 만들어주는 과정
	HBRUSH emptyBrush = GetStockBrush(NULL_BRUSH);  
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, emptyBrush);

	CenterRect renderRect = this->GetCollision();
	Vector2Int cameraPos = CurrentScene->GetCameraPos();
	Vector2Int screenSizeHalf = Vector2Int(WIN_SIZE_X / 2, WIN_SIZE_Y / 2);
	renderRect.pos.x = renderRect.pos.x - cameraPos.x + screenSizeHalf.x;
	renderRect.pos.y = renderRect.pos.y - cameraPos.y + screenSizeHalf.y;

	this->GetCollision().Draw(hdc);

	// 앞으로 만들것들도 투명하면 곤란하니 원래대로 돌려주는 과정
	SelectObject(hdc, oldBrush);  
	DeleteObject(emptyBrush);

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
	{

		CircleCollider* otherCollider = static_cast<CircleCollider*>(other);
		Vector2 otherColliderPos = otherCollider->GetCollisionPos();
		float otherColliderRadius = otherCollider->GetRadius();
		return Collision::RectInCircle(this->GetCollision(), otherColliderPos, otherColliderRadius);

		return false;
	}
		break;
	case ColliderType::Box:
	{
		BoxCollider* otherCollider = static_cast<BoxCollider*>(other);// 원래 dynamic_cast로 가져오는게 맞는데 현재 기준(Day21) 확실히 될거기 때문에 dynamic_cast보다 빠른 static_cast를 사용한다.
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

// 자식에서 부모생성자 사용가능
BoxCollider::BoxCollider() : Collider(ColliderType::Box)
{
	_collision = {};
}
BoxCollider::~BoxCollider()
{

}

CenterRect BoxCollider::GetCollision()
{
	CenterRect rect;
	rect.pos.x = this->_collision.pos.x + this->_owner->GetBody().pos.x;
	rect.pos.y = this->_collision.pos.y + this->_owner->GetBody().pos.y;
	rect.width = this->_collision.width;
	rect.height = this->_collision.height;

	return rect;
}
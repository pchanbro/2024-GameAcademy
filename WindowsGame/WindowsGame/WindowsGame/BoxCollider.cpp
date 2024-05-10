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

	// �Ʒ��� this->GetCollision().Draw(hdc); �̰� �ϸ鼭 ���� �׸� �����ϰ� ������ִ� ����
	HBRUSH emptyBrush = GetStockBrush(NULL_BRUSH);  
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, emptyBrush);

	CenterRect renderRect = this->GetCollision();
	Vector2Int cameraPos = CurrentScene->GetCameraPos();
	Vector2Int screenSizeHalf = Vector2Int(WIN_SIZE_X / 2, WIN_SIZE_Y / 2);
	renderRect.pos.x = renderRect.pos.x - cameraPos.x + screenSizeHalf.x;
	renderRect.pos.y = renderRect.pos.y - cameraPos.y + screenSizeHalf.y;

	this->GetCollision().Draw(hdc);

	// ������ ����͵鵵 �����ϸ� ����ϴ� ������� �����ִ� ����
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
		BoxCollider* otherCollider = static_cast<BoxCollider*>(other);// ���� dynamic_cast�� �������°� �´µ� ���� ����(Day21) Ȯ���� �ɰű� ������ dynamic_cast���� ���� static_cast�� ����Ѵ�.
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

// �ڽĿ��� �θ������ ��밡��
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
#include "pch.h"
#include "Collider.h"

void Collider::Init()
{
	Super::Init();

	GET_SINGLE(CollisionManager)->AddCollider(this);
}
void Collider::Render(HDC hdc)
{
	Super::Render(hdc);

}
void Collider::Update()
{
	Super::Update();

}
void Collider::Release()
{
	Super::Release();

	GET_SINGLE(CollisionManager)->RemoveCollider(this);

}
bool Collider::CheckCollision(Collider* other)
{
	// flag 검사

	// 나 => other를 검사할 자격이 있는지
	// other가 나를 검사할 자격이 있는지

	uint8 otherLayer = other->GetCollisionLayer();

	if (0 < (_collisionFlag & (1 << otherLayer)))
	{
		uint8 myLayer = this->GetCollisionLayer();
		// Other => 나를 검사할 자격이 있는지
		if (0 < (other->GetCollisionFlag() & (1 << myLayer)))
		{
			return true;
		}
	}

	return true;
}

// 실습 : 함수 두개 구현하기.
void Collider::AddCollisionFlagLayer(CollisionLayerType layer)
{
	// 0000 0000 0000 0111  ==> 4
	// 
	// 
	// CLT_DEFAULT  0(0x01) 0001
	// CLT_CREATURE 1(0x02) 0010
	// CLT_ITEM     2(0x04) 0100
	// CLT_ITEM2    3
	// CLT_ITEM3    4
	
	
	// _flag => 0010
	// layer => CLT_ITEM (0100)
	// _flag => 0110

#define CLT_ITEM1 0x01
#define CLT_ITEM2 0x02
#define CLT_ITEM3 0x04

	
	_collisionFlag = (1 << layer) | _collisionFlag;

}

void Collider::RemoveCollisionFlagLayer(CollisionLayerType layer)
{
	// CLT_DEFAULT  (0x01) 0001
	// CLT_CREATURE (0x02) 0010
	// CLT_ITEM     (0x04) 0100

	// _flag => 0011
	// layer => CLT_ITEM (0010)
	// _flag => 0001

	_collisionFlag = ~(1 << layer) & _collisionFlag;

}
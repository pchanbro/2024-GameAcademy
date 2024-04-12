#include "pch.h"
#include "CollisionManager.h"
#include "Collider.h"
#include "Actor.h"

void CollisionManager::Init()
{

}
void CollisionManager::Update()
{
	// 실질적인 충돌체크 처리

	// 모든 Collider를 한번씩 비교한다. (CheckCollision함수 사용)
	// 충돌되었으면
	//		충돌 Map에 있는지 확인
	//		충돌 Map안에 없으면
	//			충돌 Map에 넣어준다
	//			충돌되었다고 Actor에 알림
	// 충돌이 안되어 있으면 
	//		충돌 Map에 있는지 확인
	//		충돌 Map에 있으면
	//			충돌 Map에서 꺼내준다.
	//			충돌끝났다고 Actor에 알림

	for (int i = 0; i < _colliders.size(); i++)
	{
		Collider* c1 = _colliders[i];
		for (int j = i + 1; j < _colliders.size(); j++)
		{
			Collider* c2 = _colliders[j];

			// 충돌이 되었으면
			if (c1->CheckCollision(c2))
			{
				// 충돌 Map안에 없으면
				if (false == c1->_collisionMap.contains(c2))
				{
					// 충돌 Map에 넣어준다.
					c1->_collisionMap.insert(c2);
					c2->_collisionMap.insert(c1);
					// 충돌되었다고 Actor에 알림.
					c1->GetOwner()->OnTriggerEnter(c1, c2);
					c2->GetOwner()->OnTriggerEnter(c2, c1);

				}
			}
			// 충돌이 안되어 있으면 
			else
			{
				// 충돌 Map에 있으면
				if (true == c1->_collisionMap.contains(c2))
				{
					c1->_collisionMap.erase(c2);
					c2->_collisionMap.erase(c1);
					// 충돌되었다고 Actor에 알림.
					c1->GetOwner()->OnTriggerExit(c1, c2);
					c2->GetOwner()->OnTriggerExit(c2, c1);
				}
			}
		}
	}
}
void CollisionManager::AddCollider(Collider* collider)
{
	_colliders.push_back(collider);
	// 이럴거면 _colliders를 public으로 만드는게 낫지 않나?
	// 하지만 변수 자체를 노출시키지 않는것이 좋다.
	// 함수는 로그를 추적, 찾기가 쉬운데, 변수는 찾기 어렵기 때문이다.(변수명을 바꾼다거나 하면 진짜 곤란함)
}
void CollisionManager::RemoveCollider(Collider* collider)
{
	// 지울때 쓰는거
	auto findIt = find(_colliders.begin(), _colliders.end(), collider);

	if (findIt != _colliders.end())
	{
		_colliders.erase(findIt);
	}
}
void CollisionManager::ClearCollider()
{
	_colliders.clear();
}
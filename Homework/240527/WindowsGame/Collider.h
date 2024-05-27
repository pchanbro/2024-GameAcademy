#pragma once
#include "Component.h"
class Collider : public Component
{
protected:
	ColliderType _colliderType;

	// 나는 누구인지에 대한 변수
	CollisionLayerType _collisionLayer = CLT_DEFAULT;
	// 이 오브젝트가 충돌할 layer는 무엇인지?
	uint32 _collisionFlag = ~0; // 0xFFFFFFFF; (모든 레이어랑 충돌할거다.)

public:
	unordered_set<Collider*> _collisionMap;
	// binary트리 같은 모습에서 수가 지저분하게 추가되도 자동 정렬을 해주진 않겠다. 같은 느낌으로 쓰는 것

public:
	// 상속받은 것은 이 구조를 써줘라
	using Super = Component;

public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

public:
	//충돌되었는지 체크.
	virtual bool CheckCollision(Collider* other);
	ColliderType GetColliderType() { return _colliderType; }

public:
	uint32 GetCollisionFlag() { return _collisionFlag; }
	void SetCollisionFlag(uint32 collisionFlag) { _collisionFlag = collisionFlag; }

	void AddCollisionFlagLayer(CollisionLayerType layer);
	void RemoveCollisionFlagLayer(CollisionLayerType layer);
	void ResetCollisionFlag() { _collisionFlag = 0; }

	CollisionLayerType GetCollisionLayer() { return _collisionLayer; }
	void SetCollisionLayer(CollisionLayerType collisionLayer) { _collisionLayer = collisionLayer; }
public:
	Collider(ColliderType colliderType) { _colliderType = colliderType; }
	virtual ~Collider() {}
};


// 생성자 소멸자 순서
// Collider 생성자 소멸자 호출순서

// Component 생성자 함수
// Collider 생성자 함수
// Collider 소멸자 함수
// Component 소멸자 함수
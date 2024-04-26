#pragma once
#include "Component.h"
class Collider : public Component
{
protected:
	ColliderType _colliderType;

public:
	unordered_set<Collider*> _collisionMap; 
	// binaryƮ�� ���� ������� ���� �������ϰ� �߰��ǵ� �ڵ� ������ ������ �ʰڴ�. ���� �������� ���� ��

public:
	// ��ӹ��� ���� �� ������ �����
	using Super = Component;

public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

public:
	//�浹�Ǿ����� üũ.
	virtual bool CheckCollision(Collider* other);
	ColliderType GetColliderType() { return _colliderType; }

public:
	Collider(ColliderType colliderType) { _colliderType = colliderType; }
	virtual ~Collider() {}
};


// ������ �Ҹ��� ����
// Collider ������ �Ҹ��� ȣ�����

// Component ������ �Լ�
// Collider ������ �Լ�
// Collider �Ҹ��� �Լ�
// Component �Ҹ��� �Լ�
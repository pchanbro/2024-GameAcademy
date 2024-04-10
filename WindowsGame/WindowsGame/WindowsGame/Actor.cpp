#include "pch.h"
#include "Actor.h"
#include "Component.h"
#include "Collider.h"

void Actor::OnTriggerEnter(Collider* collider, Collider* other)
{
	printf("�浹 ���� : {%s} -> {%s}\n", collider->GetOwner()->GetName().c_str(), other->GetOwner()->GetName().c_str());
}
void Actor::OnTriggerExit(Collider* collider, Collider* other)
{
	printf("�浹 �� : {%s} -> {%s}\n", collider->GetOwner()->GetName().c_str(), other->GetOwner()->GetName().c_str());

}


void Actor::Init()
{

}
void Actor::Render(HDC hdc)
{
	for (Component* component : _components)
	{
		component->Render(hdc);
	}
}
void Actor::Update()
{
	for (Component* component : _components)
	{
		component->Update();
	}
}
void Actor::Release()
{
	for (Component* component : _components)
	{
		component->Release();
		SAFE_DELETE(component);
	}
	_components.clear();
}
void Actor::AddComponent(Component* component)
{
	if (component == nullptr) return; 
	// ������ ���ٷ� ���� ���� �ߴµ� ���� �̷��� �� �ٷ� ���� ����
	// ���� �ڵ�� ������Ʈ �Ӽ��� ���� �޶����� ����
	// ���� �ۼ��� �� �κ���
	// �������� ����(������ ������)�� ������ ������ ���� �����ڵ�
	// �׸��� ������� 0.000000000001�� ���̰� ���� ������ ������ �ߴ�.

	component->SetOwner(this);
	component->Init();  // ���⼭ Init�� ���ִϱ� ���� Init �Լ����� �����ʿ�� ����.
	_components.push_back(component);
}
void Actor::RemoveComponent(Component* component)
{
	// ���� auto �������� �س��� �� ����?
	// Iterator�� �Ⱦ��� �ʹ� ������� ���⼭ auto�� �׳� ����.
	auto findIt = find(_components.begin(), _components.end(), component);

	if (findIt != _components.end())
	{
		Component* deleteComponent = *findIt;
		deleteComponent->Release();
		SAFE_DELETE(deleteComponent);
		_components.erase(findIt);
	}
}
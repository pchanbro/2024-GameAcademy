#include "pch.h"
#include "Actor.h"
#include "Component.h"
#include "Collider.h"

void Actor::OnTriggerEnter(Collider* collider, Collider* other)
{
	printf("충돌 시작 : {%s} -> {%s}\n", collider->GetOwner()->GetName().c_str(), other->GetOwner()->GetName().c_str());
}
void Actor::OnTriggerExit(Collider* collider, Collider* other)
{
	printf("충돌 끝 : {%s} -> {%s}\n", collider->GetOwner()->GetName().c_str(), other->GetOwner()->GetName().c_str());

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
	// 예전엔 한줄로 쓰지 말라 했는데 지금 이렇게 한 줄로 쓰는 이유
	// 좋은 코드는 프로젝트 속성에 따라 달라지기 때문
	// 지금 작성한 저 부분은
	// 따지고보면 유저(컨텐츠 개발자)가 개입할 여지가 없는 엔진코드
	// 그리고 띄워쓰면 0.000000000001초 차이가 나기 때문에 저렇게 했다.

	component->SetOwner(this);
	component->Init();  // 여기서 Init을 해주니까 위의 Init 함수에서 해줄필요는 없다.
	_components.push_back(component);
}
void Actor::RemoveComponent(Component* component)
{
	// 전에 auto 쓰지말라 해놓고 왜 쓰냐?
	// Iterator는 안쓰면 너무 길어져서 여기서 auto를 그냥 쓴다.
	auto findIt = find(_components.begin(), _components.end(), component);

	if (findIt != _components.end())
	{
		Component* deleteComponent = *findIt;
		deleteComponent->Release();
		SAFE_DELETE(deleteComponent);
		_components.erase(findIt);
	}
}
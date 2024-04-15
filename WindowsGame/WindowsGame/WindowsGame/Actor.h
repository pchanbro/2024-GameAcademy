#pragma once
// actor는 여러가지 component를 들고 있어야함
class Component;
class Collider;
class Actor
{
	// Actor의 기본적인 속성은 많이 안들어가 있는게 좋다.
protected:
	CenterRect _body = {};
	string _name;
	vector<Component*> _components;

	bool _isEnable = true;

public:
	// 게터(Getter), 세터(Setter)
	CenterRect GetBody() { return _body; }
	void SetBody(CenterRect body) { _body = body; }

	string GetName() { return _name; }
	void SetName(string name) { _name = name; }

	bool GetEnable() { return _isEnable; }
	void SetEnable(bool isEnable) { _isEnable = isEnable; }

public:
	// 충돌 시작되었을때.
	// Unity
	virtual void OnTriggerEnter(Collider* collider, Collider* other);
	// 충돌 끝났을때 
	virtual void OnTriggerExit(Collider* collider, Collider* other);

	// Unreal
	// void OnComponentBeginOverlap(Collider* collider, Collider * other);
	// 충돌 끝났을때 
	// void OnComponentEndOverlap(Collider* collider, Collider * other);

public:
	void AddComponent(Component* component);
	void RemoveComponent(Component* component);

public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();
};


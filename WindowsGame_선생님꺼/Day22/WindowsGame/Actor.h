#pragma once
class Component;
class Collider;
class Actor
{
protected:
	CenterRect _body = {};
	string _name;
	vector<Component*> _components;

public:
	// 게터, 세터 (Getter, Setter)
	CenterRect GetBody() { return _body; }
	void SetBody(CenterRect body) { _body = body; }

	string GetName() { return _name; }
	void SetName(string name) { _name = name; }

public:
	//충돌 시작되었을때.
	//Unity
	virtual void OnTriggerEnter(Collider* collider, Collider* other);
	//충돌 끝났을때.
	virtual void OnTriggerExit(Collider* collider, Collider* other);

	//Unreal
	//void OnComponentBeginOverlap(Collider* collider, Collider * other);
	//충돌 끝났을때.
	//void OnComponentEndOverlap(Collider* collider, Collider * other);
public:
	void AddComponent(Component* component);
	void RemoveComponent(Component* component);

public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();
};


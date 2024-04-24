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

	void SetPos(Vector2 pos) { _body.pos = pos; }
	vector2 GetPos() { return _body.pos; }

	void SetWidth(float width) { _body.width = width; }

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
	template<typename T>
	T* GetComponent()
	{
		for (auto component : _components)
		{
			if (typeid(*component) == typeid(T))
			{
				// dynamic_cast => 특정이벤트에서 한 번!(특정이벤트란, 매프레임 할 정도는 아니고 클릭 한 번 할떄정도?
				T* result = dynamic_cast<T*>(component);
				if (result != nullptr)
				{
					return result;
				}
			}
		}
		
		return nullptr;
	}

public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();
};


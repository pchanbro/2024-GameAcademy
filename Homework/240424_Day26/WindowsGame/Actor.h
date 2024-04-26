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
	Vector2 GetPos() { return _body.pos; }

	void SetWidth(float width) { _body.width = width; }
	float GetWidth() { return _body.width; }

	void SetHeight(float height) { _body.height = height; }
	float GetHeight() { return _body.height; }

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
	template<typename T> // 여기 T에다가난 Collider 넣을거다.
	T* GetComponent() // type이 뭔지를 받아줄거니까
	{
		for (Component* component : _components)
		{
			// dynamic_cast => 특정이벤트에서 한 번 쓰는거!(특정이벤트란, 매프레임 할 정도는 아니고 예를들어 클릭 한 번 할때정도?
			// 그러니 여기서 매 번 쓰이지 않도록 다음과 같은 if문을 쓴다
			// 이런게 바로 방어체계!! 코드는 평생 쓰이기 때문에 이런 방어체계가 필수!
			if (typeid(*component) == typeid(T)) // typeid -> component의 본체를 체크했을때 T와 같으면 해준다. 
			{
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

public:
	Actor() {}
	virtual ~Actor() {}
};


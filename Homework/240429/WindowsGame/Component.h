#pragma once
class Actor;
class Component
{
protected:
	Actor* _owner = nullptr;

public: // 왠만한 actor는 getter, setter을 갖는다.
	void SetOwner(Actor* owner) { _owner = owner; }
	Actor* GetOwner() { return _owner; }

public:
	// 게임구조
	// 기본적으로 씬을 Init, Render, Update, Release 한다.
	// 씬 안에서 Actor들이 Init, Render, Update, Release 이 구조를 따라갈 수 밖에 없다.
	// Actor들이 가진 Component들은 자연스럽게 Init, Render, Update, Release 함수들의 생명주기를 따라간다.
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();
};


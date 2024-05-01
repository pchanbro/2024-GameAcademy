#pragma once
#include "Actor.h"
class FlipbookActor : public Actor
{
protected:
	Flipbook* _flipbook = nullptr;
	int _index = 0;
	float _sumTime = 0.0f;
	bool _loop = true;

public:
	void SetFlipbook(Flipbook* flipbook);
	void Reset();

public:
	using Super = Actor;

public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

public :
	FlipbookActor() {}
	virtual ~FlipbookActor() {} // 이게 없으면 dynamic_cast가 안되고 메모리 적으로도 낭비가 된다.
};


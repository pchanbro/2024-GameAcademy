#pragma once
#include "Actor.h"
class Sprite;
class SpriteActor : public Actor
{
protected:
	Sprite* _sprite = nullptr;

public:
	void SetSprite(Sprite* sprite) { _sprite = sprite; }
	Sprite* GetSprite() { return _sprite; }

public:
	using Super = Actor;
public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

public:
	SpriteActor() {}
	virtual ~SpriteActor() {}
};


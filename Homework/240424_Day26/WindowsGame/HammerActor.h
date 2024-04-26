#pragma once
#include "SpriteActor.h"

// state는 엑터마다 존재한다.
enum class HammerActorState
{
	Hit,
	Idle,
	None
};

class HammerActor : public SpriteActor
{
public:
	using Super = SpriteActor;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

	void ChangeState(HammerActorState state);
	HammerActorState GetState() { return _state; }

private:
	void DoHit();
	void DoIdle();

private:
	HammerActorState _state;
};


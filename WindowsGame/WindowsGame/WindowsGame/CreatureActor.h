#pragma once
#include "FlipbookActor.h"

enum class CreatureActorState
{
	Attack,
	Move,
	Idle,
	None,
};

enum eCreatureDirection
{
	RIGHT,
	LEFT,
	UP,
	DOWN,
	END
};

class CreatureActor : public FlipbookActor
{
public:
	using Super = FlipbookActor;

public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

public:
	
	void ChangeDirection(eCreatureDirection dir);
	void UpdateInput();

	CreatureActor() {}
	virtual ~CreatureActor() {}

	void ChangeState(CreatureActorState state);
	CreatureActorState GetState() { return _state; }

private:
	void Attack(); 
	void Move(eCreatureDirection dir);
	void Idle(); 

protected:
	eCreatureDirection _dir = eCreatureDirection::DOWN;
	Flipbook* _idleFlipbook[eCreatureDirection::END] = {};
	CreatureActorState _state = CreatureActorState::None;
};


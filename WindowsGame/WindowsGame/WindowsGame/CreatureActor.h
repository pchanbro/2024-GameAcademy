#pragma once
#include "FlipbookActor.h"

enum class CreatureActorState
{
	Attack,
	Move,
	Idle,
	None,
};

enum class Direction
{
	Up,
	Down,
	Left,
	Right,
	None
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
	CreatureActor() {}
	virtual ~CreatureActor() {}

	void ChangeState(CreatureActorState state);
	CreatureActorState GetState() { return _state; }

private:
	void Attack(); 
	void Move(Direction dir);
	void Idle(); 

private:
	CreatureActorState _state = CreatureActorState::None;

protected:
	Direction _dir = Direction::None;
};


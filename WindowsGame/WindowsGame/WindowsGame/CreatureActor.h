#pragma once
#include "FlipbookActor.h"
#include "ITilemapActor.h"

enum eCreatureDirection
{
	RIGHT,
	LEFT,
	UP,
	DOWN,
	END
};

enum class CreatureState
{
	Idle,
	Move,
	Attack
};

class CreatureActor : public FlipbookActor, public ITilemapActor
{
public:
	using Super = FlipbookActor;

public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

	CreatureActor() {}
	virtual ~CreatureActor() {}

public:
	void SetVelocity(Vector2 velocity) { _velocity = velocity; }
	Vector2 GetVelocity() { return _velocity; }
	void SetDestPos(Vector2 destPos) { _destPos = destPos; }
	Vector2 GetDestPos() { return _destPos; }

public:
	bool HasReachedDest();
	bool CanMove();

public:
	virtual void SetCellPos(Vector2Int cellPos, bool teleport = false) override;
	virtual Vector2Int GetCellPos() override;

public:
	void SetState(CreatureState state);
	void ChangeDirection(eCreatureDirection dir);

public:
	void UpdateIdle();
	void UpdateMove();
	void UpdateAttack();

public:
	void SetIsAttackInput(bool isAttackInput) { _isAttackInput = isAttackInput; }

public:// Astar 관련
	void SetPath(vector<Vector2Int> path);

protected:
	bool _isAttackInput = false;

	Vector2 _velocity = {};

	CreatureState _state = CreatureState::Idle;
	eCreatureDirection _dir = eCreatureDirection::DOWN;
	Flipbook* _idleFlipbook[eCreatureDirection::END] = {};
	Flipbook* _moveFlipbook[eCreatureDirection::END] = {};
	Flipbook* _attackFlipbook[eCreatureDirection::END] = {};

	Vector2 _destPos = {};
	Vector2Int _cellPos;

protected: // Astar 관련
	vector<Vector2Int> _path = {};
	int _pathIndex = 0;
};


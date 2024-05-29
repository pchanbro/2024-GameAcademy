#pragma once
#include "Actor.h"

class NumBoxActor : public Actor
{
	DECLARE_CHILD(NumBoxActor, Actor);
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

public:
	void Move();
	bool DoRightMove();
	bool DoLeftMove();
	bool DoDownMove();
	bool DoUpMove();
	//void IsAlreadyExist(NumBoxActor* other);

public:
	int GetNumber() { return _number; }
	void SetNumber(int num) { _number = num; }

	int GetSectionNum() { return _sectionNum; }
	void SetSectionNum(int sectionNum) { _sectionNum = sectionNum; }

	int GetPrevSectionNum() { return _prevSectionNum; }
	void SetPrevSectionNum(bool prevSectionNum) { _prevSectionNum = prevSectionNum; }

	bool GetMoving() { return _moving; }
	void SetMoving(bool moving) { _moving = moving; }

protected:
	int _number = 2;
	int _sectionNum = 0;
	int _prevSectionNum = -1;
	bool _moving = false;
};


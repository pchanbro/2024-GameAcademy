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
	bool IsRightMove();
	bool IsLeftMove();
	bool IsDownMove();
	bool IsUpMove();

public:
	int GetNumber() { return _number; }
	void SetNumber(int num) { _number = num; }

	int GetSectionNum() { return _sectionNum; }
	void SetSectionNum(int sectionNum) { _sectionNum = sectionNum; }

protected:
	int _number = 2;
	int _sectionNum = 0;
};


#pragma once
#include "FlipbookActor.h"
class TowerActor : public FlipbookActor
{
public:
	using Super = FlipbookActor;

public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
};


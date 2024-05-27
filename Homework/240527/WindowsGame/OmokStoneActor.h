#pragma once
#include "SpriteActor.h"

enum class StoneState
{
	Black,
	White,
	None
};

class OmokStoneActor : public SpriteActor
{
public:
	using Super = SpriteActor; // cpp 파일에서 Super:Init() 이런거 하려면 필요함
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

	void ChangeState(StoneState state);
	StoneState GetState() { return _state; }

private:
	StoneState _state = StoneState::Black;
};


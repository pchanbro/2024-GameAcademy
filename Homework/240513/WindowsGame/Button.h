#pragma once
#include "UI.h"

class Sprite;

enum class ButtonState
{
	Default,
	Hover,
	Pressed,
	Disabled,

	End
};


class Button : public UI
{
	DECLARE_CHILD(Button, UI)

public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

public:
	void SetSprite(ButtonState state, Sprite* sprite)
	{
		_sprites[(int)state] = sprite;
	}
	Sprite* GetSprite(ButtonState state) { return _sprites[(int)state]; }

	
public:
	void SetState(ButtonState state);

protected:
	// 버튼을 구성하는 요소
	Sprite* _sprites[(int)ButtonState::End] = {};
	Sprite* _currentSprite = nullptr;

	ButtonState _state = ButtonState::End;
};


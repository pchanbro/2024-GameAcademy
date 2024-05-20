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

	// 이건 근데 나중에 쓸때 가독성 측면에서 많이 구리다.
	/*void AddOnClickDelegate()
	{

	}*/

	template<typename T>
	void AddOnClickDelegate(T* owner, void(T::* func)())
	{
		_onclick = bind(func, owner);
	}

protected:
	// 버튼을 구성하는 요소
	Sprite* _sprites[(int)ButtonState::End] = {};
	Sprite* _currentSprite = nullptr;

	ButtonState _state = ButtonState::End;

	// 버튼을 눌렀을 때 이벤트
	function<void()> _onclick = nullptr;
};


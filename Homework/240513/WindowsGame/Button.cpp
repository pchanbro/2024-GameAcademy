#include "pch.h"
#include "Button.h"
#include "Sprite.h"
#include "Panel.h"
void Button::Init()
{
	Super::Init();

	_state = ButtonState::Default;
	_currentSprite = _sprites[(int)_state];
}
void Button::Render(HDC hdc)
{
	if (_isShow == false) return;
	Super::Render(hdc);

	if (_currentSprite == nullptr) return;
	
	Vector2Int size = _currentSprite->GetSize();

	Panel* parent = this->GetParent();
	Vector2 parentPos = Vector2::Zero();
	while (parent != nullptr)
	{
		parentPos += parent->GetPos();
		parent = parent->GetParent();
	}

	Vector2Int renderPos = Vector2Int(
		static_cast<int>(parentPos.x + _pos.x - size.x / 2),
		static_cast<int>(parentPos.y + _pos.y - size.y / 2)
	);

	::TransparentBlt(hdc,
		renderPos.x,
		renderPos.y,
		size.x,
		size.y,
		_currentSprite->GetDC(),
		_currentSprite->GetPos().x,
		_currentSprite->GetPos().y,
		size.x,
		size.y,
		_currentSprite->GetTransparent()
	);

}
void Button::Update()
{
	Super::Update();

	// 버튼의 특성
	// 내 마우스 위에 있으면 Hover로 보여줌.
	// 내 마우스 위에 있고 + 클릭하면 Pressed로 보여줌
	// Disabled면 그냥 Disbled로 보여줌
	// 그 외에는 Default

	// -> _state

	/*
	if(상태 == Disabled) return;

	if(마우스가 자기 충돌영역 안에 있다면) ==> IsInMouse (UI코드에서 이미 만듦)
	나중에 라이브코드가면 (이미 상용화된 게임 코드)
	보통 대부분의 함수들은 이미 누군가가 구현해놨다.
	문제가 뭐냐면
	A가 구현해놓고
	B가 또 구현해놓고
	C가 또 구현하면
	*/

	/*
	수도코드
	수도코드 안에 한 줄로 되어있는것들 한줄 넘어가면 함수로 바꿔라
	if (상태 == Disabled) return;

	if(마우스가 자기 충돌영역 안에 있다면)
	{
		if(마우스가 클릭중인 상태라면)
		{
			_state = pressed;
			_currentSprite = PressedSprite;
		}
		else
		{
			// 클릭했다가 떼었는가?
			if(상태 == Pressed)
			{
				// 딱 지금 클릭했을때 작동!!
			}

			상태 = Hover;
		}
	}
	else
	{
		상태 = Default;
	}
	*/
	if (_state == ButtonState::Disabled) return;

	if (this->IsInMouse())
	{
		if (Input->GetKey(KeyCode::LeftMouse))
		{
			this->SetState(ButtonState::Pressed);
		}
		else
		{
			if (_state == ButtonState::Pressed)
			{
				// 딱 지금 클릭했을때 동작
				this->SetState(ButtonState::Hover);
				// 새로운 문법 : 함수 포인터
				// 이걸 여기에 써주는게 좋다.
			}
		}
	}
	else
	{
		this->SetState(ButtonState::Default);
	}
}
void Button::Release()
{
	Super::Release();
}

void Button::SetState(ButtonState state)
{
	_state = state;
	_currentSprite = _sprites[(int)_state];
}
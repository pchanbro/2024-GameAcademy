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

	// ��ư�� Ư��
	// �� ���콺 ���� ������ Hover�� ������.
	// �� ���콺 ���� �ְ� + Ŭ���ϸ� Pressed�� ������
	// Disabled�� �׳� Disbled�� ������
	// �� �ܿ��� Default

	// -> _state

	/*
	if(���� == Disabled) return;

	if(���콺�� �ڱ� �浹���� �ȿ� �ִٸ�) ==> IsInMouse (UI�ڵ忡�� �̹� ����)
	���߿� ���̺��ڵ尡�� (�̹� ���ȭ�� ���� �ڵ�)
	���� ��κ��� �Լ����� �̹� �������� �����س���.
	������ ���ĸ�
	A�� �����س���
	B�� �� �����س���
	C�� �� �����ϸ�
	*/

	/*
	�����ڵ�
	�����ڵ� �ȿ� �� �ٷ� �Ǿ��ִ°͵� ���� �Ѿ�� �Լ��� �ٲ��
	if (���� == Disabled) return;

	if(���콺�� �ڱ� �浹���� �ȿ� �ִٸ�)
	{
		if(���콺�� Ŭ������ ���¶��)
		{
			_state = pressed;
			_currentSprite = PressedSprite;
		}
		else
		{
			// Ŭ���ߴٰ� �����°�?
			if(���� == Pressed)
			{
				// �� ���� Ŭ�������� �۵�!!
			}

			���� = Hover;
		}
	}
	else
	{
		���� = Default;
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
				// �� ���� Ŭ�������� ����
				this->SetState(ButtonState::Hover);
				// ���ο� ���� : �Լ� ������
				// �̰� ���⿡ ���ִ°� ����.
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
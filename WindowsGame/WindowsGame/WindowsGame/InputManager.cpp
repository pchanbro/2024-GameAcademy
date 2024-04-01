#include "pch.h"
#include "InputManager.h"

// 시작할 때 딱 한번만 실행하는것
void InputManager::Init(HWND hwnd)
{
	_hwnd = hwnd;
	// 컨텐츠코드라면 이게 문제가 없다.
	/*for (int i = 0; i < static_cast<int>(KEY_TYPE_COUNT); i++)
	{
		_states.push_back(KeyState::None);
	}*/

	// 근데 우리가 짜고 있는 코드는
	// 프레임워크 코드이기에 
	// 하나라도 줄일 수 있는 부분은 줄여야 한다.
	// 그래서 쓰는게 resize
	_states.resize(KEY_CODE_COUNT, KeyState::None);
	
}

// Updata는 매 프레임마다 실행 되는것
void InputManager::Updata()
{
	::GetCursorPos(&_mousePos);
	::ScreenToClient(_hWnd, &_mousePos);

	BYTE asciiKeys[KEY_CODE_COUNT] = {};
	if (::GetKeyboardState(asciiKeys) == false)
	{
		return;
	}

	for (uint32 key = 0; key < KEY_CODE_COUNT; key++)
	{
		//key가 눌러져 있다
		if (0 < (asciiKeys[key] & 0x80))
		{
			KeyState& state = _states[key];

			// 누르고 있었다
			if (state == KeyState::Press || state == KeyState::Down)
			{
				state = KeyState::Press;
			}// 이제 막 눌렀다.
			else
			{
				state = KeyState::Down;
			}
		}
		// key가 안눌러져 있다/
		else
		{
			KeyState& state = _states[key];

			// 누르고 있었던 상태면
			if (state == KeyState::Press || state == KeyState::Down)
			{
				state = KeyState::Up;
			}
			else
			{
				state = KeyState::None;
			}
		}
	}
}

bool InputManager::GeyKey(KeyCode key)
{
	return GetState(key) == KeyState::Press;
}
bool InputManager::GetKeyDown(KeyCode key)
{
	return GetState(key) == KeyState::Down;
}
bool InputManager::GetKeyUp(KeyCode key)
{
	return GetState(key) == KeyState::Up;
}

POINT InputManager::GetMousePos()
{
	return _mousePos;
}
#pragma once
enum class KeyCode
{
	LeftMouse = VK_LBUTTON,
	RightMouse = VK_RBUTTON,

	Up = VK_UP,
	Down = VK_DOWN,
	Left = VK_LEFT,
	Right = VK_RIGHT,
	Space = VK_SPACE,

	W = 'W',
	A = 'A',
	S = 'S',
	d = 'D',

	Control = VK_CONTROL,
};

enum class KeyState
{
	None,  // 아무것도 아닐 떄
	Press, // 누르는 사앹일 때
	Down,  // 눌렀을 때
	Up,    // 손을 막 땠을 때

	End
};

enum
{	// key의 종류는 총 256개 UINT8_MAX는 256
	// static_cast<int32>(UINT8_MAX) 는 그냥 UINT8_MAX와 같다
	// 이걸 안하면 실행했을 때 warning이 뜨는데 
	// 엔진에서는 이 warning을 없애주는게 중요하기 때문에 쓴다.
	KEY_CODE_COUNT = static_cast<int32>(UINT8_MAX) + 1,
	KEY_STATE_COUNT = static_cast<int32>(KeyState::End)

};

class InputManager
{
	DECLARE_SINGLE(InputManager);

public:
	void Init(HWND hwnd);
	void Updata();

	bool GetKey(KeyCode key);
	bool GetKeyDown(KeyCode key);
	bool GetKeyUp(KeyCode key);

	POINT GetMousePos();

private:
	KeyState GetState(KeyCode key) { return _states[static_cast<uint8>(key)]; }

private:
	HWND _hwnd = {};
	vector<KeyState> _states;
	POINT _mousePos;
};

// _states[키코드] = Pressed;
// _states[키코드] = Up;
// _states[키코드] = Down;
// _states[키코드] = None;
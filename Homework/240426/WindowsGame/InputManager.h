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
	None,  // �ƹ��͵� �ƴ� ��
	Press, // ������ ����� ��
	Down,  // ������ ��
	Up,    // ���� �� ���� ��

	End
};

enum
{	// key�� ������ �� 256�� UINT8_MAX�� 256
	// static_cast<int32>(UINT8_MAX) �� �׳� UINT8_MAX�� ����
	// �̰� ���ϸ� �������� �� warning�� �ߴµ� 
	// ���������� �� warning�� �����ִ°� �߿��ϱ� ������ ����.
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

// _states[Ű�ڵ�] = Pressed;
// _states[Ű�ڵ�] = Up;
// _states[Ű�ڵ�] = Down;
// _states[Ű�ڵ�] = None;
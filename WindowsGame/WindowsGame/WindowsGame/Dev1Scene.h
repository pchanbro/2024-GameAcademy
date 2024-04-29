#pragma once
#include "Scene.h" // ��� ���Ͽ��� �� include ���� �����ߴµ� �̰� ����ϱ� ���� include�ߴ�.
class Dev1Scene : public Scene
{
	using Super = Scene;
public:
	virtual void Init() override; // override�� �����ֱ��, �ڸ�Ʈ��, ���� ȿ���� ����.
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

	void LoadResource();

private:
	/*CenterRect _player;
	Vector2 _playerDir;
	Vector2 _targetPos = { -1, -1 };

	CenterRect _wall = {};*/
};


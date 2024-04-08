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

private:
	RECT _rect = {};
	Vector2 _platerDir;
	Vector2 _targetPos
};


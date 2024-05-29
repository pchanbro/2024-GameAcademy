#pragma once
#include "Scene.h" // ��� ���Ͽ��� �� include ���� �����ߴµ� �̰� ����ϱ� ���� include�ߴ�.
class Panel;
class BoxCollider;
class FlipbookActor;
class MapToolController;
class CreatureController;
class Dev1Scene : public Scene
{
	using Super = Scene;
public:
	virtual void Init() override; // override�� �����ֱ��, �ڸ�Ʈ��, ���� ȿ���� ����.
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;


private:
	void LoadResource();

protected:
	FlipbookActor* _monster;
	vector<BoxCollider*> _colliders;
	MapToolController* _mapToolController = nullptr;
	CreatureController* _creatureController = nullptr;
};


// ������ ���� ������ �� �� ������ ��ӹ޾Ƽ� ����Ŵ�.

#pragma once
class Actor; // ���漱��
class Scene
{
protected:
	vector<Actor*> _actors; // �� ���� �߰����� �𸣴� vector�� �����

//----------------------------
//  ## �⺻�Լ�
//----------------------------
public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

public:
	void SpawnActor(Actor* actor);
	void DespawnActor(Actor* actor);
};

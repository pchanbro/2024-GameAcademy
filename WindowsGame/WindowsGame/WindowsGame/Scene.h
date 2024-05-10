// ������ ���� ������ �� �� ������ ��ӹ޾Ƽ� ����Ŵ�.

#pragma once
class Actor; // ���漱��
class UI;
class Scene
{
protected: // ������ ����, ī�޶�, UI �������� �־�� �Ѵ�.
	vector<Actor*> _actors; // �� ���� �߰����� �𸣴� vector�� �����
	Vector2Int _cameraPosition = {};
	vector<UI*> _uis;

//----------------------------
//  ## �⺻�Լ�
//----------------------------
public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

public:
	// Actor �����Լ�
	void SpawnActor(Actor* actor);
	void DespawnActor(Actor* actor);

public:
	// Camera �����Լ�
	void SetCameraPos(Vector2Int pos) { _cameraPosition = pos; }
	Vector2Int GetCameraPos() { return _cameraPosition; }
};


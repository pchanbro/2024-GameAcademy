#pragma once
class Actor;
class Scene
{
protected:
	vector<Actor*> _actors;


	Vector2 _cameraPosition = {};

//-----------------------------
//  ## �⺻�Լ� 
//-----------------------------
public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

public:
	//Actor �����Լ�
	void SpawnActor(Actor* actor);
	void DespawnActor(Actor* actor);

public:
	//Camera �����Լ�
	void SetCameraPos(Vector2 pos) { _cameraPosition = pos; }
	Vector2 GetCameraPos() { return _cameraPosition; }
};


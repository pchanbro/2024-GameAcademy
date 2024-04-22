#pragma once
class Actor;
class Scene
{
protected:
	vector<Actor*> _actors;

//-----------------------------
//  ## �⺻�Լ� 
//-----------------------------
public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

public:
	void SpawnActor(Actor* actor);
	void DespawnActor(Actor* actor);
};


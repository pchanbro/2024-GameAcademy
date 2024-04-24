#pragma once
class Actor;
class Scene
{
protected:
	vector<Actor*> _actors;

//-----------------------------
//  ## 기본함수 
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


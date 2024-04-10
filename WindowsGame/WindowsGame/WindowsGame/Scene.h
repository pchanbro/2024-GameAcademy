// 앞으로 만들 씬들은 이 씬 파일을 상속받아서 만들거다.

#pragma once
class Actor; // 전방선언
class Scene
{
protected:
	vector<Actor*> _actors; // 몇 개가 추가될지 모르니 vector로 해줘라

//----------------------------
//  ## 기본함수
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


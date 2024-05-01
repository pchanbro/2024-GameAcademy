// 앞으로 만들 씬들은 이 씬 파일을 상속받아서 만들거다.

#pragma once
class Actor; // 전방선언
class Scene
{
protected:
	vector<Actor*> _actors; // 몇 개가 추가될지 모르니 vector로 해줘라

	Vector2Int _cameraPosition = {};
//----------------------------
//  ## 기본함수
//----------------------------
public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

public:
	// Actor 조작함수
	void SpawnActor(Actor* actor);
	void DespawnActor(Actor* actor);

public:
	// Camera 조작함수
	void SetCameraPos(Vector2Int pos) { _cameraPosition = pos; }
	Vector2Int GetCameraPos() { return _cameraPosition; }
};


#pragma once


// 앞에서 이렇게 클래스 선언을 해주면 포인터 변수는 사용이 가능해진다 (밑에 Scene* _scene = nullptr; 이 이것때문에 가능해짐)
class Scene;

// 씬매니저에서는 씬들을 관리할 것
class SceneManager
{
	DECLARE_SINGLE(SceneManager);

public:
	void Init();
	void Render(HDC hdc);
	void Update();
	void Release();


public:
	void ChangeScene(SceneType sceneType); // 핵심기능

private:
	SceneType _sceneType = SceneType::None;
	SceneType _nextSceneType = SceneType::None;

private:
	Scene* _scene = nullptr;

public:
	Scene* GetCurrentScene() { return _scene; } // 씬을 꺼내서 쓰고 싶을때가 있으면 사용
};


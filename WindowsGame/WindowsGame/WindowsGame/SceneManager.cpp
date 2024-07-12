#include "pch.h"
#include "SceneManager.h"
#include "Scene.h"
#include "Dev1Scene.h"
#include "Dev2Scene.h"
#include "InGameScene.h"
#include "MoleGameScene.h"
#include "Game2048Scene.h"
#include "TowerDefenseScene.h"

void SceneManager::Init()
{

}
void SceneManager::Render(HDC hdc)
{
	if (_scene)
	{
		_scene->Render(hdc);
	}
}
void SceneManager::Update()
{
	if (_scene)
	{
		_scene->Update();
	}

	

	//if (_nextSceneType != SceneType::None)
	//{
	//	// ����
	//}
	// �̷��� �ؼ� ���� ���� �κ����� ������ �����ִ� �� ���ٴ� �Ʒ�ó�� �ϰ� ������ �� �ؿ� ���ִ°� �ڵ尡 �� ���������.

	if (_nextSceneType == SceneType::None)
	{
		return;
	}

	//--------------------------------------------
	//		Scene Change
	//--------------------------------------------
	if (_scene)
	{
		_scene->Release(); // ���� �� ����(����)
	}

	Scene* newScene = nullptr;

	// ������ ���Ӱ� ������ش�.
	switch (_nextSceneType)
	{
	case SceneType::None:
		break;
	case SceneType::Dev1Scene:
		newScene = new Dev1Scene();
		break;
	case SceneType::Dev2Scene:
		newScene = new Dev2Scene();
		break;
	case SceneType::InGameScene:
		newScene = new InGameScene();
		break;
	case SceneType::MoleGameScene:
		newScene = new MoleGameScene();
		break;
	case SceneType::Game2048Scene:
		newScene = new Game2048Scene();
		break;
	case SceneType::TowerDefenseScene:
		newScene = new TowerDefenseScene();
		break;
	default:
		break;
	}

	SAFE_DELETE(_scene);
	// SAFE_DELETE
	/*if (_scene)
	{
		delete _scene;
		_scene = nullptr;
	}*/
	_scene = newScene; // �� ��ü �Ϸ�
	_sceneType = _nextSceneType;
	_nextSceneType = SceneType::None;
	newScene->Init();
}

void SceneManager::Release()
{
	if (_scene)
	{
		_scene->Release();
	}
}

void SceneManager::ChangeScene(SceneType sceneType)
{
	if (_sceneType == sceneType)
	{
		return;
	}

	_nextSceneType = sceneType;
}
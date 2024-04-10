#include "pch.h"
#include "Scene.h"
#include "Actor.h"

void Scene::Init()
{
	// 기본적인 처리
}
void Scene::Render(HDC hdc)
{
	// ranged-base
	for (Actor* actor : _actors)// 순회하면서 받아줌
	{
		actor->Render(hdc);
	}
}
void Scene::Update()
{
	for (Actor* actor : _actors)// 순회하면서 받아줌
	{
		actor->Update();
	}
}
void Scene::Release()
{
	for (Actor* actor : _actors)// 순회하면서 받아줌
	{
		actor->Release();
		SAFE_DELETE(actor);
	}
	_actors.clear();
}
void Scene::SpawnActor(Actor* actor)
{
	if (actor == nullptr) return;

	// 여기서 actor를 처음 생성하니까
	actor->Init();
	_actors.push_back(actor);
}
void Scene::DespawnActor(Actor* actor)
{
	if (actor == nullptr) return;

	// 삭제할 객체찾기
	auto findIt = find(_actors.begin(), _actors.end(), actor);

	if (findIt != _actors.end())
	{
		(*findIt)->Release();
		Actor* deleteActor = (*findIt);
		SAFE_DELETE(deleteActor);
		_actors.erase(findIt);
	}
}

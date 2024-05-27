#include "pch.h"
#include "Scene.h"
#include "Actor.h"
#include "UI.h"

void Scene::Init()
{
	// 기본적인 처리
	for (UI* ui : _uis)
	{
		ui->Init();
	}
}
void Scene::Render(HDC hdc)
{
	/*for (int i = 0; i < _actors.size(); i++)
	{
		_actors[i]->Render(hdc);
	}*/

	// ranged-base for문
	for (const vector<Actor*> actors : _actors)// 요소들을 순회하면서 받아줌
	{   // const를 붙이면 변화가 없나??? vector에 대한 내용을 바꾸지 않기 위해 썻다는데
		for (Actor* actor : actors)
		{
			actor->Render(hdc);
		}
	}
	for (UI* ui : _uis)
	{
		ui->Render(hdc);
	}
}
void Scene::Update()
{
	for (const vector<Actor*> actors : _actors)
	{   
		for (Actor* actor : actors)
		{
			actor->Update();
		}
	}
	for (UI* ui : _uis)
	{
		ui->Update();
	}
}

void Scene::Release()
{
	for (vector<Actor*> actors : _actors) // 여기선 actors를 지워줘야 하니까 const 제외
	{
		for (Actor* actor : actors)
		{
			actor->Release();
			SAFE_DELETE(actor);
		}
		actors.clear();
	}

	for (UI* ui : _uis)
	{
		ui->Release();
		SAFE_DELETE(ui);
	}
	_uis.clear();

	GET_SINGLE(CollisionManager)->ClearCollider();
}

void Scene::SpawnActor(Actor* actor)
{
	if (actor == nullptr) return;

	_actors[actor->GetLayerInt()].push_back(actor);
}
void Scene::DespawnActor(Actor* actor)
{
	if (actor == nullptr) return;

	vector<Actor*>& actors = _actors[actor->GetLayerInt()];

	// 삭제할 객체찾기
	auto findIt = find(actors.begin(), actors.end(), actor); // 처음부터 끝까지 중 actor라는게 있는지를 찾는다.
	// 못찾았으면 findIt이 _actors.end()가 된다.
	if (findIt != actors.end())
	{
		(*findIt)->Release();
		Actor* deleteActor = (*findIt);
		SAFE_DELETE(deleteActor);
		actors.erase(findIt);
	}
}

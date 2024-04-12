#include "pch.h"
#include "Scene.h"
#include "Actor.h"

void Scene::Init()
{
	// �⺻���� ó��
}
void Scene::Render(HDC hdc)
{
	// ranged-base for��
	for (Actor* actor : _actors)// ��ҵ��� ��ȸ�ϸ鼭 �޾���
	{
		actor->Render(hdc);
	}
}
void Scene::Update()
{
	for (Actor* actor : _actors)
	{
		actor->Update();
	}
}
void Scene::Release()
{
	for (Actor* actor : _actors)
	{
		actor->Release();
		SAFE_DELETE(actor);
	}
	_actors.clear();
}
void Scene::SpawnActor(Actor* actor)
{
	if (actor == nullptr) return;

	_actors.push_back(actor);
}
void Scene::DespawnActor(Actor* actor)
{
	if (actor == nullptr) return;

	// ������ ��üã��
	auto findIt = find(_actors.begin(), _actors.end(), actor); // ó������ ������ �� actor��°� �ִ����� ã�´�.
	// ��ã������ findIt�� _actors.end()�� �ȴ�.
	if (findIt != _actors.end())
	{
		(*findIt)->Release();
		Actor* deleteActor = (*findIt);
		SAFE_DELETE(deleteActor);
		_actors.erase(findIt);
	}
}

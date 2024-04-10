#include "pch.h"
#include "Scene.h"
#include "Actor.h"

void Scene::Init()
{
	// �⺻���� ó��
}
void Scene::Render(HDC hdc)
{
	// ranged-base
	for (Actor* actor : _actors)// ��ȸ�ϸ鼭 �޾���
	{
		actor->Render(hdc);
	}
}
void Scene::Update()
{
	for (Actor* actor : _actors)// ��ȸ�ϸ鼭 �޾���
	{
		actor->Update();
	}
}
void Scene::Release()
{
	for (Actor* actor : _actors)// ��ȸ�ϸ鼭 �޾���
	{
		actor->Release();
		SAFE_DELETE(actor);
	}
	_actors.clear();
}
void Scene::SpawnActor(Actor* actor)
{
	if (actor == nullptr) return;

	// ���⼭ actor�� ó�� �����ϴϱ�
	actor->Init();
	_actors.push_back(actor);
}
void Scene::DespawnActor(Actor* actor)
{
	if (actor == nullptr) return;

	// ������ ��üã��
	auto findIt = find(_actors.begin(), _actors.end(), actor);

	if (findIt != _actors.end())
	{
		(*findIt)->Release();
		Actor* deleteActor = (*findIt);
		SAFE_DELETE(deleteActor);
		_actors.erase(findIt);
	}
}

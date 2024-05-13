#include "pch.h"
#include "Scene.h"
#include "Actor.h"
#include "UI.h"

void Scene::Init()
{
	// �⺻���� ó��
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

	// ranged-base for��
	for (Actor* actor : _actors)// ��ҵ��� ��ȸ�ϸ鼭 �޾���
	{
		actor->Render(hdc);
	}
	for (UI* ui : _uis)
	{
		ui->Render(hdc);
	}
}
void Scene::Update()
{
	for (Actor* actor : _actors)
	{
		actor->Update();
	}
	for (UI* ui : _uis)
	{
		ui->Update();
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

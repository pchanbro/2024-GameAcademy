#include "pch.h"
#include "Dev1Scene.h"
#include "PlayerActor.h"
#include "BoxCollider.h"
#include "SpriteActor.h"
#include "FlipbookActor.h"
#include "Flipbook.h"
#include "CreatureActor.h"

void Dev1Scene::Init()
{
	Super::Init();
	LoadResource();

	
}

void Dev1Scene::Render(HDC hdc)
{
	// �θ��Լ� ���� �����ϰ� �ڽ��� �Լ��� �����ϴ°��� �Ϲ����̴�.
	Super::Render(hdc);

	wstring str = L"Dev1Scene";
	::TextOut(hdc, 0, 45, str.c_str(), str.length());

}

void Dev1Scene::Update()
{
	Super::Update();

	//if (!_flipbook) return;
}
void Dev1Scene::Release()
{
	Super::Release();
}

void Dev1Scene::LoadResource()
{

}

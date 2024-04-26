#include "pch.h"
#include "Dev2Scene.h"
#include "MoleActor.h"
#include "FlipbookActor.h"
#include "Flipbook.h"
#include "CreatureActor.h"
#include "UserCharacterController.h"

void Dev2Scene::Init()
{
	Super::Init();

	CreatureActor* _creature = new CreatureActor();
	_creature->Init();
	SpawnActor(_creature);

}
void Dev2Scene::Render(HDC hdc)
{
	Super::Render(hdc);

	wstring str = L"Dev2Scene";
	::TextOut(hdc, 0, 45, str.c_str(), str.length());
}
void Dev2Scene::Update()
{
	Super::Update();

}
void Dev2Scene::Release()
{
	Super::Release();

}
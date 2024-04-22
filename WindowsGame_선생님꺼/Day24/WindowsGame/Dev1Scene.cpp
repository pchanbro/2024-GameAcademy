#include "pch.h"
#include "Dev1Scene.h"
#include "PlayerActor.h"
#include "BoxCollider.h"
#include "SpriteActor.h"
void Dev1Scene::Init()
{
	Super::Init();
	
	Resource->LoadTexture(L"T_MoleBackground", L"Mole/bg_mole.bmp");
	Resource->CreateSprite(L"S_MoleBackground", Resource->GetTexture(L"T_MoleBackground"));

	{
		SpriteActor* spriteActor = new SpriteActor();
		spriteActor->SetSprite(Resource->GetSprite(L"S_MoleBackground"));
		spriteActor->Init();
		spriteActor->SetBody(Shape::MakeCenterRectLTRB(0, 0, 795, 363));
		SpawnActor(spriteActor);
	}


	Resource->LoadTexture(L"T_Character", L"Mole/idle.bmp");
	Resource->CreateSprite(L"S_Character", Resource->GetTexture(L"T_Character"));
	{
		SpriteActor* spriteActor = new SpriteActor();
		spriteActor->SetSprite(Resource->GetSprite(L"S_Character"));
		spriteActor->Init();
		spriteActor->SetBody(Shape::MakeCenterRectLTRB(0, 0, 224, 224));
		SpawnActor(spriteActor);
	}
}
void Dev1Scene::Render(HDC hdc)
{
	Super::Render(hdc);

	wstring str = L"Dev1Scene";
	::TextOut(hdc, 0, 45, str.c_str(), str.length());


	
}
void Dev1Scene::Update()
{
	Super::Update();



}
void Dev1Scene::Release()
{
	Super::Release();

}
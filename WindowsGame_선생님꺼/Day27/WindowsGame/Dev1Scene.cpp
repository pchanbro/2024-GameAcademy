#include "pch.h"
#include "Dev1Scene.h"
#include "PlayerActor.h"
#include "BoxCollider.h"
#include "SpriteActor.h"
#include "FlipbookActor.h"
#include "Flipbook.h"
void Dev1Scene::Init()
{
	Super::Init();
	
	Resource->LoadTexture(L"T_Character", L"FilpbookTest/PlayerDown.bmp", RGB(128,128,128));
	FlipbookInfo info = {};
	info.start = 0;
	info.end = 9;
	info.line = 0;
	info.size = Vector2Int(200, 200);
	info.loop = true;
	info.duration = 1.0f;
	info.texture = Resource->GetTexture(L"T_Character");
	Resource->CreateFlipbook(L"FB_CharacterIdle", info);

	{
		FlipbookActor* flipbookActor = new FlipbookActor();

		flipbookActor->SetFlipbook(Resource->GetFlipbook(L"FB_CharacterIdle"));
		flipbookActor->SetPos(Vector2(WIN_SIZE_X / 2, WIN_SIZE_Y / 2));

		SpawnActor(flipbookActor);
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
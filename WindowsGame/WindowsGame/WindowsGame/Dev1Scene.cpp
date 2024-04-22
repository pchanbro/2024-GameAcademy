#include "pch.h"
#include "Dev1Scene.h"
#include "PlayerActor.h"
#include "BoxCollider.h"
#include "SpriteActor.h"

void Dev1Scene::Init()
{
	// 부모 함수 호출하려면
	// super.Init(); 혹은
	// base.Init();
	// 지금은 헤더파일에 Super 변수 만들어줬으니 이렇게 쓴다.
	Super::Init();

	// Windows API에서는 bmp밖에 사용이 안된다.(png파일같은건 로딩 불가능)
	// 게임을 많이 뜯어봤으면
	// png파일이 훨씬 더 많은걸 볼 수 있다. (이건 Direct X에서 제공해주는 API를 통해 로딩한 것!)

	// 텍스처 키, 찾기 쉬운거로 정해서 외우기, 겹치지 않게 주의하셈, Texture는 T로 시작, Sprite는 S로 시작
	Resource->LoadTexture(L"T_MoleBackground", L"Mole/bg_mole.bmp"); 
	Resource->CreateSprite(L"S_MoleBackground", Resource->GetTexture(L"T_MoleBackground"));

	{
		SpriteActor* spriteActor = new SpriteActor();
		spriteActor->SetSprite(Resource->GetSprite(L"S_MoleBackground"));
		spriteActor->Init();
		spriteActor->SetBody(Shape::MakeCenterRectLTRB(0, 0, 1134, 770));
		SpawnActor(spriteActor);
	}
}

void Dev1Scene::Render(HDC hdc)
{
	// 부모함수 먼저 실행하고 자신의 함수를 실행하는것이 일반적이다.
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
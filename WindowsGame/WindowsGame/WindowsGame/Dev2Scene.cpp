#include "pch.h"
#include "Dev2Scene.h"
#include "MoleActor.h"
#include "HammerActor.h"

void Dev2Scene::Init()
{
	Super::Init();

	{
		_hammer = new HammerActor();
		_hammer->Init();
		this->SpawnActor(_hammer);
	}

	for (int i = 0; i < 3; i++)
	{
		
		MoleActor* _mole = new MoleActor();
		_mole->SetBody(Shape::MakeCenterRectLTWH(i * 400 + 100, 300, 200, 200));
		_mole->Init();
		Time->Updata();
		this->SpawnActor(_mole);
		_mole = nullptr;
	}
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
#include "pch.h"
#include "TestPanel.h"
#include "Image.h"
void TestPanel::Init()
{
	Super::Init();

	Resource->LoadTexture(L"T_VictoryUI", L"UIStudy/img_victory.bmp");
	Resource->CreateSprite(L"S_VistoryUI", Resource->GetTexture(L"T_VictoryUI"));

	this->SetRect(Shape::MakeCenterRectLTWH(0, 0, WIN_SIZE_X, WIN_SIZE_Y));

	{
		Image* image = new Image();
		image->SetRect(Shape::MakeCenterRectLTWH(0, 0, WIN_SIZE_X, WIN_SIZE_Y));
		image->SetSprite(Resource->GetSprite(L"S_VistoryUI"));
		image->Init();
		this->AddChild(image);
	}
}
void TestPanel::Render(HDC hdc)
{
	Super::Render(hdc);
}
void TestPanel::Update()
{
	Super::Update();
}
void TestPanel::Release()
{
	Super::Release();
}
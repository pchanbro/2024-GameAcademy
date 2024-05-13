#include "pch.h"
#include "TestPanel.h"
#include "Image.h"

void TestPanel::Init()
{
	Super::Init();

	// ������ �������� ��ȹ�ڳ� �����̳ʰ� ����� �ϴ� �۾���
	// ��ġ�ϴ� �۾�

	Resource->LoadTexture(L"T_VictoryUI", L"UIStudy/victory.bmp");
	Resource->CreateSprite(L"S_VictoryUI", Resource->GetTexture(L"T_VictoryUI"));
	
	CenterRect panelRect = Shape::MakeCenterRectLTWH(0, 0, WIN_SIZE_X, WIN_SIZE_Y);
	this->SetRect(panelRect);
	
	{
		Image* image = new Image();
		image->SetRect(Shape::MakeCenterRect(panelRect.pos.x + 0, panelRect.pos.y + 0, WIN_SIZE_X, WIN_SIZE_Y));
		image->SetSprite(Resource->GetSprite(L"S_VictoryUI"));
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
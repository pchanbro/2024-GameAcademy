#include "pch.h"
#include "PanelTestScene.h"
#include "Panel.h"
#include "Image.h"
#include "Texture.h"
#include "Sprite.h"

void PanelTestScene::Init()
{
	Super::Init();

	Resource->LoadTexture(L"T_Victory", L"UIStudy/img_victory.bmp");	
	Resource->CreateSprite(L"S_Victory", Resource->GetTexture(L"T_Victory"));
	{
		Panel* panel = new Panel();
		
		{
			Image* image = new Image();
			image->SetSprite(Resource->GetSprite(L"S_Victory"));
			panel->AddChild(image);
			image->Init();

		}
		panel->Init();
	}

}
void PanelTestScene::Render(HDC hdc)
{
	Super::Render(hdc);
}
void PanelTestScene::Update()
{
	Super::Update();
}
void PanelTestScene::Release()
{
	Super::Release();
}
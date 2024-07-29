#include "pch.h"
#include "TowerGamePanel.h"
#include "UISpriteNumber.h"
#include "Label.h"
void TowerGamePanel::Init()
{
	Super::Init();


	{
		_timer = new UISpriteNumber();
		_timer->SetNumber(0);
		_timer->SetSprites(L"S_DefaultNumber");
		_timer->SetRect(Shape::MakeCenterRectLTRB(0, 0, 500, 100));

		this->AddChild(_timer);
	}

	{
		_waveStatusLabel = new Label();
		_waveStatusLabel->Init();
		_waveStatusLabel->SetRect(Shape::MakeCenterRect(WIN_SIZE_X / 2, WIN_SIZE_Y /2, 300, 50));
		_waveStatusLabel->SetFont(L"¿µ´ö¹Ù´ÙÃ¼", 30);
		_waveStatusLabel->SetAlign(TA_CENTER);
		_waveStatusLabel->SetText(L"");


		this->AddChild(_waveStatusLabel);
	}

	{
		_roundLabel = new Label();
		_roundLabel->Init();
		_roundLabel->SetRect(Shape::MakeCenterRectLTWH(WIN_SIZE_X - 100 , WIN_SIZE_Y - 200, 100, 100));
		_roundLabel->SetFont(L"¿µ´ö¹Ù´ÙÃ¼", 30);
		_roundLabel->SetAlign(TA_RIGHT);
		_roundLabel->SetText(L"");


		this->AddChild(_roundLabel);
	}
}
void TowerGamePanel::Render(HDC hdc)
{
	Super::Render(hdc);
}
void TowerGamePanel::Update()
{
	Super::Update();
}
void TowerGamePanel::Release()
{
	Super::Release();
}

void TowerGamePanel::SetText(wstring text)
{
	_waveStatusLabel->SetText(text);
}

void TowerGamePanel::SetRoundText(wstring text)
{
	_roundLabel->SetText(text);
}

void TowerGamePanel::SetTimer(int time)
{
	_timer->SetNumber(time);
}
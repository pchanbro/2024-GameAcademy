#pragma once
#include "Panel.h"
class UISpriteNumber;
class Label;
class TowerGamePanel : public Panel
{
	DECLARE_CHILD(TowerGamePanel, Panel);

public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

public:
	void SetText(wstring text);
	void SetRoundText(wstring text);
	void SetTimer(int time);
	

private:
	UISpriteNumber* _timer = nullptr;
	Label* _waveStatusLabel = nullptr;
	Label* _roundLabel = nullptr;
};


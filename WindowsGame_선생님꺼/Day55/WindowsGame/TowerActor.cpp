#include "pch.h"
#include "TowerActor.h"

void TowerActor::Init()
{
	Super::Init();

	this->SetFlipbook(Resource->GetFlipbook(L"FB_DrillTank2_Down"));
}

void TowerActor::Render(HDC hdc)
{
	Super::Render(hdc);
}

void TowerActor::Update()
{
	Super::Update();
}

void TowerActor::Release()
{
	Super::Release();
}

void TowerActor::SetData(int64 id)
{
	this->_data = DATA->GetTower(id);
}
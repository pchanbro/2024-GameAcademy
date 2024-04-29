#include "pch.h"
#include "OmokStoneActor.h"

void OmokStoneActor::Init()
{
	Super::Init();

	this->SetName("¿À¸ñµ¹");
	this->SetSprite(Resource->GetSprite(L"S_BlackStone"));

}
void OmokStoneActor::Render(HDC hdc)
{
	Super::Render(hdc);
}
void OmokStoneActor::Update()
{
	Super::Update();
}
void OmokStoneActor::Release()
{
	Super::Release();
}

void OmokStoneActor::ChangeState(StoneState state)
{
	switch(state)
	{
	case StoneState::Black:
		this->SetSprite(Resource->GetSprite(L"S_BlackStone"));
		return;
	case StoneState::White:
		this->SetSprite(Resource->GetSprite(L"S_WhiteStone"));
		return;
	case StoneState::None:
		return;
	}
}

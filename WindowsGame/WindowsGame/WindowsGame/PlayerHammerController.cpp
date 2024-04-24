#include "pch.h"
#include "PlayerHammerController.h"


void PlayerHammerController::Init(HammerActor* playerHammer, vector<MoleActor*> moles)
{
	// Linking
	// SetLink
	_playerHammer = playerHammer;
	_moles = moles;
}
void PlayerHammerController::Update()
{
	this->ChangePlayerHammerPos();

	if (Input->GetKeyDown(KeyCode::LeftMouse))
	{
		_playerHammer->ChangeState(HammerActorState::Hit);
		this->CatchMole();
	}


}
void PlayerHammerController::ChangePlayerHammerPos()
{

}
void PlayerHammerController::CatchMole()
{

}
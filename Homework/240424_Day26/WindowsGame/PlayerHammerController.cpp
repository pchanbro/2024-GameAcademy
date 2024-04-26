#include "pch.h"
#include "PlayerHammerController.h"
#include "HammerActor.h"
#include "MoleActor.h"
#include "BoxCollider.h"
#include "MoleGameScene.h"

void PlayerHammerController::Init(HammerActor* playerHammer, vector<MoleActor*> moles)
{
	// Linking (받은 인수를 선언한 변수에 넣어주는거)
	// SetLink
	_playerHammer = playerHammer;
	_moles = moles;
}
void PlayerHammerController::Update()
{
	this->ChangePlayerHammerPos(); // 이걸 해줘서 마우스에 해머가 따라다닐거다

	if (Input->GetKeyDown(KeyCode::LeftMouse))
	{
		_playerHammer->ChangeState(HammerActorState::Hit);
		this->CatchMole();
	}

	if (Input->GetKeyUp(KeyCode::LeftMouse))
	{
		_playerHammer->ChangeState(HammerActorState::Idle);
	}
}
void PlayerHammerController::ChangePlayerHammerPos()
{
	POINT mousePos = Input->GetMousePos();
	_playerHammer->SetPos(mousePos);
}
void PlayerHammerController::CatchMole()
{
	POINT mousePos = Input->GetMousePos();
	for (MoleActor* mole : _moles)
	{
		BoxCollider* moleCollider = mole->GetComponent<BoxCollider>();
		// RectInRect의 경우에는 PtInRect을 8번 호출한다 그러니 PtInRect 사용해도 괜찮은 곳에선 이걸 사용해라
		// 이런 사소한 부분이 바로 최적화를 해주는 것! 너무 신경쓰지 않는다 해도 이런 알아볼 수 있는 부분은 최적화를 해주는게 좋다.
		if (Collision::PtInRect(mousePos, moleCollider->GetCollision().ToRect()))
		{
			if (mole->GetState() == MoleActorState::Out)
			{
				// 점수는 씬에 있지

				// 현재 씬을 가지고 오기
				MoleGameScene* currentScene = dynamic_cast<MoleGameScene*>(GET_SINGLE(SceneManager)->GetCurrentScene());

				// 코드는 평생간다 그러니 다른게임에 사용되어 치명적인 오류가 되는걸 방지하도록 다음과 같은 if문을 추가한다.
				// 두더지 잡기에서만 사용하도록 이 코드를 추가한다. 
				// 이걸 추가 안해주면 다른데에서 이 엑터를 사용할 경우에도 아래 코드가 실행될 가능성이 존재한다.
				// 그렇게 되면 매우 치명적인 오류가 된다.
				if (currentScene != nullptr)
				{
					// MoleGameScene일때만 동작!
					currentScene->PlusScore();
				}

				mole->ChangeState(MoleActorState::Die);
			}
		}
	}
}
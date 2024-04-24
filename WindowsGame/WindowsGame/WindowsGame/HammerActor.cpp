#include "pch.h"
#include "HammerActor.h"
#include "MoleActor.h"
#include "MoleGameScene.h"

void HammerActor::Init()
{
	Super::Init();

	this->SetName("Hammer");
	this->SetSprite(Resource->GetSprite(L"S_Hammer_Idle"));
}
void HammerActor::Render(HDC hdc)
{
	Super::Render(hdc);
}
void HammerActor::Update()
{
	Super::Update();

	POINT mousePos = Input->GetMousePos();
	this->SetBody(Shape::MakeCenterRect(mousePos.x, mousePos.y, 51, 51));

	if (Input->GetKeyDown(KeyCode::LeftMouse))
	{
		this->SetSprite(Resource->GetSprite(L"S_Hammer_Hit"));

		MoleGameScene* currentScene = dynamic_cast<MoleGameScene*>(GET_SINGLE(SceneManager)->GetCurrentScene());

		// 두더지 잡기에서만 사용하도록 이 코드를 추가한다. 
		// 이걸 추가 안해주면 다른데에서 이 엑터를 사용할 경우에도 아래 코드가 실행될 가능성이 존재한다.
		// 그렇게 되면 매우 치명적인 오류가 된다.
		if (currentScene != nullptr)
		{

			for (MoleActor* _mole : currentScene->_moles)
			{
				if (_mole->GetState() == MoleActorState::Out)
				{
					if (Collision::PtInRect(mousePos, _mole->GetBody().ToRect()))
					{
						_mole->ChangeState(MoleActorState::Die);
						currentScene->score++;
					}
				}
			}
		}
	}

	if (Input->GetKeyUp(KeyCode::LeftMouse))
	{
		this->SetSprite(Resource->GetSprite(L"S_Hammer_Idle"));
	}
}
void HammerActor::Release()
{
	Super::Release();

}

void HammerActor::ChangeState(HammerActorState state)
{
	if (_state == state) return;

	_state = state;

	switch (_state)
	{
	case HammerActorState::Hit:
		this->DoHit();
		break;
	case HammerActorState::Idle:
		this->DoIdle();
		break;
	case HammerActorState::None:
		break;
	default:
		break;
	}
}

void HammerActor::DoHit()
{
	this->SetSprite(Resource->GetSprite(L"S_Hammer_Hit"));

	// 나중에 여기서 더 할거라고는 이펙트 생성 정도
	// 이펙트는 애니메이션을 배워야함
}
void HammerActor::DoIdle()
{
	this->SetSprite(Resource->GetSprite(L"S_Hammer_Idle"));
}
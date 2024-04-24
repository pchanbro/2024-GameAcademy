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

		// �δ��� ��⿡���� ����ϵ��� �� �ڵ带 �߰��Ѵ�. 
		// �̰� �߰� �����ָ� �ٸ������� �� ���͸� ����� ��쿡�� �Ʒ� �ڵ尡 ����� ���ɼ��� �����Ѵ�.
		// �׷��� �Ǹ� �ſ� ġ������ ������ �ȴ�.
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

	// ���߿� ���⼭ �� �ҰŶ��� ����Ʈ ���� ����
	// ����Ʈ�� �ִϸ��̼��� �������
}
void HammerActor::DoIdle()
{
	this->SetSprite(Resource->GetSprite(L"S_Hammer_Idle"));
}
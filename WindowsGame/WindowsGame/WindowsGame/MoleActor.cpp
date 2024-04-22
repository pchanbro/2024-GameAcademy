#include "pch.h"
#include "MoleActor.h"
#include "BoxCollider.h"
#include "Dev2Scene.h"

void MoleActor::Init()
{
	Super::Init();


	this->SetName("Mole");
	this->SetSprite(Resource->GetSprite(L"S_Mole_Idle"));
}
void MoleActor::Render(HDC hdc)
{
	Super::Render(hdc);
}
void MoleActor::Update()
{
	Super::Update();

	if (Input->GetKeyDown(KeyCode::Space))
	{
		//죽기 실행
		ChangeState(MoleActorState::Die);
	}

	if (Input->GetKeyDown(KeyCode::Control))
	{
		//죽기 실행
		ChangeState(MoleActorState::Out);
	}



	// Unity 에서는 Invoke
	if (0.0f <= _comeInTimer)
	{
		_comeInTimer -= Time->GetDeltaTime();

		if (_comeInTimer < 0.0f)
		{
			ChangeState(MoleActorState::In);
		}
	}
}
void MoleActor::Release()
{
	Super::Release();

}

void MoleActor::ComeOut()
{
	cout << "MoleActor::ComeOut()" << endl;
	this->SetSprite(Resource->GetSprite(L"S_Mole_Idle"));
	_comeInTimer = 1.5f;
}
void MoleActor::ComeIn()
{
	cout << "MoleActor::ComeIn()" << endl;

	this->SetSprite(nullptr);
}
void MoleActor::Die()
{
	cout << "MoleActor::Die()" << endl;

	// 수도코드
	// 죽었을 떄 기능?

	// 1. 스프라이트 변경이 일어나야 한다.
	// 2. 사라짐 타이머 동작을 시켜준다. (Unity에는 Invoke라는 함수가 존재함 이걸 만들어야함)

	cout << "MoleActor::Die()" << endl;

	this->SetSprite(Resource->GetSprite(L"S_Mole_Die"));
	_comeInTimer = 1.0f;
}

void MoleActor::ChangeState(MoleActorState state)
{
	//FSM 유한상태머신

	if (_state == state) return;

	_state = state;

	switch (_state)
	{
	case MoleActorState::Out:
		this->ComeOut();
		break;
	case MoleActorState::In:
		this->ComeIn();
		break;
	case MoleActorState::Die:
		this->Die();
		break;
	case MoleActorState::None:
		break;
	default:
		break;
	}
}
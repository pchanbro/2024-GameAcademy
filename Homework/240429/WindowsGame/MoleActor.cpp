#include "pch.h"
#include "MoleActor.h"
#include "BoxCollider.h"

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
		// 그냥 바로 Die(); 해서 함수를 호출하는게 아니라 이렇게 호출하면 몬스터의 상태만 바꿔줬는데 알아서 동작하는것 같은 효과를 준다.
		// 스타크래프트로 치면
		// 유닛한테 
		// 패트롤 상태 << 명령을 주면
		// 상태만 변경,
		// 코드단에서는 state만 제어해주면 다 알아서 되는 것 같은거다.
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

	// 땅꿀로 들어가면 그림을 그려주면 안되니까 NULL로 해준다.
	this->SetSprite(nullptr);
}
void MoleActor::Die()
{
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
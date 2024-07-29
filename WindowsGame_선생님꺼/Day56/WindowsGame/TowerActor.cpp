#include "pch.h"
#include "TowerActor.h"

void TowerActor::Init()
{
	Super::Init();

	this->SetState(ETowerState::Rest);

	{
		GameEvent<int>* gameEvent = GET_SINGLE(GameEventManager)->GetEvent<int>("WaveStart");
		if (gameEvent != nullptr)
		{
			gameEvent->AddListen(this, &TowerActor::OnWaveStart);
		}
	}


	{
		GameEvent<int>* gameEvent = GET_SINGLE(GameEventManager)->GetEvent<int>("BuildStart");
		if (gameEvent != nullptr)
		{
			gameEvent->AddListen(this, &TowerActor::OnBuildStart);
		}
	}
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

	//string 자료형을 => wstring으로 변경하기
	//string2wstring
	
	this->SetFlipbook(Resource->GetFlipbook(GetFlipbookName()));
}

wstring TowerActor::GetFlipbookName()
{

	wstring flipbookName = Util::string2Wstring(_data.ResourceName);

	switch (_state)
	{
	case ETowerState::Rest:
		flipbookName += L"1";
		break;
	case ETowerState::Idle:
		flipbookName += L"2";
		break;
	case ETowerState::Attack:
		flipbookName += L"3";
		break;
	default:
		break;
	}

	flipbookName += L"_Down";


	return flipbookName;
}

void TowerActor::SetState(ETowerState state)
{
	if (state == _state) return;


	_state = state;

	switch (_state)
	{
	case ETowerState::Rest:
		break;
	case ETowerState::Idle:
		break;
	case ETowerState::Attack:
		break;
	default:
		break;
	}


	this->SetFlipbook(Resource->GetFlipbook(GetFlipbookName()));
}


void TowerActor::OnWaveStart(int round)
{
	this->SetState(ETowerState::Idle);
}

void TowerActor::OnBuildStart(int round)
{
	this->SetState(ETowerState::Rest);
}
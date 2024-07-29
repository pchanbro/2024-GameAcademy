#include "pch.h"
#include "WaveController.h"
#include "TowerGamePanel.h"
#include "Scene.h"
void WaveController::Init()
{
	_data = DATA->GetWaveOption();

	GET_SINGLE(GameEventManager)->AddEvent("WaveStart", new GameEvent<int>());
	GET_SINGLE(GameEventManager)->AddEvent("BuildStart", new GameEvent<int>());

	_mainPanel = new TowerGamePanel();
	_mainPanel->Init();
	wchar_t str[50];
	swprintf_s(str, L"Round %d", _round);
	_mainPanel->SetRoundText(wstring(str));

	CurrentScene->AddUI(_mainPanel);
}

void WaveController::Update()
{
	_textTimer -= Time->GetDeltaTime();

	// _data.FloatingTextTime 초가 지났다면
	if (_textTimer <= 0)
	{
		_mainPanel->SetText(L"");
	}

	switch (_state)
	{	
	case EWaveState::None:
		break;
	case EWaveState::BuildTime:
		Update_BuildTime();
		break;
	case EWaveState::WaveTime:
		Update_WaveTime();
		break;
	default:
		break;
	}
}

void WaveController::Update_WaveTime()
{
	_waveTime -= Time->GetDeltaTime();
	_mainPanel->SetTimer(static_cast<int>(_waveTime));

	if (_waveTime <= 0)
	{
		_round++;
		wchar_t str[50];
		swprintf_s(str, L"Round %d", _round);
		_mainPanel->SetRoundText(wstring(str));
		this->SetState(EWaveState::BuildTime);
	}
}
void WaveController::Update_BuildTime()
{
	_buildTime -= Time->GetDeltaTime();
	_mainPanel->SetTimer(static_cast<int>(_buildTime));

	if (_buildTime <= 0)
	{
		this->SetState(EWaveState::WaveTime);
	}
}

void WaveController::SetState(EWaveState state)
{
	if (_state == state) return;

	_state = state;
	_textTimer = _data.FloatingTextTime;

	switch (state)
	{
	case EWaveState::None:
		break;
	case EWaveState::BuildTime:
		_mainPanel->SetText(L"타워를 건설할 시간입니다.");
		GET_SINGLE(GameEventManager)->GetEvent<int>("BuildStart")->Invoke(_round);
		_buildTime = _data.BuildTime;
		break;
	case EWaveState::WaveTime:
		_mainPanel->SetText(L"적군이 도착할 시간입니다.");
		GET_SINGLE(GameEventManager)->GetEvent<int>("WaveStart")->Invoke(_round);
		_waveTime = _data.WaveTime;
		break;
	default:
		break;
	}
}
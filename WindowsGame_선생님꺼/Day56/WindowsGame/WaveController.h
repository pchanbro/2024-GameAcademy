#pragma once
class TowerGamePanel;
class WaveController
{
public:
	void Init();
	void Update();

	void SetState(EWaveState state);

public:
	void Update_WaveTime();
	void Update_BuildTime();

private:
	TowerGamePanel* _mainPanel = nullptr;

	EWaveState _state = EWaveState::None;

	float _textTimer = 3.0f;
	float _waveTime = 30.0f;
	float _buildTime = 30.0f;

	int _round = 1;

	WaveOptionData _data;
};


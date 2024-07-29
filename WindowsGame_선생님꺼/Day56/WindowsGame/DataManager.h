#pragma once
class DataManager
{
	DECLARE_SINGLE(DataManager)

public:
	void Init();
	void Release();


	MonsterData GetMonster(int64 id) { return _monsterDatas[id]; }
	TowerData GetTower(int64 id) { return _towerDatas[id]; }
	WaveOptionData GetWaveOption() { return _waveOption; }
private:
	map<int64, MonsterData> _monsterDatas = {};
	map<int64, TowerData> _towerDatas = {};
	WaveOptionData _waveOption = {};
};


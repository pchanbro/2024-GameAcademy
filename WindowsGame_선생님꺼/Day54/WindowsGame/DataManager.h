#pragma once
class DataManager
{
	DECLARE_SINGLE(DataManager)

public:
	void Init();
	void Release();


	MonsterData GetMonster(int64 id) { return _monsterDatas[id]; }
private:
	map<int64, MonsterData> _monsterDatas = {};
};


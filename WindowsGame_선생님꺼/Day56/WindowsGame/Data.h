#pragma once

class DataBase
{
public:
	virtual void FromJson(string json) = 0;	//JSON => °´Ã¼·Î
	virtual string ToJson() = 0;	//°´Ã¼ => JSON
};

#pragma region MonsterData

struct MonsterData : public DataBase
{
	int64 Id;
	string Name;
	float Hp;
	float MoveSpeed;
	int64 SkillId;

public:
	virtual void FromJson(string json) override;
	virtual string ToJson() override;
};
/*
  "id": 100001,		// 100`000`000  21¾ï±îÁö ±Ý¹æ¾¹´Ï´Ù.
  "name": "Monster1",
  "hp": 1000,
  "moveSpeed": 300,
  "skillId":  200001
*/
#pragma endregion

#pragma region TowerData
struct TowerData : public DataBase
{
	int64 Id;
	string Name;
	float Damage;
	float AttackSpeed;
	float AttackRange;
	string ResourceName;

public:
	virtual void FromJson(string json) override;
	virtual string ToJson() override;
};
/*
{
	"id": 100002,
	"name": "Tower2",
	"damage": 50,
	"attackSpeed": 300,
	"attackRange": 200,
	"resourceName": "FB_Tank"
}
*/
#pragma endregion

#pragma region WaveOptionData
struct WaveOptionData : public DataBase
{
	float WaveTime;
	float BuildTime;
	float FloatingTextTime;

public:
	virtual void FromJson(string json) override;
	virtual string ToJson() override;
};
/*
{
  "waveTime": 5,
  "buildTime": 5,
  "floatingTextTime": 3
}
*/
#pragma endregion
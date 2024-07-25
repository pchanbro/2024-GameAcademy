#pragma once

class DataBase
{
public:
	virtual void FromJson(string json) = 0;	//JSON => °´Ã¼·Î
	virtual string ToJson() = 0;	//°´Ã¼ => JSON
};


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
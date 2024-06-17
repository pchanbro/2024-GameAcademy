#pragma once

class DataBase
{
public:
	virtual void FromJson(string json) = 0; // JSON => 객체
	virtual string ToJson() = 0; // 객체 => JSON
};

struct MonsterData : public DataBase // struct도 상속이 된다.
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
{
  "id": 100001,		// 100'000'000 21억까지 금방 씀
  "name": "Monster",
  "hp": 1000,
  "moveSpeed": 300,
  "skillId": 200001
}
*/
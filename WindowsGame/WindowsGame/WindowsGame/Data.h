#pragma once

class DataBase
{
public:
	virtual void FromJson(string json) = 0; // JSON => ��ü
	virtual string ToJson() = 0; // ��ü => JSON
};

struct MonsterData : public DataBase // struct�� ����� �ȴ�.
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
  "id": 100001,		// 100'000'000 21����� �ݹ� ��
  "name": "Monster",
  "hp": 1000,
  "moveSpeed": 300,
  "skillId": 200001
}
*/
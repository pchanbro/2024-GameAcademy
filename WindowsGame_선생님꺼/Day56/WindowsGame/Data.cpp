#include "pch.h"
#include "Data.h"

#pragma region MonsterData
void MonsterData::FromJson(string json)
{
	Document document;
	document.Parse(json.c_str());

	assert(document.HasParseError() == false);

	this->Id = document["id"].GetInt64();
	this->Hp = document["hp"].GetFloat();
	this->MoveSpeed = document["moveSpeed"].GetFloat();
	this->Name = document["name"].GetString();
	this->SkillId = document["skillId"].GetInt64();
}
string MonsterData::ToJson()
{
	StringBuffer buffer;
	Writer<StringBuffer> writer(buffer);

	writer.StartObject();
	writer.Key("id");
	writer.Int64(this->Id);
	writer.Key("hp");
	writer.Double(this->Hp);
	writer.Key("moveSpeed");
	writer.Double(this->MoveSpeed);
	writer.Key("name");
	writer.String(this->Name.c_str());
	writer.Key("skillId");
	writer.Int64(this->SkillId);

	writer.EndObject();

	return string(buffer.GetString());
}
#pragma endregion


#pragma region TowerData
void TowerData::FromJson(string json)
{
	Document document;
	document.Parse(json.c_str());

	assert(document.HasParseError() == false);


	this->Id = document["id"].GetInt64();
	this->Name = document["name"].GetString();
	this->Damage = document["damage"].GetFloat();
	this->AttackSpeed = document["attackSpeed"].GetFloat();
	this->AttackRange = document["attackRange"].GetFloat();
	this->ResourceName = document["resourceName"].GetString();
}
string TowerData::ToJson()
{
	StringBuffer buffer;
	Writer<StringBuffer> writer(buffer);

	writer.StartObject();
	writer.Key("id");
	writer.Int64(this->Id);
	writer.Key("name");
	writer.String(this->Name.c_str());
	writer.Key("damage");
	writer.Double(this->Damage);
	writer.Key("attackSpeed");
	writer.Double(this->AttackSpeed);
	writer.Key("attackRange");
	writer.Double(this->AttackRange);
	writer.Key("resourceName");
	writer.String(this->ResourceName.c_str());

	writer.EndObject();

	return string(buffer.GetString());
}
#pragma endregion

#pragma region WaveOptionData
void WaveOptionData::FromJson(string json)
{
	Document document;
	document.Parse(json.c_str());

	assert(document.HasParseError() == false);

	this->BuildTime = document["buildTime"].GetFloat();
	this->WaveTime = document["waveTime"].GetFloat();
	this->FloatingTextTime = document["floatingTextTime"].GetFloat();
}
string WaveOptionData::ToJson()
{
	StringBuffer buffer;
	Writer<StringBuffer> writer(buffer);

	writer.StartObject();

	writer.Key("buildTime");
	writer.Double(this->BuildTime);
	writer.Key("waveTime");
	writer.Double(this->WaveTime);
	writer.Key("floatingTextTime");
	writer.Double(this->FloatingTextTime);

	writer.EndObject();

	return string(buffer.GetString());
}
#pragma endregion


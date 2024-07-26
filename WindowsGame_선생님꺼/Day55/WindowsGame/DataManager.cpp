#include "pch.h"
#include "DataManager.h"

void DataManager::Init()
{
#pragma region MonsterData
	{
		//파일 읽어서 로드하기
		ifstream ifs(L"../Resources/Data/MonsterData.json");

		assert(ifs.is_open());

		stringstream buffer;
		buffer << ifs.rdbuf();
		string json = buffer.str();

		Document document;
		document.Parse(json.c_str());

		assert(document.HasParseError() == false);

		assert(document.IsArray());
		GenericArray<false, Value> array = document.GetArray();

		for (SizeType i = 0; i < array.Size(); ++i) {
			// json
			StringBuffer buffer;
			Writer<StringBuffer> writer(buffer);
			array[i].Accept(writer);

			MonsterData data;
			data.FromJson(buffer.GetString());

			assert(_monsterDatas.contains(data.Id) == false);
			_monsterDatas[data.Id] = data;
		}


		for (auto monster : _monsterDatas)
		{
			string aa = monster.second.ToJson();
			cout << aa << endl;
		}
	}
#pragma endregion


#pragma region TowerData
	{
		//파일 읽어서 로드하기
		ifstream ifs(L"../Resources/Data/TowerData.json");

		assert(ifs.is_open());

		stringstream buffer;
		buffer << ifs.rdbuf();
		string json = buffer.str();

		Document document;
		document.Parse(json.c_str());

		assert(document.HasParseError() == false);

		assert(document.IsArray());
		GenericArray<false, Value> array = document.GetArray();

		for (SizeType i = 0; i < array.Size(); ++i) {
			// json
			StringBuffer buffer;
			Writer<StringBuffer> writer(buffer);
			array[i].Accept(writer);

			TowerData data;
			data.FromJson(buffer.GetString());

			assert(_towerDatas.contains(data.Id) == false);
			_towerDatas[data.Id] = data;
		}


		for (auto tower : _towerDatas)
		{
			string aa = tower.second.ToJson();
			cout << aa << endl;
		}
	}
#pragma endregion

}

void DataManager::Release()
{
	_monsterDatas.clear();
	_towerDatas.clear();
}
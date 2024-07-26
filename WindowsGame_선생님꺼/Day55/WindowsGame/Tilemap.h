#pragma once
#include "ResourceBase.h"

struct Tile
{
	//���Ŀ� Ÿ�Ͽ� ���� ������ �߰��Ǹ�, ���⿡ ���� �߰����ָ� ��
	int value = 0;

	//��ġ������ Ÿ�������� ���� �Լ�
	bool IsBuildableTile()
	{
		vector<int> buildableTiles = { 4, 15, 16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45 };

		if (find(buildableTiles.begin(), buildableTiles.end(), value) == buildableTiles.end())
		{
			return false;
		}
		
		return true;
	}
};

class Tilemap : public ResourceBase
{
	DECLARE_CHILD(Tilemap, ResourceBase)

public:
	virtual void LoadFile(const wstring& path);
	virtual void SaveFile(const wstring& path);

public:
	Vector2Int GetMapSize() { return _mapSize; }
	int GetTileSize() { return _tileSize; }
	void SetTiles(vector<vector<Tile>> tiles) { _tiles = tiles; }
	vector<vector<Tile>>& GetTiles() { return _tiles; }
	Tile* GetTileAt(Vector2Int pos);

	void SetMapSize(Vector2Int size) { _mapSize = size; }
	void SetTileSize(int size) { _tileSize = size; }

protected:
	Vector2Int _mapSize = {};
	int _tileSize = 0;	//�׻� ���簢�� ����̱⶧����.
	vector<vector<Tile>> _tiles;


};


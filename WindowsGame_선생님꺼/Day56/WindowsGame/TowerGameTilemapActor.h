#pragma once
#include "TilemapActor.h"
class TowerGameTilemapActor : public TilemapActor
{
	DECLARE_CHILD(TowerGameTilemapActor, TilemapActor);

public:
	int64 GetCellData(Vector2Int cellPos);
	void AddData(Vector2Int cellPos, int64 data);
	void RemoveData(Vector2Int cellPos);

private:
	map<Vector2Int, int64> _tileMapInfo = {};
};


// BinaryTree �����Ҷ�
//  Key������ ���� ������ ������ �����߾���.

// Key���� ������ ū��, �������� ���Ҽ��־���մϴ�.

// Vector2Int => ������ ū�� ������ �񱳸� �Ҽ�������.
// Vector2Int 
//  operator<
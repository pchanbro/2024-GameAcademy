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


// BinaryTree 구현할때
//  Key에따라서 왼쪽 오른쪽 나눠서 들어간다했었죠.

// Key끼리 누가더 큰지, 작은지를 비교할수있어야합니다.

// Vector2Int => 누가더 큰지 작은지 비교를 할수가없어.
// Vector2Int 
//  operator<
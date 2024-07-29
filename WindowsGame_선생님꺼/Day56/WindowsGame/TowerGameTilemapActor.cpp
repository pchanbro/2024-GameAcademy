#include "pch.h"
#include "TowerGameTilemapActor.h"
int64 TowerGameTilemapActor::GetCellData(Vector2Int cellPos)
{
	if (_tileMapInfo.contains(cellPos))
	{
		return _tileMapInfo[cellPos];
	}

	return 0;
}
void TowerGameTilemapActor::AddData(Vector2Int cellPos, int64 data)
{
	assert(_tileMapInfo.contains(cellPos) == false);
	if (_tileMapInfo.contains(cellPos))
	{
		return;
	}

	_tileMapInfo[cellPos] = data;
}
void TowerGameTilemapActor::RemoveData(Vector2Int cellPos)
{
	_tileMapInfo.erase(cellPos);
}
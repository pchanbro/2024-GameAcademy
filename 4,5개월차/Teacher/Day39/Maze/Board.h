#pragma once

enum class TileType
{
	EMPTY,
	WALL
};

class Board
{
public:
	Board() {}
	~Board() {}

	void Init(int size);
	void Render();

private:
	vector<vector<TileType>> _tiles = {};
	int _size = 0;

};


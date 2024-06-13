#pragma once

class Board;
class Player
{
public:
	void Init(Board* board);
	void Update();

	void SetPos(Vector2Int pos) { _pos = pos; }
	Vector2Int GetPos() { return _pos; }

	bool CanGo(Vector2Int pos);

	void CalulatePath_RightHand();
	void CalulatePath_BFS();
	void CalulatePath_Astar();

private:
	Vector2Int _pos;
	Board* _board = nullptr;

	vector<Vector2Int> _path;
	int _pathIndex = 0;
};


#include "pch.h"
#include "Player.h"
#include "Board.h"
#include <queue>
void Player::Init(Board* board)
{
	_board = board;

	_pos = _board->GetEnterPos();

	//this->CalulatePath_RightHand();
	this->CalulatePath_BFS();
}

bool Player::CanGo(Vector2Int pos)
{
	return _board->CanGo(pos);
}

void Player::CalulatePath_RightHand()
{
	// _path에 값이 담기는 함수
	//_path.push_back

	Vector2Int pos = _pos;

	_path.clear();
	_path.push_back(pos);

	Vector2Int dest = _board->GetExitPos();

	Vector2Int dir[4] =
	{
		Vector2Int(0, -1), // UP
		Vector2Int(1, 0), // RIGHT
		Vector2Int(0, 1), // DOWN
		Vector2Int(-1, 0), // LEFT
	};

	//탈출구를 찾을때까지 무한루프 계속 오른손방향으로 이동
	int index = 0;
	int dirIndex = 0;
	while (pos != dest)
	{
		index++;
		if (index > 10000)
		{
			return;
		}

		int newDir = dirIndex + 1;
		newDir %= 4;

		//오른쪽방향으로 갈수있으면
		if (CanGo(pos + dir[newDir]))
		{
			dirIndex = newDir;
			pos += dir[newDir];
			_path.push_back(pos);
		}
		//오른쪽으로 못가는데 앞으로는 갈수있으면
		else if (CanGo(pos + dir[dirIndex]))
		{
			pos += dir[dirIndex];
			_path.push_back(pos);
		}
		else
		{
			//왼쪽방향으로 90도 회전
			dirIndex = (dirIndex + 3) % 4;
		}
	}
}
void Player::CalulatePath_BFS()
{
	queue<Vector2Int> queue;
	queue.push(_pos);
	//x, y
	int size = _board->GetSize();
	vector<vector<bool>> visited(size, vector<bool>(size, false));

	//parent[y][x] = pos (xy는 pos에 의해 발견된곳)
	vector<vector<Vector2Int>> parent(size, vector<Vector2Int>(size, Vector2Int(-1, -1)));

	parent[_pos.y][_pos.x] = _pos;
	while (false == queue.empty())
	{
		Vector2Int current = queue.front();
		queue.pop();
		//방문했다 체크
		visited[current.y][current.x] = true;

		if (current == _board->GetExitPos())
		{
			//갈수있다. 없다.
			break;
		}

		//1. current에서 갈수있는 정점을 체크
		Vector2Int dir[4] =
		{
			Vector2Int(0, -1), // UP
			Vector2Int(1, 0), // RIGHT
			Vector2Int(0, 1), // DOWN
			Vector2Int(-1, 0), // LEFT
		};

		for (int i = 0; i < 4; i++)
		{
			Vector2Int nextPos = current + dir[i];
			//다음지점이 갈수있는 지점이면,
			if (this->CanGo(nextPos) && visited[nextPos.y][nextPos.x] == 0)
			{
				//nextPos는 current로부터 왔습니다.
				parent[nextPos.y][nextPos.x] = current;
				queue.push(nextPos);
			}
		}
	}


	//_path 에 담아보기.
	// --> 목적지부터 역으로 담으로 담으면 된다.

	Vector2Int pos = _board->GetExitPos();
	while (true)
	{
		_path.push_back(pos);

		if (pos == _board->GetEnterPos())
		{
			break;
		}

		pos = parent[pos.y][pos.x];
	}


	//배열의 절반
	for (int i = 0; i < _path.size() / 2; i++)
	{
		//스왑합니다.
		Vector2Int temp = _path[i];
		_path[i] = _path[_path.size() - 1 - i];
		_path[_path.size() - 1 - i] = temp;
	}
}

void Player::Update()
{
	if (_path.size() <= _pathIndex)
	{
		return;
	}

	_pos = _path[_pathIndex];
	_pathIndex++;

}
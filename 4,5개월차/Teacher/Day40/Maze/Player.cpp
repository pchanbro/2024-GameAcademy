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
	// _path�� ���� ���� �Լ�
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

	//Ż�ⱸ�� ã�������� ���ѷ��� ��� �����չ������� �̵�
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

		//�����ʹ������� ����������
		if (CanGo(pos + dir[newDir]))
		{
			dirIndex = newDir;
			pos += dir[newDir];
			_path.push_back(pos);
		}
		//���������� �����µ� �����δ� ����������
		else if (CanGo(pos + dir[dirIndex]))
		{
			pos += dir[dirIndex];
			_path.push_back(pos);
		}
		else
		{
			//���ʹ������� 90�� ȸ��
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

	//parent[y][x] = pos (xy�� pos�� ���� �߰ߵȰ�)
	vector<vector<Vector2Int>> parent(size, vector<Vector2Int>(size, Vector2Int(-1, -1)));

	parent[_pos.y][_pos.x] = _pos;
	while (false == queue.empty())
	{
		Vector2Int current = queue.front();
		queue.pop();
		//�湮�ߴ� üũ
		visited[current.y][current.x] = true;

		if (current == _board->GetExitPos())
		{
			//�����ִ�. ����.
			break;
		}

		//1. current���� �����ִ� ������ üũ
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
			//���������� �����ִ� �����̸�,
			if (this->CanGo(nextPos) && visited[nextPos.y][nextPos.x] == 0)
			{
				//nextPos�� current�κ��� �Խ��ϴ�.
				parent[nextPos.y][nextPos.x] = current;
				queue.push(nextPos);
			}
		}
	}


	//_path �� ��ƺ���.
	// --> ���������� ������ ������ ������ �ȴ�.

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


	//�迭�� ����
	for (int i = 0; i < _path.size() / 2; i++)
	{
		//�����մϴ�.
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
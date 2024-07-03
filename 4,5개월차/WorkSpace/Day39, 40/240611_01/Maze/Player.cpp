#include "pch.h"
#include "Player.h"
#include "Board.h"
#include <queue>
void Player::Init(Board* board)
{
	_board = board;

	_pos = _board->GetEnterPos();

	//this->CalulatePath_RightHand();
	//this->CalulatePath_BFS();
	this->CalulatePath_Astar();
}

bool Player::CanGo(Vector2Int pos)
{
	return _board->CanGo(pos);
}

// �����ʹ������� �ϸ� ������ Ż�ⱸ�� ������, �״� �߿����� ���� �˰��� �����Ե� ó����
void Player::CalulatePath_RightHand()
{
	// _path�� ���� ���� �Լ�, ���Ŀ� _path�� ���� �������� �������ָ� ��
	//_path.push_back

	Vector2Int pos = _pos;

	_path.clear();
	_path.push_back(pos);

	Vector2Int dest = _board->GetExitPos();

	Vector2Int dir[4] =
	{	// �̰� ���� ���� �߿���
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

// �ڡڡ��� �˰����� �ſ� �߿� ���� / ���׶� �ܰ� �����ڡڡ�
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
			// end �������� �������� üũ -> �� �� �ִ�, ���ٸ� �Ǵ�
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

	// ��������� �ϸ� �������� �� �� ���� ������ ��� üũ�ϱ⸸ �ϴ� �κ�
	// �Ʒ� ������ ���Եǰ� ����
	//if (current == _board->GetExitPos())
	//{
	//	// end �������� �������� üũ -> �� �� �ִ�, ���ٸ� �Ǵ�
	//	break;
	//} �� ������ �߰��ϸ� 
	// end �������� ��� �������� ���� �ߴ����� ���θ� �Ǵܱ��� �Ѵ�.

	//_path �� ��ƺ���.
	// --> ���������� ������ ������ �ȴ�.

	Vector2Int pos = _board->GetExitPos();
	while (true)
	{
		_path.push_back(pos);

		// ���������� ����
		if (pos == _board->GetEnterPos())
		{
			break;
		}

		pos = parent[pos.y][pos.x];
	}

	// ���� ������, 1������ ���� ������ ����
	// ������ ���������� ��������� ���� ������, ������ �����ϱ� �������� ��������� ���������� ����.
	// �迭�� ����
	for (int i = 0; i < _path.size() / 2; i++)
	{
		//�����մϴ�.
		Vector2Int temp = _path[i];
		_path[i] = _path[_path.size() - 1 - i];
		_path[_path.size() - 1 - i] = temp;
	}
}


// Astar���� ����� ����� ��带 �� ���Ͽ��� �����ϰ� ���� ���Ŵϱ� ���⿡ �����.
struct PQNode
{
	int Cost;
	Vector2Int Vertex;
	int G;

	bool operator<(const PQNode& other) const
	{
		return Cost > other.Cost;
	}

	bool operator>(const PQNode& other) const
	{
		return Cost > other.Cost;
	}
};

void Player::CalulatePath_Astar()
{
	// �켱���� ť�� ����(Vector2Int)�� ������ ������� ��ɷ� �ؾ����� �𸣰� �ȴ�.
	// �켱���� ť���� ���������� ������⸦ �ϰų� �Ʒ������� ������⸦ �ϴµ� ū�� ���������� ������ ���������� ���°� less�� greater
	// less     (�� ū�� ��Ʈ�� ��)
	// greater  (�� ������ ��Ʈ�� ��)
	// ���⼭ Cost�� Ŭ���� ������ ������ greator�� ����
	priority_queue<PQNode, vector<PQNode>, greater<PQNode>> queue;
	
	Vector2Int dest = _board->GetExitPos();
	PQNode node;
	node.Vertex = _pos;
	node.G = 0;
	node.Cost = node.G + (dest - _pos).Length();// ������� �� ���(G) + ���������� ���� ���� ���(H);
	queue.push(node);
	
	int size = _board->GetSize();
	vector<vector<bool>> visited(size, vector<bool>(size, false));

	vector<vector<Vector2Int>> parent(size, vector<Vector2Int>(size, Vector2Int(-1, -1)));

	parent[_pos.y][_pos.x] = _pos;
	while (false == queue.empty())
	{
		PQNode current = queue.top();
		queue.pop();
		visited[current.Vertex.y][current.Vertex.x] = true;

		if (current.Vertex == _board->GetExitPos())
		{
			break;
		}

		Vector2Int dir[4] =
		{
			Vector2Int(0, -1),
			Vector2Int(1, 0), 
			Vector2Int(0, 1), 
			Vector2Int(-1, 0),
		};

		int moveCost[4] =
		{
			1,
			1,
			1,
			1,
		};

		for (int i = 0; i < 4; i++)
		{
			Vector2Int nextPos = current.Vertex + dir[i];

			if (this->CanGo(nextPos) && visited[nextPos.y][nextPos.x] == 0)
			{
				parent[nextPos.y][nextPos.x] = current.Vertex;
				PQNode newNode;
				newNode.Vertex = nextPos;
				newNode.G = current.G + moveCost[i];
				newNode.Cost = newNode.G + (dest - nextPos).Length();
				queue.push(newNode);
			}
		}
	}

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

	for (int i = 0; i < _path.size() / 2; i++)
	{
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
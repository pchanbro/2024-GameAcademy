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

// 오른쪽방향으로 하면 언젠가 탈출구에 도착함, 그닥 중요하지 않은 알고리즘 선생님도 처음봄
void Player::CalulatePath_RightHand()
{
	// _path에 값이 담기는 함수, 이후에 _path를 통해 움직임을 연출해주면 됨
	//_path.push_back

	Vector2Int pos = _pos;

	_path.clear();
	_path.push_back(pos);

	Vector2Int dest = _board->GetExitPos();

	Vector2Int dir[4] =
	{	// 이거 적는 순서 중요함
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

// ★★★이 알고리즘은 매우 중요 면접 / 코테때 단골 질문★★★
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
			// end 지점으로 갔는지를 체크 -> 갈 수 있다, 없다를 판단
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

	// 여기까지만 하면 정점에서 갈 수 있은 정점을 모두 체크하기만 하는 부분
	// 아랫 내용이 포함되고 위의
	//if (current == _board->GetExitPos())
	//{
	//	// end 지점으로 갔는지를 체크 -> 갈 수 있다, 없다를 판단
	//	break;
	//} 이 내용을 추가하면 
	// end 지점까지 어떻게 가는지랑 도착 했는지의 여부를 판단까지 한다.

	//_path 에 담아보기.
	// --> 목적지부터 역으로 담으면 된다.

	Vector2Int pos = _board->GetExitPos();
	while (true)
	{
		_path.push_back(pos);

		// 시작점으로 오면
		if (pos == _board->GetEnterPos())
		{
			break;
		}

		pos = parent[pos.y][pos.x];
	}

	// 벡터 뒤집기, 1번에서 많이 나오는 문제
	// 위에서 도착점에서 출발점으로 가는 식으로, 역으로 했으니까 뒤집으면 출발점에서 도착점으로 간다.
	// 배열의 절반
	for (int i = 0; i < _path.size() / 2; i++)
	{
		//스왑합니다.
		Vector2Int temp = _path[i];
		_path[i] = _path[_path.size() - 1 - i];
		_path[_path.size() - 1 - i] = temp;
	}
}


// Astar에서 비용을 계산할 노드를 이 파일에선 간단하게 쓰고 말거니까 여기에 만든다.
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
	// 우선순위 큐에 정점(Vector2Int)을 넣으면 비용계산을 어떤걸로 해야할지 모르게 된다.
	// 우선순위 큐에서 위에서부터 도장깨기를 하거나 아래서부터 도장깨기를 하는데 큰게 내려갈건지 작은게 내려갈건지 고르는게 less와 greater
	// less     (더 큰게 루트로 옴)
	// greater  (더 작은게 루트로 옴)
	// 여기서 Cost는 클수록 안좋기 때문에 greator을 쓴다
	priority_queue<PQNode, vector<PQNode>, greater<PQNode>> queue;
	
	Vector2Int dest = _board->GetExitPos();
	PQNode node;
	node.Vertex = _pos;
	node.G = 0;
	node.Cost = node.G + (dest - _pos).Length();// 현재까지 온 비용(G) + 목적지까지 가는 예상 비용(H);
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
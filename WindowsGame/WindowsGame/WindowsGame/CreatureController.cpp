#include "pch.h"
#include "CreatureController.h"
#include "CreatureActor.h"
#include "TilemapScene.h"
#include "Tilemap.h"
#include "TilemapActor.h"

void CreatureController::SetLink(CreatureActor* actor)
{
	assert(actor != nullptr);

	_actor = actor;
}
void CreatureController::Update()
{
	_actor->SetIsAttackInput(false);

	// Controller
	//  - 키를 누르면 
	//  - DestPos을 정해준다. (도착지점 포지션) (컨트롤러 입장)
	// 
	//  Character Update
	//  - DestPos이 될 때까지 해당 방향으로 계속 이동한다. (캐릭터 입장)

	if (Input->GetKey(KeyCode::Up))
	{
		// 캐릭터가 지금 움직일 수 있는 상태인지?
		// Update 문은 매 프레임 들어온다.
		// 모든객체가 
		// Update 최상위 if문은
		//  매 프레임 비교됨.
		// 최대한 이벤트가 적은내용으로 적어주는게 좋다.

		// 최적화는 틈틈히 하는거. 따로 시간내서 하는게 아니다. 따로 시간내서 최적화하는건 망한게임

		if (_actor->CanMove())
		{
			Vector2Int cellPos = _actor->GetCellPos();
			cellPos.y -= 1;

			TilemapScene* scene = dynamic_cast<TilemapScene*>(CurrentScene);
			assert(scene != nullptr);
			if (scene == nullptr)
			{
				return;
			}

			if (scene->CanGo(_actor, cellPos))
			{
				_actor->SetCellPos(cellPos);
				_actor->SetState(CreatureState::Move);
				
			}
			_actor->ChangeDirection(eCreatureDirection::UP);
		}
	}
	else if (Input->GetKey(KeyCode::Left))
	{
		if (_actor->CanMove())
		{
			Vector2Int cellPos = _actor->GetCellPos();
			cellPos.x -= 1;

			TilemapScene* scene = dynamic_cast<TilemapScene*>(CurrentScene);
			assert(scene != nullptr);
			if (scene == nullptr)
			{
				return;
			}

			if (scene->CanGo(_actor, cellPos))
			{
				_actor->SetCellPos(cellPos);
				_actor->SetState(CreatureState::Move);
			}
			_actor->ChangeDirection(eCreatureDirection::LEFT);
		}
	}
	else if (Input->GetKey(KeyCode::Right))
	{
		if (_actor->CanMove())
		{
			Vector2Int cellPos = _actor->GetCellPos();
			cellPos.x += 1;

			TilemapScene* scene = dynamic_cast<TilemapScene*>(CurrentScene);
			assert(scene != nullptr);
			if (scene == nullptr)
			{
				return;
			}

			if (scene->CanGo(_actor, cellPos))
			{
				_actor->SetCellPos(cellPos);
				_actor->SetState(CreatureState::Move);
			}
			_actor->ChangeDirection(eCreatureDirection::RIGHT);
		}
	}
	else if (Input->GetKey(KeyCode::Down))
	{
		if (_actor->CanMove())
		{
			Vector2Int cellPos = _actor->GetCellPos();
			cellPos.y += 1;

			TilemapScene* scene = dynamic_cast<TilemapScene*>(CurrentScene);
			assert(scene != nullptr);
			if (scene == nullptr)
			{
				return;
			}

			if (scene->CanGo(_actor, cellPos))
			{
				_actor->SetCellPos(cellPos);
				_actor->SetState(CreatureState::Move);
			}
			_actor->ChangeDirection(eCreatureDirection::DOWN);
		}
	}

	if (Input->GetKeyDown(KeyCode::Space))
	{
		_actor->SetIsAttackInput(true);
	}


	if (Input->GetKeyDown(KeyCode::RightMouse))
	{
		TilemapScene* scene = dynamic_cast<TilemapScene*>(CurrentScene);
		assert(scene != nullptr);
		if (scene == nullptr)
		{
			return;
		}

		TilemapActor* tilmapActor = scene->GetTilemapActor();
		assert(tilmapActor != nullptr);
		if (tilmapActor == nullptr)
		{
			return;
		}


		vector<Vector2Int> path = Calculator_Astar(_actor->GetCellPos(), tilmapActor->GetTileIndexByPos(Input->GetMousePos()));
		_actor->SetPath(path);

	}
}

vector<Vector2Int> CreatureController::Calculator_Astar(Vector2Int startPos, Vector2Int endPos)
{
	vector<Vector2Int> result;


	TilemapScene* scene = dynamic_cast<TilemapScene*>(CurrentScene);
	assert(scene != nullptr);
	if (scene == nullptr)
	{
		return result;
	}

	Tilemap* tilemap = scene->GetTilemap();
	assert(tilemap != nullptr);
	if (tilemap == nullptr)
	{
		return result;
	}

	priority_queue<PQNode, vector<PQNode>, greater<PQNode>> queue;

	Vector2Int dest = endPos;
	PQNode node;
	node.Vertex = startPos;
	node.G = 0;
	node.Cost = node.G + (dest - startPos).Length();// 현재까지 온 비용(G) + 목적지까지 가는 예상 비용(H);
	queue.push(node);


	Vector2Int mapSize = tilemap->GetMapSize();
	vector<vector<bool>> visited(mapSize.y, vector<bool>(mapSize.x, false));

	vector<vector<Vector2Int>> parent(mapSize.y, vector<Vector2Int>(mapSize.x, Vector2Int(-1, -1)));

	parent[startPos.y][startPos.x] = startPos;
	while (false == queue.empty())
	{
		PQNode current = queue.top();
		queue.pop();
		visited[current.Vertex.y][current.Vertex.x] = true;

		if (current.Vertex == endPos)
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

			if (scene->CanGo(_actor, nextPos) && visited[nextPos.y][nextPos.x] == 0)
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

	Vector2Int pos = endPos;
	vector<Vector2Int> path = {};
	while (true)
	{
		path.push_back(pos);
		if (pos == startPos)
		{
			break;
		}

		pos = parent[pos.y][pos.x];
	}

	for (int i = 0; i < path.size() / 2; i++)
	{
		Vector2Int temp = path[i];
		path[i] = path[path.size() - 1 - i];
		path[path.size() - 1 - i] = temp;
	}

	result = path;

	return result;
}

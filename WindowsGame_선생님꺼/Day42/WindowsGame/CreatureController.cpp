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

	if (Input->GetKey(KeyCode::Up))
	{
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

		TilemapActor* tilemapActor = scene->GetTilemapActor();
		assert(tilemapActor != nullptr);

		if (tilemapActor == nullptr)
		{
			return;
		}

		vector<Vector2Int> path = Calulator_Astar(_actor->GetCellPos(), 
			tilemapActor->GetTileIndexByPos(Input->GetMousePos()));
		_actor->SetPath(path);
	}





}

vector<Vector2Int> CreatureController::Calulator_Astar(Vector2Int startPos, Vector2Int endPos)
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
	node.Cost = node.G + (dest - startPos).Length();
	queue.push(node);


	//x, y
	Vector2Int mapSize = tilemap->GetMapSize();
	vector<vector<bool>> visited(mapSize.y, vector<bool>(mapSize.x, false));

	//parent[y][x] = pos (xy는 pos에 의해 발견된곳)
	vector<vector<Vector2Int>> parent(mapSize.y, vector<Vector2Int>(mapSize.x, Vector2Int(-1, -1)));

	parent[startPos.y][startPos.x] = startPos;
	while (false == queue.empty())
	{
		PQNode current = queue.top();
		queue.pop();
		//방문했다 체크
		visited[current.Vertex.y][current.Vertex.x] = true;

		if (current.Vertex == endPos)
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
			//다음지점이 갈수있는 지점이면,
			if (scene->CanGo(_actor, nextPos) && visited[nextPos.y][nextPos.x] == 0)
			{
				//nextPos는 current로부터 왔습니다.
				parent[nextPos.y][nextPos.x] = current.Vertex;
				PQNode newNode;
				newNode.Vertex = nextPos;
				newNode.G = current.G + moveCost[i];
				newNode.Cost = newNode.G + (dest - nextPos).Length();
				queue.push(newNode);
			}
		}
	}


	//_path 에 담아보기.
	// --> 목적지부터 역으로 담으로 담으면 된다.

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


	//배열의 절반
	for (int i = 0; i < path.size() / 2; i++)
	{
		//스왑합니다.
		Vector2Int temp = path[i];
		path[i] = path[path.size() - 1 - i];
		path[path.size() - 1 - i] = temp;
	}


	result = path;

	return result;
}
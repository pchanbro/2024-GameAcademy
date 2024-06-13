#include "pch.h"
#include "CreatureController.h"
#include "CreatureActor.h"
#include "TilemapScene.h"

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

}
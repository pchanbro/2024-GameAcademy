#include "pch.h"
#include "CreatureActor.h"
#include "Dev1Scene.h"
void CreatureActor::Init()
{
	Super::Init();

	_idleFlipbook[eCreatureDirection::DOWN] = Resource->GetFlipbook(L"FB_PlayerDownIdle");
	_idleFlipbook[eCreatureDirection::UP] = Resource->GetFlipbook(L"FB_PlayerUpIdle");
	_idleFlipbook[eCreatureDirection::LEFT] = Resource->GetFlipbook(L"FB_PlayerLeftIdle");
	_idleFlipbook[eCreatureDirection::RIGHT] = Resource->GetFlipbook(L"FB_PlayerRightIdle");

	_moveFlipbook[eCreatureDirection::DOWN] = Resource->GetFlipbook(L"FB_PlayerDownMove");
	_moveFlipbook[eCreatureDirection::UP] = Resource->GetFlipbook(L"FB_PlayerUpMove");
	_moveFlipbook[eCreatureDirection::LEFT] = Resource->GetFlipbook(L"FB_PlayerLeftMove");
	_moveFlipbook[eCreatureDirection::RIGHT] = Resource->GetFlipbook(L"FB_PlayerRightMove");

	_attackFlipbook[eCreatureDirection::DOWN] = Resource->GetFlipbook(L"FB_PlayerDownAttack");
	_attackFlipbook[eCreatureDirection::UP] = Resource->GetFlipbook(L"FB_PlayerUpAttack");
	_attackFlipbook[eCreatureDirection::LEFT] = Resource->GetFlipbook(L"FB_PlayerLeftAttack");
	_attackFlipbook[eCreatureDirection::RIGHT] = Resource->GetFlipbook(L"FB_PlayerRightAttack");

	this->SetState(_state);
}
void CreatureActor::Render(HDC hdc)
{
	Super::Render(hdc);

}
void CreatureActor::Update()
{
	Super::Update();
	
	switch (_state)
	{
	case CreatureState::Idle:
		UpdateIdle();
		break;
	case CreatureState::Move:
		UpdateMove();
		break;
	case CreatureState::Attack:
		UpdateAttack();
		break;
	default:
		break;
	}
}
void CreatureActor::Release()
{
	Super::Release();
}

void CreatureActor::SetState(CreatureState state)
{
	_state = state;
	switch (_state)
	{
	case CreatureState::Idle:
		this->SetFlipbook(_idleFlipbook[_dir]);
		break;
	case CreatureState::Move:
		this->SetFlipbook(_moveFlipbook[_dir]);
		break;
	case CreatureState::Attack:
		this->SetFlipbook(_attackFlipbook[_dir]);
		break;
	}
}

void CreatureActor::ChangeDirection(eCreatureDirection dir)
{
	if (_dir == dir) return;

	_dir = dir;
	switch (_state)
	{
	case CreatureState::Idle:
		this->SetFlipbook(_idleFlipbook[_dir]);
		break;
	case CreatureState::Move:
		this->SetFlipbook(_moveFlipbook[_dir]);
		break;
	case CreatureState::Attack:
		this->SetFlipbook(_attackFlipbook[_dir]);
		break;
	}
}

void CreatureActor::UpdateIdle()
{
	if (_pathIndex != _path.size())
	{
		Vector2Int cellPos = _path[_pathIndex++];

		TilemapScene* scene = dynamic_cast<TilemapScene*>(CurrentScene);
		assert(scene != nullptr);
		if (scene == nullptr)
		{
			return;
		}

		if (scene->CanGo(this, cellPos))
		{
			this->SetCellPos(cellPos);
			this->SetState(CreatureState::Move);
		}
	}
	else if (this->_isAttackInput)
	{
		this->SetState(CreatureState::Attack);
	}
}
void CreatureActor::UpdateMove()
{
	// _destPos 랑 비교해서 움직이게끔.
	// 현재 내포지션이 _destPos와 다르면
	// 내 dir방향으로 계속 움직인다.

	if (HasReachedDest())
	{
		this->SetState(CreatureState::Idle);
		this->SetPos(_destPos);
	}
	else
	{
		Vector2 dirVec = _destPos - this->GetPos();
		dirVec = dirVec.Normalize();

		//각도가 상, 하, 좌, 우
		_body.pos += dirVec * 450 * Time->GetDeltaTime();

		float upDotValue = dirVec.Dot(Vector2::Up());
		float rightDotValue = dirVec.Dot(Vector2::Right());
		float downDotValue = dirVec.Dot(Vector2::Down());
		float leftDotValue = dirVec.Dot(Vector2::Left());
		float cos45 = cos(Deg2Rad(45));
		if (cos45 < upDotValue)
		{
			this->ChangeDirection(eCreatureDirection::UP);
		}
		if (cos45 < rightDotValue)
		{
			this->ChangeDirection(eCreatureDirection::RIGHT);
		}
		if (cos45 < downDotValue)
		{
			this->ChangeDirection(eCreatureDirection::DOWN);
		}
		if (cos45 < leftDotValue)
		{
			this->ChangeDirection(eCreatureDirection::LEFT);
		}

	}


}

void CreatureActor::UpdateAttack()
{

}


void CreatureActor::SetCellPos(Vector2Int cellPos, bool teleport)
{
	_cellPos = cellPos;

	//_destPos를 정확하게 짚어줄거에요.

	//현재 맵에있는 Tilemap을 불러와서
	//_destPos에 해당 셀에 있는 Tile 좌표를 가져온다.
	TilemapScene* scene = dynamic_cast<TilemapScene*>(CurrentScene);

	//assert(scene != nullptr);
	if (scene == nullptr)
	{
		printf("비정상 접근!  CreatureActor::SetCellPos(Vector2Int cellPos)");
		return;
	}

	//이론상 씬에 타일맵이 있기때문에 값을 가져올수 있어야합니다.

	//저희가 특정 클래스나 Actor에서 씬에있거나 어딘가에 있는 무언가를 들고와야하는 상황이
	// 되게 자주 발생합니다.
	// 그럴때 못가져오면 개발이 불가능합니다.

	Vector2 destPos = scene->GetTilemapPos(cellPos);
	_destPos = destPos;


	// 자연스럽게 이동해서 저 포지션으로 갈거냐.
	// 아니면 순간이동시켜서 즉시 이동시킬거냐.
	if (teleport)
	{
		this->SetPos(_destPos);
	}

}

Vector2Int CreatureActor::GetCellPos()
{
	return _cellPos;
}

bool CreatureActor::HasReachedDest()
{
	return (_destPos - this->GetPos()).Length() < 10.0f;
}

bool CreatureActor::CanMove()
{
	if (this->_state == CreatureState::Attack)
	{
		return false;
	}

	if (this->_state == CreatureState::Move)
	{
		return false;
	}

	return true;
}

void CreatureActor::SetPath(vector<Vector2Int> path)
{
	_path = path;
	_pathIndex = 0;


	// _path[0] 지점으로 텔레포트
	// 잔버그 안나도록 하는용도
	if (0 < _path.size())
	{
		//this->SetCellPos(_path[0], true);
	}

}
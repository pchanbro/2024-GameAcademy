#include "pch.h"
#include "CreatureActor.h"
#include "Flipbook.h"
#include "Texture.h"
#include "BoxCollider.h"
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
void CreatureActor:: Render(HDC hdc)
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
	// 수도코드

	// _dir = dir;
	// 만약에 방향이 바뀌었으면, SetFlipbook을 해준다.

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
		//플레이어 Move 변경
		//플레이어 EndPos = _path[_pathIndex++];

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
	// _destPos 랑 비교해서 움직이게끔
	// 현재 내 포지션이 _destPos와 다르면 
	// 내 dir 방향으로 계속 움직인다.

	// _destPos와 내 위치의 길이 < 10 px보다 작다. 로 해주자
	// 10 정도로 널널하게 해주는게 좋다. -> 안좋은 컴퓨터들 프레임 튀면 안멈출거다
	
	// if문 조건이 한 번에 안읽히면 안좋은 코드! -> (_destPos - this->GetPos()).Length() < 10.0f 이걸 함수로 고쳐라
	if (HasReachedDest())
	{
		this->SetState(CreatureState::Idle);
		this->SetPos(_destPos);
	}
	else
	{
		Vector2 dirVec = _destPos - this->GetPos();
		dirVec = dirVec.Normalize();

		// 각도가 상, 하, 좌, 우 중 1개가 올거
		_body.pos += dirVec * 450 * Time->GetDeltaTime();

		// 여기서 상 하 좌 우 에따라서 캐릭터 방향을 돌려주겠다.
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
	if (_index == this->_flipbook->GetInfo().end)
	{
		this->SetState(CreatureState::Idle);
	}
}

void CreatureActor::SetCellPos(Vector2Int cellPos, bool teleport)
{
	_cellPos = cellPos;

	// 여기서는 해줘야 하는일이 있다.
	 
	
	// _destPos를 정확하게 짚어줄거다

	// 현재 맵에있는 Tilemap을 불러와서
	// _destPos에 해당 셀에 있는 Tile 좌표를 가져온다.
	TilemapScene* scene = dynamic_cast<TilemapScene*>(CurrentScene);

	// assert(scene != nullptr); -> 예외처리를 할 때마다 적어준다.
	
	// 근데 이 assert를 쓸 때랑 안쓸 때를 구분해야 하는데

	// assert는 라이브 중에 절대 뜨면 안되는 예외처리를 할때는 무조건 쓴다.
	
	// 하지만 진짜로 씬이 TilemapScene이 아닌 경우에는 아래와 같은 if문으로 처리해줘도 된다.
	// 아니면 기획자를 위해 만들어둔 씬일때 아래와 같이 if문으로 처리해준다.

	// 그래도 assert를 안쓰는 경우가 두렵다면 printf로 문구 출력정도 해줘도 좋다.

	if (scene == nullptr)
	{
		printf("비정상 접근 ! CreatureActor::SetCellPos(Vector2Int cellPos)");
		return;
	}

	// 이론상 씬에 타일맵이 있기 때문에 값을 가져올 수 있어야 한다.

	// 우리가 특정 클래스나 Actor에서 씬에 있거나 어딘가에 있는 무언가를 들고와야하는 상황이 매우 자주 발생한다.
	// 그런 경우 못가져오면 개발이 불가능하다.
	// 그 방법이 필요하다. 

	// 1. 나를 포함하고있는 씬을 가져온다.
	// 2. 씬에서 컨트롤러를 가져온다.

	Vector2 destPos = scene->GetTilemapPos(cellPos);
	_destPos = destPos;


	// 자연스럽게 이동해서 저 포지션으로 갈거냐
	// 아니면 순간이동시켜서 1프레임만에 이동시킬거냐.
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

	// 취향차이 _path[0] 지점으로 텔레포트
	// 잔버그 안나도록 하는 용도
	if (0 < _path.size())
	{
		//this->SetCellPos(_path[0], true);
	}
}

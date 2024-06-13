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
	if (this->_isAttackInput)
	{
		this->SetState(CreatureState::Attack);
	}
	else if (EPSILON < _velocity.Length())
	{
		SetState(CreatureState::Move);
	}
}
void CreatureActor::UpdateMove()
{
	// _destPos �� ���ؼ� �����̰Բ�.
	// ���� ���������� _destPos�� �ٸ���
	// �� dir�������� ��� �����δ�.

	if (HasReachedDest())
	{
		this->SetState(CreatureState::Idle);
		this->SetPos(_destPos);
	}
	else
	{
		switch (_dir)
		{
		case eCreatureDirection::RIGHT:
			_body.pos.x += 450 * Time->GetDeltaTime();
			break;
		case eCreatureDirection::LEFT:
			_body.pos.x -= 450 * Time->GetDeltaTime();
			break;
		case eCreatureDirection::UP:
			_body.pos.y -= 450 * Time->GetDeltaTime();
			break;
		case eCreatureDirection::DOWN:
			_body.pos.y += 450 * Time->GetDeltaTime();
			break;
		}

	}


}

void CreatureActor::UpdateAttack()
{

}


void CreatureActor::SetCellPos(Vector2Int cellPos, bool teleport)
{
	_cellPos = cellPos;

	//_destPos�� ��Ȯ�ϰ� ¤���ٰſ���.

	//���� �ʿ��ִ� Tilemap�� �ҷ��ͼ�
	//_destPos�� �ش� ���� �ִ� Tile ��ǥ�� �����´�.
	TilemapScene* scene = dynamic_cast<TilemapScene*>(CurrentScene);

	//assert(scene != nullptr);
	if (scene == nullptr)
	{
		printf("������ ����!  CreatureActor::SetCellPos(Vector2Int cellPos)");
		return;
	}

	//�̷л� ���� Ÿ�ϸ��� �ֱ⶧���� ���� �����ü� �־���մϴ�.

	//���� Ư�� Ŭ������ Actor���� �����ְų� ��򰡿� �ִ� ���𰡸� ���;��ϴ� ��Ȳ��
	// �ǰ� ���� �߻��մϴ�.
	// �׷��� ���������� ������ �Ұ����մϴ�.

	Vector2 destPos = scene->GetTilemapPos(cellPos);
	_destPos = destPos;


	// �ڿ������� �̵��ؼ� �� ���������� ���ų�.
	// �ƴϸ� �����̵����Ѽ� ��� �̵���ų�ų�.
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
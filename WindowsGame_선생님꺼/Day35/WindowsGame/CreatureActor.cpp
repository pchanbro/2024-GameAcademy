#include "pch.h"
#include "CreatureActor.h"

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
}
void CreatureActor::Render(HDC hdc)
{
	Super::Render(hdc);

}
void CreatureActor::Update()
{
	Super::Update();
	
	//TODO : Controller�� ��ü
	UpdateInput();

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

void CreatureActor::UpdateInput()
{
	SetIsAttackInput(false);
	Vector2 newVelocity = this->GetVelocity();
	bool isMoveKeyInput = false;


	if (Input->GetKey(KeyCode::Up))
	{
		isMoveKeyInput = true;
		ChangeDirection(eCreatureDirection::UP);
		newVelocity.x = 0;
		newVelocity.y -= Time->GetDeltaTime() * 10.0f;
		newVelocity.y = clamp(newVelocity.y, -1.0f, 1.0f);
	}
	else if (Input->GetKey(KeyCode::Left))
	{
		isMoveKeyInput = true;
		ChangeDirection(eCreatureDirection::LEFT);
		newVelocity.x -= Time->GetDeltaTime() * 10.0f;
		newVelocity.x = clamp(newVelocity.x, -1.0f, 1.0f);
		newVelocity.y = 0;
	}
	else if (Input->GetKey(KeyCode::Right))
	{
		isMoveKeyInput = true;
		ChangeDirection(eCreatureDirection::RIGHT);
		newVelocity.x += Time->GetDeltaTime() * 10.0f;
		newVelocity.x = clamp(newVelocity.x, -1.0f, 1.0f);
		newVelocity.y = 0;
	}
	else if (Input->GetKey(KeyCode::Down))
	{
		isMoveKeyInput = true;
		ChangeDirection(eCreatureDirection::DOWN);
		newVelocity.y += Time->GetDeltaTime() * 10.0f;
		newVelocity.y = clamp(newVelocity.y, -1.0f, 1.0f);
		newVelocity.x = 0;
	}

	if (Input->GetKeyDown(KeyCode::Space))
	{
		SetIsAttackInput(true);
	}


	if (isMoveKeyInput == false)
	{
		newVelocity = { 0,0 };
	}

	this->SetVelocity(newVelocity);
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
	if (_velocity.Length() < EPSILON)
	{
		SetState(CreatureState::Idle);
	}


	if (EPSILON < _velocity.Length())
	{
		//�����δ�.
		Vector2 newPos = this->GetPos();
		newPos += _velocity * 300 * Time->GetDeltaTime();
		this->SetPos(newPos);
	}
}

void CreatureActor::UpdateAttack()
{

}
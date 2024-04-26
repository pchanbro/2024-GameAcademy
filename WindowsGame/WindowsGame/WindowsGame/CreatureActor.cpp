#include "pch.h"
#include "CreatureActor.h"
#include "Flipbook.h"
#include "Texture.h"

void CreatureActor::Init()
{
	Super::Init();

	Resource->LoadTexture(L"T_Character", L"FlipbookTest/PlayerDown.bmp", RGB(128,128,128));
	Texture* texture = Resource->GetTexture(L"T_Character");
	Resource->CreateSprite(L"S_Character", texture, 0, 0, 200, 200);
	Sprite* sprite = Resource->GetSprite(L"S_Character");
	{
		FlipbookInfo info = {};
		info.duration = 1.0f;
		info.start = 0;
		info.end = 9;
		info.line = 0;
		info.loop = true;
		info.size = Vector2(200, 200);
		info.texture = Resource->GetTexture(L"T_Character");
		Resource->CreateFlipbook(L"FB_Player", info);
	}

	{
		Resource->LoadTexture(L"T_Character_Up", L"FlipbookTest/PlayerUp.bmp", RGB(128, 128, 128));
		FlipbookInfo info1 = {};
		info1.duration = 1.0f;
		info1.start = 0;
		info1.end = 9;
		info1.line = 1;
		info1.loop = true;
		info1.size = Vector2(200, 200);
		info1.texture = Resource->GetTexture(L"T_Character_Up");
		Resource->CreateFlipbook(L"FB_PlayerUp", info1);
	}

	{
		Resource->LoadTexture(L"T_Character_Down", L"FlipbookTest/PlayerDown.bmp", RGB(128, 128, 128));
		FlipbookInfo info1 = {};
		info1.duration = 1.0f;
		info1.start = 0;
		info1.end = 9;
		info1.line = 1;
		info1.loop = true;
		info1.size = Vector2(200, 200);
		info1.texture = Resource->GetTexture(L"T_Character_Down");
		Resource->CreateFlipbook(L"FB_PlayerDown", info1);
	}

	{
		Resource->LoadTexture(L"T_Character_Left", L"FlipbookTest/PlayerLeft.bmp", RGB(128, 128, 128));
		FlipbookInfo info1 = {};
		info1.duration = 1.0f;
		info1.start = 0;
		info1.end = 9;
		info1.line = 1;
		info1.loop = true;
		info1.size = Vector2(200, 200);
		info1.texture = Resource->GetTexture(L"T_Character_Left");
		Resource->CreateFlipbook(L"FB_PlayerLeft", info1);
	}

	{
		Resource->LoadTexture(L"T_Character_Right", L"FlipbookTest/PlayerRight.bmp", RGB(128, 128, 128));
		FlipbookInfo info1 = {};
		info1.duration = 1.0f;
		info1.start = 0;
		info1.end = 9;
		info1.line = 1;
		info1.loop = true;
		info1.size = Vector2(200, 200);
		info1.texture = Resource->GetTexture(L"T_Character_Right");
		Resource->CreateFlipbook(L"FB_PlayerRight", info1);
	}

	SetFlipbook(Resource->GetFlipbook(L"FB_Player"));
	SetBody(Shape::MakeCenterRect(WIN_SIZE_X / 2, WIN_SIZE_Y / 2, 200, 200));
}
void CreatureActor:: Render(HDC hdc)
{
	Super::Render(hdc);
}
void CreatureActor::Update()
{
	Super::Update();

	if (Input->GetKeyDown(KeyCode::Up))
	{
		SetFlipbook(Resource->GetFlipbook(L"FB_PlayerUp"));
		Vector2 newpos = this->_body.pos;
		newpos.y -= 10;
		SetPos(newpos);
	}

	if (Input->GetKey(KeyCode::Up))
	{
		Vector2 newpos = this->_body.pos;
		// 1ÃÊ : 100px : Time->GetDeltaTime()ÃÊ : ??px
		newpos.y -= 100 * Time->GetDeltaTime();
		SetPos(newpos);
	}

	if (Input->GetKeyDown(KeyCode::Down))
	{
		SetFlipbook(Resource->GetFlipbook(L"FB_PlayerDown"));
		Vector2 newpos = this->_body.pos;
		newpos.y += 10;
		SetPos(newpos);
	}

	if (Input->GetKey(KeyCode::Down))
	{
		Vector2 newpos = this->_body.pos;
		newpos.y += 100 * Time->GetDeltaTime();
		SetPos(newpos);
	}

	if (Input->GetKeyDown(KeyCode::Left))
	{
		SetFlipbook(Resource->GetFlipbook(L"FB_PlayerLeft"));
		Vector2 newpos = this->_body.pos;
		newpos.x -= 10;
		SetPos(newpos);
	}

	if (Input->GetKey(KeyCode::Left))
	{
		Vector2 newpos = this->_body.pos;
		newpos.x -= 100 * Time->GetDeltaTime();
		SetPos(newpos);
	}

	if (Input->GetKeyDown(KeyCode::Right))
	{
		SetFlipbook(Resource->GetFlipbook(L"FB_PlayerRight"));
		Vector2 newpos = this->_body.pos;
		newpos.x += 10;
		SetPos(newpos);
	}

	if (Input->GetKey(KeyCode::Right))
	{
		Vector2 newpos = this->_body.pos;
		newpos.x += 100 * Time->GetDeltaTime();
		SetPos(newpos);
	}
}
void CreatureActor::Release()
{
	Super::Release();
}

void CreatureActor::ChangeState(CreatureActorState state)
{
	if (_state == state) return;

	_state = state;

	switch (_state)
	{
	case CreatureActorState::Attack:
		this->Attack();
		break;
	case CreatureActorState::Move:
		//this->Move(this->dir);
		break;
	case CreatureActorState::Idle:
		this->Idle();
		break;
	case CreatureActorState::None:
		break;
	default:
		break;
	}
}

void CreatureActor::Attack()
{

}

void CreatureActor::Move(Direction dir)
{

}

void CreatureActor::Idle()
{

}
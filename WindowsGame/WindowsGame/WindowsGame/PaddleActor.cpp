#include "pch.h"
#include "PaddleActor.h"

#include "BoxCollider.h"

void PaddleActor::Init()
{
	Super::Init();

	this->SetName("Paddle");

	BoxCollider* collider = new BoxCollider();
	collider->SetCollision(Shape::MakeCenterRect(0, 0, 170, 26)); // ��� �����̱� ������ 
	this->AddComponent(collider);
	this->SetBody(Shape::MakeCenterRect(WIN_SIZE_X / 2, WIN_SIZE_Y - 70, 170, 26));

	_speed = 500;
}

void PaddleActor::Render(HDC hdc)
{
	Super::Render(hdc);

	_body.Draw(hdc);
}

void PaddleActor::Update()
{
	Super::Update();

	// ���� ���⿡ �е� �������� ������ �ʰ� PlayerController�� ���� ����
	
	// ���߿� ��Ʈ��ũ�� �߰��ϰ� �Ǹ�,
	// Paddle�� �������� ����� �ֽ��ϴ�.

	// �ƴϸ� ���߿� ��ȹ���� ��ҷ� ������ �־���ϴ� �е��� �߰��ϰ� �Ǹ�
	// Paddle�� �������� ����� �ֽ��ϴ�.

	// �� �е��� ��� ������� �Է����� �̵����� �ʾƿ�.
	// �׷��� �׷� ������ �е��� ���Ӱ� ����ų� IF�� �� ������ ������ ���ݾƿ�.

	// �׷��� ���� �ڵ尡 ����������.

	// �ű⿡�� ���� ������ ���� �ٷ� SRP

	// SRP (����å�ӿ�Ģ)
	// �ϳ���Ŭ�������� �ϳ��� ��ɸ��ϰ��ϴ°��� ����.
}

void PaddleActor::Release()
{
	Super::Release();
}

void PaddleActor::Move(Vector2 moveDir)
{
	if (moveDir.Length() == 0.0f)
	{
		return;
	}

	if (moveDir.y != 0)
	{
		moveDir.y = 0;
		moveDir = moveDir.Normalize();
	}


	_body.pos += moveDir * Time->GetDeltaTime() * _speed;
}
#include "pch.h"
#include "BallActor.h"

#include "BoxCollider.h"
#include "InGameScene.h"
#include "BrickActor.h"

void BallActor::Init()
{
	Super::Init();

	this->SetName("Ball");

	BoxCollider* collider = new BoxCollider();
	collider->SetCollision(Shape::MakeCenterRect(0, 0, 20, 20));
	this->AddComponent(collider);
	this->SetBody(Shape::MakeCenterRect(WIN_SIZE_X / 2, WIN_SIZE_Y - 70 - 26, 26, 26));

	_speed = 500;
}

void BallActor::Render(HDC hdc)
{
	Super::Render(hdc);

	_body.Draw(hdc);
}

void BallActor::Update()
{
	Super::Update();


	Vector2 prevPos = _body.pos; // �������� ������ ���� ������ �����µ� prevPos�� ���� �װ� �����Ѵ�.
	this->Move();

	//Collision Check (�浹 üũ)
	if (this->_body.pos.x <= 10)
	{
		this->_moveDir.x = -this->_moveDir.x;
		_body.pos = prevPos;
	}
	if (this->_body.pos.x >= WIN_SIZE_X - 10)
	{
		this->_moveDir.x = -this->_moveDir.x;
		_body.pos = prevPos;
	}
	if (this->_body.pos.y <= 10)
	{
		this->_moveDir.y = -this->_moveDir.y;
		_body.pos = prevPos;
	}
	if (this->_body.pos.y >= WIN_SIZE_Y - 10)
	{
		//���ӿ���
		InGameScene* currentScene = dynamic_cast<InGameScene*>(GET_SINGLE(SceneManager)->GetCurrentScene());
		if (currentScene != nullptr)
		{
			currentScene->ChangeGameState(GameState::Wait);
		}
	}
}

void BallActor::Release()
{
	Super::Release();
}

void BallActor::Move()
{
	_body.pos += _moveDir * Time->GetDeltaTime() * _speed;
}

void BallActor::SetPos(Vector2 position)
{
	this->_body.pos = position;
}

void BallActor::OnTriggerEnter(Collider* collider, Collider* other)
{
	Super::OnTriggerEnter(collider, other);


	// �̰� �̷��� or�� �ص��� ���� paddle���� ��ȣ�ۿ�� brick���� ��ȣ�ۿ��� �ٸ� if������ �س��°� ����.
	// ������ ����ϴϱ� �Լ�ȭ ��Ű�°� ����.
	if (other->GetOwner()->GetName() == "Paddle")
	{
		this->bounceBall(collider, other);
	}

	if (other->GetOwner()->GetName() == "Brick")
	{
		this->bounceBall(collider, other);
	}

	if (other->GetOwner()->GetName() == "Brick")
	{
		// dynamic_cast<>�� c++�� �� ��ȯ ��Ÿ���̴�.
		BrickActor* brickActor = dynamic_cast<BrickActor*>(other->GetOwner());

		if (brickActor == nullptr)
		{
			printf("[warning] is not BrickActor !\n");
			return;
		}

		// ������ ��츦 ���� retrurn ���ְ� �Ϲ����ΰ� �Ʒ��ʿ� ���ִ°� ���⿡ �ξ� ����.
		// �̰� �����̴�. 

		//// ������ �������.
		////  -> ������ Despawn ��Ų��.
		////  (Spawn ���Ѽ� ����������, Despawn ���Ѽ� ���ָ� �ȴ�.)

		//// �� ���� InGameScene�� �������� �ִ�.
		///*InGameScene* ingameScene = dynamic_cast<InGameScene*>(scene);
		//if (ingameScene == nullptr)
		//{
		//	return;
		//}*/
		//currentScene->DespawnActor(brickActor);

		brickActor->SetEnable(false);

		// 1. ���� �ε����� �� Ƣ���
		// 2. ���� ���� 1���ۿ� �ȳ����µ�
		//		-4�� ������ �������� ����


		// �Լ��� ����ϴ� ����
		//  - 1. ������
		//  - 2. ��Ȱ�뼺 (��������)
		

		// �����ϴٺ���
		// �Լ��� �ȵǾ��ִ� ������ �������ϵ� �����
		// �ƴϸ� if������ �ǰԲ� ����� ��쵵 �ִ�.

		// �����ϼ��� �ִ�
		// �⺻������ ���α׷����� ���������� ���ư��⸸�ϸ� �� �����Դϴ�.
		// �� ���ķ� ��� ���������� �� ���� �� �ֳ� << �̰� ���� �ܰ迡�� ����ϴ°ſ���
		// �ٵ� ���� �ñ�� ��� ���α׷��� ���ư� �� �ְԲ��� ������
		// ����� �ð��� �ΰ� ����ض� 
		// �׷� ����� �Ի� ���Ŀ� �ص� ���� �ʴ�

		// ��� �����ϸ鼭 �ڵ�¥�ٺ��� ������ ������ �� �� �ְԵȴ�.
		// �Լ����Ұ���, if������ �Ұ���, �ƴϸ� �ٸ�������� �Ұ����� ���ؼ��� 
		
		// �츮�� �Լ��� �� �������, if�� �� �������, �������� ����� �� ��������� �����غ���

		// �׸��� ��ȹ�� ���̳����ϰ� �ٲ�������� ����ϸ� �� ������ ���´�.
		// ��� ¥�� �ڵ尡 �� ���� ����� �� ����� ����ض�

		// �� �ڵ�� ȥ�� ¥�°� �ƴ��� ����ض�
		// ������ ȥ���ϴ°� �ƴϴ�.
		// ���� ���� �� ��ó�� 
		// ƨ��� if���� ||���� ������ �߰��ϸ�
		// ���Ŀ� ���� || ������ �߰��Ǿ� �Ⱬ������.
		// �׸��� �� ���Ŀ� if�� �ȿ��� �� �Ⱬ������ �Ͼ��.

		// �ִ��� if���� �ѱ۷� ���� �� �ְ� ������ִ°� ����.


		// ���α׷��� ���� �а� ���� ������� ���� ª���Ϳ� �����ϴ� ����� ������

		// ������ �������� �ڵ��
		// �ټ��� �������� ���������� ���ﶧ�� ����.
		// �׸��� �ټ��� ���ٰ� ���������� �ʴ´�. (����������)

		// ���������� ��κ��� ���ϴ�
		// ���������� �ɸ���.
		// �ٵ� �� ������ ������ ������ ���ƶ� 
		
	}
}

void BallActor::bounceBall(Collider* collider, Collider* other)
{
	//�浹����üũ
	RECT myRect = static_cast<BoxCollider*>(collider)->GetCollision().ToRect();

	myRect.left -= 1;
	myRect.top -= 1;
	myRect.right += 1;
	myRect.bottom += 1;
	RECT otherRect = static_cast<BoxCollider*>(other)->GetCollision().ToRect();
	RECT temp = {};

	if (IntersectRect(&temp, &myRect, &otherRect))
	{

		int width = temp.right - temp.left;
		int height = temp.bottom - temp.top;
		if (width < height)
		{
			//�����ʿ��� �������� �浹�Ǿ���.
			if (temp.left == myRect.left)
			{
				_moveDir.x = -_moveDir.x;
				_body.pos.x += temp.right - temp.left;
			}

			//���ʿ��� ���������� �浹�Ǿ���.
			if (temp.right == myRect.right)
			{
				_moveDir.x = -_moveDir.x;
				_body.pos.x -= temp.right - temp.left;
			}
		}
		else
		{
			//�Ʒ����� ���� �浹�Ǿ���.
			if (temp.top == myRect.top)
			{
				_moveDir.y = -_moveDir.y;
				_body.pos.y += temp.bottom - temp.top;
			}


			//������ �Ʒ��� �浹�Ǿ���.
			if (temp.bottom == myRect.bottom)
			{
				_moveDir.y = -_moveDir.y;
				_body.pos.y -= temp.bottom - temp.top;
			}
		}

	}
}


void BallActor::Bounce(RECT myRect, RECT otherRect)
{
	RECT temp = {};

	if (IntersectRect(&temp, &myRect, &otherRect))
	{

		int width = temp.right - temp.left;
		int height = temp.bottom - temp.top;
		if (width < height)
		{
			//�����ʿ��� �������� �浹�Ǿ���.
			if (temp.left == myRect.left)
			{
				_moveDir.x = -_moveDir.x;
				_body.pos.x += temp.right - temp.left;
			}

			//���ʿ��� ���������� �浹�Ǿ���.
			if (temp.right == myRect.right)
			{
				_moveDir.x = -_moveDir.x;
				_body.pos.x -= temp.right - temp.left;
			}
		}
		else
		{
			//�Ʒ����� ���� �浹�Ǿ���.
			if (temp.top == myRect.top)
			{
				_moveDir.y = -_moveDir.y;
				_body.pos.y += temp.bottom - temp.top;
			}


			//������ �Ʒ��� �浹�Ǿ���.
			if (temp.bottom == myRect.bottom)
			{
				_moveDir.y = -_moveDir.y;
				_body.pos.y -= temp.bottom - temp.top;
			}
		}

	}
}
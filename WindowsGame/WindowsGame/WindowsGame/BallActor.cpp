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


	Vector2 prevPos = _body.pos; // 프레임이 낮으면 비비는 현상이 나오는데 prevPos를 통해 그걸 방지한다.
	this->Move();

	//Collision Check (충돌 체크)
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
		//게임오버
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


	// 공이 튕기는건 여러번 써야하니까 함수화 시키는게 좋다.
	if (other->GetOwner()->GetName() == "Paddle")
	{
		bounceBall(collider, other);
	}

	// 선생님이 벽돌이 부숴지도록 만든 부분
	if (other->GetOwner()->GetName() == "Brick")
	{
		// dynamic_cast<>가 c++의 형 변환 스타일이다.
		BrickActor* brickActor = dynamic_cast<BrickActor*>(other->GetOwner());

		if (brickActor == nullptr)
		{
			printf("[warning] is not BrickActor !\n");
			return;
		}

		// 예외의 경우를 빨리 retrurn 해주고 일반적인걸 아래쪽에 써주는게 보기에 훨씬 좋다.
		// 이게 패턴이다. 

		// 벽돌이 사라진다.
		//  -> 씬에서 Despawn 시킨다.
		//  (Spawn 시켜서 생성했으니, Despawn 시켜서 없애면 된다.)

		// Scene* currentScene = GET_SINGLE(SceneManager)->GetCurrentScene();
		// 이 씬을 InGameScene로 받을수도 있다.
		/*InGameScene* ingameScene = dynamic_cast<InGameScene*>(scene);
		if (ingameScene == nullptr)
		{
			return;
		}*/
		//currentScene->DespawnActor(brickActor);
		// 근데 이 위에처럼 하니까 게임이 꺼진다. FrameWork가 불안정하니 OnTriggerEnter에서 DespawnActor 시켜주려하면 문제가 발생하는 것 같다.

		brickActor->SetEnable(false);

		bounceBall(collider, other);

	}
}

void BallActor::bounceBall(Collider* collider, Collider* other)
{
	//충돌로직체크
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
			//오른쪽에서 왼쪽으로 충돌되었다.
			if (temp.left == myRect.left)
			{
				_moveDir.x = -_moveDir.x;
				_body.pos.x += temp.right - temp.left;
			}

			//왼쪽에서 오른쪽으로 충돌되었다.
			if (temp.right == myRect.right)
			{
				_moveDir.x = -_moveDir.x;
				_body.pos.x -= temp.right - temp.left;
			}
		}
		else
		{
			//아래에서 위로 충돌되었다.
			if (temp.top == myRect.top)
			{
				_moveDir.y = -_moveDir.y;
				_body.pos.y += temp.bottom - temp.top;
			}


			//위에서 아래로 충돌되었다.
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
			//오른쪽에서 왼쪽으로 충돌되었다.
			if (temp.left == myRect.left)
			{
				_moveDir.x = -_moveDir.x;
				_body.pos.x += temp.right - temp.left;
			}

			//왼쪽에서 오른쪽으로 충돌되었다.
			if (temp.right == myRect.right)
			{
				_moveDir.x = -_moveDir.x;
				_body.pos.x -= temp.right - temp.left;
			}
		}
		else
		{
			//아래에서 위로 충돌되었다.
			if (temp.top == myRect.top)
			{
				_moveDir.y = -_moveDir.y;
				_body.pos.y += temp.bottom - temp.top;
			}


			//위에서 아래로 충돌되었다.
			if (temp.bottom == myRect.bottom)
			{
				_moveDir.y = -_moveDir.y;
				_body.pos.y -= temp.bottom - temp.top;
			}
		}

	}
}
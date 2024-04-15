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


	// 이거 이렇게 or로 해두지 말고 paddle과의 상호작용과 brick과의 상호작용은 다른 if문으로 해놓는게 좋다.
	// 여러번 써야하니까 함수화 시키는게 좋다.
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
		// dynamic_cast<>가 c++의 형 변환 스타일이다.
		BrickActor* brickActor = dynamic_cast<BrickActor*>(other->GetOwner());

		if (brickActor == nullptr)
		{
			printf("[warning] is not BrickActor !\n");
			return;
		}

		// 예외의 경우를 빨리 retrurn 해주고 일반적인걸 아래쪽에 써주는게 보기에 훨씬 좋다.
		// 이게 패턴이다. 

		//// 벽돌이 사라진다.
		////  -> 씬에서 Despawn 시킨다.
		////  (Spawn 시켜서 생성했으니, Despawn 시켜서 없애면 된다.)

		//// 이 씬을 InGameScene로 받을수도 있다.
		///*InGameScene* ingameScene = dynamic_cast<InGameScene*>(scene);
		//if (ingameScene == nullptr)
		//{
		//	return;
		//}*/
		//currentScene->DespawnActor(brickActor);

		brickActor->SetEnable(false);

		// 1. 벽돌 부딪히면 볼 튀기기
		// 2. 벽돌 지금 1개밖에 안나오는데
		//		-4줄 정도로 나오도록 수정


		// 함수를 사용하는 이유
		//  - 1. 가독성
		//  - 2. 재활용성 (유지보수)
		

		// 개발하다보면
		// 함수로 안되어있는 내용을 복사할일도 생기고
		// 아니면 if땜질로 되게끔 만드는 경우도 있다.

		// 정답일수도 있다
		// 기본적으로 프로그래밍은 정상적으로 돌아가기만하면 다 정답입니다.
		// 그 이후로 어떻게 유지보수할 떄 잘할 수 있냐 << 이걸 다음 단계에서 고민하는거에요
		// 근데 지금 시기는 사실 프로그램이 돌아갈 수 있게끔만 만들어라
		// 충분한 시간을 두고 고민해라 
		// 그런 고민은 입사 이후에 해도 늦지 않다

		// 계속 생각하면서 코드짜다보면 누구나 언젠간 할 수 있게된다.
		// 함수로할건지, if땜질로 할건지, 아니면 다른방법으로 할건지에 대해서는 
		
		// 우리가 함수를 왜 배웠는지, if를 왜 배웠는지, 여러가지 방법을 왜 배웠는지를 생각해보자

		// 그리고 기획이 다이나믹하게 바뀌었을때를 상상하면 또 정답이 나온다.
		// 어떻게 짜둔 코드가 더 쉽게 변경될 수 있을까를 고민해라

		// 또 코드는 혼자 짜는게 아님을 고려해라
		// 수정은 혼자하는게 아니다.
		// 만약 내가 한 것처럼 
		// 튕기는 if문에 ||으로 조건을 추가하면
		// 이후에 점점 || 조건이 추가되어 기괴해진다.
		// 그리고 그 이후에 if문 안에서 더 기괴한짓이 일어난다.

		// 최대한 if문은 한글로 읽을 수 있게 만들어주는게 좋다.


		// 프로그래밍 관련 학과 나온 사람들은 줄이 짧은것에 집착하는 사람이 많은데

		// 오히려 컨텐츠쪽 코드는
		// 줄수가 많을수록 유지보수가 쉬울때가 많다.
		// 그리고 줄수가 많다고 느려지지도 않는다. (컨텐츠쪽은)

		// 컨텐츠쪽의 대부분의 부하는
		// 렌더링에서 걸린다.
		// 근데 이 내용은 면접땐 말하지 말아라 
		
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
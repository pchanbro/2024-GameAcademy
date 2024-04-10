#include "pch.h"
#include "Dev1Scene.h"

void Dev1Scene::Init()
{
	// 부모 함수 호출하려면
	// super.Init(); 혹은
	// base.Init();
	// 지금은 헤더파일에 Super 변수 만들어줬으니 이렇게 쓴다.
	Super::Init();

	_player = { Vector2(250, 250), 100, 100 };
	_wall = Shape::MakeCenterRectLTRB(700, 200, 800, 300);
}

void Dev1Scene::Render(HDC hdc)
{
	// 부모함수 먼저 실행하고 자신의 함수를 실행하는것이 일반적이다.
	Super::Render(hdc);

	wstring str = L"Dev1Scene";
	::TextOut(hdc, 0, 45, str.c_str(), str.length());

	_wall.Draw(hdc);
	_player.Draw(hdc);
}

void Dev1Scene::Update()
{
	Super::Update();

	if (Input->GetKey(KeyCode::Control) && Input->GetKeyDown(KeyCode::RightMouse))
	{
		GET_SINGLE(SceneManager)->ChangeScene(SceneType::Dev2Scene);
	}


	RECT collision = {};
	//첫번째에는 충돌영역을 구해주는 변수
	RECT playerCollision = _player.ToRect();
	RECT wallCollision = _wall.ToRect();
	if (::IntersectRect(&collision, &playerCollision, &wallCollision))
	{
		int collisionWidth = collision.right - collision.left;
		int collisionHeight = collision.bottom - collision.top;

		//더 짧은쪽이 부딪힌 쪽 (세로가 짧으면 세로로 부딪힌거다.)
		if (collisionHeight < collisionWidth)
		{
			if (collision.top == playerCollision.top)
			{
				cout << "아래에서 위로 충돌되었다." << endl;
				//_player.pos.y += collisionHeight;
				_wall.pos.y -= collisionHeight;
			}

			if (collision.bottom == playerCollision.bottom)
			{
				cout << "위에서 아래로 충돌되었다." << endl;
				//_player.pos.y -= collisionHeight;
				_wall.pos.y += collisionHeight;
			}
		}
		else
		{
			if (collision.left == playerCollision.left)
			{
				cout << "오른쪽에서 왼쪽으로 충돌되었다." << endl;
				//_player.pos.x += collisionWidth;
				_wall.pos.x -= collisionWidth;
			}

			if (collision.right == playerCollision.right)
			{
				cout << "왼쪽에서 오른쪽으로 충돌되었다." << endl;
				//_player.pos.x -= collisionWidth;
				_wall.pos.x += collisionWidth;
			}
		}
	}

	//if (Input->GetKey(KeyCode::Left))
	//{
	//	_playerDir = Vector2(-1, 0);
	//	_player.pos += _playerDir * Time->GetDeltaTime() * 100; // 이거 앞으로 많이씀 이해 안되면 외우기
	//}

	//if (Input->GetKey(KeyCode::Up))
	//{
	//	_playerDir = Vector2(0, -1);
	//	_player.pos += _playerDir * Time->GetDeltaTime() * 100;
	//}

	//if (Input->GetKey(KeyCode::Right))
	//{
	//	_playerDir = Vector2(1, 0);
	//	_player.pos += _playerDir * Time->GetDeltaTime() * 100;
	//}

	//if (Input->GetKey(KeyCode::Down))
	//{
	//	_playerDir = Vector2(0, 1);
	//	_player.pos += _playerDir * Time->GetDeltaTime() * 100;
	//}

	if (Input->GetKeyDown(KeyCode::RightMouse))
	{
		// 마우스 클릭했을 때 플레이어가 움직여줄 방향을 정해준다.
		POINT pt = Input->GetMousePos();
		_targetPos = Vector2(pt.x, pt.y);
		_playerDir = (_targetPos - _player.pos).Normalize(); // 방향벡터는 항상 길이가 1이어야 한다.
	}

	if (2 < (_targetPos - _player.pos).Length())
	{
		_player.pos += _playerDir * (Time->GetDeltaTime() * 100);
	}
}
void Dev1Scene::Release()
{
	Super::Release();
}
#include "pch.h"
#include "Homework1Scene.h"

enum wall
{
	LeftWall,
	RightWall,
	BottomWall,
	TopWall,

	WallEnd,
};

void Homework1Scene::Init()
{
	Super::Init();

	_wall[LeftWall] = Shape::MakeCenterRectLTRB(380, 50, 400, 670);
	_wall[RightWall] = Shape::MakeCenterRectLTRB(1620, 50, 1640, 670); 
	_wall[BottomWall] = Shape::MakeCenterRectLTRB(400, 650, 1000, 670);
	_wall[TopWall] = Shape::MakeCenterRectLTRB(1000, 50, 1600, 70);

	_ball = { Vector2(550, 500), 20, 20 };
	
}

void Homework1Scene::Render(HDC hdc)
{
	Super::Render(hdc);

	wstring str = L"Homework1Scene";
	::TextOut(hdc, 0, 45, str.c_str(), str.length());

	for (int i = LeftWall; i < WallEnd; i++)
	{
		_wall[i].Draw(hdc);
	}
	_ball.Draw(hdc);
}

void Homework1Scene::Update()
{
	Super::Update();

	if (Input->GetKey(KeyCode::Control) && Input->GetKeyDown(KeyCode::RightMouse))
	{
		GET_SINGLE(SceneManager)->ChangeScene(SceneType::Dev1Scene);
	}


	RECT collision = {};
	//ù��°���� �浹������ �����ִ� ����
	RECT playerCollision = _ball.ToRect();
	RECT wallCollision = _wall[0].ToRect();
	if (::IntersectRect(&collision, &playerCollision, &wallCollision))
	{
		int collisionWidth = collision.right - collision.left;
		int collisionHeight = collision.bottom - collision.top;

		//�� ª������ �ε��� �� (���ΰ� ª���� ���η� �ε����Ŵ�.)
		if (collisionHeight < collisionWidth)
		{
			if (collision.top == playerCollision.top)
			{
				cout << "�Ʒ����� ���� �浹�Ǿ���." << endl;
				//_player.pos.y += collisionHeight;
				_wall[0].pos.y -= collisionHeight;
			}

			if (collision.bottom == playerCollision.bottom)
			{
				cout << "������ �Ʒ��� �浹�Ǿ���." << endl;
				//_player.pos.y -= collisionHeight;
				_wall[0].pos.y += collisionHeight;
			}
		}
		else
		{
			if (collision.left == playerCollision.left)
			{
				cout << "�����ʿ��� �������� �浹�Ǿ���." << endl;
				//_player.pos.x += collisionWidth;
				_wall[0].pos.x -= collisionWidth;
			}

			if (collision.right == playerCollision.right)
			{
				cout << "���ʿ��� ���������� �浹�Ǿ���." << endl;
				//_player.pos.x -= collisionWidth;
				_wall[0].pos.x += collisionWidth;
			}
		}
	}

	//if (Input->GetKey(KeyCode::Left))
	//{
	//	_playerDir = Vector2(-1, 0);
	//	_player.pos += _playerDir * Time->GetDeltaTime() * 100; // �̰� ������ ���̾� ���� �ȵǸ� �ܿ��
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
		// ���콺 Ŭ������ �� �÷��̾ �������� ������ �����ش�.
		POINT pt = Input->GetMousePos();
		_targetPos = Vector2(pt.x, pt.y);
		_playerDir = (_targetPos - _ball.pos).Normalize(); // ���⺤�ʹ� �׻� ���̰� 1�̾�� �Ѵ�.
	}

	if (2 < (_targetPos - _ball.pos).Length())
	{
		_ball.pos += _playerDir * (Time->GetDeltaTime() * 100);
	}
}
void Homework1Scene::Release()
{
	Super::Release();
}
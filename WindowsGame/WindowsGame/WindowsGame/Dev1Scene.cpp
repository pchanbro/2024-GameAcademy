#include "pch.h"
#include "Dev1Scene.h"

void Dev1Scene::Init()
{
	// �θ� �Լ� ȣ���Ϸ���
	// super.Init(); Ȥ��
	// base.Init();
	// ������ ������Ͽ� Super ���� ����������� �̷��� ����.
	Super::Init();

	_player = { Vector2(250, 250), 100, 100 };
	_wall = Shape::MakeCenterRectLTRB(700, 200, 800, 300);
}

void Dev1Scene::Render(HDC hdc)
{
	// �θ��Լ� ���� �����ϰ� �ڽ��� �Լ��� �����ϴ°��� �Ϲ����̴�.
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
	//ù��°���� �浹������ �����ִ� ����
	RECT playerCollision = _player.ToRect();
	RECT wallCollision = _wall.ToRect();
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
				_wall.pos.y -= collisionHeight;
			}

			if (collision.bottom == playerCollision.bottom)
			{
				cout << "������ �Ʒ��� �浹�Ǿ���." << endl;
				//_player.pos.y -= collisionHeight;
				_wall.pos.y += collisionHeight;
			}
		}
		else
		{
			if (collision.left == playerCollision.left)
			{
				cout << "�����ʿ��� �������� �浹�Ǿ���." << endl;
				//_player.pos.x += collisionWidth;
				_wall.pos.x -= collisionWidth;
			}

			if (collision.right == playerCollision.right)
			{
				cout << "���ʿ��� ���������� �浹�Ǿ���." << endl;
				//_player.pos.x -= collisionWidth;
				_wall.pos.x += collisionWidth;
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
		_playerDir = (_targetPos - _player.pos).Normalize(); // ���⺤�ʹ� �׻� ���̰� 1�̾�� �Ѵ�.
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
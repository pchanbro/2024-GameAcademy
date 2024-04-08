#include "pch.h"
#include "Dev1Scene.h"

void Dev1Scene::Init()
{
	// �θ� �Լ� ȣ���Ϸ���
	// super.Init(); Ȥ��
	// base.Init();
	// ������ ������Ͽ� Super ���� ����������� �̷��� ����.
	Super::Init();

	_rect.left = 100;
	_rect.right = 150;
	_rect.top = 100;
	_rect.bottom = 150;
}
void Dev1Scene::Render(HDC hdc)
{
	// �θ��Լ� ���� �����ϰ� �ڽ��� �Լ��� �����ϴ°��� �Ϲ����̴�.
	Super::Render(hdc);

	wstring str = L"Dev1Scene";
	::TextOut(hdc, 0, 45, str.c_str(), str.length());


	::Rectangle(hdc, _rect.left, _rect.top, _rect.right, _rect.bottom);
}
void Dev1Scene::Update()
{
	Super::Update();

	if (Input->GetKey(KeyCode::Control) && Input->GetKeyDown(KeyCode::RightMouse))
	{
		GET_SINGLE(SceneManager)->ChangeScene(SceneType::Dev2Scene);
	}

	if (Input->GetKey(KeyCode::Left))
	{
		_rect.left -= 1;
		_rect.right -= 1;
	}
	if (Input->GetKey(KeyCode::Right))
	{
		_rect.left += 1;
		_rect.right += 1;
	}
}
void Dev1Scene::Release()
{

}
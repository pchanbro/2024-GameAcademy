#include "pch.h"
#include "Dev1Scene.h"

void Dev1Scene::Init()
{
	// 부모 함수 호출하려면
	// super.Init(); 혹은
	// base.Init();
	// 지금은 헤더파일에 Super 변수 만들어줬으니 이렇게 쓴다.
	Super::Init();

	_rect.left = 100;
	_rect.right = 150;
	_rect.top = 100;
	_rect.bottom = 150;
}
void Dev1Scene::Render(HDC hdc)
{
	// 부모함수 먼저 실행하고 자신의 함수를 실행하는것이 일반적이다.
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
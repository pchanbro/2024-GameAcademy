#include "pch.h"
#include "CameraComponent.h"
#include "Actor.h"
#include "Scene.h"
#include "Sprite.h"
#include "CenterRect.h"

void CameraComponent::Init()
{
	Super::Init();
	_sumTime = 0.0f; 
	_duration = 0.3f;
	Vector2 _endPos = Vector2::Zero();
}
void CameraComponent::Render(HDC hdc)
{
	Super::Render(hdc);
}
void CameraComponent::Update()
{
	Super::Update();

	// 수도코드
	// 1. 나의 액터를 가져온다.
	//  if ( 0 < 액터 포지션.x ) (일단 x만 가지고 해보자)
	// 2. 카메라 좌표를 구성해준다.
	//  - newCameraPos = clamp(WIN_SIZE_X / 2 ~ 배경 width - WIN_SIZE_X /2 )
	// 3. [씬의 카메라 위치를] 내 액터위치로 바꾼다. (카메라는 씬에 존재)
	// 
	

	Actor* owner = this->GetOwner(); // 컴포넌트가 붙여져있는 액터를 가져옴

	if (owner)
	{
		// 현재 씬의 위치를 가져온다.
		Vector2 startPos = Vector2(CurrentScene->GetCameraPos().x, CurrentScene->GetCameraPos().y);
		// 플레이어의 위치를 가져온다
		Vector2 endPos = owner->GetPos(); 

		// 캐릭터가 움직였다면 연출 다시시작
		if (false == ((_endPos - endPos).Length() <= EPSILON))// 차이가 EPSILON보다 작으면 둘의 위치가 같다, _endPos가 바뀌었는지 확인
		{
			_sumTime = 0.01f;
			_startPos = startPos;
			_endPos = endPos;
		}

		_sumTime += Time->GetDeltaTime();

		float clampSumTime = clamp<float>(_sumTime / _duration, 0.0f, 1.0f);
		
		// _sumTime :: ?? = _duration : 1
		Vector2 newCameraPos = Vector2::Lerp(_startPos, _endPos, clampSumTime);

		int realMinX = min(_minX + WIN_SIZE_X / 2, _maxX - WIN_SIZE_X / 2);
		int realMaxX = max(_minX + WIN_SIZE_X / 2, _maxX - WIN_SIZE_X / 2);
		int realMinY = min(_minY + WIN_SIZE_Y / 2, _maxY - WIN_SIZE_Y / 2);
		int realMaxY = max(_minY + WIN_SIZE_Y / 2, _maxY - WIN_SIZE_Y / 2);

		newCameraPos.x = clamp<float>(newCameraPos.x, realMinX, realMaxX);
		newCameraPos.y = clamp<float>(newCameraPos.y, realMinY, realMaxY);

		// 현재 씬을 가져오는 방법
		
		// Actor* owner = this->GetOwner();
		// Vector2 newCameraPos = owner->GetPos();
		CurrentScene->SetCameraPos(newCameraPos); // #define CurrentScene (GET_SINGLE(SceneManager)->GetCurrentScene());
		// 했으면 newCameraPos 기준으로 카메라가 변경

		// 이거로 실행중 여기 코드 위치에 마우스를 갖다댐으로 값의 변화 확인 가능
		//Vector2Int currentScenePos = CurrentScene->GetCameraPos(); 	
	}

}
void CameraComponent::Release()
{
	Super::Release();
}

void CameraComponent::SetLTWH(int left, int top, int width, int height)
{
	_minX = left;
	_minY = top;
	_maxX = width;
	_maxY = height;
}
void CameraComponent::SetLTWH(Sprite* backgroundSprite)
{
	_minX = 0;
	_minY = 0;
	_maxX = backgroundSprite->GetSize().x;
	_maxY = backgroundSprite->GetSize().y;
}
void CameraComponent::SetLTWH(CenterRect backgroundBody)
{
	RECT rc = backgroundBody.ToRect();
	_minX = rc.left;
	_minY = rc.top;
	_maxX = rc.right;
	_maxY = rc.bottom;
}
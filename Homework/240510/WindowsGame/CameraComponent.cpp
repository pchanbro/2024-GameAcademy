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

	// �����ڵ�
	// 1. ���� ���͸� �����´�.
	//  if ( 0 < ���� ������.x ) (�ϴ� x�� ������ �غ���)
	// 2. ī�޶� ��ǥ�� �������ش�.
	//  - newCameraPos = clamp(WIN_SIZE_X / 2 ~ ��� width - WIN_SIZE_X /2 )
	// 3. [���� ī�޶� ��ġ��] �� ������ġ�� �ٲ۴�. (ī�޶�� ���� ����)
	// 
	

	Actor* owner = this->GetOwner(); // ������Ʈ�� �ٿ����ִ� ���͸� ������

	if (owner)
	{
		// ���� ���� ��ġ�� �����´�.
		Vector2 startPos = Vector2(CurrentScene->GetCameraPos().x, CurrentScene->GetCameraPos().y);
		// �÷��̾��� ��ġ�� �����´�
		Vector2 endPos = owner->GetPos(); 

		// ĳ���Ͱ� �������ٸ� ���� �ٽý���
		if (false == ((_endPos - endPos).Length() <= EPSILON))// ���̰� EPSILON���� ������ ���� ��ġ�� ����, _endPos�� �ٲ������ Ȯ��
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

		// ���� ���� �������� ���
		
		// Actor* owner = this->GetOwner();
		// Vector2 newCameraPos = owner->GetPos();
		CurrentScene->SetCameraPos(newCameraPos); // #define CurrentScene (GET_SINGLE(SceneManager)->GetCurrentScene());
		// ������ newCameraPos �������� ī�޶� ����

		// �̰ŷ� ������ ���� �ڵ� ��ġ�� ���콺�� ���ٴ����� ���� ��ȭ Ȯ�� ����
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
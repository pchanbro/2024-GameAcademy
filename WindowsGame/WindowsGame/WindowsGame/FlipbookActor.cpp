#include "pch.h"
#include "FlipbookActor.h"
#include "Flipbook.h"
#include "Texture.h"
#include "Scene.h"

void FlipbookActor::Init()
{
	Super::Init();
}
void FlipbookActor::Render(HDC hdc)
{
	if (!_flipbook) return;

	const FlipbookInfo& info = _flipbook->GetInfo();

	// 지금 아래 코드에서 
	// static_cast<int>(_body.pos.x - info.size.x / 2)
	// static_cast<int>(_body.pos.y - info.size.y / 2
	// 요 위치에 그림을 그리겠습니다. 이 값을 고정시키면 캐릭터 안움직임

	// 카메라 = 눈속임
	// 카메라가 오른쪽으로 이동하면, 
	// 모든게 왼쪽으로 이동

	// 내가 그릴좌표 (캐릭터 좌표가 작아지면, 카메라도 같이 작아진다.)
	// pos - cameraPos >> 이게 현재 내 창에서 보일 창의 좌표

	Vector2Int cameraPos = CurrentScene->GetCameraPos();
	Vector2Int screenSizeHalf = Vector2Int(WIN_SIZE_X / 2, WIN_SIZE_Y / 2);
	Vector2Int renderPos = Vector2Int(
		static_cast<int>(_body.pos.x - info.size.x / 2 - cameraPos.x + screenSizeHalf.x),
		static_cast<int>(_body.pos.y - info.size.y / 2 - cameraPos.y + screenSizeHalf.y)
	);

	::TransparentBlt(hdc,
		renderPos.x,
		renderPos.y,
		info.size.x,
		info.size.y,
		info.texture->GetDC(),
		_index * info.size.x,
		info.line * info.size.y,
		info.size.x,
		info.size.y,
		info.texture->GetTransparent() // 투명색
	);

	Super::Render(hdc);
}
void FlipbookActor::Update()
{
	Super::Update();
	if (_flipbook == nullptr) return;


	const FlipbookInfo& info = _flipbook->GetInfo();
	int frameAmount = (info.end - info.start + 1);

	_sumTime += Time->GetDeltaTime();

	// 변경되는 원하는 시간
	// duration(총 걸린 시간) / frameAmount(장수)
	// 1장을 실행시킬때 몇초가 걸릴까?
	// frameAmount : duration = 1 : ??
	// ?? = duration / frameAmount

	// 한 주기에 몇 초로 할건지를 조정하는 코드 
	// 선생님꺼
	float delta = info.duration / frameAmount;

	if (delta <= _sumTime)
	{
		_sumTime -= delta;

		if (false == (info.loop == false && _index == info.end))
		{
			_index++;
			_index %= frameAmount + info.start;
		}
	}

	// 내가 한거
	/*if (this->_loop)
	{
		if (info.duration / static_cast<float>(info.end - info.start + 1) <= _sumTime)
		{
			_index++;

			if (info.end < _index)
			{
				_index = info.start;

				if (!info.loop)
				{
					this->_loop = false;
				}
			}
			_sumTime = 0;
		}
	}*/
	
}
void FlipbookActor::Release()
{
	Super::Release();
}

void FlipbookActor::SetFlipbook(Flipbook* flipbook)
{
	if (!flipbook) return; // 프레임 워크다 보니 필요한 안전장치, 없는거 들어오면 큰일남
	if (_flipbook == flipbook) return; // 안전장치!!

	_flipbook = flipbook;
	Reset();
}
void FlipbookActor::Reset()
{
	// Flipbook은 초기화 해주면 안됨
	_index = 0;
	_sumTime = 0;
}
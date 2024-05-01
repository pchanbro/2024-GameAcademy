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

	// ���� �Ʒ� �ڵ忡�� 
	// static_cast<int>(_body.pos.x - info.size.x / 2)
	// static_cast<int>(_body.pos.y - info.size.y / 2
	// �� ��ġ�� �׸��� �׸��ڽ��ϴ�. �� ���� ������Ű�� ĳ���� �ȿ�����

	// ī�޶� = ������
	// ī�޶� ���������� �̵��ϸ�, 
	// ���� �������� �̵�

	// ���� �׸���ǥ (ĳ���� ��ǥ�� �۾�����, ī�޶� ���� �۾�����.)
	// pos - cameraPos >> �̰� ���� �� â���� ���� â�� ��ǥ

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
		info.texture->GetTransparent() // �����
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

	// ����Ǵ� ���ϴ� �ð�
	// duration(�� �ɸ� �ð�) / frameAmount(���)
	// 1���� �����ų�� ���ʰ� �ɸ���?
	// frameAmount : duration = 1 : ??
	// ?? = duration / frameAmount

	// �� �ֱ⿡ �� �ʷ� �Ұ����� �����ϴ� �ڵ� 
	// �����Բ�
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

	// ���� �Ѱ�
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
	if (!flipbook) return; // ������ ��ũ�� ���� �ʿ��� ������ġ, ���°� ������ ū�ϳ�
	if (_flipbook == flipbook) return; // ������ġ!!

	_flipbook = flipbook;
	Reset();
}
void FlipbookActor::Reset()
{
	// Flipbook�� �ʱ�ȭ ���ָ� �ȵ�
	_index = 0;
	_sumTime = 0;
}
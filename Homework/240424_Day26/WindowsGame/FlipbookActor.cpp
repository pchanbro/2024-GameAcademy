#include "pch.h"
#include "FlipbookActor.h"
#include "Flipbook.h"
#include "Texture.h"

void FlipbookActor::Init()
{
	Super::Init();
}
void FlipbookActor::Render(HDC hdc)
{
	if (!_flipbook) return;

	const FlipbookInfo& info = _flipbook->GetInfo();

	::TransparentBlt(hdc,
		static_cast<int>(_body.pos.x - info.size.x / 2),
		static_cast<int>(_body.pos.y - info.size.y / 2),
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

	const FlipbookInfo& info = _flipbook->GetInfo();
	_sumTime += Time->GetDeltaTime();

	if (this->_loop)
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
	}

	if (Input->GetKeyDown(KeyCode::A))
	{
		cout << "����!" << endl;
		FlipbookInfo tmpInfo = info;
		tmpInfo.loop = !info.loop;
		_flipbook->SetInfo(tmpInfo);

		if (this->_loop == false)
		{
			this->_loop = true;
		}
	}
	
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
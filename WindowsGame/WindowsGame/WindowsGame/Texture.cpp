#include "pch.h"
#include "Texture.h"


Texture* Texture::LoadBmp(const wstring& path)
{
	// 외부의 Texture를 로딩하는 방법

	// 우리가 그동안 배운건
	// if랑 for문 이런거 뿐인데 외부 리소스에 관한건 배운게 없다.

	// 이거는 WindowsAPI에서 제공해주는걸 갖다 쓴거다.
	// 이게 없으면 누굴 데려다 놔도 못한다.

	// 즉 외부의 Texture를 로딩하는 방법은
	// Windows API에 있는 함수를 찾아서 쓰는것

	HDC hdc = ::GetDC(_hWnd); 
	// 우리만의 dc를 만든다면서 window handle의 dc를 가져온 이유
	// 이걸 쓸게 아니라 화면에 뿌리는 것과 호환되는 것을 만들기 위해서
	_hdc = CreateCompatibleDC(hdc); // 이게 바로 hdc와 호환되는 것을 만들어서 _hdc에 넣으라는 것
	_bitmap = (HBITMAP)LoadImage(nullptr, path.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	if (_bitmap == NULL)
	{
		MessageBox(_hWnd, path.c_str(), L"Imge Load Failed!", 0);
		return nullptr;
	}

	HBITMAP prev = (HBITMAP)SelectObject(_hdc, _bitmap); // _hdc에 _bitmap을 넣어주겠다. 근데 이 함수는 좀 이상함
	DeleteObject(prev);

	BITMAP bit = {};
	GetObject(_bitmap, sizeof(BITMAP), &bit);
	_size.x = bit.bmWidth;
	_size.y = bit.bmHeight;

	return this;
}
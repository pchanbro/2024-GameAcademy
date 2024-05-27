#include "pch.h"
#include "Texture.h"


Texture* Texture::LoadBmp(const wstring& path)
{
	// �ܺ��� Texture�� �ε��ϴ� ���

	// �츮�� �׵��� ����
	// if�� for�� �̷��� ���ε� �ܺ� ���ҽ��� ���Ѱ� ���� ����.

	// �̰Ŵ� WindowsAPI���� �������ִ°� ���� ���Ŵ�.
	// �̰� ������ ���� ������ ���� ���Ѵ�.

	// �� �ܺ��� Texture�� �ε��ϴ� �����
	// Windows API�� �ִ� �Լ��� ã�Ƽ� ���°�

	HDC hdc = ::GetDC(_hWnd); 
	// �츮���� dc�� ����ٸ鼭 window handle�� dc�� ������ ����
	// �̰� ���� �ƴ϶� ȭ�鿡 �Ѹ��� �Ͱ� ȣȯ�Ǵ� ���� ����� ���ؼ�
	_hdc = CreateCompatibleDC(hdc); // �̰� �ٷ� hdc�� ȣȯ�Ǵ� ���� ���� _hdc�� ������� ��
	_bitmap = (HBITMAP)LoadImage(nullptr, path.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	if (_bitmap == NULL)
	{
		MessageBox(_hWnd, path.c_str(), L"Imge Load Failed!", 0);
		return nullptr;
	}

	HBITMAP prev = (HBITMAP)SelectObject(_hdc, _bitmap); // _hdc�� _bitmap�� �־��ְڴ�. �ٵ� �� �Լ��� �� �̻���
	DeleteObject(prev);

	BITMAP bit = {};
	GetObject(_bitmap, sizeof(BITMAP), &bit);
	_size.x = bit.bmWidth;
	_size.y = bit.bmHeight;

	return this;
}
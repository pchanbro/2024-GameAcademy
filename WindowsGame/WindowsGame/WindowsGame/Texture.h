#pragma once
#include "ResourceBase.h"
class Texture : public ResourceBase
{
	//HDC��
	// HBITMAP�� �ִ°�
	// + SIZE (INT��) => Vector2Int
	// + �����(Uint32)
protected:
	HDC _hdc = {};
	HBITMAP _bitmap = {};
	Vector2Int _size = {};
	uint32 _transparent = RGB(255, 0, 255);	//����Ÿ (defalut�� ���� ���� ��, �� ���� ���� ������ �����̳ʵ��� ���� �ȽἭ �׷���.)

public:
	Texture();
	virtual ~Texture();

public:
	Texture* LoadBmp(const wstring& path);

	void SetSize(Vector2Int size) { _size = size; }
	Vector2Int GetSize() { return _size; }

	void SetTransparent(uint32 transparent) { _transparent = transparent; }
	uint32 GetTransparent() { return _transparent; }

	HDC GetDC() { return _hdc; }

};


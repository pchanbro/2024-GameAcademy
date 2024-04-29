#pragma once
#include "ResourceBase.h"
class Texture : public ResourceBase
{
	//HDC와
	// HBITMAP이 있는것
	// + SIZE (INT형) => Vector2Int
	// + 투명색(Uint32)
protected:
	HDC _hdc = {};
	HBITMAP _bitmap = {};
	Vector2Int _size = {};
	uint32 _transparent = RGB(255, 0, 255);	//마젠타 (defalut로 많이 쓰는 색, 이 색이 가장 쓸모없어서 디자이너들이 많이 안써서 그렇다.)

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


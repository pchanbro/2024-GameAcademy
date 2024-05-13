#pragma once
#include "ResourceBase.h"

class Texture;
class Sprite : public ResourceBase
{
public:
	Sprite(Texture* texture, int x, int y, int cx, int cy);
	virtual ~Sprite();

public:
	HDC GetDC();
	int32 GetTransparent();
	Vector2Int GetPos();
	Vector2Int GetSize();

protected:
	Texture* _texture = nullptr;
	int _x;
	int _y;
	int _cx; // width
	int _cy; // height 인데 변수명 길어서 그냥 이렇게 쓸 때도 있다.
};

// Sprite는 Texture에서 어디부터 어디까지 영역인 이미지
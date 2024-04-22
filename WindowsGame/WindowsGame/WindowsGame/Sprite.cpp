#include "pch.h"
#include "Sprite.h"
#include "Texture.h"

Sprite::Sprite(Texture* texture, int x, int y, int cx, int cy) : _texture(texture), _x(x), _y(y), _cx(cx), _cy(cy)
{
	// 위의 : 하고 옆에 쓴거랑 아래랑 같음
	// _texture = texture;
	// _x = x;
	// _y = y;
	// _cx = cx;
	// _cy = cy;
	// 근데 둘 중 하나 선택하라면 지금 여기에 이렇게 쓰는게 더 좋다.
}
Sprite::~Sprite()
{

}

HDC Sprite::GetDC()
{
	return _texture->GetDC();
}

int32 Sprite::GetTransparent()
{
	return _texture->GetTransparent();
}

Vector2Int Sprite::GetPos()
{
	return Vector2Int(_x, _y);
}

Vector2Int Sprite::GetSize()
{
	return Vector2Int(_cx, _cy);
}
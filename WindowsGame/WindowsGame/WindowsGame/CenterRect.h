#pragma once

struct Vector2;  // 다른 헤더파일도 이렇게 선언이 가능한가? 마치 #include "Vector2" 한것처럼?
struct CenterRect
{
	Vector2 pos;
	float width, height;

	RECT ToRect();
	void Draw(HDC hdc);
};


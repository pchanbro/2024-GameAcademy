#pragma once

struct Vector2;  // �ٸ� ������ϵ� �̷��� ������ �����Ѱ�? ��ġ #include "Vector2" �Ѱ�ó��?
struct CenterRect
{
	Vector2 pos;
	float width, height;

	RECT ToRect();
	void Draw(HDC hdc);
};


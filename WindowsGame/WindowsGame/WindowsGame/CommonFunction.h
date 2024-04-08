#pragma once

// ��ܾ��� �Լ����� �߰��ϰڴ�.

namespace Collision
{
	bool PtInRect(POINT pt, RECT rect);
	bool ptInRect(int ptX, int ptY, int x1, int y1, int x2, int y2);

	bool RectInRect(RECT rect1, RECT rect2);
}


namespace Shape
{
	// ������ ���� �ڷ��� ���� �� �ַξ��� namespace

	// inline Ű����� #define (��ũ�� �ѰͰ� ���� �ӵ��� ���� ���ؼ� �����)
	// �ٵ� cpu �����̶�
	// inline�� �����ؼ�
	// ������ ������ ������ cpu�� �˾Ƽ� ����
	// (���ٰ� �ؼ� ���ش� ����)
	// inline���� : ��������� �����ؾ���.
	inline RECT MakeRect(int x, int y, int width, int height)
	{
		RECT rc;
		rc.left = x - static_cast<int>(width / 2);
		rc.right = x + static_cast<int>(width / 2);
		rc.top = y - static_cast<int>(height / 2);
		rc.bottom = y + static_cast<int>(height / 2);

		return rc;
	}

	inline CenterRect MakeCenterRect(int x, int y, int width, int height)
	{
		CenterRect rc;
		rc.pos.x = x;
		rc.pos.y = y;
		rc.width = width;
		rc.height = height;

		return rc;
	}

	inline CenterRect MakeCenterRectLTRB(int left, int top, int right, int bottom)
	{
		CenterRect rc;
		rc.pos.x = (left + top) / 2;
		rc.pos.y = (top + bottom) / 2;
		rc.width = right - left;
		rc.height = bottom - top;

		return rc;
	}

	inline void ChangeToNormalValue(RECT& rc)
	{
		if (rc.left > rc.right)
		{
			LONG tmp = rc.left;
			rc.left = rc.right;
			rc.right = tmp;
		}
		if (rc.top > rc.bottom)
		{
			LONG tmp = rc.top;
			rc.top = rc.bottom;
			rc.bottom = tmp;
		}
	}
}
#pragma once

// 즐겨쓰는 함수들을 추가하겠다.

namespace Collision
{
	bool PtInRect(POINT pt, RECT rect);
	bool ptInRect(int ptX, int ptY, int x1, int y1, int x2, int y2);

	bool RectInRect(RECT rect1, RECT rect2);
}

// 도형에 관한 자료형 만들 때 주로쓰는 namespace
namespace Shape
{
	// inline 키워드는 #define (define 매크로 한것과 같은 속도를 내기 위해서 사용함)
	// (매크로 속도가 엄청 빠름)
	// 근데 cpu 마음이라
	// inline을 쓴다해서
	// 빠르게 해줄지 말지는 cpu가 알아서 결정
	// (쓴다고 해서 손해는 없음)
	// 하지만 여태까지 안쓴이유
	// inline단점 : 헤더에서만 구현해야함.
	// 헤더에서 구현하면 코드가 꼬이는 link error가 발생
	inline RECT MakeRect(int x, int y, int width, int height)
	{
		RECT rc;
		rc.left = x - static_cast<int>(width / 2);
		rc.right = x + static_cast<int>(width / 2);
		rc.top = y - static_cast<int>(height / 2);
		rc.bottom = y + static_cast<int>(height / 2);

		return rc;
	}

	inline CenterRect MakeCenterRect(float x, float y, float width, float height)
	{
		CenterRect rc;
		rc.pos.x = x;
		rc.pos.y = y;
		rc.width = width;
		rc.height = height;

		return rc;
	}

	inline CenterRect MakeCenterRectLTRB(float left, float top, float right, float bottom)
	{
		CenterRect rc;
		rc.pos.x = (left + top) / 2;
		rc.pos.y = (top + bottom) / 2;
		rc.width = right - left;
		rc.height = bottom - top;

		return rc;
	}

	inline CenterRect MakeCenterRectLTWH(float left, float top, float right, float bottom)
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
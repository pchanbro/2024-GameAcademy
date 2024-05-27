#include "pch.h"
#include "CommonFunction.h"

namespace Collision
{
	bool PtInRect(POINT pt, RECT rect)
	{
		if (rect.left <= pt.x && pt.x <= rect.right &&
			rect.top <= pt.y && pt.y <= rect.bottom)
		{
			return true;
		}

		return false;
	}

	// 오버라이드 : 클래스에서의 상속개념 (virtual)
	//				자식클래스를 호출하도록 하는

	// 오버로딩 : 함수명은 같은데 매개변수가 다른거
	bool ptInRect(int ptX, int ptY, int x1, int y1, int x2, int y2)
	{
		if (x1 <= ptX && ptX <= x2 &&
			y1 <= ptY && ptY <= y2)
		{
			return true;
		}
		return false;
	}



	bool RectInRect(RECT rect1, RECT rect2)
	{
		POINT pt1 = { rect1.left, rect1.top };
		POINT pt2 = { rect1.right, rect1.top };
		POINT pt3 = { rect1.left, rect1.bottom };
		POINT pt4 = { rect1.right, rect1.bottom };
		POINT pt5 = { rect2.left, rect2.top };
		POINT pt6 = { rect2.right, rect2.top };
		POINT pt7 = { rect2.left, rect2.bottom };
		POINT pt8 = { rect2.right, rect2.bottom };

		return PtInRect(pt1, rect2) || PtInRect(pt2, rect2) || PtInRect(pt3, rect2) || PtInRect(pt4, rect2) ||
			PtInRect(pt5, rect1) || PtInRect(pt6, rect1) || PtInRect(pt7, rect1) || PtInRect(pt8, rect1);
	}

	bool CircleInCircle(Vector2 pos1, float radius1, Vector2 pos2, float radius2)
	{
		// Circle와 Circle
		// Circle1과 Circle2의 중심좌표 사이 거리
		// 중심좌표 사이 거리 <= (Circle1 반지름 + Circle2 반지름)
		// 이면 접촉했다는 것

		Vector2 lengthVector = pos2 - pos1;
		float length_sq = lengthVector.LengthSqrt();

		if (length_sq <= (radius1 + radius2) * (radius1 + radius2))
		{
			return true;
		}

		return false;
	}

	bool RectInCircle(CenterRect rect, Vector2 circlePos, float radius)
	{
		// 사각형의 중심과 원의 중심 사이의 거리
		// abs(절댓값)
		float dx = abs(rect.pos.x - circlePos.x);
		float dy = abs(rect.pos.y - circlePos.y);

		// 사각형과 원의 중심 사이의 거리를 계산
		float distX = dx - rect.width / 2;
		float distY = dy - rect.height / 2;

		// 1. 원의 지름을 모서리로 하여 사각형화 해도 충돌이 되지 않는 경우
		if (distX > radius || distY > radius)
		{
			return false;
		}

		// 2. 사각형이 원의 중심점을 포함하고 있는 경우
		if (distX <= 0 || distY <= 0)
		{
			return true;
		}

		// 3. 사각형의 꼭지점과 원의 중심 사이의 거리
		float cornerDistanceSqrt = (distX * distX) + (distY * distY);

		return cornerDistanceSqrt <= (radius * radius);
	}
}
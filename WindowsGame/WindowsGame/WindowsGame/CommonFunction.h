#pragma once

// ��ܾ��� �Լ����� �߰��ϰڴ�.

namespace Collision
{
	bool PtInRect(POINT pt, RECT rect);
	bool ptInRect(int ptX, int ptY, int x1, int y1, int x2, int y2);

	bool RectInRect(RECT rect1, RECT rect2);
}

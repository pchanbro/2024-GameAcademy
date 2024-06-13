#pragma once

// 인터페이스는 함수만 작성. 순수 가상함수로만 구성한다.
// 왜 그런가 하면 그냥 그런 규칙이다
class ITilemapActor
{
public:
	// = 0; 은 이 클래스를 상속받고 override 해야만 쓸 수 있다라는 의미.
	virtual void SetCellPos(Vector2Int cellPos, bool teleport = false) = 0;
	virtual Vector2Int GetCellPos() = 0;
};


#include "pch.h"

void Comment1()
{
	// 1. Flipbook 완성
	//    -duration, loop 기능
	// 
}

void Comment2()
{
	// if문 동작원리

	bool conditionHeavy1 = true;	// ex) CheckCollision (아주 조금 무거웠던 것)
	bool conditionHeavy2 = false;
	bool conditionLight3 = true;	// 
	bool conditionLight4 = false;

	// if문에서
	// || 연산동작은 true를 만나면 뒤에 연산을 하지 않는다.
	if (conditionLight3 || conditionHeavy1) // 그러니 ||(or) 조건에서 가벼운 애를 앞에 보내라
	{
		printf("해당 코드가 실행된다.\n");
	}
	else
	{
		printf("해당 코드가 실행된다.\n");
	}

	// if문에서 
	// && 연산자 동작은 false를 만나면 뒤의 연산을 하지 않는다.
	if (conditionLight3 && conditionHeavy1) // 그러니 &&(and) 동작도 가벼운 애를 앞에 보내라
	{
		printf("해당 코드가 실행된다.\n");
	}
	else
	{
		printf("해당 코드가 실행된다.\n");
	}

	// 그렇다고 이걸 의식하면서 할 필요는 없다. 

	// 그냥 알쓸신잡 정도로 기억해주면 좋다.

	RECT rc1;
	RECT rc2;
	if (Input->GetKeyDown(KeyCode::d) && Collision::RectInRect(rc1, rc2))
	{
		// 그냥 이정도만 습관화 해줘라
		// 확실하게 너무 무겁거나 여러번 반복하는걸 뒤로 보내라
	}

	// 말로 바꿀때도
	// (더)희귀한거일때, 뭐뭐했으면..

	// 키보드 눌렀을때까 희귀한건가?
}

void Comment3()
{
	// Flipbook이란?

	// 종이 애니메이션

	// 여러장의 종이에 비슷하게 그림 그려주고
	// 한장씩 빠르게 넘기는 형식으로 애니메이션 효과를 보는거
	// 그런거

	// 언리얼에는 Flipbook 이라고 있는 기능 Animation도 따로 있음
	// 유니티에는 Animation으로 통합되어 있음
}

void Comment4()
{
	// 실습

	// FlipbookActor를 상속받아서 
	// CreatureActor, UserCharacterController를 만들고

	// Space를 누르면 공격
	// 화살표 위아래양옆을 누르면 Move
	// 가만히 있으면 Idle 상태

	// 만들기

	// + 금방 한다면 몬스터까지 만들어서
	// 공격하면 몬스터 사라지게

	// 이것도 금방한다면 몬스터 체력구현까지
}
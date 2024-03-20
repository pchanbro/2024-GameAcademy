// 요게 핵심이다!!
#pragma once // 이걸 헤더파일에 붙여야 하는 이유다.
// 이걸 붙이지 않으면 헤더파일을 두 번 복붙해버려서 (재정의 관련)에러가 뜰 수 있다

struct Card
{
	int Index;

	void Print();
	void Swap(Card& another);
};

// 변수선언을 헤더해서 할거면 extern 키워드를 붙여야한다.
// 그렇지 않으면 이 헤더를 include한 main이 존재하는 파일에서 이 변수를 건들일 수 없다.
// 예를 들면 main이 존재하는 파일에서 _a++ 하면 오류가 난다.
extern int _a = 0;

// 즉 #pragma once 이게 밑에 구조의 역할을 하는 것


// __CARD_H__ 라는 매크로가 선언되어 있지 않으면
//#ifndef __CARD_H__
//
// __CARD_H__ 를 선언해주겠다.
//#define __CARD_H__
//
// CARD라는 구조체를 선언한다.
//struct Card
//{
//	int Index;
//
//	void Print();
//	void Swap(Card& another);
//};
//
//#endif

// 이렇게 함으로써 
// 헤더파일은 무조건 한 번만 include 된다.
// 라는 효과를 얻을 수 있음.


// 이 줄을 요약할 수 있는 단 하나의 명령어
//#ifndef __CARD_H__
//#define __CARD_H__
//#endif
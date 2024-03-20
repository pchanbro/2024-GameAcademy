//요게 핵심!!!!
//#pragma once를 헤더파일에 붙여야한다.
//그렇지 않으면 (재정의 관련) 에러가 뜰수있다.
#pragma once // 이 파일은 한번만 선언됩니다.

//// __CARD_H__ 라는 매크로가 선언되어있지않으면
//#ifndef __CARD_H__
//// __CARD_H__ 를 선언해주겠다.
//#define __CARD_H__

// CARD라는 구조체를 선언한다.
struct Card
{
	int Index;

	void Print();
	void Swap(Card& another);
};

//변수선언을 헤더에서 할거면 extern 키워드를 붙여야합니다.
//extern => 이 변수는 다른파일에서도 사용할겁니다.
//main이 있는 cpp 파일에서 한번더 선언해줘야합니다.
//extern에서는 값까지 넣으면안되고 
//main이 있는 cpp파일에서 선언할때 값을 초기화 해준다.
extern int _a;

//#endif
//// 이렇게 함으로써 
//// 헤더파일은 무조건 한번만 include된다.
//// 라는 효과를 얻을수있음.



//// 이 줄을 요약할수있는 단하나의 명령어
//
//#ifndef __CARD_H__
//#define __CARD_H__
//#endif
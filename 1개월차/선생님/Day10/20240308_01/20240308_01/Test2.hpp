#pragma once
#include "Card.hpp"
#include <iostream>

void Function2()
{
	Function1();
}

void Function3()
{
	printf("AA");
}


//Main => Test2.hpp 불러오고
//Test2.hpp => Card.hpp 를 불러오는데
//Card.hpp => Test2.hpp 가 필요하면!!

//여기서 문제가 발생함.

//Test2.hpp => Function2 구현, Function3 구현, Function1 구현
//Card.hpp => #include "Test2.hpp"  Function2 구현, Function3 구현, Function1 구현

// Function2 구현부가 두번 겹치면
//  ==> 재정의 에러


// 항상 프로그램의 시작은?
//  => main이 있는 cpp부터 시작한다.

// main02.cpp
//  #include "Test2.hpp"  => #include "Card.hpp" (Function1 구현)  Function2 구현, Function3 구현
//	#include "Card.hpp" => pragma once로 인해 , 이미 한번 읽은파일 무시.

// Function1호출 
//  => Card.hpp 에 있음.
//   => Card.hpp 에서는 실행하려고 보니까
//		Function3 을 호출해야함.
//      Function3을 찾기위해 위에 include를 뒤지게됩니다.
//       "Test2.hpp" << 이파일을 읽으려고하니
//				 pragma once로 인해 , 이미 한번 읽은파일 무시.
//				그래서 결과적으로 그 어디에도 없기때문에 빌드를하면, 식별자를 찾을수 없다고 함.


// 그래서 결론!!!
//		가이드를 드리겠습니다.
//		내가 진짜 .h, .cpp 에 대해 많은걸알고 다 커버할수있다.
//			그런게 아니라면, .hpp형식으로는 쓰지마세요!!
//			헤더에서 구현을 하지말라는 소리입니다!!
//			헤더는 전방선언이나 자료형 선언만!!


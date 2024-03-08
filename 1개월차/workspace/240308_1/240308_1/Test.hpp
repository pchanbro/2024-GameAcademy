#pragma once
#include <iostream>
#include "Card.hpp"

void Function2()
{
	Function1();
}

void Function3()
{
	printf("AA");
}

// 지금 현재 Test.hpp와 Card.hpp 상태가 문제가 발생함

// Test.hpp => Card.hpp를 불러오는데
// Card.hpp => Test.hpp 가 필요하면

// 여기서 문제가 발생

// Test.hpp => Function2 구현, Function3구현, Function1 구현
// Card.hpp => #inlcude "Test.hpp"  Function2 구현, Function3 구현, Function1 구현

// Function2 구현부가 두 번 겹치면
// ===> 재정의 에러


// 항상 프로그램의 시작은 
// main이 존재하는 cpp부터 시작


// main02.cpp
// #include "Test.cpp" => #inlcude "Card.hpp" (Function1 구현) Function2 구현, Function3 구현
// #include "Card.hpp" => pragma once로 인해, 이미 한 번 읽은파일 무시

// Function1 호출
// => Card.hpp에 있음.
//	=> Card.hpp 에서는 실행하려고 보니까
//		Function3을 호출해 줘야함.
//		Function3을 찾기 위해 include를 뒤지게 된다.
//		 "Test.hpp" << 이 파일을 읽으려고 하니
//			pragma once 로 인해, 이미 한 번 읽은파일 무시.
//				그래서 결과적으로 그 어디에도 없기 때문에 빌드를하면, 식별자를 찾을 수 없다고 함.


// 그래서 결론!!
//	가이드
//		내가 진짜 .h, .cpp에 대해 많은걸 알고	
#include <iostream>
#include "Card.h"
#include "Test3.h"

// 내가 만든파일이 아니면 <> 로 지정한다.
// 내가 만든파일이면 "" 으로 지정한다


using namespace std;
int _a = 0;

void main()
{
	// 헤더

	// 헤더란???
	// #include <iostream>
	// iostream 처럼 MS에서 만든 헤더파일도 있지만
	// 우리가 만든 헤더파일도 존재할 수 있음.

	// .h(헤더),  .cpp , .hpp
	// 확장자가 없을수도있음.

	// 헤더파일 (파일명.h)
	//   - 함수 전방선언
	//   - 사용자 정의 자료형 선언 ( 구조체 선언 )
	//   - 다른 헤더파일 include

	// CPP 파일 (파일명.cpp)
	//  => 빌드 되는 파일
	//   - 함수 구현

	// HPP 파일 (파일명.hpp) (.h + .cpp => .hpp)
	//  - 함수 선언과 구현을 같이함.
	//  - 다만, include가 가능

	// 확장자가 없는 파일
	//  - 헤더파일, HPP파일 이런거는 그냥 이름을 지어준거 일뿐이에요
	//  - 사실 CPP말고는 의미가 없습니다. 우리맘대로 지어도 돼요.


	_a++;
	IncreaseA();

	cout << _a << endl;
}
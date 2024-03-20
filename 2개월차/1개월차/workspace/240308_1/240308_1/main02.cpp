#include <iostream>

// 내가 만든 파일이 아니면 <>로 지정한다.
// 내가 만든 파일이면 ""으로 지정한다.

#include "Card.h" 
// 이 줄의 효과 >> Card.h의 내용을 전체 Ctrl + C 해서 이 파일에 Ctrl + V 한 것과 같다.
// 그래서 
// #include "Card.h" 이걸 한 줄 더 써주면 무조건 에러난다.
// 근데 
#include <iostream>
// 이건 아무리 써도 에러가 안난다.
// 왜냐?
// #ifdef - endif 를 통해 #include <iostream>가 먼저 되어있으면 다시 include하지 않도록 설정해주었기 때문이다.
// #ifndef -endif 를 통해 해도 좋다.
// 그러니 헤더 파일에는 
// pargma once를 맨 윗줄에 넣어주자

//#include "Test.hpp"
//#include "Card.hpp"

using namespace std;

// 여기서 이렇게 선언해주면 Card.h의 _a랑 같은 거로 취급 받는다.
// 물론 Card.h에서 extern int _a;로 선언해줬어야 한다.
int _a = 0;

void main()
{
	// 헤더
	
	// 헤더란?
	// #include <iostream> 이런거
	// iostream 처럼 MS에서 만든 헤더파일도 있지만
	// 우리가 만든 헤더파일도 존재할 수 있음

	// .h(헤더), .cpp, .hpp 등 여러가지 있다..
	// iostream마냥 확장자가 없을수도 있다.

	// 헤더파일 (파일명.h)
	//	- 함수 전방선언
	//	- 사용자 정의 자료형 선언 ( 구조체 선언 )
	//	- 다른 헤더파일 include

	// CPP파일 (파일명.cpp)
	//  => 빌드 되는 파일
	//   - 함수 구현

	// HPP 파일 (파일명.hpp) (.h + .cpp => .hpp)
	//  - 함수 선언과 구현을 같이함.
	//  - cpp파일과 비슷하나 include가 가능하다.

	// 확장자가 없는 파일
	//  - 헤더파일, HPP파일 같은건 이름을 지어준 거 뿐이다.
	//  - 사실 CPP 말고는 의미가 없다. 우리 맘대로 지어도 된다.
}
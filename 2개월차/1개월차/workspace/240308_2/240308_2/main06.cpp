#include <iostream>
#include "MainGame.h"

using namespace std;

// 클래스 선언 저번 시간에 만든 sturct Card와 다를게 없다.
// 하지만 class는 기본이 private이며, 
class Card
{
private: // 접근 제어를 나만 할 수 있는 변수
	int MyVarible;
public: // 접근 제어를 아무나 할 수 있는 변수
	int Index;
};

// struct는 기본이 public 이다.
// 구조체 함수는 원래 안됐다가. 나중에 문법적으로 허용이 된 것.
// 클래스 함수는 원래 가능했다.
struct CardStruct
{
private:
	int MyVarible;
public:
	int Index;
};

void main()
{
	// 클래스 - 1
	// 뉴비 절단기 2호

	// 프로그래밍이 철학인 이유가 클래스에서 나온다.


	// 클래스 = 구조체
	// 이게 무슨소리인가?

	// 클래스 사용
	// 클래스는 구조체와 동일하게 
	// 사용자 정의 자료형이다.

	Card card = {};

	// card.Index = 3; 
	// 근데 클래스(기본이 private)는 구조체(기본이 public)처럼 이렇게 사용 불가
	// 하지만 사용하고 싶다면 class 안에서 public : 를 붙여준다.	
	card.Index = 3; // 그러면 이렇게 사용이 가능해진다

	CardStruct myCard = {};
	myCard.Index = 3;


	// C++만 특이하기 때문에
	// 일반적인 클래스 특징은 짚고 넘어가는게 좋다.

	// 클래스 - 보편적으로 많은 언어에서 Heap에 할당된다. (동적 메모리)
	// 구조체 - 보편적으로 많은 언어에서 stack에 할당된다. (정적 메모리)

	// [주로 Heap은 데이터 큰걸 다룬다]
	// 클래스 자료형 -> 객체 (자아가 있는)
	// 구조체 자료형 -> 데이터 (자아가 없는)
	// 사실 구조체를 제외한 모든 내용을 클래스라고 생각하는게 편함


	// 클래스 - 많은 언어에서 클래스는 Heap에 할당된다. 
	// C++에서도 보통 클래스는 new를 사용한다.
	// 클래스를 당장은 이렇게 사용하자.
	// 소스파일 - 추가 - 클래스

	MainGame* mainGame = new MainGame;
}
#include <iostream>
#include "MainGame.h"
using namespace std;

//클래스 선언
class Card
{
private: // 접근제어를 나만 할수있다.
	int MyVariable;
public:	// 접근제어를 아무나 할수있게한다.
	int Index;

	//구조체는 기본이 public이고
	//클래스는 기본이 private다.
	//구조체 함수는 원래 안됐다가, 나중에 문법적으로 허용이 된거고,
	//클래스 함수는 원래부터 됐습니다.
	//그렇기 때문에 진짜 차이가 private, public 밖에 차이가 없다. (C++ 한정)
	void Print()
	{
		printf("print");
	}
};

struct CardStruct
{
private: // 접근제어를 나만 할수있다.
	int MyVariable;
public:	// 접근제어를 아무나 할수있게한다.
	int Index;
};


void main()
{
	// 클래스 - 1
	// 뉴비 절단기 2호

	// 프로그래밍을 철학이라고 많이 말씀드렸는데,
	// 그이유가 여기서 나옵니다.


	// 클래스 = 구조체
	// 이게 무슨소리인가??

	// 클래스 사용
	// 클래스는 구조체랑 동일하게
	// 사용자 정의 자료형입니다.

	Card card = {};
	card.Index = 3;

	CardStruct myCard = {};
	myCard.Index = 3;



	//C++만 특이하기 때문에
	//일반적인 클래스 특징은 짚고 넘어가는게 좋습니다.
	// 클래스 - 많은 언어에서 클래스는 Heap에 할당됩니다.
	// 구조체 - 많은 언어에서 구조체는 Stack에 할당됩니다.

	// [주로 Heap은 데이터 큰걸 다룬다]
	// 클래스 자료형 -> 객체 ( 자아가 있는 )
	// 구조체 자료형 -> 데이터 ( 자아가 없는 )
	// 사실 구조체를 제외한 모든 내용을 클래스라고 생각하는게 편함.



	// 클래스 - 많은 언어에서 클래스는 Heap에 할당됩니다.
	// C++에서도 보통 클래스는 new를 사용합니다.
	// 클래스를 당장은 이렇게 사용해주세요.
	// 소스파일 - 추가 - 클래스


	MainGame* mainGame = new MainGame();
	delete mainGame;
}
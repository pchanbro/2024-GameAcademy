#include <iostream>
#include "Defines.h"
using namespace std;

class GameManager
{
DECLARE_SINGLE(GameManager)

public:
	void GameStart()
	{
		printf("게임이 시작합니다.\n");
	}
};

void Function()
{
	//static은 한번만 초기화되고
	//다시 선언할때는 동작을 하지 않는다.
	static int a = 0;
	a++;
	printf("%d\n", a);

	
}


void main()
{

	//싱글톤패턴이란??
	// 싱글톤패턴이란
	// 프로그램에서 단 하나의 객체만 존재하게 만드는 패턴

	//아래가 안되게해야함..
	/*MySingleton* single1 = new MySingleton();
	MySingleton* single2 = new MySingleton();
	MySingleton* single3 = new MySingleton();
	MySingleton* single4 = new MySingleton();
	MySingleton* single5 = new MySingleton();*/

	// 이렇게 만들기 싫다.
	// 프로그래머가 잘해서 한개만 만들면 좋은데
	// 강제적으로 한개만 만들게 제약을 줄수있으면 실수를 방지할수 있으니까

	// 언제쓰나요??
	// GameManager 같이 게임을 관리하는 클래스
	// 여러개 있어야할 이유가 없죠
	// GameManager 는 단하나만 존재하게 하기위해 싱글톤 패턴을 씁니다.

	for (int i = 0; i < 10; i++)
	{
		Function();
	}

	GameManager::GetInstance()->GameStart();


	// 싱글톤이 뭔지도 알고, 왜쓰는지도알고, 어떻게 쓰는지도 알았는데
	// 얘를 왜 쓰지 말라는거지???

	// 기본적으로
	// 전역변수를 사용하는건 안좋다고 봅니다.
	// 메모리관점에서나
	// 프로그래밍관점에서나

	// 메모리 구조
	// 1. Code영역
	// 2. Data영역 (static과 전역변수), 용량이 적어요. (read가 빠르고, write가 느림)
	// 3. Heap영역
	// 4. Stack영역 

	// 뭐가 안좋다는거지?
	// 전역변수가??

	// GameManager 를 호출하는곳
	// 되게 여러군데에서 GameManager를 참조하게 됩니다.

	// 어디서나 쓸수있기때문에
	// 캡슐화가 100% 잘되어있는게 아니라면
	// 코드가 꼬일수밖에 없음

	// 어? 안좋은 패턴이다.
	// 전역변수는 나쁘다.
	// 각자 알아서 잘 관리하는 코드가 좋은 코드다.


	// 전역변수가 생산성을 올려줘요. (편하기 때문에)
	// 막말로 싱글톤을 안쓰면 게임개발을 못할정도
	// 여러분들은 이런거 신경쓰지말고 싱글톤 패턴 쓰면됩니다.

}
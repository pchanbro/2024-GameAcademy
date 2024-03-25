#include <iostream>

using namespace std;

class GameManager
{
private:
	// 생성자를 막아준다 (new 못하게 막아준다)
	GameManager() {}
	~GameManager() {}
public:
	static GameManager* GetInstance()
	{
		static GameManager gameManager;
		return &gameManager;
	}
	// 싱글톤 패턴을 쓰려면 여기까지는 다 써줘야 하는데 이걸 해결해주는 꼼수가 있다. 

	void GameStart()
	{
		printf("게임이 시작합니다.\n");
	}
};

void Function()
{
	// static는 한 번만 초기화하고 
	// 다시 선언할때는 동작하지 않는다.
	static int a = 0;
	a++;
	printf("%d\n", a);

}

void main()
{
	// 싱글톤이란??
	// 프로그램에서 단 하나의 객체만 존재하게 만드는 패턴
	
	// 아래가 안되도록 해야한다.
	/*MySingleton* single1 = new MySingleton();
	MySingleton* single2 = new MySingleton();
	MySingleton* single3 = new MySingleton();
	MySingleton* single4 = new MySingleton();
	MySingleton* single5 = new MySingleton();*/
	
	// 이 위처럼 여러개 만들기 싫다.
	// 프로그래머가 잘해서 한개만 만들면 좋지만
	// 강제적으로 한개만 만들게 제약을 걸면 실수를 방지할 수 있다.

	// 언제쓰나?
	// GameManager 같이 게임을 관리하는 클래스
	// 여러개 있을 이유가 없다.
	// GameManager는 단 하나만 존재하게 하기 위해서 싱글톤 패턴을 쓴다.

	for (int i = 0; i < 10; i++)
	{
		Function();
	}

	GameManager* gm = GameManager::GetInstance(); // static 변수는 이렇게 접근해야 한다.
	gm->GameStart();

	
	// 싱글톤이 뭔지도 알고, 왜쓰는지도 알고, 어떻게 쓰는지도 알았는데
	// 얘를 왜 쓰지 말라는건가?

	// 20년차 말 다르고
	// 10년차 말 다르고
	// 5년차 말 다르고
	// 심지어 신입도 생각이 다르다.

	// 일단 선생님의 생각은
	
	// 기본적으로 전역변수 사용을 좋지않다.
	// 메모리 관점에서도
	// 프로그래밍 유지보수 관점에서도

	// 메모리구조
	// 1. Code 영역
	// 2. Data 영역 (static 과 전역변수 는 여기에 속한다), 용량이 적다. 그래서 전역변수를 줄여야 한다.
	// 3. Heap 영역
	// 4. stack영역

	// 전역변수가 뭐가 안좋다는 건가?
	
	// 예를 들어
	// GameManager를 호출하는곳
	// 여러군데에서 GamaManager를 참조하게 된다.
	// 어디서나 쓸 수 있기때문에
	// 캡슐화가 100% 잘되어있는게 아니라면
	// 코드가 꼬일 수 밖에 없다.

	// 즉 안좋은 패턴이라면
	// 전역변수는 나쁘다.
	// 각자 알아서 잘 관리하는 코드가 좋은 코드다

	// 하지만 전역변수는 생산성을 올려준다.
	// 편하기 때문에

	// 막말로 싱글톤을 안쓰면 게임개발을 못할정도다.
	// 우리는 이런거 신경쓰지말고 싱글톤 패턴 쓰면된다.
}
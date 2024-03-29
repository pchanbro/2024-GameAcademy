#include <iostream>

using namespace std;

class Game
{
public:
	void Init() {}
	void Draw() {}
	void Update() 
	{ 
		// Input을 관리하는 객체 (클래스)
		// Input에서 마우스클릭이라는 일이 생기면

		// 마인 생성
		// scv 미네랄 캐기

	}
	void Release() {}
};

void main()
{
	// 2. 클래스
	// 객체 지향 프로그래밍

	// 그동안 콘솔에서 해온 프로그래밍 방식은
	// 절차 지향 프로그래밍
	// 입니다.


	// 절차 지향 프로그래밍은
	// 함수들로 구성되어있어서
	// 위에서 아래로. 코드를 읽기만 하면된다.

	// 객체 지향 프로그래밍은
	// 객체를 여러개만들어서
	// 객체끼리 알아서 상호작용 되게끔 만드는게
	// 객체 지향 프로그래밍입니다.

	// class 많이쓰면 객체지향 프로그래밍 입니다.

	// 오늘 할 이론들은
	// 진짜 이상향에 가까운 이야기들이 많이나올거에요.
	// 클래스 5대 원칙
	// 디자인패턴


	//Game* game = new Game();
	//game->Init();
	//while (true)
	//{
	//	game->Draw();
	//	game->Update();
	//}
	//game->Release();

	// 어? 객체지향 프로그래밍이
	// 클래스로 덕지덕지 붙여져있는건 알겠는데
	// 왜쓰는거지?

	// What?, How?, Why?

	// 절차 지향 프로그래밍
	//  단점 : 
	//  - 기획 단계에서 뭔가 바뀌면, 수정하기가 어려워요.
	//     ( 이미 서로서로를 너무 의존하고있어서 )
	// ( 위에서 아래로 흐르고있는데, 윗물에서 수정이 일어나면, 아래를 모두 바꿔줘야합니다. )
	//  - 유지보수성이 안좋다
	//  - 협업에 안좋다.
	// ( 협업을 하게되면. 모두가 위에서 아래로 코드를 짭니다. )
	// ( 파일 하나에서 위에서 아래로 짜게되면 )
	//  A 프로그래머가 5Line ~ 15Line 수정했어요.
	//  B 프로그래머가 30Line ~ 45Line 을 수정했는데
	// 이때 A프로그래머가 변수명을 수정했으면 ..?
	// 머지할때 문제가 많아요.
	// 그래서 파일분할을 최대한 많이합니다. (회사에서는)

	// 그래서 객체지향 프로그래밍을 하게됩니다.
	// 장점 : 
	//  - 유지보수성이 좋습니다.
	//  - 협업에 좋다.

	// 단점 :
	//  - 이론상 없는데, 코드레벨이 조금 올라간다?
	//  - 실행속도 느리다. (이론상 파일하나로하는게 컴퓨터입장에선 빨라요)

	// 코드로 최적화하는것보다
	// 3D 모델, 2D 텍스쳐에서 조금 이득보는게 훨씬 좋습니다.

}
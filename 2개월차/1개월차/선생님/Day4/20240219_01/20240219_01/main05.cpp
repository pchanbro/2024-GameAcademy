#include <iostream>
#include <time.h>
using namespace std;

//변수 선언
//여기서 선언하는 변수는 _ + 소문자로 시작
int _myHand = 0; //내 손
int _comHand = 0; // 상대방 손

//함수 선언 
// 함수 (main함수 위에 선언할것!!)
// void 함수명()  (함수명은 대문자로 시작)
// {
//		실행시킬 코드
// }
void PrintGameStartScene()
{
	printf("┌─────────────────────────────────────────────┐\n");
	printf("│       Rock Scissor Paper Game Start         │\n");
	printf("└─────────────────────────────────────────────┘\n");
}

//main은 최대한 가독성위주로!!
void main()
{
	// 수도코드 (직감적으로 하는 프로그래머) 
	// (손으로 써가면서 연습하는 프로그래머)
	// 
	// 1. 게임 시작화면을 출력한다. (PrintGameStartScene)
	// 2. 내가 어떤걸 뽑을지 선택한다. (ChooseMyHand)
	// 3. 상대방이 어떤걸 뽑을지 정한다. (ChooseComHand) (출력할거 없음) (랜덤사용)
	// 4. 내가 뽑은것과 상대방이 뽑은것을 출력한다 (PrintHands)
	// 5. 승패를 출력한다. (PrintGameResult)

	
	//PrintGameStartScene();
	//ChooseMyHand();
	//ChooseComHand();
	//PrintHands();
	//PrintGameResult();


	//숙제1.
	//  가위바위보 만들기
	
}
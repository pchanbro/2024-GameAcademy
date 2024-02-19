#include <iostream>
#include <time.h>

using namespace std;

// 변수 선언
// 여기서 선언하는 변수는 (_소문자) 로 시작
int _myHand = 0; // 내손
int _comHand = 0; // 상대방 손


// 함수 선언
// main함수 위에 선언해야 한다.
// 함수명은 대문자로 시작해야 한다.


// 1. 게임 시작화면을 출력한다. (PrintGameStartScene)
void PrintGameStartScece()
{
	printf("┌──────────────────────────────────────┐\n");
	printf("│    Rock Scissor Paper Game Start     │\n");
	printf("└──────────────────────────────────────┘\n");
}

// 2. 내가 어떤걸 뽑을지 선택한다. (ChooseMyHand)
void ChooseMyHand()
{
	cout << "가위 (0) 바위(1) 보(2) 중에 하나를 뽑아주세요 : ";
	cin >> _myHand;
}


// 3. 상대방이 어떤걸 뽑을지 선택한다. (ChooseComHand) (출력할거 없음) (랜덤사용) 
void ChooseComHand()
{
	cout << "컴퓨터가 손을 선택합니다. " << endl;
	_comHand = rand() % 3;
}


// 4. 내가 뽑은것과 상대방이 뽑은것을 출력한다. (PrintHands)
void PrintHands()
{
	cout << endl;
	switch (_myHand)
	{
	case 0:
		cout << "내 손 : 가위 " << endl;
		break;
	case 1:
		cout << "내 손 : 바위 " << endl;
		break;
	case 2:
		cout << "내 손 : 보 " << endl;
		break;
	default:
		cout << "플레이어가 잘못 선택하셨습니다. " << endl;
	}

	switch (_comHand)
	{
	case 0:
		cout << "컴퓨터 손 : 가위 " << endl;
		break;
	case 1:
		cout << "컴퓨터 손 : 바위 " << endl;
		break;
	case 2:
		cout << "컴퓨터 손 : 보 " << endl;
		break;
	default:
		cout << "컴퓨터가 잘못 선택하였습니다. " << endl;
	}
}


// 5. 승패를 출력한다. (PrintGameResult)
void PrintGameResult()
{
	puts("");
	if (_myHand == 0 && _comHand == 2 || _myHand == 1 && _comHand == 0 || _myHand == 2 && _comHand == 1)
	{
		cout << "플레이어의 승리!" << endl;
	}
	else if (_myHand == 0 && _comHand == 1 || _myHand == 1 && _comHand == 2 || _myHand == 2 && _comHand == 0)
	{
		cout << "플레이어의 패배..." << endl;
	}
	else
	{
		cout << "플레이어와 컴퓨터가 비겼습니다." << endl;
	}
}

void main()
{
	// 함수 (무조건 main함수 위에 존재해야 한다. => C/C++ 프로그램은 항상 위에서 아래로 읽는데 다른함수가 main함수 아래 있으면 main문에서 실행 중에 다른 함수인식을 못함)
	// 사용법
	// void 함수명()
	// {
	//		실행시킬 코드
	// }


	// 프로그래밍에서 가장 중요한 것은 "가독성" 그런데 위에 저런식으로 여러가지가 섞여 복잡하게 될 수 있다. 그래서 함수를 사용한다.
	// main은 최대한 가독성 위주로!!

	// 그리고 게임을 만들기 전에 "수도코드"를 작성해라

	// 수도코드 (손으로 써가며 연습하는 프로그래머가 되어라)
	// 
	// 1. 게임 시작화면을 출력한다. (PrintGameStartScene)
	// 2. 내가 어떤걸 뽑을지 선택한다. (ChooseMyHand)
	// 3. 상대방이 어떤걸 뽑을지 선택한다. (ChooseComHand) (출력할거 없음) (랜덤사용) 
	// 4. 내가 뽑은것과 상대방이 뽑은것을 출력한다. (PrintHands)
	// 5. 승패를 출력한다. (PrintGameResult)

	srand(time(NULL));
	::PrintGameStartScece();
	::ChooseMyHand();
	::ChooseComHand();
	::PrintHands();
	::PrintGameResult();
}
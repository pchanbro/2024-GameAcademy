//include 선언하는 영역
#include <iostream>

//namespace 선언하는 영역
using namespace std;

//enum 선언하는 영역
enum eHandName
{
	HAND_LEFT,
	HAND_RIGHT,

	HAND_END
};
enum eRockScissorPaper
{
	RSP_ROCK,
	RSP_SCISSOR,
	RSP_PAPER,

	RSP_END
};

//함수 전방선언 하는 영역
//이런 함수가 있어.
void ChooseMyHand();
void ChooseComHand();
void PrintHands();
void ChooseFinalMyHand();
void ChooseFinalComHand();
void PrintResult();
void PrintHand(int hand);

//변수 선언 영역 
// 0과 1 외에는 모두 define 이나 상수로 변경해주는게 좋습니다.
int _myHand[HAND_END] = {};
int _comHand[HAND_END] = {};
int _myFinalHand = 0;
int _comFinalHand = 0;

void main()
{
	//가위바위보 하나빼기

	// 함수 뒷내용 잠깐씩 사용하면서 설명드릴거에요

	// 가위바위보 하나빼기 수도코드
	// 1. 내가 낼것 두개를 정한다.
	//		ChooseMyHand()
	// 2. 상대(컴퓨터)가 낼것 두개를 정한다.
	//		ChooseComHand()
	//    - 이때 상대가 낼것은 rand() % 3;
	// 3. 내가 낸것과 상대가 낸것을 보여준다.
	//		PrintHands()
	// 4. 내가 최종적으로 낼것을 고른다.
	//		ChooseFinalMyHand()
	// 5. 상대가 최종적으로 낼것을 고른다.
	//		ChooseFinalComHand()
	// 6. 승패비교를 한다.
	//		PrintResult()


	// 수도코드 스텝당으로 함수를 짜는게 좋다.
	//   - 가독성측면

	srand(time(NULL));
	::ChooseMyHand();
	::ChooseComHand();
	::PrintHands();
	::ChooseFinalMyHand();
	::ChooseFinalComHand();
	::PrintResult();

	//함수 전방선언
	// main함수위에 함수원형을 선언해주면, main아래에 함수를 구현해도 문제가 없다.

}

void ChooseMyHand()
{
	// 내손 두개를 정해준다.
	printf("사용자가 왼손에 낼 것을 골라주세요 바위(0), 가위(1), 보(2) : ");
	cin >> _myHand[HAND_LEFT];
	printf("사용자가 오른손에 낼 것을 골라주세요 바위(0), 가위(1), 보(2) : ");
	cin >> _myHand[HAND_RIGHT];
}

void ChooseComHand()
{
	//_comHand[HAND_LEFT]
	//_comHand[HAND_RIGHT] 여기에 랜덤한 값을 넣어줘야합니다.

	//배열을 쓰고있는 이상
	//반복문이랑 같이써주는게 좋아요.

	//comHand 배열크기만큼 반복한다
	for (int i = 0; i < HAND_END; i++)
	{
		_comHand[i] = rand() % RSP_END;	//가위바위보 랜덤뽑기
	}
}

void PrintHands()
{
	// 내 손과 상대방의 손을 보여준다
	printf("내가 뽑은 것 : ");
	for (int i = 0; i < HAND_END; i++)
	{
		::PrintHand(_myHand[i]);
	}
	printf("\n");

	printf("상대가 뽑은 것 : ");
	for (int i = 0; i < HAND_END; i++)
	{
		::PrintHand(_comHand[i]);
	}
	printf("\n");


	// 플레이어 2명만큼 반복한다.
	// i = 0 : 플레이어 출력
	// i = 1 : 상대방 출력
	//for (int i = 0; i < 2; i++)
	//{
	//	if (i == 0)
	//	{
	//		printf("내가 뽑은 것 : ");
	//	}
	//	else if (i == 1)
	//	{
	//		printf("상대가 뽑은 것 : ");
	//	}

	//	//손의 갯수만큼 반복한다.
	//	for (int j = 0; j < HAND_END; j++)
	//	{
	//		int hand = 0;

	//		//i => 플레이어 넘버
	//		//i = 0 : 플레이어
	//		//i = 1 : 상대방
	//		if (i == 0)
	//		{
	//			hand = _myHand[j];
	//		}
	//		else if (i == 1)
	//		{
	//			hand = _comHand[j];
	//		}

	//		switch (hand)
	//		{
	//		case RSP_ROCK:
	//			printf("바위\t");
	//			break;
	//		case RSP_SCISSOR:
	//			printf("가위\t");
	//			break;
	//		case RSP_PAPER:
	//			printf("보\t");
	//			break;
	//		default:
	//			printf("UnKnown\t");
	//			break;
	//		}
	//	}
	//	printf("\n");
	//}


}

void ChooseFinalMyHand()
{
	//printf("ChooseFinalMyHand\n");
	printf("내가 최종적으로 고를 손을 선택해주세요 (0: 왼손, 1: 오른손) : ");
	int choose;
	cin >> choose;

	//_myFinalHand에 값을 넣어준다.
	//_myFinalHand = _myHand[choose];

	if (choose == 0)
	{
		_myFinalHand = _myHand[HAND_LEFT];
	}
	else if (choose == 1)
	{
		_myFinalHand = _myHand[HAND_RIGHT];
	}


	//왼손을 고르면
	//_myFinalHand = _myHand[0];
	//오른손을 고르면
	//_myFinalHand = _myHand[1];
}

void ChooseFinalComHand()
{
	//printf("ChooseFinalComHand\n");

	//_comFinalHand 변수에 최종값을 넣어준다.
	//_comHand[0], _comHand[1] 중에 랜덤으로 하나 넣어준다.
	int random = rand() % HAND_END;
	_comFinalHand = _comHand[random];
}

void PrintResult()
{
	printf("PrintResult\n");
	//내가 고른것과
	//상대가 고른것을 보여준다
	printf("내가 최종적으로 선택한 것 : ");
	::PrintHand(_myFinalHand);
	printf("\n");

	printf("상대가 최종적으로 선택한 것 : ");
	::PrintHand(_comFinalHand);
	printf("\n");


	//승패를 알려준다.

	if (_myFinalHand == _comFinalHand)
	{
		printf("비겼습니다.\n");
	}
	else if (
		(_myFinalHand == RSP_ROCK && _comFinalHand == RSP_SCISSOR) || 
		(_myFinalHand == RSP_SCISSOR && _comFinalHand == RSP_PAPER) || 
		(_myFinalHand == RSP_PAPER && _comFinalHand == RSP_ROCK))
	{
		printf("이겼습니다.\n");
	}
	else
	{
		printf("졌습니다.\n");
	}
}


void PrintHand(int hand)
{
	switch (hand)
	{
	case RSP_ROCK:
		printf("▶바위◀\t");
		break;
	case RSP_SCISSOR:
		printf("가위\t");
		break;
	case RSP_PAPER:
		printf("보\t");
		break;
	default:
		printf("UnKnown\t");
		break;
	}
}
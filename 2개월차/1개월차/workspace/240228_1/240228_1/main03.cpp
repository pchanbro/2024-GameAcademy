// main02를 함수 void PrintHand(int hand);추가로 단축시켜보자

// include 선언하는 영역
#include <iostream>

// namespace 선언하는 영역
using namespace std;

// enum 선언하는 영역
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

// 함수 전방선언 하는 영역
// 이런 함수가 있다 라고 알리는 정도
void ChooseMyHand();
void ChooseComHand();
void PrintHands();
void ChooseFinalMyHand();
void ChooseFinalComHand();
void PrintResult();

// 여기서 hand는 매개변수, 알규먼트, 파라미터 등으로 불린다.
void PrintHand(int hand);

// 변수 선언 영역
// 0과 1 외에는 모두 define이나 상수로 변경해주는게 좋습니다.
int _myHand[HAND_END];
int _comHand[HAND_END];
int _myFinalHand = 0;
int _comFinalHand = 0;

void main()
{
	// 함수
	// - 지금까지는 가독성 좋은 용도로만 썼다.
	// 하지만 함수의 '진짜' 용도는
	// 재사용성!!

	//PrintHand(0);
	//PrintHand(1);
	//PrintHand(2);


	// 가위바위보 하나빼기

	// 함수 뒷내용 잠깐씩 사용하면서 설명

	// 가위바위보 하나빼기 수도코드
	// 1. 내가 낼 것 두개를 정한다.
	//		ChooseMyHand()
	// 2. 상대(컴퓨터)가 낼 것 두개를 정한다.
	//		ChooseComHand()
	//	  - 이 때 상대가 낼것은 rand() % 3;
	// 3. 내가 낸 것과 상대가 낸 것을 보여준다.
	//		PrintHands()
	// 4. 내가 최종적으로 낼 것을 고른다.
	//		ChooseFinalMyHand()
	// 5. 상대가 최종적으로 낼 것을 고른다.
	//		ChooseFinalComHand()
	// 6. 승패비교를 한다.
	//		PrintResult()


	// 수도코드 스텝당으로 함수를 짜는게 좋다.
	// - 가독성 측면 때문에
	srand(time(NULL));
	::ChooseMyHand();
	::ChooseComHand();
	::PrintHands();
	::ChooseFinalMyHand();
	::ChooseFinalComHand();
	::PrintResult();

	// 함수 전방선언 
	// - 함수를 main문 위에 잔뜩 써놓으면 main문을 보기 힘듦 
	// - 이를 보완하고자 main앞에 함수를 선언만 하고 나머지 내용은 main문 아래 작성
}

void ChooseMyHand()
{
	// 내 손 두개를 정해준다.
	printf("사용자가 왼손에 낼 것을 골라주세요( 0 : 바위, 1 : 가위, 2 : 보) : ");
	cin >> _myHand[HAND_LEFT];
	printf("사용자가 오른손에 낼 것을 골라주세요( 0 : 바위, 1 : 가위, 2 : 보) : ");
	cin >> _myHand[HAND_RIGHT];
	puts("");
}

void ChooseComHand()
{
	// _comHand[HAND_LEFT]
	// _comHand[HAND_RIGHT] 에 랜덤한 값을 넣어줘야 한다.

	// 배열을 쓰고있는 이상
	// 반복문이랑 같이써주는게 좋다.
	for (int i = 0; i < HAND_END; i++)
	{
		_comHand[i] = rand() % RSP_END; // 가위바위보 랜덤뽑기
	}
}

void PrintHands()
{
	// 내 손과 상대방의 손을 보여준다.
	printf("내가 뽑은 것 : ");
	for (int i = 0; i < HAND_END; i++)
	{
		PrintHand(_myHand[i]);
	}
	puts("");

	printf("컴퓨터가 뽑은 것 : ");
	for (int i = 0; i < HAND_END; i++)
	{
		PrintHand(_comHand[i]);		
	}
	puts("");

	// 위의 두 가지를 합쳐서 반복문으로 나타낸다면

	// 플레이어 2명만큼 반복한다.
	// i = 0 : 플레이어 출력
	// i = 1 : 상대방 출력
	for (int i = 0; i < 2; i++)
	{
		if (i == 0)
		{
			printf("내가 뽑은 것 : ");
		}
		else if (i == 1)
		{
			printf("컴퓨터가 뽑은 것 : ");
		}
		for (int j = 0; j < HAND_END; j++)
		{
			// i -> 플레이어 넘버
			// i = 0 : 플레이어
			// i = 1 : 컴퓨터
			int hand = 0;
			if (i == 0)
			{
				hand = _myHand[j];
			}
			else if (i == 1)
			{
				hand = _comHand[j];
			}
			PrintHand(hand);
		
		}
		puts("");
	}
	puts("");
}

void ChooseFinalMyHand()
{
	printf("내가 최종적으로 고른 손을 선택해주세요 (0: 왼손, 1 : 오른손) : ");
	int choose;
	cin >> choose;

	// _myFinalHand에 값을 넣어준다.
	_myFinalHand = _myHand[choose];

	// 왼손을 고르면
	// _myFinalHand = _myHand[0];
	// 오른손을 고르면
	// _myFinalHand = _myHand[1];
}

void ChooseFinalComHand()
{
	// printf("ChooseFinalComHand\n");

	// _comFinalHand 변수에 최종값을 넣어준다.
	// _comHand[0], _comHand[1] 중에 랜덤으로 하나 넣어준다.
	int random = rand() % HAND_END;
	_comFinalHand = _comHand[random];
}

void PrintResult()
{
	// 상대가 고른것을 보여준다
	printf("내가 최종적으로 선택한 것 : ");
	PrintHand(_myFinalHand);
	printf("\n");

	printf("상대방이 최종적으로 선택한 것 : ");
	PrintHand(_comFinalHand);
	puts("");
	puts("");

	if (
		(_myFinalHand == RSP_ROCK && _comFinalHand == RSP_SCISSOR) ||
		(_myFinalHand == RSP_SCISSOR && _comFinalHand == RSP_PAPER) ||
		(_myFinalHand == RSP_PAPER && _comFinalHand == RSP_ROCK))
	{
		printf("플레이어 승리!!\n");
	}
	else if (
		(_myFinalHand == RSP_ROCK && _comFinalHand == RSP_PAPER) ||
		(_myFinalHand == RSP_SCISSOR && _comFinalHand == RSP_ROCK) ||
		(_myFinalHand == RSP_PAPER && _comFinalHand == RSP_SCISSOR))
	{
		printf("플레이어 패배...\n");
	}
	else
	{
		printf("무승부\n");
	}
}

// 실습, 이 함수를 통해 지금까지 반복적으로 써왔던 부분을 수정해보자
// 여기서 hand는 매개변수, 알규먼트, 파라미터 등으로 불린다.
void PrintHand(int hand)
{
	switch (hand)
	{
	case RSP_ROCK:
		printf("바위\t");
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
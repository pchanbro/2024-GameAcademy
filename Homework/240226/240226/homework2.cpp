// 가위바위보 하나빼기 (배열사용)
#include <iostream>

using namespace std;

enum eHand {
	RCP_HAND_LEFT,
	RCP_HAND_RIGHT,
	RCP_HAND_END
};

enum eRockScissorPaper {
	RCP_ONE_SCISSOR,
	RCP_ONE_ROCK,
	RCP_ONE_PAPER,
	RCP_ONE_END
};


// 1. 게임시작 알림판
void PrintGameStartText()
{
	printf("┌───────────────────────────────────┐\n");
	printf("│  Start RockScissorPaper One out   │\n");
	printf("└───────────────────────────────────┘\n");
	cout << endl;
}

// 2. 내 손 선택
void ChooseMyHand(int* myHand)
{
	cout << "왼손을 선택하세요(0 : 가위, 1 : 바위, 2 : 보) : ";
	cin >> myHand[RCP_HAND_LEFT];
	while((myHand[RCP_HAND_LEFT] != RCP_ONE_ROCK) && (myHand[RCP_HAND_LEFT] != RCP_ONE_SCISSOR) && (myHand[RCP_HAND_LEFT] != RCP_ONE_PAPER))
	{
		cout << "플레이어의 왼손이 잘못 선택되었습니다. 다시 선택하세요.." << endl;
		cin >> myHand[RCP_HAND_LEFT];
	}

	cout << "오른손을 선택하세요(0 : 가위, 1 : 바위, 2 : 보) : ";
	cin >> myHand[RCP_HAND_RIGHT];
	while ((myHand[RCP_HAND_RIGHT] != RCP_ONE_ROCK) && (myHand[RCP_HAND_RIGHT] != RCP_ONE_SCISSOR) && (myHand[RCP_HAND_RIGHT] != RCP_ONE_PAPER))
	{
		cout << "플레이어의 오른손이 잘못 선택되었습니다. 다시 선택하세요.." << endl;
		cin >> myHand[RCP_HAND_RIGHT];
	}
	
}

// 3. 컴퓨터 손 선택
void ChooseComHand(int* comHand)
{
	cout << "컴퓨터가 손을 선택합니다. " << endl;
	comHand[RCP_HAND_LEFT] = rand() % RCP_ONE_END;
	comHand[RCP_HAND_RIGHT] = rand() % RCP_ONE_END;
	cout << endl;
}

// 4. 현재 선택한 손 출력
void PrintHandState(int* myHand, int* comHand)
{
	cout << "플레이어 왼손 : ";
	switch (myHand[RCP_HAND_LEFT])
	{
	case RCP_ONE_SCISSOR:
		cout << "가위" << endl;
		break;
	case RCP_ONE_ROCK:
		cout << "바위" << endl;
		break;
	case RCP_ONE_PAPER:
		cout << "보" << endl;
		break;
	default:
		break;
	}

	cout << "플레이어 오른손 : ";
	switch (myHand[RCP_HAND_RIGHT])
	{
	case RCP_ONE_SCISSOR:
		cout << "가위" << endl;
		break;
	case RCP_ONE_ROCK:
		cout << "바위" << endl;
		break;
	case RCP_ONE_PAPER:
		cout << "보" << endl;
		break;
	default:
		break;
	}

	cout << "컴퓨터 왼손 : ";
	switch (comHand[RCP_HAND_LEFT])
	{
	case RCP_ONE_SCISSOR:
		cout << "가위" << endl;
		break;
	case RCP_ONE_ROCK:
		cout << "바위" << endl;
		break;
	case RCP_ONE_PAPER:
		cout << "보" << endl;
		break;
	default:
		break;
	}

	cout << "컴퓨터 오른손 : ";
	switch (comHand[RCP_HAND_RIGHT])
	{
	case RCP_ONE_SCISSOR:
		cout << "가위" << endl;
		break;
	case RCP_ONE_ROCK:
		cout << "바위" << endl;
		break;
	case RCP_ONE_PAPER:
		cout << "보" << endl;
		break;
	default:
		break;
	}	

	cout << endl;
}

// 5. 하나빼기할 내 손 선택 
int chooseOneOutMyHand(int* myHand)
{
	int choice;
	cout << "손을 선택하세요(0 : 왼손, 1: 오른손) :";
	cin >> choice;

	return myHand[choice];
}

// 6. 하나빼기할 컴퓨터 손 선택 
int chooseOneOutComHand(int* comHand)
{
	cout << "컴퓨터가 손을 선택합니다. " << endl;
	int choice = rand() % RCP_HAND_END;
	cout << endl;

	return comHand[choice];
}

// 7. 최종 결정한 손 출력
void PrintChoosedHand(int choosedMyHand, int choosedComHand)
{
	cout << "플레이어 : ";
	switch (choosedMyHand)
	{
	case RCP_ONE_SCISSOR:
		cout << "가위" << endl;
		break;
	case RCP_ONE_ROCK:
		cout << "바위" << endl;
		break;
	case RCP_ONE_PAPER:
		cout << "보" << endl;
		break;
	default:
		break;
	}

	cout << "컴퓨터 : ";
	switch (choosedComHand)
	{
	case RCP_ONE_SCISSOR:
		cout << "가위" << endl;
		break;
	case RCP_ONE_ROCK:
		cout << "바위" << endl;
		break;
	case RCP_ONE_PAPER:
		cout << "보" << endl;
		break;
	default:
		break;
	}
	cout << endl;
}

// 8. 결과 출력
void ShowResult(int choosedMyHand, int choosedComHand)
{
	cout << "가위바위보 하나빼기 결과 " << endl;
	
	if (((choosedMyHand == RCP_ONE_ROCK) && (choosedComHand == RCP_ONE_SCISSOR)) || ((choosedMyHand == RCP_ONE_SCISSOR) && (choosedComHand == RCP_ONE_PAPER)) || ((choosedMyHand == RCP_ONE_PAPER) && (choosedComHand == RCP_ONE_ROCK)))
	{
		cout << "플레이어 승리!!" << endl;
	} 
	else if (((choosedMyHand == RCP_ONE_ROCK) && (choosedComHand == RCP_ONE_PAPER)) || ((choosedMyHand == RCP_ONE_SCISSOR) && (choosedComHand == RCP_ONE_ROCK)) || ((choosedMyHand == RCP_ONE_PAPER) && (choosedComHand == RCP_ONE_SCISSOR)))
	{
		cout << "플레이어 패배.." << endl;
	}
	else
	{
		cout << "무승부" << endl;
	}
}

void main()
{
	srand(time(NULL));

	// 1. 게임시작 알림판
	PrintGameStartText();

	// 2. 내 손 선택
	int myHand[2] = {};
	ChooseMyHand(myHand);

	// 3. 컴퓨터 손 선택
	int comHand[2] = {};
	ChooseComHand(comHand);

	// 4. 현재 선택한 손 출력
	PrintHandState(myHand, comHand);

	// 5. 하나빼기할 내 손 선택 
	int choosedMyHand = chooseOneOutMyHand(myHand);

	// 6. 하나빼기할 컴퓨터 손 선택 
	int choosedComHand = chooseOneOutComHand(comHand);

	// 7. 최종 결정한 손 출력
	PrintChoosedHand(choosedMyHand, choosedComHand);

	// 8. 결과 출력
	ShowResult(choosedMyHand, choosedComHand);

}
// 5.(심화) 3-4 합친 모드.
// 1. 게임시작하면 게임모드 정하기 (승수로할지, 판수로할지)

#include <iostream>
#include <time.h>

using namespace std;

int _gameMode = 0;
int _round = 1;
int _myHand = 0;
int _comHand = 0;
int _winPoint = 0;
int _losePoint = 0;
int _drawPoint = 0;

enum eRockScissorPaper {
	RSP_ROCK,
	RSP_SCISSOR,
	RSP_PAPER,
	RSP_END
};

enum eGameMode {
	GM_5WIN,
	GM_10ROUND,
	GM_END
};

// 1. 게임모드 선택
void ChooseGameMode()
{
	cout << "게임모드를 선택하세요 (0 : 5승할때까지 반복, 1: 가위바위보 10판) : ";
	cin >> _gameMode;
	if (_gameMode != 0 && _gameMode != 1)
	{
		cout << "게임모드를 잘못 선택하셨습니다. 다시 선택하세요." << endl;
		ChooseGameMode();
	}
}

// 2. 내 손 선택
void ChooseMyHand()
{
	cout << "내 손을 선택하세요( ROCK : 0 , SCISSOR : 1, PAPER : 2) : ";
	cin >> _myHand;
}

// 3. 컴퓨터 손 선택
void ChooseComHand()
{
	cout << "컴퓨터의 손을 선택합니다. " << endl;
	_comHand = rand() % RSP_END;
}

// 4. 선택한 손 출력
void PrintHands()
{
	switch (_myHand)
	{
	case RSP_ROCK:
		cout << "내 손 : ROCK" << endl;
		break;
	case RSP_SCISSOR:
		cout << "내 손 : SCISSOR" << endl;
		break;
	case RSP_PAPER:
		cout << "내 손 : PAPER" << endl;
		break;
	default:
		cout << "잘못 선택하셨습니다." << endl;
		break;
	}

	switch (_comHand)
	{
	case RSP_ROCK:
		cout << "컴퓨터 손 : ROCK" << endl;
		break;
	case RSP_SCISSOR:
		cout << "컴퓨터 손 : SCISSOR" << endl;
		break;
	case RSP_PAPER:
		cout << "컴퓨터 손 : PAPER" << endl;
		break;
	default:
		cout << "잘못 선택하셨습니다." << endl;
		break;
	}
}


// 5. 결과 비교
void ResultRockScissorPaper()
{
	// 5-1 이기면 WIN 출력, WINPOINT + 1
	if ((_myHand == RSP_ROCK && _comHand == RSP_SCISSOR) || (_myHand == RSP_SCISSOR && _comHand == RSP_PAPER) || (_myHand == RSP_PAPER && _comHand == RSP_ROCK))
	{
		cout << "WIN!!" << endl;
		_winPoint++;
	}
	// 5-2 지면 LOSE 출력 
	else if ((_myHand == RSP_ROCK && _comHand == RSP_PAPER) || (_myHand == RSP_SCISSOR && _comHand == RSP_ROCK) || (_myHand == RSP_PAPER && _comHand == RSP_SCISSOR))
	{
		cout << "LOSE..." << endl;
		_losePoint++;
	}
	// 5-3 비기면 DRAW 출력
	else if ((_myHand == RSP_ROCK && _comHand == RSP_ROCK) || (_myHand == RSP_SCISSOR && _comHand == RSP_SCISSOR) || (_myHand == RSP_PAPER && _comHand == RSP_PAPER))
	{
		cout << "DRAW" << endl;
		_drawPoint++;
	}
	// 5-4 잘못 입력한 경우
	else
	{
		cout << "잘못된 입력이 존재합니다. " << endl;
	}

	// 게임모드에 따라 결과르
	switch (_gameMode)
	{
	case GM_5WIN:
		cout << "현재 WINPOINT : " << _winPoint << endl;
		cout << endl;
		break;
	case GM_10ROUND:
		cout << "WIN  : " << _winPoint << endl;
		cout << "LOSE : " << _losePoint << endl;
		cout << "DRAW : " << _drawPoint << endl;
		break;
	}
	
}

// 6. 라운드 갱신
void roundUpdate()
{
	cout << "ROUND " << _round << " 종료" << endl;
	cout << endl;
	_round++;
}

void main()
{

	srand(time(NULL));

	// 1. 게임모드 선택 
	ChooseGameMode();

	while (true)
	{
		// 2. 내 손 선택
		ChooseMyHand();

		// 3. 컴퓨터 손 선택
		ChooseComHand();

		// 4. 선택한 손 출력
		PrintHands();

		// 5. 결과 비교
		// 5-1 이기면 WIN 출력, WINPOINT + 1
		// 5-2 지면 LOSE 출력 
		// 5-3 비기면 DRAW 출력
		ResultRockScissorPaper();

		// 6. 게임 모드에 따라 조건 만족 시 종료
		switch (_gameMode)
		{
		// 6-1. 게임모드 5번 이기기의 경우, WINPOINT가 5가 되면 프로그램 종료
		case GM_5WIN:
			if (_winPoint == 5)
			{
				exit(0);
			}
			break;
		// 6-2. 게임모드 10번 가위바위보의 경우, ROUND 갱신을 해준다.
		// 10ROUND가 끝나면 프로그램 종료
		case GM_10ROUND:
			roundUpdate();
			if (10 < _round)
			{
				exit(0);
			}
			break;
		}		
	}
}
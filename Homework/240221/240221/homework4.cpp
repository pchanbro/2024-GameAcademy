// 4. 가위바위보 만든거
// 10번 반복

#include <iostream>
#include <time.h>

using namespace std;

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

// 1. 내 손 선택
void ChooseMyHand()
{
	cout << "내 손을 선택하세요( ROCK : 0 , SCISSOR : 1, PAPER : 2) : ";
	cin >> _myHand;
}

// 2. 컴퓨터 손 선택
void ChooseComHand()
{
	cout << "컴퓨터의 손을 선택합니다. " << endl;
	_comHand = rand() % RSP_END;
}

// 3. 선택한 손 출력
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


// 4. 결과 비교
void ResultRockScissorPaper()
{
	// 4-1 이기면 WIN 출력, WINPOINT + 1
	if ((_myHand == RSP_ROCK && _comHand == RSP_SCISSOR) || (_myHand == RSP_SCISSOR && _comHand == RSP_PAPER) || (_myHand == RSP_PAPER && _comHand == RSP_ROCK))
	{
		cout << "WIN!!" << endl;
		_winPoint++;
	}
	// 4-2 지면 LOSE 출력 
	else if ((_myHand == RSP_ROCK && _comHand == RSP_PAPER) || (_myHand == RSP_SCISSOR && _comHand == RSP_ROCK) || (_myHand == RSP_PAPER && _comHand == RSP_SCISSOR))
	{
		cout << "LOSE..." << endl;
		_losePoint++;
	}
	// 4-3 비기면 DRAW 출력
	else if ((_myHand == RSP_ROCK && _comHand == RSP_ROCK) || (_myHand == RSP_SCISSOR && _comHand == RSP_SCISSOR) || (_myHand == RSP_PAPER && _comHand == RSP_PAPER))
	{
		cout << "DRAW" << endl;
		_drawPoint++;
	}
	// 4-4 잘못 입력한 경우
	else
	{
		cout << "잘못된 입력이 존재합니다. " << endl;
	}

	cout << "WIN  : " << _winPoint << endl;
	cout << "LOSE : " << _losePoint << endl;
	cout << "DRAW : " << _drawPoint << endl;
}

// 5. 라운드 갱신
void roundUpdate()
{
	cout << "ROUND " << _round << " 종료" << endl;
	cout << endl;
	_round++;
}

void main()
{

	srand(time(NULL));

	while (_round <= 10)
	{
		cout << "ROUND " << _round << endl;
		// 1. 내 손 선택
		ChooseMyHand();

		// 2. 컴퓨터 손 선택
		ChooseComHand();

		// 3. 선택한 손 출력
		PrintHands();

		// 4. 결과 비교
		// 4-1 이기면 WIN 출력, WINPOINT + 1
		// 4-2 지면 LOSE 출력 
		// 4-3 비기면 DRAW 출력
		ResultRockScissorPaper();

		// 5. 라운드 갱신
		roundUpdate();
	}
}
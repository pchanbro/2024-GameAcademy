// 5.(��ȭ) 3-4 ��ģ ���.
// 1. ���ӽ����ϸ� ���Ӹ�� ���ϱ� (�¼�������, �Ǽ�������)

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

// 1. ���Ӹ�� ����
void ChooseGameMode()
{
	cout << "���Ӹ�带 �����ϼ��� (0 : 5���Ҷ����� �ݺ�, 1: ���������� 10��) : ";
	cin >> _gameMode;
	if (_gameMode != 0 && _gameMode != 1)
	{
		cout << "���Ӹ�带 �߸� �����ϼ̽��ϴ�. �ٽ� �����ϼ���." << endl;
		ChooseGameMode();
	}
}

// 2. �� �� ����
void ChooseMyHand()
{
	cout << "�� ���� �����ϼ���( ROCK : 0 , SCISSOR : 1, PAPER : 2) : ";
	cin >> _myHand;
}

// 3. ��ǻ�� �� ����
void ChooseComHand()
{
	cout << "��ǻ���� ���� �����մϴ�. " << endl;
	_comHand = rand() % RSP_END;
}

// 4. ������ �� ���
void PrintHands()
{
	switch (_myHand)
	{
	case RSP_ROCK:
		cout << "�� �� : ROCK" << endl;
		break;
	case RSP_SCISSOR:
		cout << "�� �� : SCISSOR" << endl;
		break;
	case RSP_PAPER:
		cout << "�� �� : PAPER" << endl;
		break;
	default:
		cout << "�߸� �����ϼ̽��ϴ�." << endl;
		break;
	}

	switch (_comHand)
	{
	case RSP_ROCK:
		cout << "��ǻ�� �� : ROCK" << endl;
		break;
	case RSP_SCISSOR:
		cout << "��ǻ�� �� : SCISSOR" << endl;
		break;
	case RSP_PAPER:
		cout << "��ǻ�� �� : PAPER" << endl;
		break;
	default:
		cout << "�߸� �����ϼ̽��ϴ�." << endl;
		break;
	}
}


// 5. ��� ��
void ResultRockScissorPaper()
{
	// 5-1 �̱�� WIN ���, WINPOINT + 1
	if ((_myHand == RSP_ROCK && _comHand == RSP_SCISSOR) || (_myHand == RSP_SCISSOR && _comHand == RSP_PAPER) || (_myHand == RSP_PAPER && _comHand == RSP_ROCK))
	{
		cout << "WIN!!" << endl;
		_winPoint++;
	}
	// 5-2 ���� LOSE ��� 
	else if ((_myHand == RSP_ROCK && _comHand == RSP_PAPER) || (_myHand == RSP_SCISSOR && _comHand == RSP_ROCK) || (_myHand == RSP_PAPER && _comHand == RSP_SCISSOR))
	{
		cout << "LOSE..." << endl;
		_losePoint++;
	}
	// 5-3 ���� DRAW ���
	else if ((_myHand == RSP_ROCK && _comHand == RSP_ROCK) || (_myHand == RSP_SCISSOR && _comHand == RSP_SCISSOR) || (_myHand == RSP_PAPER && _comHand == RSP_PAPER))
	{
		cout << "DRAW" << endl;
		_drawPoint++;
	}
	// 5-4 �߸� �Է��� ���
	else
	{
		cout << "�߸��� �Է��� �����մϴ�. " << endl;
	}

	// ���Ӹ�忡 ���� �����
	switch (_gameMode)
	{
	case GM_5WIN:
		cout << "���� WINPOINT : " << _winPoint << endl;
		cout << endl;
		break;
	case GM_10ROUND:
		cout << "WIN  : " << _winPoint << endl;
		cout << "LOSE : " << _losePoint << endl;
		cout << "DRAW : " << _drawPoint << endl;
		break;
	}
	
}

// 6. ���� ����
void roundUpdate()
{
	cout << "ROUND " << _round << " ����" << endl;
	cout << endl;
	_round++;
}

void main()
{

	srand(time(NULL));

	// 1. ���Ӹ�� ���� 
	ChooseGameMode();

	while (true)
	{
		// 2. �� �� ����
		ChooseMyHand();

		// 3. ��ǻ�� �� ����
		ChooseComHand();

		// 4. ������ �� ���
		PrintHands();

		// 5. ��� ��
		// 5-1 �̱�� WIN ���, WINPOINT + 1
		// 5-2 ���� LOSE ��� 
		// 5-3 ���� DRAW ���
		ResultRockScissorPaper();

		// 6. ���� ��忡 ���� ���� ���� �� ����
		switch (_gameMode)
		{
		// 6-1. ���Ӹ�� 5�� �̱���� ���, WINPOINT�� 5�� �Ǹ� ���α׷� ����
		case GM_5WIN:
			if (_winPoint == 5)
			{
				exit(0);
			}
			break;
		// 6-2. ���Ӹ�� 10�� ������������ ���, ROUND ������ ���ش�.
		// 10ROUND�� ������ ���α׷� ����
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
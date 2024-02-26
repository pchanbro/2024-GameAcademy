// 3. ���������� ����� 
// ���� 5���� ������ �ݺ�

#include <iostream>
#include <time.h>

using namespace std;

int _winPoint = 0;
int _myHand = 0;
int _comHand = 0;

enum eRockScissorPaper {
	RSP_ROCK,
	RSP_SCISSOR,
	RSP_PAPER,
	RSP_END
};

// 1. �� �� ����
void ChooseMyHand()
{
	cout << "�� ���� �����ϼ���( ROCK : 0 , SCISSOR : 1, PAPER : 2) : ";
	cin >> _myHand;
}

// 2. ��ǻ�� �� ����
void ChooseComHand()
{
	cout << "��ǻ���� ���� �����մϴ�. " << endl;
	_comHand = rand() % RSP_END;
}

// 3. ������ �� ���
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


// 4. ��� ��
void ResultRockScissorPaper()
{
	// 4-1 �̱�� WIN ���, WINPOINT + 1
	if ((_myHand == RSP_ROCK && _comHand == RSP_SCISSOR) || (_myHand == RSP_SCISSOR && _comHand == RSP_PAPER) || (_myHand == RSP_PAPER && _comHand == RSP_ROCK))
	{
		cout << "WIN!!" << endl;
		_winPoint++;
	}
	// 4-2 ���� LOSE ��� 
	else if ((_myHand == RSP_ROCK && _comHand == RSP_PAPER) || (_myHand == RSP_SCISSOR && _comHand == RSP_ROCK) || (_myHand == RSP_PAPER && _comHand == RSP_SCISSOR))
	{
		cout << "LOSE..." << endl;
	}
	// 4-3 ���� DRAW ���
	else if ((_myHand == RSP_ROCK && _comHand == RSP_ROCK) || (_myHand == RSP_SCISSOR && _comHand == RSP_SCISSOR) || (_myHand == RSP_PAPER && _comHand == RSP_PAPER))
	{
		cout << "DRAW" << endl;
	}
	// 4-4 �߸� �Է��� ���
	else
	{
		cout << "�߸��� �Է��� �����մϴ�. " << endl;
	}

	cout << "���� WINPOINT : " << _winPoint << endl;
}

void main()
{	
	
	srand(time(NULL));
	
	while (_winPoint < 5)
	{
		// 1. �� �� ����
		ChooseMyHand();

		// 2. ��ǻ�� �� ����
		ChooseComHand();

		// 3. ������ �� ���
		PrintHands();

		// 4. ��� ��
		// 4-1 �̱�� WIN ���, WINPOINT + 1
		// 4-2 ���� LOSE ��� 
		// 4-3 ���� DRAW ���
		ResultRockScissorPaper();
	}
}
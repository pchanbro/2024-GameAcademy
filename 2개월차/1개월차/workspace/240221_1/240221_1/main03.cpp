#include <iostream>
#include <time.h>

using namespace std;

enum eRockScissorPaper
{
	RSP_ROCK,
	RSP_SCISSOR,
	RSP_PAPER,
	RSP_END
};

// ���� ����
// ���⼭ �����ϴ� ������ (_�ҹ���) �� ����
int _myHand = 0; // ����
int _comHand = 0; // ���� ��


// �Լ� ����
// main�Լ� ���� �����ؾ� �Ѵ�.
// �Լ����� �빮�ڷ� �����ؾ� �Ѵ�.


// 1. ���� ����ȭ���� ����Ѵ�. (PrintGameStartScene)
void PrintGameStartScece()
{
	printf("��������������������������������������������������������������������������������\n");
	printf("��    Rock Scissor Paper Game Start     ��\n");
	printf("��������������������������������������������������������������������������������\n");
}

// 2. ���� ��� ������ �����Ѵ�. (ChooseMyHand)
void ChooseMyHand()
{
	cout << "���� (0) ����(1) ��(2) �߿� �ϳ��� �̾��ּ��� : ";
	cin >> _myHand;
}


// 3. ������ ��� ������ �����Ѵ�. (ChooseComHand) (����Ұ� ����) (�������) 
void ChooseComHand()
{
	cout << "��ǻ�Ͱ� ���� �����մϴ�. " << endl;
	_comHand = rand() % RSP_END;
}


// 4. ���� �����Ͱ� ������ �������� ����Ѵ�. (PrintHands)
void PrintHands()
{
	cout << endl;
	switch (_myHand)
	{
	case RSP_ROCK:
		cout << "�� �� : ���� " << endl;
		break;
	case RSP_SCISSOR:
		cout << "�� �� : ���� " << endl;
		break;
	case RSP_PAPER:
		cout << "�� �� : �� " << endl;
		break;
	default:
		cout << "�÷��̾ �߸� �����ϼ̽��ϴ�. " << endl;
	}

	switch (_comHand)
	{
	case RSP_ROCK:
		cout << "��ǻ�� �� : ���� " << endl;
		break;
	case RSP_SCISSOR:
		cout << "��ǻ�� �� : ���� " << endl;
		break;
	case RSP_PAPER:
		cout << "��ǻ�� �� : �� " << endl;
		break;
	default:
		cout << "��ǻ�Ͱ� �߸� �����Ͽ����ϴ�. " << endl;
	}
}


// 5. ���и� ����Ѵ�. (PrintGameResult)
void PrintGameResult()
{
	puts("");
	if (_myHand == RSP_ROCK && _comHand == RSP_SCISSOR || _myHand == RSP_SCISSOR && _comHand == RSP_PAPER || _myHand == RSP_PAPER && _comHand == RSP_ROCK)
	{
		cout << "�÷��̾��� �¸�!" << endl;
	}
	else if (_myHand == RSP_ROCK && _comHand == RSP_PAPER || _myHand == RSP_SCISSOR && _comHand == RSP_ROCK || _myHand == RSP_PAPER && _comHand == RSP_SCISSOR)
	{
		cout << "�÷��̾��� �й�..." << endl;
	}
	else
	{
		cout << "�÷��̾�� ��ǻ�Ͱ� �����ϴ�." << endl;
	}
}

void main()
{
	// �Լ� (������ main�Լ� ���� �����ؾ� �Ѵ�. => C/C++ ���α׷��� �׻� ������ �Ʒ��� �дµ� �ٸ��Լ��� main�Լ� �Ʒ� ������ main������ ���� �߿� �ٸ� �Լ��ν��� ����)
	// ����
	// void �Լ���()
	// {
	//		�����ų �ڵ�
	// }


	// ���α׷��ֿ��� ���� �߿��� ���� "������" �׷��� ���� ���������� ���������� ���� �����ϰ� �� �� �ִ�. �׷��� �Լ��� ����Ѵ�.
	// main�� �ִ��� ������ ���ַ�!!

	// �׸��� ������ ����� ���� "�����ڵ�"�� �ۼ��ض�

	// �����ڵ� (������ �ᰡ�� �����ϴ� ���α׷��Ӱ� �Ǿ��)
	// 
	// 1. ���� ����ȭ���� ����Ѵ�. (PrintGameStartScene)
	// 2. ���� ��� ������ �����Ѵ�. (ChooseMyHand)
	// 3. ������ ��� ������ �����Ѵ�. (ChooseComHand) (����Ұ� ����) (�������) 
	// 4. ���� �����Ͱ� ������ �������� ����Ѵ�. (PrintHands)
	// 5. ���и� ����Ѵ�. (PrintGameResult)

	srand(time(NULL));
	::PrintGameStartScece();
	::ChooseMyHand();
	::ChooseComHand();
	::PrintHands();
	::PrintGameResult();
}
// main02�� �Լ� void PrintHand(int hand);�߰��� ������Ѻ���

// include �����ϴ� ����
#include <iostream>

// namespace �����ϴ� ����
using namespace std;

// enum �����ϴ� ����
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

// �Լ� ���漱�� �ϴ� ����
// �̷� �Լ��� �ִ� ��� �˸��� ����
void ChooseMyHand();
void ChooseComHand();
void PrintHands();
void ChooseFinalMyHand();
void ChooseFinalComHand();
void PrintResult();

// ���⼭ hand�� �Ű�����, �˱Ը�Ʈ, �Ķ���� ������ �Ҹ���.
void PrintHand(int hand);

// ���� ���� ����
// 0�� 1 �ܿ��� ��� define�̳� ����� �������ִ°� �����ϴ�.
int _myHand[HAND_END];
int _comHand[HAND_END];
int _myFinalHand = 0;
int _comFinalHand = 0;

void main()
{
	// �Լ�
	// - ���ݱ����� ������ ���� �뵵�θ� ���.
	// ������ �Լ��� '��¥' �뵵��
	// ���뼺!!

	//PrintHand(0);
	//PrintHand(1);
	//PrintHand(2);


	// ���������� �ϳ�����

	// �Լ� �޳��� ��� ����ϸ鼭 ����

	// ���������� �ϳ����� �����ڵ�
	// 1. ���� �� �� �ΰ��� ���Ѵ�.
	//		ChooseMyHand()
	// 2. ���(��ǻ��)�� �� �� �ΰ��� ���Ѵ�.
	//		ChooseComHand()
	//	  - �� �� ��밡 ������ rand() % 3;
	// 3. ���� �� �Ͱ� ��밡 �� ���� �����ش�.
	//		PrintHands()
	// 4. ���� ���������� �� ���� ����.
	//		ChooseFinalMyHand()
	// 5. ��밡 ���������� �� ���� ����.
	//		ChooseFinalComHand()
	// 6. ���к񱳸� �Ѵ�.
	//		PrintResult()


	// �����ڵ� ���ܴ����� �Լ��� ¥�°� ����.
	// - ������ ���� ������
	srand(time(NULL));
	::ChooseMyHand();
	::ChooseComHand();
	::PrintHands();
	::ChooseFinalMyHand();
	::ChooseFinalComHand();
	::PrintResult();

	// �Լ� ���漱�� 
	// - �Լ��� main�� ���� �ܶ� ������� main���� ���� ���� 
	// - �̸� �����ϰ��� main�տ� �Լ��� ���� �ϰ� ������ ������ main�� �Ʒ� �ۼ�
}

void ChooseMyHand()
{
	// �� �� �ΰ��� �����ش�.
	printf("����ڰ� �޼տ� �� ���� ����ּ���( 0 : ����, 1 : ����, 2 : ��) : ");
	cin >> _myHand[HAND_LEFT];
	printf("����ڰ� �����տ� �� ���� ����ּ���( 0 : ����, 1 : ����, 2 : ��) : ");
	cin >> _myHand[HAND_RIGHT];
	puts("");
}

void ChooseComHand()
{
	// _comHand[HAND_LEFT]
	// _comHand[HAND_RIGHT] �� ������ ���� �־���� �Ѵ�.

	// �迭�� �����ִ� �̻�
	// �ݺ����̶� ���̽��ִ°� ����.
	for (int i = 0; i < HAND_END; i++)
	{
		_comHand[i] = rand() % RSP_END; // ���������� �����̱�
	}
}

void PrintHands()
{
	// �� �հ� ������ ���� �����ش�.
	printf("���� ���� �� : ");
	for (int i = 0; i < HAND_END; i++)
	{
		PrintHand(_myHand[i]);
	}
	puts("");

	printf("��ǻ�Ͱ� ���� �� : ");
	for (int i = 0; i < HAND_END; i++)
	{
		PrintHand(_comHand[i]);		
	}
	puts("");

	// ���� �� ������ ���ļ� �ݺ������� ��Ÿ���ٸ�

	// �÷��̾� 2��ŭ �ݺ��Ѵ�.
	// i = 0 : �÷��̾� ���
	// i = 1 : ���� ���
	for (int i = 0; i < 2; i++)
	{
		if (i == 0)
		{
			printf("���� ���� �� : ");
		}
		else if (i == 1)
		{
			printf("��ǻ�Ͱ� ���� �� : ");
		}
		for (int j = 0; j < HAND_END; j++)
		{
			// i -> �÷��̾� �ѹ�
			// i = 0 : �÷��̾�
			// i = 1 : ��ǻ��
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
	printf("���� ���������� �� ���� �������ּ��� (0: �޼�, 1 : ������) : ");
	int choose;
	cin >> choose;

	// _myFinalHand�� ���� �־��ش�.
	_myFinalHand = _myHand[choose];

	// �޼��� ����
	// _myFinalHand = _myHand[0];
	// �������� ����
	// _myFinalHand = _myHand[1];
}

void ChooseFinalComHand()
{
	// printf("ChooseFinalComHand\n");

	// _comFinalHand ������ �������� �־��ش�.
	// _comHand[0], _comHand[1] �߿� �������� �ϳ� �־��ش�.
	int random = rand() % HAND_END;
	_comFinalHand = _comHand[random];
}

void PrintResult()
{
	// ��밡 ������ �����ش�
	printf("���� ���������� ������ �� : ");
	PrintHand(_myFinalHand);
	printf("\n");

	printf("������ ���������� ������ �� : ");
	PrintHand(_comFinalHand);
	puts("");
	puts("");

	if (
		(_myFinalHand == RSP_ROCK && _comFinalHand == RSP_SCISSOR) ||
		(_myFinalHand == RSP_SCISSOR && _comFinalHand == RSP_PAPER) ||
		(_myFinalHand == RSP_PAPER && _comFinalHand == RSP_ROCK))
	{
		printf("�÷��̾� �¸�!!\n");
	}
	else if (
		(_myFinalHand == RSP_ROCK && _comFinalHand == RSP_PAPER) ||
		(_myFinalHand == RSP_SCISSOR && _comFinalHand == RSP_ROCK) ||
		(_myFinalHand == RSP_PAPER && _comFinalHand == RSP_SCISSOR))
	{
		printf("�÷��̾� �й�...\n");
	}
	else
	{
		printf("���º�\n");
	}
}

// �ǽ�, �� �Լ��� ���� ���ݱ��� �ݺ������� ��Դ� �κ��� �����غ���
// ���⼭ hand�� �Ű�����, �˱Ը�Ʈ, �Ķ���� ������ �Ҹ���.
void PrintHand(int hand)
{
	switch (hand)
	{
	case RSP_ROCK:
		printf("����\t");
		break;
	case RSP_SCISSOR:
		printf("����\t");
		break;
	case RSP_PAPER:
		printf("��\t");
		break;
	default:
		printf("UnKnown\t");
		break;
	}
}
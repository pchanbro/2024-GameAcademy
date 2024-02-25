#include <iostream>
#include <time.h>
using namespace std;

//���� �����ϴ� ��
int _temp = 0;
int _myHand = 0;
int _comHand = 0;

//�Լ� �����ϴ� ��
void PrintGameStartMessage()
{
	printf("��������������������������������������������������������������������������������������\n");
	printf("��             Game Start!                 ��\n");
	printf("��           Rock Scissor Paper!           ��\n");
	printf("��������������������������������������������������������������������������������������\n");
}

void ChooseMyHand()
{
	printf("��������������������������������������������������������������������������������������\n");
	printf("��  Choose My Hand!                        ��\n");
	printf("��   Rock(0) Scissor(1) Paper(2)           ��\n");
	printf("��������������������������������������������������������������������������������������\n");
	cin >> _myHand;
}

void ChooseComHand()
{
	_comHand = rand() % 3;	// 0 ~ 2 ������ ������ ���ϱ� ���ؼ�
}

void PrintHands()
{
	cout << "myHand : " << _myHand << endl;
	cout << "_comHand : " << _comHand << endl;

	cout << "���� �� �� : ";
	switch (_myHand)
	{
	case 0:
		cout << "����" << endl;
		break;
	case 1:
		cout << "����" << endl;
		break;
	case 2:
		cout << "��" << endl;
		break;
	default:
		cout << "[�ý��� ���� : -10001] �߸��� ���Դϴ�." << endl;
		break;
	}

	cout << "��밡 �� �� : ";
	switch (_comHand)
	{
	case 0:
		cout << "����" << endl;
		break;
	case 1:
		cout << "����" << endl;
		break;
	case 2:
		cout << "��" << endl;
		break;
	default:
		cout << "[�ý��� ���� : -10001] �߸��� ���Դϴ�." << endl;
		break;
	}
}

void PrintDrawMessage()
{
	printf("��������������������������������������������������������������������������������������\n");
	printf("��  Draw !!!!!!!!!!                        ��\n");
	printf("��������������������������������������������������������������������������������������\n");
}

void PrintLoseMessage()
{
	printf("��������������������������������������������������������������������������������������\n");
	printf("��  Lose !!!!!!!!!!                        ��\n");
	printf("��������������������������������������������������������������������������������������\n");
}

void PrintWinMessage()
{
	printf("��������������������������������������������������������������������������������������\n");
	printf("��  WIN!!!!!!!!!!!!                        ��\n");
	printf("��������������������������������������������������������������������������������������\n");
}

void PrintGameResultMessage()
{
	// - ������� 
	//		- �����ϴٸ� ����Ѵ�.
	// - �̰�����
	//		- �̰���ϴٸ� ����Ѵ�.
	// - ������
	//		- �����ϴٸ� ����Ѵ�.

	// ��κ��� ��ȹ�� ������ 
	// �� �״�� �ڵ�� ��ȯ
	// �������ڵ忡���� ������!!
	//		=> �������ڵ忡�� ���� �߿��Ѱ� ���꼺
	//			=> ���꼺 : �ڵ尡���� + ����������

	//�������
	if (_comHand == _myHand)
	{
		::PrintDrawMessage();
	}
	//������
	else if ((_comHand == 0 && _myHand == 1) ||
		(_comHand == 1 && _myHand == 2) ||
		(_comHand == 2 && _myHand == 0))
	{
		::PrintLoseMessage();
	}
	//�̰�����
	else
	{
		::PrintWinMessage();
	}
}

void main() 
{
	//����Ǯ��.
	//1. ����������
	// - ���� ���� �޽����� ����Ѵ�.
	//  PrintGameStartMessage()
	// - ���� ������ ���Ѵ�
	//  ChooseMyHand();
	// - ��ǻ�Ͱ� ������ ���Ѵ�.
	//  ChooseComHand();
	// - ���� ���Ͱ� ��ǻ�Ͱ� ������ ����Ѵ�.
	//  PrintHands();
	//  PrintGameResultMessage();

	srand(time(NULL));

	::PrintGameStartMessage();
	::ChooseMyHand();
	::ChooseComHand();
	::PrintHands();
	::PrintGameResultMessage();
	
}
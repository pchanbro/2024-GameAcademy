#include <iostream>
using namespace std;

enum eChampionName {
	CN_GAREN = 100,	// 0���� �����ϱ� ���� ���.
	CN_GANGPLANK,
	CN_GALIO,

	//������ ���� �׷��� ������ ����.



	CN_END
};

enum eErrorCode {
	ERR_NETWORK = -100001, //���� �ڵ� : ��Ʈ��ũ �����Դϴ�. �ٽýõ����ּ��� ���
};

void main()
{
	//enum
	// ���ο� �ڷ���

	//���� ���� ����
	//�ڷ��� ������;
	//�ڷ��� ������ = ��;
	//int - ������
	//enum - ������ (������ ǥ��)
	//enum : ���� �̸��� �����ټ��ִ�.


	int myChampion = CN_GAREN;	// 0 - ����, 1 - ���÷�ũ, 2 - ������
	//���꼺�� �ʹ� �������ϴ�.

	if (myChampion == CN_GAREN)
	{
		//dfasf
	}
	else if (myChampion == CN_GANGPLANK)
	{
		//asdfsa
	}

	//�ڵ� �������� ���� ��� (�������� ���� ����)


	//�ڷ���
	//int
	//enum (�츮�� �ڷ����� ���Ӱ� ����ڴ�.)

	//int ������ = ��;
	eChampionName ������ = CN_GAREN; // (���߿� ������ ��찡 ����..)
	//�׷��� ����� ���� int ������ ��Ƽ� ����Ѵ�..



	// enum Ȱ��
	// (enum + switch)���� ȿ���� ���������ϴ�.
	switch (������)
	{
	case CN_GAREN:
		cout << "������ �����Դϴ�." << endl;
		break;
	case CN_GANGPLANK:
		cout << "������ ���÷�ũ�Դϴ�." << endl;
		break;
	case CN_GALIO:
		cout << "������ �������Դϴ�." << endl;
		break;
	default:
		break;
	}
}
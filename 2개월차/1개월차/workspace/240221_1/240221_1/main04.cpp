#include <iostream>
 
using namespace std;

enum eChampionName {
	CN_GAREN,
	CN_GALIO,
	CN_GANGPLANK

	//������ ���� �������� �ʴ´�.
};

// ������ �̷����� ���� �����ؼ� ����Ѵ�
// ������ ���ڷ� Ư�� ������ ǥ���� ��, ���� �����Ͽ� ����Ѵ�.
enum eErrorCode {
	ERR_NETWORK = -100001, //���� �ڵ� : ��Ʈ��ũ �����Դϴ�. �ٽýõ����ּ��� ���
};


void main()
{
	// enum
	// ���ο� �ڷ���
	// �ڵ� �������� ���� ��� (�������� ���� ����)

	// ���� ���� ����
	// �ڷ��� ������;
	// �ڷ��� ������ = ��;
	// int - ������
	// enum - ������ (������ ǥ��)


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

	// �ڵ� �������� ���� ��� (�������� ���� ����)

	
	// �ڷ��� 
	// int
	// enum (�츮�� �ڷ����� ���Ӱ� ����ڴ�.)

	//int ������ = ��;
	eChampionName ������ = CN_GAREN; // (���߿� ������ ��찡 ����..)
	// �׷��� ����� ���� int ������ ��Ƽ� ����Ѵ�..


	// enum Ȱ��
	// (enum + switch)���� ȿ���� ���� ����.
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
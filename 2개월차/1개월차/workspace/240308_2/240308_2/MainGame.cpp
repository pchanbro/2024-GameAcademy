#include "MainGame.h"
#include <iostream>

using namespace std;

MainGame::MainGame()
{
	printf("���ΰ��� ������\n");
	// ���⸦ void main() �̶� �����ϰ� �ڵ��ϸ� �ȴ�.

	// ���������� ���??
	// �Լ��� ���??


	// 1. �������� �ϴ¹�
	// ������Ϸ� ����
	// int _money = 1000;		// _�� Ŭ���� ���������� �������� ���´�.

	this->_money = 1000; // �� �� ����
	_money = 1000;

	// �Լ� ���� �ϴ� ��
}

MainGame::~MainGame()
{
	printf("�������ּ��� :");
	cin >> this->_betMoney;
}
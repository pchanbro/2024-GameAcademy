#include "MainGame.h"
#include <iostream>
#include "Card.h"
using namespace std;

MainGame::MainGame()
{
	printf("���ΰ��� ������\n");

	//���⸦ void main() �̶� �����ϰ� �ڵ��Ͻø� �˴ϴ�!!

	// ���������� ���?
	// �Լ��� ���??


	// 1. �������� �ϴ¹�
	//   ������Ϸ� ����
	//   int _money = 1000;		//_�� Ŭ���� ���������� �������� �����ϴ�.


	this->_money = 1000;	//�ΰ� ����
	_money = 1000;


	// 2. �Լ� ���� �ϴ� ��
	this->Bet();

}

void MainGame::Bet()
{
	printf("�������ּ��� : ");
	cin >> this->_betMoney;
}


MainGame::~MainGame()
{
	printf("���ΰ��� �Ҹ���\n");
}
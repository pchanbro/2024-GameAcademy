#include "MainGame.h"
#include <iostream>

using namespace std;

MainGame::MainGame()
{
	printf("메인게임 생성자\n");
	// 여기를 void main() 이라 생각하고 코딩하면 된다.

	// 변수선언은 어떻게??
	// 함수는 어떻게??


	// 1. 변수선언 하는법
	// 헤더파일로 가서
	// int _money = 1000;		// _는 클래스 멤버변수라는 컨벤션을 갖는다.

	this->_money = 1000; // 두 개 같음
	_money = 1000;

	// 함수 선언 하는 법
}

MainGame::~MainGame()
{
	printf("베팅해주세요 :");
	cin >> this->_betMoney;
}
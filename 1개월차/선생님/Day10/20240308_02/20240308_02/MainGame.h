#pragma once
class MainGame
{
private:
	int _money = 1000;
	int _betMoney = 0;

public:
	MainGame();		// ������		new�Ҷ� ����˴ϴ�. (���� ����1��)
	~MainGame();	// �Ҹ���		delete�Ҷ� ����˴ϴ�. (���� ����1��)

	void Bet();

};


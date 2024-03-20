#pragma once
class MainGame
{
private:
	int _money = 1000;
	int _betMoney = 0;

public:
	MainGame();		// 생성자		new할때 실행됩니다. (생애 최초1번)
	~MainGame();	// 소멸자		delete할때 실행됩니다. (생애 최초1번)

	void Bet();

};


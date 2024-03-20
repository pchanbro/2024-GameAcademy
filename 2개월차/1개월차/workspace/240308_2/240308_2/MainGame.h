#pragma once
class MainGame
{
private:// 변수는 왠만하면 private
	int _money = 1000; // 클래스 멤버변수는 전역변수와 같이 '_이름'으로 한다
	int _betMoney = 0;
public:
	MainGame();		// 생성자		new 할 때 실행된다. (생에 최초 1번)
	~MainGame();	// 소멸자		delete 할 때 실행된다. (생에 최초 1번)

	void Bet();
	
};


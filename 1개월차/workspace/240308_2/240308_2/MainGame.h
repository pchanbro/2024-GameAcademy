#pragma once
class MainGame
{
private:// ������ �ظ��ϸ� private
	int _money = 1000; // Ŭ���� ��������� ���������� ���� '_�̸�'���� �Ѵ�
	int _betMoney = 0;
public:
	MainGame();		// ������		new �� �� ����ȴ�. (���� ���� 1��)
	~MainGame();	// �Ҹ���		delete �� �� ����ȴ�. (���� ���� 1��)

	void Bet();
	
};


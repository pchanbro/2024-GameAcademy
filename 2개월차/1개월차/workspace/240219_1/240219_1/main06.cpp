#include <iostream>

using namespace std;

int _attack = 4;
int _hp = 100;
int _moveCount = 0;
int _x = 0;
int _y = 0;
int _monsterHp = 0;
int _monsterAttack = 0;


int _input;
void BattleMonster()
{
	cout << "���Ϳ� �����ƽ��ϴ�. " << endl;
	//����
	_monsterHp = 3;
	_monsterAttack = 2;

	// while (����) 
	// {
	//		������ �����ϴ� ���� ����Ǵ� �ڵ�
	// }
	
	// �� �� ����ִ� ���� �ݺ�
	while (_monsterHp > 0 && _hp > 0)
	{
		cout << "���͸� �����߽��ϴ�. " << endl;
		_monsterHp -= _attack;
		cout << "���� ���� ü�� : " << _monsterHp <<  endl;

		cout << "���ظ� �Ծ����ϴ�. " << endl;
		_hp -= _monsterAttack;
		cout << "�� ���� ü�� : " << _hp << endl;
	}
}

void MovePlayer()
{
	cout << "�÷��̾ ������ ������ ����ּ��� (0 : ��, 1 : ��, 2 : ��, 3 : ��)" << endl;
	cin >> _input;



}

void main()
{
	cout << "������ ���۵Ǿ����ϴ�." << endl;

	// �÷��̾ �����δ�. 
	// �÷��̾ ������ ���� �� �� ä���ֱ�
	while (_moveCount < 5)
	{
		MovePlayer();
		BattleMonster();
	}

}
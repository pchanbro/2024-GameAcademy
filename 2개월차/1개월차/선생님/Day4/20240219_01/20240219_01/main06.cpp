#include <iostream>
using namespace std;

int _attack = 4;
int _hp = 100;
int _x = 0;
int _y = 0;
int _monsterHp = 0;
int _monsterAttack = 0;
int _input;
int _moveCount = 0;
void BattleMonster()
{
	cout << "���Ϳ� �����ƽ��ϴ�." << endl;
	_monsterHp = 3;
	_monsterAttack = 2;

	//~~�� �ݺ��Ѵ�.
	//while( ���� )
	//{
	//}
	
	//�Ѵ� ����ִ� ���� �ݺ�
	while (_monsterHp > 0 && _hp > 0)
	{
		cout << "���͸� �����߽��ϴ�. " << endl;
		_monsterHp = _monsterHp - _attack;
		cout << "���� ���� ü�� : " << _monsterHp << endl;

		cout << "���ظ� �Ծ����ϴ�." << endl;
		_hp = _hp - _monsterAttack;
		cout << "�� ���� ü�� : " << _hp << endl;
	}
}

void MovePlayer()
{
	cout << "�÷��̾ ������ ������ ����ּ��� (0 : ��, 1: ��, 2: ��, 3: ��)" << endl;
	cin >> _input;

	//���� �Է�
	_y--;
	cout << "������ġ : ( X : 3, Y : 1)" << endl;
	_moveCount++;
}

void main()
{
	cout << "������ ���۵Ǿ����ϴ�." << endl;

	//�÷��̾ �����δ�.
	//�÷��̾������� ���ӳ�
	while (_moveCount < 5)
	{
		MovePlayer();
		BattleMonster();
	}



	//����2.
	//TEXT RPG �����
	// ATTACK, HP, X(0), Y(0) �� �ְ�
	// 
	//1. ������ �����ϸ�
	//   (�����¿�)�� �̵��Ҽ��ִ�.
	//2. ��ĭ �����϶����� �濡 �����Ѵ�
	//3. �濡���� ���Ϳ� ����ġ�µ�,
	//4. ������ ���ݷ��� 1 ~ 10���� , HP�� 5~10 ���̴�. (�濡 ���� �̶� ������ ���ݷ°� ü���� ����)
	//5. ���Ϳ� ���� �Ѵ뾿 ������
	//6. ���Ͱ� ������ �ٸ������� �̵��� ���ִ�.
	//7. ���� 5�� �����̰ų�
	//8. X(1), Y(1) ���� �������̴�
	//9. ������ �ɷ�ġ�� HP 50, ATTACK : 20
	//10. X(2), Y(1) ������ ���� ������ Ŭ����ȴ�.
	//11. ������ ���� ������ ������ ������.
}
#include <iostream>
#include <time.h>

using namespace std;

int _attack = 15;
int _hp = 100;
int _moveCount = 0;
int _x = 0;
int _y = 0;
int _monsterHp = 0;
int _monsterAttack = 0;

//	1. (�� �� �� ��)�� �̵�
void MoveCharacter()
{
	int move;
	cout << endl;
	cout << "���� ��ġ : " << _x << ", " << _y << endl;
	cout << "�̵��� ������ ������(�� : 0, �� : 1, �� : 2, �� : 3) : ";
	cin >> move;

	puts("");

	switch (move)
	{
	case 0:
		cout << "�������� 1��ŭ �̵��մϴ�. " << endl;
		_x++;
		_moveCount++;
		cout << "���� ��ġ : " << _x << ", " << _y << endl;
		break;
	case 1:
		cout << "�������� 1��ŭ �̵��մϴ�. " << endl;
		_x--;
		_moveCount++;
		cout << "���� ��ġ : " << _x << ", " << _y << endl;
		break;
	case 2:
		cout << "�������� 1��ŭ �̵��մϴ�. " << endl;
		_y--;
		_moveCount++;
		cout << "���� ��ġ : " << _x << ", " << _y << endl;
		break;
	case 3:
		cout << "�������� 1��ŭ �̵��մϴ�. " << endl;
		_y++;
		_moveCount++;
		cout << "���� ��ġ : " << _x << ", " << _y << endl;
		break;
	default:
		cout << "�߸��� �����Դϴ�. �ٽ� �����ϼ���." << endl;
		MoveCharacter();
	}
}

// 2. �� ĭ �����϶����� �濡 �����Ѵ�
// 3. �濡���� ���Ϳ� ����ġ�µ�
// 4. ������ ���ݷ��� 1 ~ 10 , HP�� 5 ~ 10 �̴�. (�濡 �������� �� ������ ���ݷ°� ü���� ����)
void EnterMonerterRoom()
{
	_monsterHp = rand() % 10 + 1;
	_monsterAttack = rand() % 6 + 5;
}

// 9. X(1), Y(1)�� ������
// 10. ������ �ɷ�ġ�� HP : 50, ATTACK : 20
void EnterBossMonsterRoom()
{
	_monsterHp = 50;
	_monsterAttack = 20;
}

// 5. ���Ϳ� ���� �� �뾿 ������.
// 6. ���Ͱ� ������ �ٸ������� �̵��� �� �ִ�.
void BattleMonster()
{
	puts("");

	while (_monsterHp >= 0 && _hp >= 0)
	{
		cout << "�÷��̾��� ����!" << endl;
		_monsterHp -= _attack;
		cout << "������ HP : " << _monsterHp << endl;

		puts("");

		cout << "������ ����!" << endl;
		_hp -= _monsterAttack;
		cout << "�÷��̾��� HP : " << _hp << endl;

		puts("");
	}
	cout << "���� ���� " << endl;
}

// 7. ���� 5�� �����̰ų�
// 8. X(2), Y(1) ������ ���� ������ Ŭ����ȴ�.
// 11. ���� Ŭ���� ���� ���� ������ ������ ������. 
void IsClear()
{
	if (_hp <= 0)
	{
		cout << "�÷��̾� �й�..." << endl;
	}
	else
	{
		cout << "���� Ŭ����!" << endl;
	}

	puts("");

	cout << "���" << endl;
	cout << "�÷��̾� HP : " << _hp << endl;
	cout << "�÷��̾� ��ġ : " << _x << ", " << _y << endl;
	cout << "MoveCount : " << _moveCount << endl;
}

void main()
{

	// ����
	// TEXT RPG �����
	// ATTACK, HP, X(0), Y(0)�� �ְ� 

	srand(time(NULL));

	// ���� ����
	printf("����������������������������������������������������������\n");
	printf("��    Text Rpg Game Start    ��\n");
	printf("����������������������������������������������������������\n");

	// 7. ���� 5�� �����̰ų�
	// 8. X(2), Y(1) ������ ���� ������ Ŭ����ȴ�.
	// 11. ���� Ŭ���� ���� ���� ������ ������ ������. 
	while (5 > _moveCount && _hp >= 0 && !(_x == 2 && _y == 1))
	{
		MoveCharacter();

		if (_x == 1 && _y == 1)
		{
			EnterBossMonsterRoom();
		}
		else
		{
			EnterMonerterRoom();
		}

		BattleMonster();
	}

	IsClear();
}

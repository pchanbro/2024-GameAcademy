#include <iostream>
#include <time.h>

using namespace std;

// ���� �ǵ�� 3����
// 1. ó�� ���� ����� �ڵ带 ������ �� �ֵ��� �ڵ带 �����Ѵ�.
// 2. ���� �ε�ȣ�� < �� ���� ���� ����, ������ �����ʺ��� �۴ٰ� �ν��Ѵ�.
// 3. while���� ������ Is���ñ�� �ؼ� return ���� ���� �ݺ����� �������� �����ִ°� ����.


int _attack = 15;
int _hp = 100;
int _moveCount = 0;
int _x = 0;
int _y = 0;
int _monsterHp = 0;
int _monsterAttack = 0;

enum eDirection {
	DIR_EAST,
	DIR_WEST,
	DIR_SOUTH,
	DIR_NORTH,
	DIR_END
};

void PrintGameStartMessage()
{
	printf("����������������������������������������������������������\n");
	printf("��    Text Rpg Game Start    ��\n");
	printf("����������������������������������������������������������\n");
}

// ������ ��� ����Ǵ��� ���θ� �Ǵ��ϴ� �Լ� 
// 7. ���� 5�� �����̰ų�
// 8. X(2), Y(1) ������ ���� ������ Ŭ����ȴ�. IsGoalPoint()�� ���� ���� Ȯ��
// 11. ���� Ŭ���� ���� ���� ������ ������ ������. 
bool IsGameContinue()
{
	// 5�� ���� �������ų�
	// GOAL POINT�� �����߰ų�
	// �÷��̾��� HP�� 0 ���ϰ� �Ǿ��ٸ� ������ ����
	// 3���� ���� �� �ϳ��� �����ϸ� ������ ����ǵ��� false�� return
	// �׷��� �ʴٸ� ������ ��ӵǵ��� true�� return
	if (_moveCount < 5 && 0 <= _hp && !IsGoalPoint())
	{
		return true;
	}
	else
	{
		return false;
	}
}

// X, Y�� ��ǥ�� 2, 1�� �ȴٸ� GOAL�� �����ϰ� ������ ����ǵ��� 
// ������ ��ġ�� 2, 1�̸� true�� retrun, �ƴ϶�� ������ ��ӵǵ��� false�� return �Ѵ�.
bool IsGoalPoint()
{
	if (_x == 2 && _y == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//	1. (�� �� �� ��)�� �̵�
void MoveCharacter()
{
	int move;
	cout << endl;
	cout << "���� ��ġ : " << _x << ", " << _y << endl;
	cout << "�̵��� ������ ������(�� : 0, �� : 1, �� : 2, �� : 3) : ";
	cin >> move;

	puts("");

	// ���� �����̸� ���⿡ ���� X, Y ���� ������Ʈ,
	// ���ÿ� ���������� _moveCount�� ������Ų��.
	switch (move)
	{
	case DIR_EAST:
		cout << "�������� 1��ŭ �̵��մϴ�. " << endl;
		_x++;
		_moveCount++;
		cout << "���� ��ġ : " << _x << ", " << _y << endl;
		break;
	case DIR_WEST:
		cout << "�������� 1��ŭ �̵��մϴ�. " << endl;
		_x--;
		_moveCount++;
		cout << "���� ��ġ : " << _x << ", " << _y << endl;
		break;
	case DIR_SOUTH:
		cout << "�������� 1��ŭ �̵��մϴ�. " << endl;
		_y--;
		_moveCount++;
		cout << "���� ��ġ : " << _x << ", " << _y << endl;
		break;
	case DIR_NORTH:
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

// x = 1, y = 1�̶�� ���������� ������ if���� ������ return ���ش�. 
bool IsBossRoom(int x, int y)
{
	// x , y =  1 , 1 �� �� ���������� ������ true�� ����
	if (x == 1 && y == 1)
	{
		return true;
	}
	else // �� ���� ���������� �Ϲ� ���ͷ����� ������ false�� ����
	{
		return false;
	}
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

	while (0 <= _monsterHp && 0 <= _hp)
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

// ������ Ŭ���� �Ǿ����� �÷��̾ �й��ߴ����� �����ش�.
// ���� ���� ������ �÷��̾��� hp�� 0 ���϶�� �й�, �ƴϸ� Ŭ����
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
	PrintGameStartMessage();

	// 7. ���� 5�� �����̰ų�
	// 8. X(2), Y(1) ������ ���� ������ Ŭ����ȴ�.
	// 11. ���� Ŭ���� ���� ���� ������ ������ ������. 
	while (IsGameContinue())
	{
		//	1. (�� �� �� ��)�� �̵�
		MoveCharacter();

		// 2. �� ĭ �����϶����� �濡 �����Ѵ�
		// 3. �濡���� ���Ϳ� ����ġ�µ�
		// 4. ������ ���ݷ��� 1 ~ 10 , HP�� 5 ~ 10 �̴�. (�濡 �������� �� ������ ���ݷ°� ü���� ����)
		if (IsBossRoom(_x, _y))
		{
			// 9. X(1), Y(1)�� ������
			// 10. ������ �ɷ�ġ�� HP : 50, ATTACK : 20
			EnterBossMonsterRoom();
		}
		else
		{
			EnterMonerterRoom();
		}

		// 5. ���Ϳ� ���� �� �뾿 ������.
		// 6. ���Ͱ� ������ �ٸ������� �̵��� �� �ִ�.
		BattleMonster();
	}

	// ������ Ŭ���� �Ǿ����� �÷��̾ �й��ߴ����� �����ش�.
	// ���� ���� ������ �÷��̾��� hp�� 0 ���϶�� �й�, �ƴϸ� Ŭ����
	IsClear();
}

// 6.(��ȭ) TEXT RPG
// - �濡 �����ϸ� �ٷ� �����°� �ƴ϶� 
// - ���Ϳ� ������������ �Ѵ�.
// - �¸��� ����� ������.
#include <iostream>
#include <time.h>

using namespace std;

int _playerHp = 100;
int _playerAttack = 10;
int _monsterHp = 0;
int _monsterAttack = 0;
int _x = 0;
int _y = 0;
int _movePoint = 0;
bool _monsterTurn = false;
bool _playerTurn = false;
int _playerHand = 0;
int _monsterHand = 0;

enum eDirection
{
	TRPG_EAST,
	TRPG_WEST,
	TRPG_SOUTH,
	TRPG_NORTH
};

enum eRockScissorPaper
{
	TRPG_RSP_SCISSOR,
	TRPG_RSP_ROCK,
	TRPG_RSP_PAPER,
	TRPG_RSP_END
};


// 1. ���� ���� ���� Ȯ��
bool IsGameClear();
bool IsGameOver();
void PrintState();
bool IsGameContinue()
{
	// 1-1. (2,1)�� ���ų� 5�� �̵��ϸ� ���� Ŭ����(����)
	if (IsGameClear())
	{
		PrintState();
		cout << "���� Ŭ����!!" << endl;
		return false;
	}
	// 1-2. �÷��̾��� HP�� 0�̵Ǹ� ����
	else if (IsGameOver())
	{
		cout << "�÷��̾� ���... ���� ����.." << endl;
		return false;
	}
	cout << "������ �����մϴ�." << endl;
	return true;
	cout << endl;
}

// 1-1. (2,1)�� ���ų� 5�� �̵��ϸ� ���� Ŭ����(����)
bool IsGameClear()
{
	if ((_x == 2 && _y == 1) || _movePoint == 5)
	{
		return true;
	}
	return false;
}

// 1-2. �÷��̾��� HP�� 0�̵Ǹ� ����
bool IsGameOver()
{
	if (_playerHp <= 0)
	{
		return true;
	}
	return false;
}

// 2. �÷��̾ �̵��Ѵ�.
void MovePlayer()
{
	int input = 0;
	cout << "�̵��� ������ �����ϼ��� ( 0 : �� , 1 : ��, 2 : ��, 3 : ��) : ";
	cin >> input;

	switch (input)
	{
	case 0:
		_x++;
		cout << "'��'���� 1 ��ŭ �̵��մϴ�. " << endl;
		break;
	case 1:
		_x--;
		cout << "'��'���� 1 ��ŭ �̵��մϴ�. " << endl;
		break;
	case 2:
		_y--;
		cout << "'��'���� 1 ��ŭ �̵��մϴ�. " << endl;
		break;
	case 3:
		_y++;
		cout << "'��'���� 1 ��ŭ �̵��մϴ�. " << endl;
		break;
	default:
		cout << "�߸��� �����Դϴ�. �ٽ� �����ϼ���..." << endl;
		MovePlayer();
		break;
	}
	cout << endl;
}

// 3. �濡 �����Ѵ�
void EnterMonsterRoom()
{
	// 3-1. ���� HP, ATTACK ����
	if (_x == 1 && _y == 1)
	{
		cout << "�������� �濡 �����Ͽ����ϴ�..! " << endl;
		cout << "�������� ����!!" << endl;
		_monsterHp = 50;
		_monsterAttack = 10;
	}
	// 3-2. (1,1)�� �������� ����
	else
	{
		cout << "���� �濡 �����Ͽ����ϴ�. " << endl;
		cout << "���� ����!" << endl;
		_monsterHp = rand()% 5 + 3;
		_monsterAttack = rand() % 3 + 2;
	}
	cout << endl;
}

// 4. ��Ʋ ����
void RockScissorPaper();
void Attack();
void BattleMonster()
{
	// 4-3. ���� Ȥ�� �÷��̾��� HP�� 0 ���ϰ� �Ǹ� ��Ʋ ����
	while (0 < _playerHp && 0 < _monsterHp)
	{
		// 4-1. ������������ �Ѵ�
		RockScissorPaper();
		// 4-2. ���ڰ� �����Ѵ�.
		Attack();
	}
	
	// 4-4. �÷��̾��� �¸� �� MOVECOUNT ����
	if (0 < _playerHp)
	{
		cout << "���͸� ��ġ�����ϴ�.!!" << endl;
		_movePoint++;
	}
}

// 4-1. ������������ �Ѵ�
void ChooseHand();
void PrintRSP();
void ResultRSP();
void RockScissorPaper()
{

	// 4-1-1. ������������ ���� �����Ѵ�.
	ChooseHand();
	// 4-1-2. ������������ ��Ȳ���� �����ش�.
	PrintRSP();
	// 4-1-3. ������������ ����� �˸���.
	ResultRSP();
}

// 4-1-1. ������������ ���� �����Ѵ�.
void ChooseHand()
{
	cout << "������������ ���� �����ڸ� �����մϴ�." << endl;
	cout << "���� ���� ���� �����ϼ��� (0 : ����, 1 : ����, 2 : ��) : ";
	cin >> _playerHand;
	cout << "���Ͱ� ���� ���� ���� �����մϴ�. " << endl;
	_monsterHand = rand() % TRPG_RSP_END;
	cout << endl;
}

// 4-1-2. ������������ ��Ȳ���� �����ش�.
void PrintRSP()
{
	switch (_playerHand)
	{
	case TRPG_RSP_SCISSOR:
		cout << "�÷��̾��� �� : ����" << endl;
		break;
	case TRPG_RSP_ROCK:
		cout << "�÷��̾��� �� : ����" << endl;
		break;
	case TRPG_RSP_PAPER:
		cout << "�÷��̾��� �� : ��" << endl;
		break;
	default:
		cout << "�߸��� �����Դϴ�. �ٽ� �����ϼ���.." << endl;
		ChooseHand();
		PrintRSP();
		break;
	}

	switch (_monsterHand)
	{
	case TRPG_RSP_SCISSOR:
		cout << "������ �� : ����" << endl;
		break;
	case TRPG_RSP_ROCK:
		cout << "������ �� : ����" << endl;
		break;
	case TRPG_RSP_PAPER:
		cout << "������ �� : ��" << endl;
		break;
	default:
		break;
	}
	cout << endl;
}

// 4-1-3. ������������ ����� �˸���.
// 4-1-3-1. ��� ó�� ���� ���� ���� �ʱ�ȭ(�Ѵ� �������� �ʴ� ���·�)
// 4-1-3-2. �����ڸ� �����Ѵ�
void ResultRSP()
{
	// 4-1-3-1. ��� ó�� ���� ���� ���� �ʱ�ȭ(�Ѵ� �������� �ʴ� ���·�)
	_playerTurn = false;
	_monsterTurn = false;

	// 4-1-3-2. �����ڸ� �����Ѵ�
	if ((_playerHand == TRPG_RSP_SCISSOR && _monsterHand == TRPG_RSP_PAPER) || (_playerHand == TRPG_RSP_ROCK && _monsterHand == TRPG_RSP_SCISSOR) || (_playerHand == TRPG_RSP_PAPER && _monsterHand == TRPG_RSP_ROCK))
	{
		cout << "���������� �¸�! �÷��̾��� ����!" << endl;
		_playerTurn = true;
	}
	else if ((_playerHand == TRPG_RSP_SCISSOR && _monsterHand == TRPG_RSP_ROCK) || (_playerHand == TRPG_RSP_ROCK && _monsterHand == TRPG_RSP_PAPER) || (_playerHand == TRPG_RSP_PAPER && _monsterHand == TRPG_RSP_SCISSOR))
	{
		cout << "���������� �й�... ������ ����!" << endl;
		_monsterTurn = true;
	}
	else
	{
		cout << "���������� ���º�.." << endl;
	}
}

// 4-2. ���ڰ� �����Ѵ�.
void Attack()
{
	// 4-2-1. ���ݴ��� ���� hp������Ʈ
	if (_playerTurn)
	{
		cout << "�÷��̾��� ����!" << endl;
		_monsterHp -= _playerAttack;
		cout << "���� HP : " << _monsterHp << endl;
	}
	else if (_monsterTurn)
	{
		cout << "������ ����..!" << endl; 
		_playerHp -= _monsterAttack;
		cout << "�÷��̾� HP : " << _playerHp << endl;
	}
	else
	{
		cout << "������������ ��� �ƹ��� �������� ���Ѵ�." << endl;
	}
	cout << endl;
}

void PrintState()
{
	cout << "�÷��̾��� HP : " << _playerHp << endl;
	cout << "�÷��̾��� ��ġ : ( " << _x << " , " << _y << " )" << endl;
	cout << "MOVEPOINT : " << _movePoint << endl;
}

void main()
{
	srand(time(NULL));

	while (IsGameContinue())
	{
		// 5 �÷��̾��� ���¸� �����ش�.
		PrintState();
		// 2. �÷��̾ �̵��Ѵ�.
		MovePlayer();
		EnterMonsterRoom();
		BattleMonster();
	}
}
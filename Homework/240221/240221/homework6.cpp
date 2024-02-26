// 6.(심화) TEXT RPG
// - 방에 입장하면 바로 때리는게 아니라 
// - 몬스터와 가위바위보를 한다.
// - 승리한 사람만 때린다.
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


// 1. 게임 지속 여부 확인
bool IsGameClear();
bool IsGameOver();
void PrintState();
bool IsGameContinue()
{
	// 1-1. (2,1)로 가거나 5번 이동하면 게임 클리어(종료)
	if (IsGameClear())
	{
		PrintState();
		cout << "게임 클리어!!" << endl;
		return false;
	}
	// 1-2. 플레이어의 HP가 0이되면 종료
	else if (IsGameOver())
	{
		cout << "플레이어 사망... 게임 종료.." << endl;
		return false;
	}
	cout << "게임을 진행합니다." << endl;
	return true;
	cout << endl;
}

// 1-1. (2,1)로 가거나 5번 이동하면 게임 클리어(종료)
bool IsGameClear()
{
	if ((_x == 2 && _y == 1) || _movePoint == 5)
	{
		return true;
	}
	return false;
}

// 1-2. 플레이어의 HP가 0이되면 종료
bool IsGameOver()
{
	if (_playerHp <= 0)
	{
		return true;
	}
	return false;
}

// 2. 플레이어가 이동한다.
void MovePlayer()
{
	int input = 0;
	cout << "이동할 방향을 선택하세요 ( 0 : 동 , 1 : 서, 2 : 남, 3 : 북) : ";
	cin >> input;

	switch (input)
	{
	case 0:
		_x++;
		cout << "'동'으로 1 만큼 이동합니다. " << endl;
		break;
	case 1:
		_x--;
		cout << "'서'으로 1 만큼 이동합니다. " << endl;
		break;
	case 2:
		_y--;
		cout << "'남'으로 1 만큼 이동합니다. " << endl;
		break;
	case 3:
		_y++;
		cout << "'북'으로 1 만큼 이동합니다. " << endl;
		break;
	default:
		cout << "잘못된 선택입니다. 다시 선택하세요..." << endl;
		MovePlayer();
		break;
	}
	cout << endl;
}

// 3. 방에 입장한다
void EnterMonsterRoom()
{
	// 3-1. 몬스터 HP, ATTACK 설정
	if (_x == 1 && _y == 1)
	{
		cout << "보스몬스터 방에 입장하였습니다..! " << endl;
		cout << "보스몬스터 등장!!" << endl;
		_monsterHp = 50;
		_monsterAttack = 10;
	}
	// 3-2. (1,1)은 보스몬스터 생성
	else
	{
		cout << "몬스터 방에 입장하였습니다. " << endl;
		cout << "몬스터 등장!" << endl;
		_monsterHp = rand()% 5 + 3;
		_monsterAttack = rand() % 3 + 2;
	}
	cout << endl;
}

// 4. 배틀 시작
void RockScissorPaper();
void Attack();
void BattleMonster()
{
	// 4-3. 몬스터 혹은 플레이어의 HP가 0 이하가 되면 배틀 종료
	while (0 < _playerHp && 0 < _monsterHp)
	{
		// 4-1. 가위바위보를 한다
		RockScissorPaper();
		// 4-2. 승자가 공격한다.
		Attack();
	}
	
	// 4-4. 플레이어의 승리 시 MOVECOUNT 증가
	if (0 < _playerHp)
	{
		cout << "몬스터를 해치웠습니다.!!" << endl;
		_movePoint++;
	}
}

// 4-1. 가위바위보를 한다
void ChooseHand();
void PrintRSP();
void ResultRSP();
void RockScissorPaper()
{

	// 4-1-1. 가위바위보의 손을 선택한다.
	ChooseHand();
	// 4-1-2. 가위바위보의 현황판을 보여준다.
	PrintRSP();
	// 4-1-3. 가위바위보의 결과를 알린다.
	ResultRSP();
}

// 4-1-1. 가위바위보의 손을 선택한다.
void ChooseHand()
{
	cout << "가위바위보를 통해 공격자를 결정합니다." << endl;
	cout << "가위 바위 보를 선택하세요 (0 : 가위, 1 : 바위, 2 : 보) : ";
	cin >> _playerHand;
	cout << "몬스터가 가위 바위 보를 선택합니다. " << endl;
	_monsterHand = rand() % TRPG_RSP_END;
	cout << endl;
}

// 4-1-2. 가위바위보의 현황판을 보여준다.
void PrintRSP()
{
	switch (_playerHand)
	{
	case TRPG_RSP_SCISSOR:
		cout << "플레이어의 손 : 가위" << endl;
		break;
	case TRPG_RSP_ROCK:
		cout << "플레이어의 손 : 바위" << endl;
		break;
	case TRPG_RSP_PAPER:
		cout << "플레이어의 손 : 보" << endl;
		break;
	default:
		cout << "잘못된 선택입니다. 다시 선택하세요.." << endl;
		ChooseHand();
		PrintRSP();
		break;
	}

	switch (_monsterHand)
	{
	case TRPG_RSP_SCISSOR:
		cout << "몬스터의 손 : 가위" << endl;
		break;
	case TRPG_RSP_ROCK:
		cout << "몬스터의 손 : 바위" << endl;
		break;
	case TRPG_RSP_PAPER:
		cout << "몬스터의 손 : 보" << endl;
		break;
	default:
		break;
	}
	cout << endl;
}

// 4-1-3. 가위바위보의 결과를 알린다.
// 4-1-3-1. 결과 처리 전에 공격 순서 초기화(둘다 공격하지 않는 상태로)
// 4-1-3-2. 공격자를 결정한다
void ResultRSP()
{
	// 4-1-3-1. 결과 처리 전에 공격 순서 초기화(둘다 공격하지 않는 상태로)
	_playerTurn = false;
	_monsterTurn = false;

	// 4-1-3-2. 공격자를 결정한다
	if ((_playerHand == TRPG_RSP_SCISSOR && _monsterHand == TRPG_RSP_PAPER) || (_playerHand == TRPG_RSP_ROCK && _monsterHand == TRPG_RSP_SCISSOR) || (_playerHand == TRPG_RSP_PAPER && _monsterHand == TRPG_RSP_ROCK))
	{
		cout << "가위바위보 승리! 플레이어의 공격!" << endl;
		_playerTurn = true;
	}
	else if ((_playerHand == TRPG_RSP_SCISSOR && _monsterHand == TRPG_RSP_ROCK) || (_playerHand == TRPG_RSP_ROCK && _monsterHand == TRPG_RSP_PAPER) || (_playerHand == TRPG_RSP_PAPER && _monsterHand == TRPG_RSP_SCISSOR))
	{
		cout << "가위바위보 패배... 몬스터의 공격!" << endl;
		_monsterTurn = true;
	}
	else
	{
		cout << "가위바위보 무승부.." << endl;
	}
}

// 4-2. 승자가 공격한다.
void Attack()
{
	// 4-2-1. 공격당한 쪽의 hp업데이트
	if (_playerTurn)
	{
		cout << "플레이어의 공격!" << endl;
		_monsterHp -= _playerAttack;
		cout << "몬스터 HP : " << _monsterHp << endl;
	}
	else if (_monsterTurn)
	{
		cout << "몬스터의 공격..!" << endl; 
		_playerHp -= _monsterAttack;
		cout << "플레이어 HP : " << _playerHp << endl;
	}
	else
	{
		cout << "가위바위보를 비겨 아무도 공격하지 못한다." << endl;
	}
	cout << endl;
}

void PrintState()
{
	cout << "플레이어의 HP : " << _playerHp << endl;
	cout << "플레이어의 위치 : ( " << _x << " , " << _y << " )" << endl;
	cout << "MOVEPOINT : " << _movePoint << endl;
}

void main()
{
	srand(time(NULL));

	while (IsGameContinue())
	{
		// 5 플레이어의 상태를 보여준다.
		PrintState();
		// 2. 플레이어가 이동한다.
		MovePlayer();
		EnterMonsterRoom();
		BattleMonster();
	}
}
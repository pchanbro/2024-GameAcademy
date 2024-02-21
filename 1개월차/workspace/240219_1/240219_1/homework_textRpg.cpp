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

//	1. (상 하 좌 우)로 이동
void MoveCharacter()
{
	int move;
	cout << endl;
	cout << "현재 위치 : " << _x << ", " << _y << endl;
	cout << "이동할 방향을 고르세요(동 : 0, 서 : 1, 남 : 2, 북 : 3) : ";
	cin >> move;

	puts("");

	switch (move)
	{
	case 0:
		cout << "동쪽으로 1만큼 이동합니다. " << endl;
		_x++;
		_moveCount++;
		cout << "현재 위치 : " << _x << ", " << _y << endl;
		break;
	case 1:
		cout << "서쪽으로 1만큼 이동합니다. " << endl;
		_x--;
		_moveCount++;
		cout << "현재 위치 : " << _x << ", " << _y << endl;
		break;
	case 2:
		cout << "남쪽으로 1만큼 이동합니다. " << endl;
		_y--;
		_moveCount++;
		cout << "현재 위치 : " << _x << ", " << _y << endl;
		break;
	case 3:
		cout << "북쪽으로 1만큼 이동합니다. " << endl;
		_y++;
		_moveCount++;
		cout << "현재 위치 : " << _x << ", " << _y << endl;
		break;
	default:
		cout << "잘못된 선택입니다. 다시 선택하세요." << endl;
		MoveCharacter();
	}
}

// 2. 한 칸 움직일때마다 방에 입장한다
// 3. 방에서는 몬스터와 마주치는데
// 4. 몬스터의 공격력은 1 ~ 10 , HP는 5 ~ 10 이다. (방에 입장했을 때 몬스터의 공격력과 체력이 지정)
void EnterMonerterRoom()
{
	_monsterHp = rand() % 10 + 1;
	_monsterAttack = rand() % 6 + 5;
}

// 9. X(1), Y(1)은 보스방
// 10. 보스의 능력치는 HP : 50, ATTACK : 20
void EnterBossMonsterRoom()
{
	_monsterHp = 50;
	_monsterAttack = 20;
}

// 5. 몬스터와 내가 한 대씩 때린다.
// 6. 몬스터가 죽으면 다른방으로 이동할 수 있다.
void BattleMonster()
{
	puts("");

	while (_monsterHp >= 0 && _hp >= 0)
	{
		cout << "플레이어의 공격!" << endl;
		_monsterHp -= _attack;
		cout << "몬스터의 HP : " << _monsterHp << endl;

		puts("");

		cout << "몬스터의 공격!" << endl;
		_hp -= _monsterAttack;
		cout << "플레이어의 HP : " << _hp << endl;

		puts("");
	}
	cout << "전투 종료 " << endl;
}

// 7. 방을 5번 움직이거나
// 8. X(2), Y(1) 방으로 가면 게임이 클리어된다.
// 11. 게임 클리어 전에 내가 죽으면 게임이 끝난다. 
void IsClear()
{
	if (_hp <= 0)
	{
		cout << "플레이어 패배..." << endl;
	}
	else
	{
		cout << "게임 클리어!" << endl;
	}

	puts("");

	cout << "결과" << endl;
	cout << "플레이어 HP : " << _hp << endl;
	cout << "플레이어 위치 : " << _x << ", " << _y << endl;
	cout << "MoveCount : " << _moveCount << endl;
}

void main()
{

	// 숙제
	// TEXT RPG 만들기
	// ATTACK, HP, X(0), Y(0)가 있고 

	srand(time(NULL));

	// 게임 시작
	printf("┌───────────────────────────┐\n");
	printf("│    Text Rpg Game Start    │\n");
	printf("└───────────────────────────┘\n");

	// 7. 방을 5번 움직이거나
	// 8. X(2), Y(1) 방으로 가면 게임이 클리어된다.
	// 11. 게임 클리어 전에 내가 죽으면 게임이 끝난다. 
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

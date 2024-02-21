#include <iostream>
#include <time.h>

using namespace std;

// 숙제 피드백 3가지
// 1. 처음 보는 사람도 코드를 이해할 수 있도록 코드를 구성한다.
// 2. 보통 부등호는 < 를 많이 쓴다 보통, 왼쪽이 오른쪽보다 작다고 인식한다.
// 3. while문의 조건은 Is뭐시기로 해서 return 값을 통해 반복할지 안할지를 보여주는게 좋다.


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
	printf("┌───────────────────────────┐\n");
	printf("│    Text Rpg Game Start    │\n");
	printf("└───────────────────────────┘\n");
}

// 게임이 계속 진행되는지 여부를 판단하는 함수 
// 7. 방을 5번 움직이거나
// 8. X(2), Y(1) 방으로 가면 게임이 클리어된다. IsGoalPoint()를 통해 여부 확인
// 11. 게임 클리어 전에 내가 죽으면 게임이 끝난다. 
bool IsGameContinue()
{
	// 5번 방을 움직였거나
	// GOAL POINT에 도착했거나
	// 플레이어의 HP가 0 이하가 되었다면 게임이 종료
	// 3가지 조건 중 하나라도 만족하면 게임이 종료되도록 false를 return
	// 그렇지 않다면 게임이 계속되도록 true를 return
	if (_moveCount < 5 && 0 <= _hp && !IsGoalPoint())
	{
		return true;
	}
	else
	{
		return false;
	}
}

// X, Y의 좌표가 2, 1이 된다면 GOAL로 인정하고 게임이 종료되도록 
// 현재의 위치가 2, 1이면 true를 retrun, 아니라면 게임이 계속되도록 false를 return 한다.
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

//	1. (상 하 좌 우)로 이동
void MoveCharacter()
{
	int move;
	cout << endl;
	cout << "현재 위치 : " << _x << ", " << _y << endl;
	cout << "이동할 방향을 고르세요(동 : 0, 서 : 1, 남 : 2, 북 : 3) : ";
	cin >> move;

	puts("");

	// 방을 움직이면 방향에 따라 X, Y 값을 업데이트,
	// 동시에 움직였으니 _moveCount를 증가시킨다.
	switch (move)
	{
	case DIR_EAST:
		cout << "동쪽으로 1만큼 이동합니다. " << endl;
		_x++;
		_moveCount++;
		cout << "현재 위치 : " << _x << ", " << _y << endl;
		break;
	case DIR_WEST:
		cout << "서쪽으로 1만큼 이동합니다. " << endl;
		_x--;
		_moveCount++;
		cout << "현재 위치 : " << _x << ", " << _y << endl;
		break;
	case DIR_SOUTH:
		cout << "남쪽으로 1만큼 이동합니다. " << endl;
		_y--;
		_moveCount++;
		cout << "현재 위치 : " << _x << ", " << _y << endl;
		break;
	case DIR_NORTH:
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

// x = 1, y = 1이라면 보스룸으로 들어가도록 if문의 조건을 return 해준다. 
bool IsBossRoom(int x, int y)
{
	// x , y =  1 , 1 일 때 보스룸으로 들어가도록 true를 리턴
	if (x == 1 && y == 1)
	{
		return true;
	}
	else // 그 외의 지역에서는 일반 몬스터룸으로 들어가도록 false를 리턴
	{
		return false;
	}
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

	while (0 <= _monsterHp && 0 <= _hp)
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

// 게임이 클리어 되었는지 플레이어가 패배했는지를 보여준다.
// 게임 종료 시점에 플레이어의 hp가 0 이하라면 패배, 아니면 클리어
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
	PrintGameStartMessage();

	// 7. 방을 5번 움직이거나
	// 8. X(2), Y(1) 방으로 가면 게임이 클리어된다.
	// 11. 게임 클리어 전에 내가 죽으면 게임이 끝난다. 
	while (IsGameContinue())
	{
		//	1. (상 하 좌 우)로 이동
		MoveCharacter();

		// 2. 한 칸 움직일때마다 방에 입장한다
		// 3. 방에서는 몬스터와 마주치는데
		// 4. 몬스터의 공격력은 1 ~ 10 , HP는 5 ~ 10 이다. (방에 입장했을 때 몬스터의 공격력과 체력이 지정)
		if (IsBossRoom(_x, _y))
		{
			// 9. X(1), Y(1)은 보스방
			// 10. 보스의 능력치는 HP : 50, ATTACK : 20
			EnterBossMonsterRoom();
		}
		else
		{
			EnterMonerterRoom();
		}

		// 5. 몬스터와 내가 한 대씩 때린다.
		// 6. 몬스터가 죽으면 다른방으로 이동할 수 있다.
		BattleMonster();
	}

	// 게임이 클리어 되었는지 플레이어가 패배했는지를 보여준다.
	// 게임 종료 시점에 플레이어의 hp가 0 이하라면 패배, 아니면 클리어
	IsClear();
}

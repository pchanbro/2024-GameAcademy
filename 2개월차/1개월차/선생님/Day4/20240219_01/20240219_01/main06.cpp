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
	cout << "몬스터와 마주쳤습니다." << endl;
	_monsterHp = 3;
	_monsterAttack = 2;

	//~~면 반복한다.
	//while( 조건 )
	//{
	//}
	
	//둘다 살아있는 동안 반복
	while (_monsterHp > 0 && _hp > 0)
	{
		cout << "몬스터를 가격했습니다. " << endl;
		_monsterHp = _monsterHp - _attack;
		cout << "몬스터 남은 체력 : " << _monsterHp << endl;

		cout << "피해를 입었습니다." << endl;
		_hp = _hp - _monsterAttack;
		cout << "내 남은 체력 : " << _hp << endl;
	}
}

void MovePlayer()
{
	cout << "플레이어가 움직일 방향을 골라주세요 (0 : 북, 1: 남, 2: 서, 3: 동)" << endl;
	cin >> _input;

	//상을 입력
	_y--;
	cout << "현재위치 : ( X : 3, Y : 1)" << endl;
	_moveCount++;
}

void main()
{
	cout << "게임이 시작되었습니다." << endl;

	//플레이어가 움직인다.
	//플레이어죽으면 게임끝
	while (_moveCount < 5)
	{
		MovePlayer();
		BattleMonster();
	}



	//숙제2.
	//TEXT RPG 만들기
	// ATTACK, HP, X(0), Y(0) 가 있고
	// 
	//1. 게임이 시작하면
	//   (상하좌우)로 이동할수있다.
	//2. 한칸 움직일때마다 방에 입장한다
	//3. 방에서는 몬스터와 마주치는데,
	//4. 몬스터의 공격력은 1 ~ 10사이 , HP는 5~10 사이다. (방에 들어가면 이때 몬스터의 공격력과 체력이 지정)
	//5. 몬스터와 내가 한대씩 때린다
	//6. 몬스터가 죽으면 다른방으로 이동할 수있다.
	//7. 방을 5번 움직이거나
	//8. X(1), Y(1) 방은 보스방이다
	//9. 보스의 능력치는 HP 50, ATTACK : 20
	//10. X(2), Y(1) 방으로 가면 게임이 클리어된다.
	//11. 그전에 내가 죽으면 게임이 끝난다.
}
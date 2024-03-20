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
	cout << "몬스터와 마주쳤습니다. " << endl;
	//대충
	_monsterHp = 3;
	_monsterAttack = 2;

	// while (조건) 
	// {
	//		조건이 만족하는 동안 실행되는 코드
	// }
	
	// 둘 다 살아있는 동안 반복
	while (_monsterHp > 0 && _hp > 0)
	{
		cout << "몬스터를 가격했습니다. " << endl;
		_monsterHp -= _attack;
		cout << "몬스터 남은 체력 : " << _monsterHp <<  endl;

		cout << "피해를 입었습니다. " << endl;
		_hp -= _monsterAttack;
		cout << "내 남은 체력 : " << _hp << endl;
	}
}

void MovePlayer()
{
	cout << "플레이어가 움직일 방향을 골라주세요 (0 : 북, 1 : 남, 2 : 서, 3 : 동)" << endl;
	cin >> _input;



}

void main()
{
	cout << "게임이 시작되었습니다." << endl;

	// 플레이어가 움직인다. 
	// 플레이어가 죽으면 게임 끝 등 채워넣기
	while (_moveCount < 5)
	{
		MovePlayer();
		BattleMonster();
	}

}
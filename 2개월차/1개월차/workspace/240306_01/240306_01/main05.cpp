#include <iostream>
#include <string>

using namespace std;

// 클래스가 무엇이냐.
// - 포인터가 1차 뉴비 절단기라면
// - 클래스는 2차 뉴비 절단기

struct Character
{
	string Name = "";
	int Hp = 0;
	int Attack = 0;

	void Print(int test)
	{
		cout << "캐릭터 정보" << endl;
		cout << "Name : " << Name << endl;
		cout << "Hp : " << Hp << endl;
		cout << "Attack : " << Attack << endl;

		cout << test << endl;
	}

	void Print2();
};

void Character::Print2()
{
	cout << "캐릭터 정보" << endl;
	cout << "Name : " << Name << endl;
	cout << "Hp : " << Hp << endl;
	cout << "Attack : " << Attack << endl;
}



void main()
{
	// 구조체

	// 캐릭터 구조체
	// - 다마고치(전투가 있는 다마고치)
	//	- 캐릭터 이름
	//	- HP
	//	- ATTACK

	// 캐릭터 선택창
	// 각 스탯들을 입력받을 수 있도록 만들어주세요.
	printf("┌─────────────────────────────────┐\n");
	printf("│           캐릭터 생성            │\n");
	printf("└─────────────────────────────────┘\n");
	Character character;

	cout << "캐릭터 이름 : ";
	cin >> character.Name;
	cout << "캐릭터 HP : ";
	cin >> character.Hp;
	cout << "캐릭터 공격력 : ";
	cin >> character.Attack;

	// 구조체 함수
	// 구조체 안에 함수를 선언할 수 있다.

	// 캐릭터 정보를 출력하고싶다.
	character.Print(55);
}
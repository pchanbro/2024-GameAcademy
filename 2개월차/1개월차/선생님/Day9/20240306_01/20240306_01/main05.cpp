#include <iostream>
#include <string>

using namespace std;

//클래스가 무엇이냐.
// - 포인터가 1차 뉴비 절단기
// - 클래스가 2차 뉴비 절단기

struct Character
{
	string Name;
	int Hp;
	int Attack;

	void Print(int test)
	{
		cout << "캐릭터 정보1" << endl;
		cout << "Name : " << Name << endl;
		cout << "Hp : " << Hp << endl;
		cout << "Attack : " << Attack << endl;

		cout << "test : " << test << endl;
	}

	void Print2();
};

void Character::Print2()
{
	cout << "캐릭터 정보2" << endl;
	cout << "Name : " << Name << endl;
	cout << "Hp : " << Hp << endl;
	cout << "Attack : " << Attack << endl;
}

Character _character;

void PrintCharacter(Character character)
{
	cout << "캐릭터 정보를 출력합니다!" << endl;

}
void main()
{
	// 구조체
	
	// 캐릭터 구조체
	//  - 다마고치 (전투)
	//   - 캐릭터 이름
	//   - HP
	//   - ATTACK

	// 캐릭터 선택창
	//  각 스탯들을 입력받을수 있게끔 만들어주세요.

	cout << "캐릭터 스탯을 입력하겠습니다." << endl;

	cout << "캐릭터 이름을 입력해주세요 : " << endl;
	getline(cin, _character.Name);
	cout << "캐릭터 HP : " << endl;
	cin >> _character.Hp;
	cout << "캐릭터 Attack : " << endl;
	cin >> _character.Attack;

	//구조체 함수
	//구조체 안에 함수를 선언할수있습니다.

	//캐릭터 정보를 출력하고싶다.!!
	::PrintCharacter(_character);

	_character.Print(3);

}
#include <iostream>
#include <string>

using namespace std;

//Ŭ������ �����̳�.
// - �����Ͱ� 1�� ���� ���ܱ�
// - Ŭ������ 2�� ���� ���ܱ�

struct Character
{
	string Name;
	int Hp;
	int Attack;

	void Print(int test)
	{
		cout << "ĳ���� ����1" << endl;
		cout << "Name : " << Name << endl;
		cout << "Hp : " << Hp << endl;
		cout << "Attack : " << Attack << endl;

		cout << "test : " << test << endl;
	}

	void Print2();
};

void Character::Print2()
{
	cout << "ĳ���� ����2" << endl;
	cout << "Name : " << Name << endl;
	cout << "Hp : " << Hp << endl;
	cout << "Attack : " << Attack << endl;
}

Character _character;

void PrintCharacter(Character character)
{
	cout << "ĳ���� ������ ����մϴ�!" << endl;

}
void main()
{
	// ����ü
	
	// ĳ���� ����ü
	//  - �ٸ���ġ (����)
	//   - ĳ���� �̸�
	//   - HP
	//   - ATTACK

	// ĳ���� ����â
	//  �� ���ȵ��� �Է¹����� �ְԲ� ������ּ���.

	cout << "ĳ���� ������ �Է��ϰڽ��ϴ�." << endl;

	cout << "ĳ���� �̸��� �Է����ּ��� : " << endl;
	getline(cin, _character.Name);
	cout << "ĳ���� HP : " << endl;
	cin >> _character.Hp;
	cout << "ĳ���� Attack : " << endl;
	cin >> _character.Attack;

	//����ü �Լ�
	//����ü �ȿ� �Լ��� �����Ҽ��ֽ��ϴ�.

	//ĳ���� ������ ����ϰ�ʹ�.!!
	::PrintCharacter(_character);

	_character.Print(3);

}
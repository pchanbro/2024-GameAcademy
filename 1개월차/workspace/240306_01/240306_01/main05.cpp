#include <iostream>
#include <string>

using namespace std;

// Ŭ������ �����̳�.
// - �����Ͱ� 1�� ���� ���ܱ���
// - Ŭ������ 2�� ���� ���ܱ�

struct Character
{
	string Name = "";
	int Hp = 0;
	int Attack = 0;

	void Print(int test)
	{
		cout << "ĳ���� ����" << endl;
		cout << "Name : " << Name << endl;
		cout << "Hp : " << Hp << endl;
		cout << "Attack : " << Attack << endl;

		cout << test << endl;
	}

	void Print2();
};

void Character::Print2()
{
	cout << "ĳ���� ����" << endl;
	cout << "Name : " << Name << endl;
	cout << "Hp : " << Hp << endl;
	cout << "Attack : " << Attack << endl;
}



void main()
{
	// ����ü

	// ĳ���� ����ü
	// - �ٸ���ġ(������ �ִ� �ٸ���ġ)
	//	- ĳ���� �̸�
	//	- HP
	//	- ATTACK

	// ĳ���� ����â
	// �� ���ȵ��� �Է¹��� �� �ֵ��� ������ּ���.
	printf("����������������������������������������������������������������������\n");
	printf("��           ĳ���� ����            ��\n");
	printf("����������������������������������������������������������������������\n");
	Character character;

	cout << "ĳ���� �̸� : ";
	cin >> character.Name;
	cout << "ĳ���� HP : ";
	cin >> character.Hp;
	cout << "ĳ���� ���ݷ� : ";
	cin >> character.Attack;

	// ����ü �Լ�
	// ����ü �ȿ� �Լ��� ������ �� �ִ�.

	// ĳ���� ������ ����ϰ�ʹ�.
	character.Print(55);
}
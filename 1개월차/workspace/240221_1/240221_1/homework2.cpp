// 2. while�� Ȱ��
// - ���ڸ��߱� ����
// ���ڸ� ���� ���� �ݺ�
// 1. ��ǻ�Ͱ� �������ڸ� ���Ѵ�. (1 ~ 100)
// 2. ���� ���ڸ� �Է�
// 3-1. �������� �� ���ں��� ���� : UP ���
// 3-2. �������� �� ���ں��� ���� : DOWN ���
// 3-3. �������� ������ ���� ���� (exit(0);)
#include <iostream>
#include <time.h>

using namespace std;

int _max = 100;
int _min = 1;
int _number = 0;

// 1. ��ǻ�Ͱ� �������ڸ� ���Ѵ�. (1 ~ 100)
int GenerateNumber()
{
	int num = rand() % 100 + 1;
	return num;
}

// 2. ���� ���ڸ� �Է�
// 3-1. �������� �� ���ں��� ���� : UP ���
// 3-2. �������� �� ���ں��� ���� : DOWN ���
// 3-3. �������� ������ ���� ���� (exit(0);)
int ChooseNumber()
{
	int choice;
	cout << _min << " ~ " << _max << " �� �ϳ��� ���ڸ� �����ϼ��� : ";
	cin >> choice;

	return  choice;
}

void IsCorrect(int choiceNumber)
{
	if (choiceNumber == _number)
	{
		cout << _number << " ����!!" << endl;
		exit(0);
	}
	else if (choiceNumber < _number)
	{
		cout << "UP" << endl;
		_min = choiceNumber;
	}
	else
	{
		cout << "DOWN" << endl;
		_max = choiceNumber;
	}
}

void main()
{
	srand(time(NULL));
	// 1. ��ǻ�Ͱ� �������ڸ� ���Ѵ�. (1 ~ 100)
	_number = GenerateNumber();


	while (true)
	{
		// 2. ���� ���ڸ� �Է�
		int num = ChooseNumber();

		// 3-1. �������� �� ���ں��� ���� : UP ���
		// 3-2. �������� �� ���ں��� ���� : DOWN ���
		// 3-3. �������� ������ ���� ���� (exit(0);)
		IsCorrect(num);
	}
}
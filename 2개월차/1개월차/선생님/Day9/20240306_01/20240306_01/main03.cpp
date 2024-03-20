#include <iostream>
#include <vector>
using namespace std;

//string length  => ���ڿ� ���̸� �������ݴϴ�.
int MyStrlen(char* str)
{
	int index = 0;
	while (true)
	{
		if (str[index] != '\0')
		{
			index++;
		}
		else
		{
			break;
		}
	}

	return index;
}
//
bool MyStrCmp(char * str1, char * str2)
{
	//str1 ���ڿ� str2���ڰ� ������ true, �ٸ��� false ����
	//���ڿ� ��

	//������ �����ڵ�
	// - N��(str1 ���ڿ� ����)��ŭ �ݺ��Ѵ�. 
	// - str1[index] == str[index] �� �ٸ����� �ִٸ�
	// - false ����
	// - ��� ���ٸ� 
	// - str1 ���ڿ����̿� str2 ���ڿ����̰� ������ true
	// - �ٸ��� false

	// - 1. ���ڿ� ���̰� ���ƾ��Ѵ�.
	// - 2. str1 �������� ��� �ε����� ���� ���ƾ��Ѵ�.

	int str1Length = MyStrlen(str1);
	int str2Length = MyStrlen(str2);

	if (str1Length != str2Length)
	{
		return false;
	}

	for (int i = 0; i < str1Length; i++)
	{
		if (str1[i] != str2[i])
		{
			return false;
		}
	}

	return true;
}

char* MyStrCat(char* str1, char* str2)
{
	//str1 ���ڿ� str2���ڸ� �̾��ش�.

	//str1 => hello
	//str2 => world

	int str1Length = strlen(str1);
	int str2Length = strlen(str2);

	//str2 ���ڿ� ���̸�ŭ �ݺ��ϸ鼭
	//str1 ���������� str2�� ���ڸ� �ϳ��� ���δ�.

	for (int i = 0; i < str2Length; i++)
	{
		str1[str1Length + i] = str2[i];
	}
	str1[str1Length + str2Length] = '\0';


	return str1;


	//return => helloworld
}


void main()
{
	char str1[128] = "Hello World!";
	char str2[128] = "Hello World!";

	if (MyStrCmp(str1, str2))
	{
		printf("�� ���ڿ��� �����ϴ�\n");
	}


	int length = MyStrlen(str1);
	printf("���ڿ� ���� : %d\n", length);

	
	cout << MyStrCat(str1, str2) << endl;
}
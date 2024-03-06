#include <iostream>

using namespace std;

int MyStrLen(char* str);
bool MyStrCmp(char* str1, char* str2);
char* MystrCat(char* str1, char* str2);

void main()
{
	char str1[6] = "hello";
	char str2[6] = "hello";
	if (MyStrCmp(str1, str2))
	{
		printf("str1�� str2�� �����ϴ�.\n");
	}
	else
	{
		printf("str1�� str2�� �ٸ��ϴ�.\n");
	}

	char* str3 = nullptr;
	str3 = MystrCat(str1, str2);
	cout << str3 << endl;
}

//string length => ���ڿ��� ���̸� �������ݴϴ�.
int MyStrLen(char* str)
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

// str1 ���ڿ� str2 ���ڰ� ������ true, �ٸ��� false ����
bool MyStrCmp(char* str1, char* str2)
{
	bool same = true;
	
	int str1Length = MyStrLen(str1);

	for (int i = 0; i < str1Length + 1; i++)
		// ���� ���ǹ��� MyStrLen(str1) �̰� ������� ��� �Լ��� ������ ������ ����ȭ�� �ȵ�
		// �׷��� ���� �����ؼ� �ϳ� �־��ִ°� ����.
		// ���� ���� str1�� ���̿� 1�� ���� str1�� ������ ����� \0(null)�� str2�� �� ������ ��Ҹ�
		// ���ߴµ� �̷��� �ص� �ǳ�?
	{
		if (str1[i] != str2[i])
		{
			same = false;
		}
	}

	if (same)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

char* MystrCat(char* str1, char* str2)
{
	// str1 ���ڿ� str2 ���ڸ� �̾��ش�.

	// str1 -> hello
	// str2 -> world

	// return helloworld
	int str1Length = MyStrLen(str1);
	int str2Length = MyStrLen(str2);

	int strLength = MyStrLen(str1) + MyStrLen(str2) + 1;

	int strNum = 0;

	char* str = new char[strLength];

	for (int i = 0; i < str1Length; i++)
	{
		str[strNum] = str1[i];
		strNum++;
	}

	for (int i = 0; i < str2Length; i++)
	{
		str[strNum] = str2[i];
		strNum++;
	}

	str[strNum] = '\0';

	return str;
}
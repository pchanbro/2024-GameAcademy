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
		printf("str1과 str2가 같습니다.\n");
	}
	else
	{
		printf("str1과 str2가 다릅니다.\n");
	}

	char* str3 = nullptr;
	str3 = MystrCat(str1, str2);
	cout << str3 << endl;
}

//string length => 문자열의 길이를 리턴해줍니다.
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

// str1 문자와 str2 문자가 같으면 true, 다르면 false 리턴
bool MyStrCmp(char* str1, char* str2)
{
	bool same = true;
	
	int str1Length = MyStrLen(str1);

	for (int i = 0; i < str1Length + 1; i++)
		// 여기 조건문에 MyStrLen(str1) 이거 써놓으면 계속 함수를 돌리기 때문에 최적화가 안됨
		// 그러니 변수 선언해서 하나 넣어주는게 좋다.
		// 지금 나는 str1의 길이에 1을 더해 str1의 마지막 요소인 \0(null)과 str2의 그 길이의 요소를
		// 비교했는데 이렇게 해도 되나?
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
	// str1 문자와 str2 문자를 이어준다.

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
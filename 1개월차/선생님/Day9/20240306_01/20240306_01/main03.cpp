#include <iostream>
#include <vector>
using namespace std;

//string length  => 문자열 길이를 리턴해줍니다.
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
	//str1 문자와 str2문자가 같으면 true, 다르면 false 리턴
	//문자열 비교

	//비교조건 수도코드
	// - N번(str1 문자열 길이)만큼 반복한다. 
	// - str1[index] == str[index] 가 다른것이 있다면
	// - false 리턴
	// - 모두 같다면 
	// - str1 문자열길이와 str2 문자열길이가 같으면 true
	// - 다르면 false

	// - 1. 문자열 길이가 같아야한다.
	// - 2. str1 기준으로 모든 인덱스의 값이 같아야한다.

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
	//str1 문자와 str2문자를 이어준다.

	//str1 => hello
	//str2 => world

	int str1Length = strlen(str1);
	int str2Length = strlen(str2);

	//str2 문자열 길이만큼 반복하면서
	//str1 마지막부터 str2의 문자를 하나씩 붙인다.

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
		printf("두 문자열이 같습니다\n");
	}


	int length = MyStrlen(str1);
	printf("문자열 길이 : %d\n", length);

	
	cout << MyStrCat(str1, str2) << endl;
}
#include <iostream>

using namespace std;

void main()
{
	//문자열

	//문자 자료형
	char c = 'a'; // (정수형)

	cout << c << endl;

	//char str = 'asdfas'; // 여러개를 적으면 에러가 남

	char c1 = 48;

	cout << c1 << endl;

	//아스키코드
	//프로그래밍에서 정해둔 문자 규약
	//A => 65
	//B => 66

	//char 두개를 엮어서  한글도 표현하자 (세계 각국의 언어)

	char str1[128] = "abc";
	cout << str1 << endl;

	char str2[128] = "bbc";
	cout << str2 << endl;

	int num1 = 3;
	int num2 = 3;

	if (num1 == num2)
	{
		printf("num1과 num2가 같습니다\n");
	}

	//if (*str1 == *str2)
	//{
	//	printf("str1과 str2가 같습니다.\n");
	//}

	// 배열 = 포인터
	// 문자열을 단순히 == 으로 비교하면 주소값으로 비교하는 것이다.
	// *을 붙여서 비교하면 맨 앞글자만 비교하게 된다.

	// 그러면 문자열 비교는 어떻게하는것인가??
	//strcmp (string compare)

	// 0이면 같다
	if (strcmp(str1, str2) == 0)
	{
		printf("str1과 str2가 같습니다.\n");
	}
	//strcmp
	// -1, 0 , 1
	// -1 => str1의 값이 사전순으로 더 앞에있다.
	// 0 => 같다
	// 1 => str2의 값이 사전순으로 더 앞에있다.

	// "" => 문자열
	//문자열은 마지막 값에 \0 값이 들어간다.
	//그러므로 한칸을 항상 확보해야한다.
	char str3[5] = "abcd";
	char str4[128] = "abcdef";
	//문자열을 변수로 잡을때 예시
	// 몬스터 이름
	// 한국말로 , 골렘
	//            Golem
	//            인도어, 러시아어 이런데가면 <<<  문자열길이가 남달라집니다.

	// 예~전에 슈퍼마리오 만들던 시절에는
	//   메모리가 부족해서 아껴서 코딩을 했는데
	//   요즘은 그런거없습니다.
	//   메모리 다들기본적으로 16GB 끼고있죠 요즘은


}
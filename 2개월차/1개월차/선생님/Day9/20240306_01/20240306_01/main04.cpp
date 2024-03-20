#include <iostream>
#include <string>
using namespace std;

void main()
{
	//문자열 마지막
	char str[128] = "hello world!";		// C스타일
	//strcmp
	//strlen
	

	//C++ 스타일
	//string 자료형
	string str1 = "Hello World!";
	string str2 = "Hello World!";


	//문자열 비교
	if (str1 == str2)
	{
		printf("두 문자열이 같습니다.\n");
	}


	//문자열 입력
	//------------------------------------------
	//## 요 한줄이 핵심!!!
	getline(cin, str1);
	//------------------------------------------
	
	 
	// 정수 : %d
	// 실수 : %f
	// 주솟값 : %p
	// 문자 : %c
	// 문자열 : %s

	cout << str1 << endl;

	cout << "위가 getline----------------------------------" << endl;
	cin >> str1;
	cout << str1 << endl;

	cout << "위가 cin ----------------------------------" << endl;

	//getline은 line단위로 (엔터단위로 받는다)
	//cin 은 ' ', '\n', 문자 단위로 받는다.
	//cin.ignore()는 방어코드
	//엔터 => \n
	//사실 엔터는 => \r\n
	
	//CRLF => 엔터를 \r\n 요 문자로 취급하겠다. (Windows)
	//CR => 엔터를 \r 요 문자로 취급하겠다. (MacOS)
	//LF => 엔터를 \n 요 문자로 취급하겠다. (Linux)

	//콘솔은 저 엔터때문에 많이많이 괴로울 환경이 나와서

	// cin >> 문자열 한다음 엔터를 치면
	// \r 여기까지만 받아지고
	// \n 얘는 버퍼에 남아있어요.
	// 안버리면 다음 cin에 들어갑니다.
	// 그 버퍼를 버리는 역할을 해주는 함수가 cin.ignore() 함수에요.


}
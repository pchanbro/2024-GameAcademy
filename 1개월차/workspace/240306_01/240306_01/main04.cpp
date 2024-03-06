#include <iostream>
#include <string>
using namespace std;

void main()
{
	// 문자열 마지막
	char str[128] = "hello world"; // C언어 스타일


	// c++ 스타일
	// string 자료형
	string str1 = "Hello World!";
	string str2 = "Hello World!";

	// 문자열 비교
	if (str1 == str2) // str1, str2는 배열, 포인터가 아니기에 값 비교가 된다.
	{
		printf("두 문자열이 같습니다. \n");
	}

	// 문자열 입력
	// 이번 파일은 이 한줄이 핵심이다.
	getline(cin, str1);

	cin.ignore(); // 근데 ignore가 안된다 하신다 다음에 찾아서 알려주신다 한다.

	// 정수 : %d
	// 실수 : %f
	// 주솟값 : %p
	// 문자 : %c
	// 문자열 : %s

	cout << str1 << endl;
	

	cout << "위에는 getline ===================================" << endl;
	cin >> str1;
	cin.ignore(); // 방어코드
	cout << str1 << endl;

	cout << "위에는 cin ===================================" << endl;

	// getlin은 line 단위로(엔터단위로 받는다)
	// cin은 ' ', '\n', 문자 단위로 받는다.
	// cin.ignore()는 방어코드
	// 지금까지 엔터는 \n로 알고 있었다.
	// 하지만 사실 엔터는 => \r\n 이다
	// 이 창 좌측 하단에 CRLF라고 적힌게 있을거다
	// 그걸 누르면 CRLF, CR, LF가 있는데
	// CRLF => 엔터를 \r\n 문자로 취급하겠다. (windows)
	// CR => 엔터를 \r 문자로 취급하겠다. (MacOS)
	// LF => 엔터를 \n 문자로 취급하겠다. (Linux)

	// 콘솔은 저 엔터때문에 매우 괴로울 환경이 나오기 때문에 

	// 왜 괴롭냐면 
	// cin >> 문자열 한다음 엔터를 치면
	// /r 까지만 받아지고
	// \n 은 버퍼에 남아 있다.
	// 안버리면 다음 cin에 들어가기 때문에
	// 그 버퍼를 버리고자 cin.ignore() 을 사용한다. -> 다른거 찾아주신다 한다.
	// 참고로 이 개념은 콘솔에서만 쓰이는거고 
	// 콘솔 안쓰는 곳으로 넘어가면 몰라도 되는 부분 

}
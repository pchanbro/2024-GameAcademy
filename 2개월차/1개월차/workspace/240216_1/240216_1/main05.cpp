#include <iostream>
#include <time.h>

using namespace std;

void main()
{
	// 실습
	// 1.
	// 0 ~ 30 사이의 랜덤 숫자를 출력하기
	// 2.
	// int random1 변수에
	// 0 ~ 100 사이의 랜덤 숫자를 넣기
	// 3.
	// 25 ~ 40 사이의 랜덤 숫자를 출력하기
	// 4.
	// int random2 변수에
	// 150 ~ 270 사이의 랜덤 숫자를 넣기

	srand(time(NULL)); // 반드시 항상 선언해 줘라
	
	printf("0 ~ 30 사이의 랜덤 숫자 : %d\n", rand() % 31);
	int random1 = rand() % 101;
	printf("0 ~ 100 사이의 랜덤 숫자 : %d\n", random1);
	printf("25 ~ 40 사이의 랜덤 숫자 : %d\n", rand() % 16 + 25);

	int random2 = rand() % 121 + 150;
	printf("150 ~ 270 사이의 랜덤 숫자 : %d\n", random2);

	// 입력
	// input
	// -> 키보드, 마우스, 터치, 블루투스 등등
	// 그 중에서도 키보드, 마우스
	// -> 콘솔은 키보드만 씁니다.

	// scanf라 하는 가장 간단한 변수 입력
	int input1 = 0;

	//scanf_s("%d", &변수명);
	::scanf_s("%d", &input1);
	::printf("%d\n", input1);

	// 주사용처
	// 프로그램에 직접적인 개입이 가능함.
	// 선택지를 고를 수 있음.

	::printf("가위(0) 바위(1) 보(2) 중에 하나를 선택해주세요 : ");
	::scanf_s("%d", &input1);
	::printf("%d\n", input1);

	// 실습
	// 숫자 두 개를 입력받아서
	// 그 두 개의 사이의 랜덤 숫자를 출력하도록
	int num1 = 0, num2 = 0;
	printf("num1을 입력하세요 : ");
	scanf_s("%d", &num1);
	printf("num2를 입력하세요 : ");
	scanf_s("%d", &num2);

	if (num1 > num2)
		printf("%d와 %d사이의 수 출력 : %d", num2, num1, rand() % (num1 - num2 + 1) + num2);
	else 
		printf("%d와 %d사이의 수 출력 : %d", num1, num2, rand() % (num2 - num1 + 1) + num1);

	// 숙제
	// 숫자 네개를 입력받아서
	// 처음에 두 수 사이의 랜덤 숫자에
	// 세번째 숫자를 빼고
	// 네번쨰 숫자를 곱한값을 출력합니다.

}
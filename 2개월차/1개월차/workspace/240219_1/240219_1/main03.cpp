#include <iostream>

using namespace std;

void main()
{
	// IF문 실습

	// 1. 점수 4개를 입력받는다.
	// 2. 점수의 총합이 400점 이상이면 A를 출력한다.
	// 3. 점수의 총합이 350점 이상이면 B를 출력한다.
	// 4. 점수의 총합이 300점 이상이면 C를 출력한다.
	// 5. 그 미만이면 D를 출력한다.

	// if / else if / else 문을 활용하여 실습
	
	int num1 = 0, int num2 = 0,	int num3 = 0, int num4 = 0;

	printf("num1을 입력하세요 : ");
	scanf_s("%d", &num1);
	printf("num2을 입력하세요 : ");
	scanf_s("%d", &num2);
	printf("num3을 입력하세요 : ");
	cin >> num3;
	printf("num4을 입력하세요 : ");
	cin >> num4;

	int sum = num1 + num2 + num3 + num4;

	cout << "내 총 점수는 " << sum << " " << "A" < endl;
	printf("등급은 ");
	if (400 <= sum)
	{
		printf("A 입니다.\n");
	}
	else if(350 <= sum)
	{
		cout << "B 입니다.\n";
	}
	else if (300 <= sum)
	{
		cout << "C 입니다." << endl;
		// endl : \n 와 같다.
		// endl => end line (줄맺음)
	}
	else
	{
		cout << "D 입니다." << endl;
	}

	// TIP 변수명 바꾸기
	// (Ctrl + R + R) 
	
	// 일잘하는 프로그래머
	//	프로그래머가 아닌사람들이 봤을 때
	//	일잘하는 프로그래머는 빨리 만드는 사람
	//	빨리만드는 사람 : 단축키 잘쓰는 사람
}
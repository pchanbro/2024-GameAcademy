#include <iostream>

using namespace std;

void main()
{
	//SWITCH 문
	// IF문과 아주 유사하고 IF문에 대체될 수 있습니다.
	// 
	//어? 그러면 IF문 쓰면되지. 왜 SWITCH문 까지 복잡하게 배우나요?

	//SWITCH문이 가독성이 더 좋습니다.
	//그리고 아주 미세하지만 아주아주 미세하지만 살짝 더 빨라요.

	::printf("가위 (0), 바위(1), 보(2) 중에 하나를 입력하세요 : \n");
	int hand;
	cin >> hand;

	cout << "내가 뽑은 것은 : ";
	if (hand == 0)
	{
		cout << "가위" << endl;
	}
	else if (hand == 1)
	{
		cout << "바위" << endl;
	}
	else if (hand == 2)
	{
		cout << "보" << endl;
	}
	else
	{
		cout << "잘못 뽑았습니다" << endl;
	}


	//문법
	switch (hand)
	{
	case 0: //hand가 0이면
		cout << "가위" << endl;
		break;
	case 1: //hand가 1이면
		cout << "바위" << endl;
		break;
	case 2: //hand가 2면
		cout << "보" << endl;
		break;
	default: //그 외의 값이라면
		cout << "잘못 뽑았습니다." << endl;
		break;
	}

	//아까같이 350 ~ 400 점은 B출력
	//400이상이면 A출력
	//이런건 switch문으로 변경 불가능

	//비교연산자 
	// (비교연산자 결과는 항상 0과 1로 나온다)
	// >, <, >=, <=, ||, &&, ==, !=

	//연산자
	//사칙연산 => 연산자
	// +, -, *, /, %

	int myNumber = 1 + ((2 * 3) / 4) % ((5 > 1) && 1);
	//연산자끼리는 어떤게 먼저 이루어지는지에따라 결과가 달라져요

	// *, / 가 항상 먼저 적용됩니다.
	// +, - 가 나중에 되고

	// 모든 프로그래머가 저 순서를 외우고있지않아서
	// 기본적인 사칙연산말고는
	// 항상 우선순위 연산을 정해줌

	// 사칙연산에서도 ((1 + 1) * 2) 개념
}
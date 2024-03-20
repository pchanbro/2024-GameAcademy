#include <iostream>

using namespace std;

void main()
{
	// SWITCH 문
	// IF문과 아주 유사하며 IF문에 대체될 수 있다. 
	// 
	// 그렇다면 IF문 쓰면 되는데 왜 SWITCH문을 쓰나?

	// SWITCH문이 가독성이 더 좋다.
	// 아주아주 미세하나 살짝 더 빠르다.

	::printf("가위 (0), 바위 (1), 보(2) 중에 하나를 입력하세요 : \n");
	int hand;

	// cin과 cout은 std 출신이다
	// 즉, 원래는 
	std::cout << "안녕하세요" << endl;
	// 와 같이 써야한다 
	// 근데 위에 
	// using namespace std; 를 통해
	cout << "안녕하세요" << endl;
	// 처럼 앞에 (std::) 를 생략 가능하다.

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
		cout << "잘못 뽑았습니다. " << endl;
	}

	switch (hand)
	{
	case 0: //hand가 0이면
		cout << "가위" << endl;
		break;
	case 1: //hand가 1이면
		cout << "바위" << endl;
		break;
	case 2: //hand가 2이면
		cout << "보" << endl;
		break;
	default: // 그 외의 값이면
		cout << "잘못 뽑았습니다. " << endl;
		break;
	}
	// 아까처럼 350 ~ 400 점은 B출력 
	// 400 이상이면 A출력
	// 이런건 switch문으로 변경 불가능

	// 비교연산자 (비교연산자 결과는 항상 0과 1로 나온다)
	// >, < , >=, <=, ||, &&, ==, !=

	// 연산자
	// 사칙연산 => 연산자
	// +, -, *, /, %

	int myNumber = 1 + 2 * 3 / 4 % 5 > 1 && 1;
	// 연산자끼리는 어떤게 먼저 이루어지는지에 따라 결과가 달라진다.

	// *, / 가 +, - 보다 항상 먼저 적용됩니다.

	// 모든 프로그래머가 저 순서를 외우고 있지는 않음
	// 기본적인 사칙연산 말고는
	// 항상 우선순위 연산을 정해줌 ()를 통해 먼저 할 계산을 보여줌 
	// 만약 ()를 통해 우선순위를 표시해주지 않는다면 그 코드는 작성자만 보겠으니 타인은 신경쓰지 말라 (라는 암묵적인 룰이 존재한다)

	// 사칙연산에서도 ((1 + 1) * 2) 개념
}
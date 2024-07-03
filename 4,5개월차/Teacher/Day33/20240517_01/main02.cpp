#include <iostream>
using namespace std;

int Add(int num1, int num2)
{
	return num1 + num2;
}

int Subtract(int num1, int num2)
{
	return num1 - num2;
}

int Multiply(int num1, int num2)
{
	return num1 * num2;
}

int Divide(int num1, int num2)
{
	return num1 / num2;
}



void main()
{
	// 계산기 실습

	// 이론 배울때
	// [What, How], Why
	// 무엇이고 어떻게쓰는건지
	// 함수포인터에 대해

	// 함수포인터를 왜쓰는가?

	// 굳이 기괴한문법을 써가면서까지, 함수를 기억하고 그 변수로 사용해야하나??
	// myFunction1(2, 3); 호출하는것보다
	// Add(2,3); 이 훨씬더 가독성이 좋다.  << 이거는 이줄만읽어도 2와 3을 더한다.

	// 쓰는곳중에 한곳만 직관적으로 보이는곳
	// 몬스터 AI (몬스터)
	// 몬스터의 기본멤버변수로 
	//  -> void (몬스터::*DoSomething)(void)  라는 변수를 만들어서 
	//    활용을 합니다.

	// Update문에서
	//   - 플레이어가 내 주변에 있다 => DoSomething = &공격한다.
	//   - HP가 30 이하다 => DoSomething = &휴식한다.
	//   - 플레이어가 원거리에서 공격한다 => DoSomething = &돌진한다.

	// AI 로직에서는
	// 모든 몬스터는 DoSomething() 실행만하면, AI 로직이 완성이 되겠죠.

	// 결국에는 왜쓰냐??
	// DoSomething 변수하나로, 행동에 관한 모든 함수를 알아서 커버할수있다.

	

	// 계산기
	
	// 계산기 동작함수.
	int (*calculatorFunction)(int num1, int num2) = nullptr;
	int num1 = 0, num2 = 0;

	cout << "첫번째 숫자를 입력해주세요. " << endl;
	cin >> num1;

	cout << "두번째 숫자를 입력해주세요. " << endl;
	cin >> num2;

	int oper = 0;

	cout << "연산자를 입력해주세요 (+ : 0, - : 1, * : 2, / : 3)" << endl;
	cin >> oper;

	switch (oper)
	{
	case 0:
		calculatorFunction = &Add;
		break;
	case 1:
		calculatorFunction = &Subtract;
		break;
	case 2:
		calculatorFunction = &Multiply;
		break;
	case 3:
		calculatorFunction = &Divide;
		break;
	default:
		break;
	}

	if (calculatorFunction != nullptr)
	{
		cout << "결과 : " << calculatorFunction(num1, num2) << endl;
	}
}
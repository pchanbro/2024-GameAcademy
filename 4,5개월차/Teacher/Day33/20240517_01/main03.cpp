#include <iostream>
using namespace std;


//계산기를 객체라고 생각하고
// 기능 / 변수 를 나눠보겠습니다. 
// 
// 기능 (사용자가 어떻게 사용할것인가?)
//  - 숫자1을 입력한다.  InputNumber1()
//  - 숫자2을 입력한다.  InputNumber2()
//  - 연산자를 입력한다. InputOperator()
//  - 결과를 출력한다.   PrintResult()

// 변수
//  - int _num1
//	- int _num2;
//  - int _oper;
//  - int _result;

class Calculator
{
public:
	void InputNumber1()
	{
		cin >> _num1;
	}
	void InputNumber2()
	{
		cin >> _num2;
	}
	void InputOperator()
	{
		cout << "(0 : +, 1 : -, 2 : *, 3 : /)";
		cin >> _oper;
	}
	void PrintResult()
	{
		//연산후
		Calculate();
		// 결과 출력
		cout << "결과 : " << _result << endl;
	}

public:
	//사용자에게 노출할 필요가 없는 함수들
	void Add()
	{
		_result = _num1 + _num2;
	}
	void Subtract()
	{
		_result = _num1 - _num2;
	}
	void Multiply()
	{
		_result = _num1 * _num2;
	}
	void Divide()
	{
		_result = _num1 / _num2;
	}

	void Calculate()
	{
		switch (_oper)
		{
		case 0:
			calcFunction = &Calculator::Add;
			break;
		case 1:
			calcFunction = &Calculator::Subtract;
			break;
		case 2:
			calcFunction = &Calculator::Multiply;
			break;
		case 3:
			calcFunction = &Calculator::Divide;
			break;
		default:
			break;
		}

		//calcFunction
		// 
		//어? this를 써야하는데?
		//(calc.*calcFunction)();
		cout << "이거 쓰냐?" << endl;
		((*this).*calcFunction)();
		cout << this->calcFunction << endl; // 이거 하면 1 출력됨
		cout << "이거 썼냐??" << endl;
		//생김새부터가 완전 기괴합니다.
	}

private:
	int _num1 = 0;
	int _num2 = 0;
	int _oper = 0;
	int _result = 0;

	//함수반환형 (네임스페이스::*변수명)(매게변수)
	void (Calculator::* calcFunction)(void) = nullptr;
};



void main()
{
	// 계산기를 클래스화해서 만들어볼거에요.
	// 함수포인터를 아직 클래스 멤버함수로 해본적이 없습니다.

	Calculator calc;
	Calculator calc2;
	Calculator calc3;

	cout << "첫번째 숫자를 입력해주세요 : ";
	calc.InputNumber1();

	cout << "두번째 숫자를 입력해주세요 : ";
	calc.InputNumber2();

	cout << "연산자를 입력해주세요 : " ;
	calc.InputOperator();

	calc.PrintResult();

	void (Calculator:: * calcFunction)(void) = nullptr;

	calcFunction = &(Calculator::Add);
	
	//얘를 실행시킬때 calc,calc2,calc3 중에서 어떤 객체의 Add 함수를 호출시킬거냐??
	//calcFunction();

	//멤버함수를 포인터로 쓸때는 어떤 객체에서 쓸건지까지 확실하게 지정해줘야함.

	//calc.calcFunction();
	// 이렇게 적는 형식은, 그냥 calc의 함수콜이다.


	//생각
	// 함수포인터는  주소를 기억
	//calc 이 객체의
	// calcFunction여기에 저장된 주소로 가서 실행시켜라.
	// *calcFunction
	//(calc.*calcFunction)();
	//((*this).*calcFunction)();

}

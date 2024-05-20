#include <iostream>
#include <functional>
using namespace std;

void Run1()
{
	cout << "Run1" << endl;
}

void Run2(int a)
{
	cout << "Run2, " << a << endl;
}

int Run3(int a)
{
	cout << "Run3, " << a << endl;

	return a + 3;
}

class TestObject
{
public:
	void DoSomething()
	{
		cout << "DoSomething" << endl;
	}
};

void main()
{
	// C++20 문법 사용하는 방법
	// visual studio 2019, 2017 << 여기서는 안됩니다. C++20기능이 아예없어요.


	//함수포인터문법
	// 반환자료형 네임스페이스::*변수명(매게변수) = 값;
	// function<반환자료형(매게변수)> 변수명 = 값;
	function<void()> myFunction1 = &Run1;
	function<void(int)> myFunction2 = &Run2;
	function<int(int)> myFunction3 = &Run3;


	myFunction1();
	myFunction2(2);
	cout << "Result : " << myFunction3(4) << endl;

	//이렇게 선언하는 형식
	function<void(TestObject&)> myFunction4 = &TestObject::DoSomething;

	TestObject t1;
	myFunction4(t1);

	// 실제로 적용할 코드
	function<void()> myFunction5 = nullptr;
	// bind(바인딩시킬 함수, 실행시킬 object)
	myFunction5 = bind(&TestObject::DoSomething, &t1);
	myFunction5();


	// function, bind, (mem_fn)
}
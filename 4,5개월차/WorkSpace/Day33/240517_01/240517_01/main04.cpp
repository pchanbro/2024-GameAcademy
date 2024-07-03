#include <iostream>

using namespace std;

void Function1()
{

}

class TestObject
{
public:
	void operator() (int a) 
	{
		cout << "A : " << a << endl; 
	}
};

void main()
{
	// 함수포인터 더 할게 남아있나?
	// 함수포인터는 끝났다.

	// Callable 관련된게 안끝났다.
	// [Callable] << 
	// () 연산자를 사용하는걸 Collable 이라고 한다.
	Function1(); // () 사용했으니 Collable
	// 그렇다면 Callable이 곧 함수인가?
	// 그렇지 않다.
	// 포함관계일 뿐
	TestObject obj;
	obj(3); // 얘는 함수가 아니다. 하지만 ()를 썼으니 Callable 이긴하다.

	obj.operator()(3); // 엄격히 따지면 이 형태임

	// 위에내용 하나도 안중요하다.
	// 그냥 스쳐지나가는 상식정도로 흘려들으면 된다.

	// --------------------------------------------------------------------------

	// 지금부터 배울내용
	// C++20에 새롭게 나온 Callable 호출방법
	
	// C, C++에 대한 역사
	// 상식선에서 들어라 (이런게 있었지)
}
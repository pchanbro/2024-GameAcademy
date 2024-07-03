#include <iostream>
#include <vector>
using namespace std;

void Function1()
{

}

class TestObject
{
public:
	void operator()(int a) 
	{ 
		cout << "A : " << a << endl; 
	}
};

void main()
{
	// 함수포인터 더할게 남아있나??
	// 함수포인터는 끝났어요.

	// Callable 관련된게 안끝났어요.
	// [Callable] << 
	// () 연산자를 사용하는게 Callable이라고 합니다.
	Function1(); // Callable
	// 어? 그러면 Callable이게 곧 함수잖아요.
	// 라고하면 아니에요.
	TestObject obj;
	obj(3);	// 얘는 함수가 아닙니다. Callable 이긴함.

	obj.operator()(3); // 엄격히 따지면 이 형태임.

	// 위에내용 하나도 안중요합니다.
	// 그냥 스쳐지나가는 상식정도로 흘려들으면돼요.

	//────────────────────────────────────────────────────────────

	//지금부터 배울내용
	// C++20에 새롭게 나온 Callable 호출방법.

	// C, C++에 대한 역사
	// 상식선에서 들어주세요.
	// (이런게 있었지 하고 기억할정도로 들어주세요.)

	// 태초의 C++에는

	vector<int> a;
	a.push_back(3);
	a.push_back(4);

	for (int v : a)	// 이형태가 C++ 태초의 형태에서는 불가능했음
	{

	}

	// 시대마다 언어가 발전해나가면서 
	// 쓸수있는 문법들이 추가됩니다.

	// C++97 (태초)
	// C++14, C++17, C++20

	// 년도
	// C++20 => 2020년에 나왔다.
	// 4년전이니까, 모든회사에서 쓰지않을까?
	// 아직까지도 c++17로만 쓰는곳이 있어요.

	// 게임서버
	// 자체엔진 



}
#pragma once

template <typename Node> // 여기서의 Node 자리는 보통 T로 쓰이는데 그 부분은
// vector 선언할 때 <int> <float> 이런식으로 반환형을 설정하는데 
// 내가 설정한 게 int이면 T가 모두 int가 되고 내가 float라 하면 T가 모드 float가 된다. 그런 느낌
class MyVector
{
private:
	Node* _arr = nullptr;
	int _size = 0;
	int _capacity = 2; // 근데 옮길때마다 위치가 바뀌니까 capacity라는게 존재
	// 근데 이것도 옮겨질때마다 1.5배만 되는데 이런 부분들을 입맛대로 바꾸고 싶어서
	// 게임사에서 직접 vector를 만드는것
public: 
	void push_back(Node data);
	Node at(int index);

	// 이것도 함수다.
	// 반환자료형 : Node 
	// 함수명 : operator
	// 매개변수 : int index
	Node operator[](int index);
	// 이 operator는 
	// vec.oprator[](1)
	// vec[1] 
	// 이 두가지가 같은거다
	// 벡터는 결국엔 배열의 다른모습이라고 생각해도되는데
	// operator[] 를 배열의 다른 모습이라고 생각하는 건안돼요!!
	// operator는 함수일 뿐, 함수호출이라고만 생각해라.
public:
	MyVector();
	~MyVector();
};

// 클래스 연산자로 할 수 있는 것
// 나중에 
// Damage 클래스(큰 게임에는 무조건 존재할 것이다)
// 연산자 오버라이딩을 활용해서 계산을 해준다.
#include <iostream>

using namespace std;

class Key
{

};

class MasterKey : public Key
{

};

int main()
{
	// 형변환 캐스팅 (4가지)

	// 1개는 C형식입니다.

	//자료형과 변수
	int a = 3;
	float b = 1.1f;
	string str = "My String";
	bool d = true;

	//1. - C형식 캐스팅
	int e = (int)b;

	//주소값을 정수(int)로 받는다.
	//int f = (int)&b;
	//printf("%d\n", f);

	//2. C++형식의 캐스팅
	// -1. static_cast (정적 캐스팅)
	//float -> int
	int g = static_cast<int>(b);

	// -2. dynamic_cast
	// 상속간 가지고오는 캐스팅
	MasterKey* key = new MasterKey();
	Key* myKey1 = dynamic_cast<MasterKey*>(key);

	// -3. reinterpret_cast
	// 거의 안씁니다.
	// 메모리 그대로 캐스팅 해줄때.
	int bb = 123;
	int* ptr1 = reinterpret_cast<int*>(bb);
	
	cout << *ptr1 << endl;

	return 0;
}
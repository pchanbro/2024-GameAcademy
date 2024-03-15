#include <iostream>
#include "MyVector.h"
#include <vector>

using namespace std;

void main()
{
	// 벡터구현
	MyVector<int> vec = {};
	vector<string> vec1 = {};

	// 이제는 백터라기 보다는 클래스 관련
	// 연산자 오버라이딩
	// 클래스끼리 +(더하기) 가능할까??
	// 안된다..
	// 근데 그런 연산자를 만들 수 있다.

	for (int i = 0; i < 10; i++)
	{
		vec.push_back(i);
		vec1.push_back(i);
	}

	for (int i = 0; i < 10; i++)
	{
		cout << vec.at(i) << endl;
	}
}

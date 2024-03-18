#include <iostream>
#include "MyVector.h"
#include <vector>
using namespace std;

void main()
{
	//템플릿 빌드 과정
	MyVector<int> vecInt = {};
	MyVector<float> vecFloat = {};


	//벡터구현
	MyVector<int> vec1 = {};
	MyVector<int> vec2 = {};
	vector<int> vec = {};

	//클래스
	//연산자 오버라이딩
	//클래스끼리 + 가능할까요?
	// +, -, *, / , %, []

	for (int i = 0; i < 10; i++)
	{
		//vec.push_back(i);
		vec1.push_back(i);
	}

	vec1.operator[](0) = 10;
	vec1[0] = 10;

	//vec[0] = 3;
	//0 = 10;
	// 대입이 가능한 경우는
	//  왼쪽이 변수일때
	// 변수는 메모리공간 어쩌고 이런느낌
	// lvalue => left value
	// rvalue => right value;

	//for (int i = 0; i < 10; i++)
	//{
	//	//cout << vec[i] << endl;
	//	cout << vec1[i] << endl;
	//}


	//실습.

	//3번째 값에 5를 추가하겠다.
	vec1.insert(3, 50);
	vec1.insert(3, 100);

	for (int i = 0; i < vec1.size(); i++)
	{
		cout << vec1[i] << endl;
	}
}
#include <iostream>
#include "MyVector.h"
#include <vector>
using namespace std;

void main()
{
	//���ø� ���� ����
	MyVector<int> vecInt = {};
	MyVector<float> vecFloat = {};


	//���ͱ���
	MyVector<int> vec1 = {};
	MyVector<int> vec2 = {};
	vector<int> vec = {};

	//Ŭ����
	//������ �������̵�
	//Ŭ�������� + �����ұ��?
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
	// ������ ������ ����
	//  ������ �����϶�
	// ������ �޸𸮰��� ��¼�� �̷�����
	// lvalue => left value
	// rvalue => right value;

	//for (int i = 0; i < 10; i++)
	//{
	//	//cout << vec[i] << endl;
	//	cout << vec1[i] << endl;
	//}


	//�ǽ�.

	//3��° ���� 5�� �߰��ϰڴ�.
	vec1.insert(3, 50);
	vec1.insert(3, 100);

	for (int i = 0; i < vec1.size(); i++)
	{
		cout << vec1[i] << endl;
	}
}
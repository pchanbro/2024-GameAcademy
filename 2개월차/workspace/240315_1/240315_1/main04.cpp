#include <iostream>
#include "MyVector.h"
#include <vector>

using namespace std;

void main()
{
	// ���ͱ���
	MyVector<int> vec = {};
	vector<string> vec1 = {};

	// ������ ���Ͷ�� ���ٴ� Ŭ���� ����
	// ������ �������̵�
	// Ŭ�������� +(���ϱ�) �����ұ�??
	// �ȵȴ�..
	// �ٵ� �׷� �����ڸ� ���� �� �ִ�.

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

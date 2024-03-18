#include <iostream>

using namespace std;

void main()
{
	// Linked List 타임어택!

	LinkedList list;
	for (int i = 0; i < 10; i++)
	{
		list.push_back(i);
	}

	for (int i = 0; i < 10; i++)
	{
		cout << list.at(i) << endl;
	}

	// 여기까지 출력값: 0 ~ 9

	list.pop_back();

	for (int i = 0; i < 5; i++)
	{
		list.push_back(100 + i);
	}

	for (int i = 0; i < 14; i++)
	{
		cout << list.at(i) << endl;
	}

	// 여기까지 출력값: 0 ~ 8, 100 ~ 104
}
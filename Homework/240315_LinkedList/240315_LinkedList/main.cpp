#include <iostream>
#include "LinkedList.h"

using namespace std;

void main()
{
	LinkedList list;

	list.push_back(10);
	list.push_back(20);
	list.push_back(30);

	list.pop_back();

	list.push_back(40);
	list.push_back(50);
	list.push_back(60);
	list.push_back(70);

	list.pop_back();

	list.remove_data(10);
	list.add_data(10, 7);

	for (int i = 0; i < 5; i++)
	{
		printf("list[%d] : %d\n", i, list.at(i));
	}
}
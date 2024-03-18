#include <iostream>
#include "MyVector.h"

using namespace std;

void main()
{
	MyVector<int> vec = {};
	
	for (int i = 0; i < 10; i++)
	{
		vec.push_back(i);
	}

	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << endl;
	}
}
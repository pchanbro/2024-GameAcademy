#include <iostream>
#include <vector>
using namespace std;

void main()
{
	//2. vector �̷м��� / ����

	int arr[10];
	int count = 10;
	cin >> count;
	int* myArr = new int[count];
	delete[] myArr;

	vector<int> myDatas;
	myDatas.push_back(10);
	myDatas.push_back(20);
	myDatas.push_back(30);

	for (int i = 0; i < myDatas.size(); i++)
	{
		cout << myDatas[i] << endl;
	}
}
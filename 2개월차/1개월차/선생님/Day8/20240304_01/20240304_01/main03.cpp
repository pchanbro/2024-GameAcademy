#include <iostream>
#include <vector>
using namespace std;

void main()
{
	//vector ���� ���Կ�!!
	//vector ������ �ǰ� �߿��ϰ�, ���� ȸ�翡�� ��ü���� vector�� ����մϴ�.

	//vector�� ??? 
	//���������� �迭

	int arr[5] = {0, 0, 0, 0, 0};
	//5�� �ƴ϶� 6..

	//���׿��극����
	//4:4 ����
	// 1���� �߰��� ����

	int player[8] = {};
	// ==>
	//�߰��� ����������
	//int player[9] = {};
	//player[8] = 4;

	//vector ����!!
	// - #include<vector>
	// - using namespace std; �� ����Ǿ��־����.

	vector<int> myVector;
	//myVector.push_back(0);	//�ǵڿ� ��Ҹ� �߰��Ѵ�.

	// �ζ� ������ �����ϰ� �����ڽ��ϴ�. (���� ����)

	for (int i = 0; i < 45; i++)
	{
		//arr[i] = i + 1;
		myVector.push_back(i + 1);
	}

	printf("Vector Size : %lld\n", myVector.size());

	//myVector.begin() + 5 => 5��° �ε����� ����ڴ�.
	myVector.erase(myVector.begin() + 5);

	//cout << "Vector "
	for (int i = 0; i < myVector.size(); i++)
	{
		printf("%d\n", myVector[i]);
	}

	vector<vector<int>> arr1;

	for (int i = 0; i < 5; i++)
	{
		vector<int> temp;
		for (int j = 0; j < 5; j++)
		{
			temp.push_back(i * 5 + j);
		}
		arr1.push_back(temp);
	}
	

	system("cls");
	for (int i = 0; i < arr1.size(); i++)
	{
		for (int j = 0; j < arr1[i].size(); j++)
		{
			printf("%d\t", arr1[i][j]);
		}
		printf("\n");

	}

}
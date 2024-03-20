#include <iostream>
#include <vector>

using namespace std;

void main()
{
	// vector ���� �����
	// vector ������ �ſ� �߿��ϰ�, ���� ȸ�翡�� ��ü���� vector�� ����Ѵ�.

	// vector��?
	// ���������� �迭

	int arr[5] = {};
	// �� ũ�Ⱑ 5�� ������ ũ�⸦ ���ڱ� 6�̳� �� �ٸ��ɷ� �����ϰ� �ʹ�
	// �� �� ����ϴ°�

	// vector ����
	// - #include<vector>
	// - using namespace std; �� ����Ǿ� �־�� �Ѵ�.

	vector<int> myVector;
	//myVector.push_back(0);	// �ǵڿ� ��Ҹ� �߰��Ѵ�.

	//�ζ� ������ �����ϰ� �����ڽ��ϴ�. (���� ����)

	for (int i = 0; i < 45; i++)
	{
		//arr[i] = i + 1;
		myVector.push_back(i + 1);
	}

	printf("Vector Size : %d\n", myVector.size());

	// myVector.begin() + 5 -> 5��° �ε���
	myVector.erase(myVector.begin() + 5);

	for (int i = 0; i < myVector.size(); i++)
	{
		printf("%d\n", myVector[i]);
	}


	// vector2���� ���� ��� : �� �� �� ���´�
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
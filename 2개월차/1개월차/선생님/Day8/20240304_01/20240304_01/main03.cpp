#include <iostream>
#include <vector>
using namespace std;

void main()
{
	//vector 먼저 배울게요!!
	//vector 구현은 되게 중요하고, 보통 회사에서 자체구현 vector를 사용합니다.

	//vector란 ??? 
	//가변길이의 배열

	int arr[5] = {0, 0, 0, 0, 0};
	//5가 아니라 6..

	//리그오브레전드
	//4:4 게임
	// 1명이 중간에 참여

	int player[8] = {};
	// ==>
	//중간에 참여했으니
	//int player[9] = {};
	//player[8] = 4;

	//vector 사용법!!
	// - #include<vector>
	// - using namespace std; 가 선언되어있어야함.

	vector<int> myVector;
	//myVector.push_back(0);	//맨뒤에 요소를 추가한다.

	// 로또 생성기 간단하게 만들어보겠습니다. (섞기 제외)

	for (int i = 0; i < 45; i++)
	{
		//arr[i] = i + 1;
		myVector.push_back(i + 1);
	}

	printf("Vector Size : %lld\n", myVector.size());

	//myVector.begin() + 5 => 5번째 인덱스를 지우겠다.
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
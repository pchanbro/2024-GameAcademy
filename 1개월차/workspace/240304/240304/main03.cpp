#include <iostream>
#include <vector>

using namespace std;

void main()
{
	// vector 먼저 배우자
	// vector 구현은 매우 중요하고, 보통 회사에서 자체구현 vector를 사용한다.

	// vector란?
	// 가변길이의 배열

	int arr[5] = {};
	// 이 크기가 5인 변수의 크기를 갑자기 6이나 뭐 다른걸로 변경하고 싶다
	// 할 때 사용하는거

	// vector 사용법
	// - #include<vector>
	// - using namespace std; 가 선언되어 있어야 한다.

	vector<int> myVector;
	//myVector.push_back(0);	// 맨뒤에 요소를 추가한다.

	//로또 생성기 간단하게 만들어보겠습니다. (섞기 제외)

	for (int i = 0; i < 45; i++)
	{
		//arr[i] = i + 1;
		myVector.push_back(i + 1);
	}

	printf("Vector Size : %d\n", myVector.size());

	// myVector.begin() + 5 -> 5번째 인덱스
	myVector.erase(myVector.begin() + 5);

	for (int i = 0; i < myVector.size(); i++)
	{
		printf("%d\n", myVector[i]);
	}


	// vector2차원 쓰는 방법 : 한 번 더 감는다
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
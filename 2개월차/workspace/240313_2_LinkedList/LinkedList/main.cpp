#include <iostream>
#include <vector>
#include "LinkedList.h"

using namespace std;

void main()
{
	// 당분간 숙제는 외워오기
	// 자료구조는 게임 프로그래머에게 매우 중요
	// 한 번씩 외워보는게 아주 중요하다.
	
	// 선생님도 한 번에 못칠정도로 어려운 자료구조가 있다.
	// 그런건 이론설명을 듣고
	// 구현하는걸 숙제로

	LinkedList list;
	
	list.push_back(10);
	list.push_back(20);

	list.push_back(30);
	list.pop_back();

	list.push_back(40);

	list.add_data(80, 1);

	list.push_back(50);

	list.remove_data(40);
	

	for (int i = 0; i < 4; i++)
	{
		printf("list[%d] : %d\n", i, list.at(i));
	}


	// 자료구조 / 알고리즘에서 다루는 중요한 것.
	// 시간복잡도
	// 어떤 함수를 실행했을 때
	// 걸리는 시간 기댓값
	// ( 그 함수 안에서 포문이 얼마나 반복돼냐? 이런거)

	// 자료구조의 데이터가 N개라고 가정할 때
	// O(n) => n번 순환한다.
	// O(n) + O(n) => O(n)  // 최저고하 수치가 같다.
	// O(n^2) => 이중포문 돌았다.
	// O(n^3) => 삼중포문 돌았다.

	// 컨텐츠쪽 프로그래밍 현업에서는 시간복잡도를 잘 모른다.
	// 코테볼때는 매우 중요

	//LinkedList는 기본적으로 대부분의 함수가 O(n)이다.
	// 이게 추가 / 삭제에서는 O(n)이 좋아보지만
	// 조회할 때 O(n)이 걸리면 매우 안좋다.

	// 조회할 때 매우 안좋기 때문에 LinkedList를 잘 안쓴다.

	int arr[10] = {};
	// 5번쨰인덱스 어떻게 접근할까?
	// arr[5]하면됨
	// 이게 내부적으로 어떤 일을하냐?
	// 나머지는 영상이랑 선생님꺼 좀 둘러보기
}
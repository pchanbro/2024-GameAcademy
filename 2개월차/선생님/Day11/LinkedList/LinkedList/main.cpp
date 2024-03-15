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

	list.add_data(80, 1);
	list.remove_data(40);
	list.push_back(50);


	for (int i = 0; i < 4; i++)
	{
		printf("list[%d] : %d\n", i, list.at(i));
	}


	//실습 내용!
	//remove_data
	//add_data 
	//완성
	//9시까지 1차로 시간드리고
	//9시에 수도코드를 설명드리고
	// 시간추가로 더드릴게요!
	//linkedlist의 장단점 설명하고 끝낼거에요!


	//자료구조 / 알고리즘 에서 중요하게 다루는게 있습니다.
	//시간복잡도
	//시간복잡도가 무엇이냐??
	// 어떠한 함수를 실행했을떄
	// 걸리는 시간 기댓값
	// (그 함수안에서 포문 얼마나 도냐?)
	// 시간복잡도가
	
	//그 자료구조의 데이터가 N개라고 가정할때
	//O(n) => n번 순환한다.
	//O(n) + O(n) => O(n)
	//최적화 수치가 같다.
	//코어 엔진단,, 

	// 실제로 컨텐츠쪽 프로그래밍 현업에서는 시간복잡도자체를
	// 사람들이 몰라요.

	//LinkedList는 기본적으로
	// 대부분의 함수가 O(n)이다.
	// 이게 추가 / 삭제 에서는 O(n)이 되게 좋게보이지만
	// 조회에서 O(n)이 걸리는건 아주아주 큰 단점!!


	int arr[10] = {};
	// 5번째인덱스 어떻게 접근할까?
	// arr[5]하면됨
	// 이게 내부적으로 어떤 일을하냐?
	// arr 포인터에 + 5를한게 끝입니다
	// 이건 시간복잡도 O(1)

}
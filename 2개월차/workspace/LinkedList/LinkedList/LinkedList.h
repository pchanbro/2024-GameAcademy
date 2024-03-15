#pragma once
struct Node
{
	int Data;	// 자기 자신 데이터
	Node* Next;// 다음 데이터를 가리키는 포인터
};

class LinkedList
{
private:
	// 멤버변수 적는 자리
	// 왜 동적할당으로 들고있는건가
	// 자료구조는 대부분 동적할당인데 그 이유는
	// 데이터가 있을 수도 있고, 없을 수도 있기 때문이다(nullptr 형태일 수도 있어서).

	Node* _root = nullptr;

public:
	// 생성자 소멸자
	LinkedList();
	~LinkedList();

	// 이런식으로 public를 여러 번 써서 함수별로 구분짓는 느낌으로 사용한다.
	// 어떤 public는 몬스터랑 상호작용하는 부분
	// 어떤 public는 생성자 소멸자 이런 느낌


	// MS에서 C++관련 만든 함수들은 다 snake case라 하는
	// 소문자로쓰고 띄어쓰기를 _로 사용한다.

	// C#에서는
	// 함수를 모두 대문자로 시작하고
	// 띄어쓰기마다 대문자로 작성

	// 근데 이런 함수이름짓는 룰은 회사에서 정해준다.
	// 회사 룰 따르면 된다.
public:
	// list 마지막에 데이터를 넣는다.
	void push_back(int data);
	void pop_back();
	int at(int index);

	// 데이터 값을 판별하여 그 노드를 삭제
	// 중복된 데이터가 있으면
	// 앞에있는 인덱스 데이터가 삭제
	void remove_data(int data);

	// 내가 원하는 인덱스에
	// 데이터 넣기
	void add_data(int data, int index);
};


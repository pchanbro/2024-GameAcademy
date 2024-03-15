#pragma once
struct Node
{
	int Data;	//자기자신 데이터 
	Node* Next;//다음 데이터를 가르키는 포인터
};


class LinkedList
{
private:
	//멤버변수 적는 자리.
	//왜 동적할당으로 들고있는거지??
	//	=> nullptr 형태일수도있어서..
	Node* _root = nullptr;


	//생성자 소멸자
public:
	LinkedList();
	~LinkedList();

	//함수별로 구분짓는 느낌으로 사용합니다.
	// 요 public은 몬스터랑 상호작용하는 부분
	// 요 public은 생성자 소멸자 이런느낌..
public:
	//list 마지막에 데이터를 넣는다.
	void push_back(int data);
	void pop_back();
	int at(int index);


	//데이터 값을 판별하여 그 노드를 삭제
	//중복된 데이터가 있으면
	//앞에 인덱스 데이터가 삭제.
	void remove_data(int data);

	// 내가원하는 인덱스에
	// 데이터 넣기
	void add_data(int data, int index);
};


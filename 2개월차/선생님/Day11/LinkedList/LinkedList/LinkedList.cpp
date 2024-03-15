#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList()
{

}

LinkedList::~LinkedList()
{

}

void LinkedList::push_back(int data)
{
	//마지막에 데이터를 넣는다.

	//수도 코드 매우중요!!
	//수도코드를 알면 이 자료구조의 장단점을 알수밖에 없음

	//1. newNode를 만들어준다.
	// 
	//2. _root 값을 복사한다.
	//	current = _root
	//
	//3-1. _root가 NULL이 아니라면
	//	current의 Next가 null이 될때까지 
	//	current를 Next로 넘긴다.
	//	newNode의 주소를 current Next에 대입시킨다.
	//3-2. _root가 NULL이라면
	//	_root에 newNode를 대입시킨다.


	//1. newNode를 만들어준다.
	Node* newNode = new Node();
	newNode->Data = data;
	newNode->Next = nullptr;

	//2. _root 값을 복사한다.
	Node* current = _root;

	//3-1. _root가 NULL이 아니라면
	if (_root != nullptr)
	{
		//	current의 Next가 null이 될때까지 
		//	current를 Next로 넘긴다.
		while (current->Next != nullptr)
		{
			current = current->Next;
		}

		//	newNode의 주소를 current Next에 대입시킨다.
		current->Next = newNode;
	}
	//3-2. _root가 NULL이라면
	else
	{
		//	_root에 newNode를 대입시킨다.
		_root = newNode;
	}
}

void LinkedList::pop_back()
{
	if (_root == nullptr)
	{
		printf("_root가 nullptr 입니다.\n");
		return;
	}

	//1. DeletedNode를 만든다.
	Node* deletedNode = _root;

	//2. CurrentNode를 만든다.
	Node* currentNode = _root;

	//3. DeletedNode를 가장 마지막으로 보낸다.
	while (deletedNode->Next != nullptr)
	{
		deletedNode = deletedNode->Next;
	}

	//4. CurrentNode의 Next가 DeletedNode가 나올때까지 옆으로 넘긴다.
	while (currentNode->Next != deletedNode)
	{
		currentNode = currentNode->Next;
	}

	//5. DeletedNode지운다
	if (deletedNode != nullptr)
	{
		delete deletedNode;
		deletedNode = nullptr;
	}

	//6. CurrentNode의 Next를 NULL처리해준다.
	currentNode->Next = nullptr;
}

int LinkedList::at(int index)
{
	//수도코드

	//current를 생성한다.
	Node* current = _root;

	//(index)번 만큼 Next로 이동한다
	for (int i = 0; i < index; i++)
	{
		current = current->Next;
	}
	
	//그 값을 return한다.
	return current->Data;
}

// 숙제 2가지 선택지
//  - 1. 이거 외우기 (Prev없는 버전) 
//		(LinkedList.h, LinkedList.cpp)
//  - 2. LinkedList가 Next밖에 없잖아요?
//		Prev도 있을수 있습니다.
//		Prev만드는 버전.

void LinkedList::remove_data(int data)
{
	//1. CurrentNode와 DeleteNode를 만든다.
	Node* currentNode = _root;
	Node* deleteNode = _root;

	//2. 원하는 데이터를 만날때까지 DeleteNode를 넘긴다.
	while (deleteNode->Data != data)
	{
		deleteNode = deleteNode->Next;
	}

	//3. CurrentNode->Next가 DeleteNode가 될때까지 넘긴다.
	while (currentNode->Next != deleteNode)
	{
		currentNode = currentNode->Next;
	}

	//4. CurrentNode->Next를 DeleteNode의 Next로 바꾼다.
	currentNode->Next = deleteNode->Next;

	//5. DeleteNode를 삭제한다.
	delete deleteNode;
	deleteNode = nullptr;
}

void LinkedList::add_data(int data, int index)
{
	//1. CurrentNode를 만든다
	Node* currentNode = _root;
	
	//2. 원하는 인덱스까지 CurrentNode를 넘긴다.
	for (int i = 0; i < index; i++)
	{
		currentNode = currentNode->Next;
	}
	
	//3. NewNode를 만든다
	Node* newNode = new Node();
	newNode->Data = data;
	
	//4. NewNode->Next를 CurrentNode->Next로 바꾼다.
	newNode->Next = currentNode->Next;
	
	//5. CurrentNode->Next를 NewNode로 바꾼다.
	currentNode->Next = newNode;
}
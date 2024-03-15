#include "LinkedList.h"
#include <iostream>

using namespace std;

LinkedList::LinkedList()
{

}

LinkedList::~LinkedList()
{

}


void LinkedList::push_back(int data)
{
	// 마지막에 데이터를 넣는다.

	// 수도 코드 
	// 수도코드를 알면 자료구조의 장단점을 알 수 밖에 없다.

	// 1.newNode를 만들어준다.
	// 
	// 2. _root값을 복사한다.
	// current = _root
	// 
	// 3-1. _root가 NULL이 아니라면
	// current가 Next가 null이 될때까지 
	// current를 Next로 넘긴다.
	// newNode의 주소를 current Next에 대입시킨다.
	// 3-2. _root가 NULL이라면
	// _root에 newNode를 대입시킨다.

	// 1.newNode를 만들어준다.
	Node* newNode = new Node();
	newNode->Data = data;
	newNode->Next = nullptr;

	// 2. _root값을 복사한다.
	Node* current = _root;

	// 3-1. _root가 NULL이 아니라면
	if (_root != nullptr)
	{
		// current->Next가 null이 될때까지.
		// current를 Next로 넘긴다.
		while (current->Next != nullptr)
		{
			current = current->Next;
		}

		// newNode의 주소를 current Next에 대입시킨다.
		current->Next = newNode;
	}
	// 3-2. _root가 NULL이라면
	else
	{
		// _root에 newNode를 대입시킨다.
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

	// 1. DeletedNode를 만든다.
	Node* deletedNode = _root;

	// 2. CurrentNode를 만든다.
	Node* currentNode = _root;

	
	// 3. DeletedNode를 가장 마지막으로 보낸다.
	while (deletedNode->Next != nullptr)
	{
		deletedNode = deletedNode->Next;
	}

	// 4. CurrentNode의 Next가 DeletedNode가 나올 때 까지 옆으로 넘긴다.
	while (currentNode->Next != deletedNode)
	{
		currentNode = currentNode->Next;
	}

	// 5. DeletedNode를 지운다.
	if(deletedNode != nullptr)
	{
		delete deletedNode;
		deletedNode = nullptr;
	}

	// 6. CurrentNode의 Next를 NULL처리해준다.
	currentNode->Next = nullptr;
}

int LinkedList::at(int index)
{
	// 수도코드

	// current를 생성한다.
	Node* current = _root;

	// (index)번 만큼 Next로 이동한다.
	for (int i = 0; i < index; i++)
	{
		current = current->Next;
	}

	// 그 값을 return 한다.
	return current->Data;
}

void LinkedList::remove_data(int data)
{
	// 1. deleteNode를 만든다.
	Node* deleteNode = _root;

	// // 2. CurrentNode를 만든다.
	Node* currentNode = _root;

	// 3. deleteNode를 Data값이 매개변수 data와 같은 값이 나올때까지 Next로 이동한다.
	while ((deleteNode->Data != data) && (deleteNode->Next != nullptr))
	{
		deleteNode = deleteNode->Next;
	}

	// 4-2. 매개변수 data값을 Data로 가진 노드가 존재하지 않는다면
	// 4-2-1. 값이 존재하지 않음을 표시한다.
	if (deleteNode->Next == nullptr)
	{
		cout << "지우려는 값이 존재하지 않습니다. " << endl;
		return;
	}

	// 4-1. 매개변수 data값을 Data로 가진 노드가 존재한다면
	// 4-1-1. currentNode의 Next가 deleteNode가 나올 때 까지 옆으로 넘긴다.
	while (currentNode->Next != deleteNode)
	{
		currentNode = currentNode->Next;
	}

	// 4-1-2. currentNode의 Next에 deleteNode의 next를 대입한다.
	currentNode->Next = deleteNode->Next;

	// 4-1-3. deleteNode를 제거한다.
	delete deleteNode;
	deleteNode = nullptr; // 이건 해도되고 안해도 되는데 해주는 습관을 들여라
	// 나중에 이거 안해서 문제가 발생할 수 있다.
}

void LinkedList::add_data(int data, int index)
{
	// 1. newNode를 만든다.
	Node* newNode = new Node;
	newNode->Data = data;
	newNode->Next = nullptr;

	// 2. CurrentNode를 만든다.
	Node* CurrentNode = _root;

	// 3. CurrentNode를 index-1번 Next로 옮긴다.
	for (int i = 0; i < index-1; i++)
	{
		CurrentNode = CurrentNode->Next;
	}

	// 4. newNode의 next를 CurrentNode의 Next로 설정한다.
	newNode->Next = CurrentNode->Next;
	
	// 5. CurrentNode의 next를 newNode로 설정한다.
	CurrentNode->Next = newNode;
}

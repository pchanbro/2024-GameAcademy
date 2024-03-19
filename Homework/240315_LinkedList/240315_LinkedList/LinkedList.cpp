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
	Node* newNode = new Node();
	newNode->Data = data;
	newNode->Next = nullptr;
	newNode->Prev = nullptr;

	Node* currentNode = _root;

	if (_root != nullptr)
	{
		while (currentNode->Next != nullptr)
		{
			currentNode = currentNode->Next;
		}

		// prev 관련 추가 내용
		newNode->Prev = currentNode;
		currentNode->Next = newNode;
	}
	else
	{
		_root = newNode;
	}
}

// pop의 경우엔 prev관련해서 추가할 내용이 없을것 같습니다.
void LinkedList::pop_back()
{
	if (_root == nullptr)
	{
		printf("_root가 nullptr이기 때문에 pop할 요소가 없습니다.\n");
		return;
	}

	Node* deleteNode = _root;
	Node* currentNode = _root;

	while (deleteNode->Next != nullptr)
	{
		deleteNode = deleteNode->Next;
	}

	while (currentNode->Next != deleteNode)
	{
		currentNode = currentNode->Next;
	}

	if (deleteNode != nullptr)
	{
		delete deleteNode;
		deleteNode = nullptr;
	}

	currentNode->Next = nullptr;
}

// at의 경우에도 pop과 관련되어 추가할 내용이 없을것 같습니다.
int LinkedList::at(int index)
{
	Node* currentNode = _root;

	for (int i = 0; i < index; i++)
	{
		currentNode = currentNode->Next;
	}

	return currentNode->Data;
}

void LinkedList::remove_data(int data)
{
	Node* currentNode = _root;
	Node* deleteNode = _root;

	while (deleteNode->Data != data)
	{
		// 지우고자 하는 데이터가 존재하지 않은 경우 
		if (deleteNode->Next == nullptr) 
		{
			cout << "지우려는 데이터가 존재하지 않습니다." << endl;
			return;
		}
		deleteNode = deleteNode->Next;
	}

	// _root의 Data가 지우고자 하는 data인 경우를 고려한다.
	// 우선 _root의 Data가 지우고자 하는 data가 아닌 경우
	// 노드의 prev가 존재한다.
	if (deleteNode->Prev != nullptr)
	{
		while (currentNode->Next != deleteNode)
		{
			currentNode = currentNode->Next;
		}

		// deleteNode가 제거되어야 하므로
		// deleteNode->Next의 Prev가 currentNode가 되도록 한다.
		// 단, deleteNode->Next가 nullptr인 경우엔 
		// currentNode->Next = nullptr 해주면 된다.
		if (deleteNode->Next == nullptr)
		{
			currentNode->Next = nullptr;
		}
		// deleteNode->Next가 nullptr가 아니라면 
		// deleteNode->Next의 prev를 currentNode로 해준다.
		else
		{
			deleteNode->Next->Prev = currentNode;
			currentNode->Next = deleteNode->Next;
		}
	}
	// _root의 Data가 지우고자 하는 data인 경우
	// _root를 다음 노드로 보내고 _root의 prev를 nullptr로 만든다.
	// 이 경우엔 추후 문제가 생기지 않도록 currentNode도 nullptr로 만들어 준다.
	else
	{
		_root = _root->Next;
		_root->Prev = nullptr;

		currentNode = nullptr;
	}

	delete deleteNode;
	deleteNode = nullptr;
}

void LinkedList::add_data(int data, int index)
{
	Node* currentNode = _root;

	for (int i = 0; i < index; i++)
	{
		// index가 리스트의 마지막을 뜻하거나 리스트의 크기를 넘어선다면 마지막에 데이터를 추가한다.
		if (currentNode->Next == nullptr)
		{
			cout << "리스트의 마지막에 데이터를 추가합니다." << endl;
			break;
		}
		currentNode = currentNode->Next;
	}

	Node* newNode = new Node();
	newNode->Data = data;

	// 넣고자 하는곳이 맨 처음 위치인 경우
	if (currentNode->Prev == nullptr)
	{
		currentNode->Prev = newNode;
		newNode->Next = currentNode;
		newNode->Prev = nullptr;
		_root = newNode;
	}
	// 넣고자 하는곳이 맨 마지막인 경우
	else if(currentNode->Next == nullptr)
	{
		currentNode->Next = newNode;
		newNode->Prev = currentNode;
		newNode->Next = nullptr;
	}
	// 넣고자 하는곳이 리스트 내부인 경우
	else
	{
		currentNode->Prev->Next = newNode;
		newNode->Prev = currentNode->Prev;
		newNode->Next = currentNode;
		currentNode->Prev = newNode;
	}
}

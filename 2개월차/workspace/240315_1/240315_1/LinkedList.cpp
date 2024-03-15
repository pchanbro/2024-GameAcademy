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
	Node* newNode = new Node();
	newNode->Next = nullptr;
	newNode->Data = data;

	Node* currentNode = _root;

	if (_root != nullptr)
	{
		while (currentNode->Next != nullptr)
		{
			currentNode = currentNode->Next;
		}
		currentNode->Next = newNode;
	}
	else
	{
		_root = newNode;
	}
	// 이 윗부분을 아랫부분처럼 쓰면 맨처음 push_bakc할 때 오류가 나서 출력이 안된다.
	/*while (currentNode->Next != nullptr)
	{
		currentNode = currentNode->Next;
	}
	currentNode->Next = newNode;*/
	
}

void LinkedList::pop_back()
{
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
	delete deleteNode;
	deleteNode = nullptr;

	currentNode->Next = nullptr;
}

int LinkedList::at(int index)
{
	Node* currentNode = _root;
	
	for (int i = 0; i < index; i++)
	{
		currentNode = currentNode->Next;
	}

	return currentNode->Data;
}

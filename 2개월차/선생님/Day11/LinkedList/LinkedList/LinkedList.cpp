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
	//�������� �����͸� �ִ´�.

	//���� �ڵ� �ſ��߿�!!
	//�����ڵ带 �˸� �� �ڷᱸ���� ������� �˼��ۿ� ����

	//1. newNode�� ������ش�.
	// 
	//2. _root ���� �����Ѵ�.
	//	current = _root
	//
	//3-1. _root�� NULL�� �ƴ϶��
	//	current�� Next�� null�� �ɶ����� 
	//	current�� Next�� �ѱ��.
	//	newNode�� �ּҸ� current Next�� ���Խ�Ų��.
	//3-2. _root�� NULL�̶��
	//	_root�� newNode�� ���Խ�Ų��.


	//1. newNode�� ������ش�.
	Node* newNode = new Node();
	newNode->Data = data;
	newNode->Next = nullptr;

	//2. _root ���� �����Ѵ�.
	Node* current = _root;

	//3-1. _root�� NULL�� �ƴ϶��
	if (_root != nullptr)
	{
		//	current�� Next�� null�� �ɶ����� 
		//	current�� Next�� �ѱ��.
		while (current->Next != nullptr)
		{
			current = current->Next;
		}

		//	newNode�� �ּҸ� current Next�� ���Խ�Ų��.
		current->Next = newNode;
	}
	//3-2. _root�� NULL�̶��
	else
	{
		//	_root�� newNode�� ���Խ�Ų��.
		_root = newNode;
	}
}

void LinkedList::pop_back()
{
	if (_root == nullptr)
	{
		printf("_root�� nullptr �Դϴ�.\n");
		return;
	}

	//1. DeletedNode�� �����.
	Node* deletedNode = _root;

	//2. CurrentNode�� �����.
	Node* currentNode = _root;

	//3. DeletedNode�� ���� ���������� ������.
	while (deletedNode->Next != nullptr)
	{
		deletedNode = deletedNode->Next;
	}

	//4. CurrentNode�� Next�� DeletedNode�� ���ö����� ������ �ѱ��.
	while (currentNode->Next != deletedNode)
	{
		currentNode = currentNode->Next;
	}

	//5. DeletedNode�����
	if (deletedNode != nullptr)
	{
		delete deletedNode;
		deletedNode = nullptr;
	}

	//6. CurrentNode�� Next�� NULLó�����ش�.
	currentNode->Next = nullptr;
}

int LinkedList::at(int index)
{
	//�����ڵ�

	//current�� �����Ѵ�.
	Node* current = _root;

	//(index)�� ��ŭ Next�� �̵��Ѵ�
	for (int i = 0; i < index; i++)
	{
		current = current->Next;
	}
	
	//�� ���� return�Ѵ�.
	return current->Data;
}

// ���� 2���� ������
//  - 1. �̰� �ܿ�� (Prev���� ����) 
//		(LinkedList.h, LinkedList.cpp)
//  - 2. LinkedList�� Next�ۿ� ���ݾƿ�?
//		Prev�� ������ �ֽ��ϴ�.
//		Prev����� ����.

void LinkedList::remove_data(int data)
{
	//1. CurrentNode�� DeleteNode�� �����.
	Node* currentNode = _root;
	Node* deleteNode = _root;

	//2. ���ϴ� �����͸� ���������� DeleteNode�� �ѱ��.
	while (deleteNode->Data != data)
	{
		deleteNode = deleteNode->Next;
	}

	//3. CurrentNode->Next�� DeleteNode�� �ɶ����� �ѱ��.
	while (currentNode->Next != deleteNode)
	{
		currentNode = currentNode->Next;
	}

	//4. CurrentNode->Next�� DeleteNode�� Next�� �ٲ۴�.
	currentNode->Next = deleteNode->Next;

	//5. DeleteNode�� �����Ѵ�.
	delete deleteNode;
	deleteNode = nullptr;
}

void LinkedList::add_data(int data, int index)
{
	//1. CurrentNode�� �����
	Node* currentNode = _root;
	
	//2. ���ϴ� �ε������� CurrentNode�� �ѱ��.
	for (int i = 0; i < index; i++)
	{
		currentNode = currentNode->Next;
	}
	
	//3. NewNode�� �����
	Node* newNode = new Node();
	newNode->Data = data;
	
	//4. NewNode->Next�� CurrentNode->Next�� �ٲ۴�.
	newNode->Next = currentNode->Next;
	
	//5. CurrentNode->Next�� NewNode�� �ٲ۴�.
	currentNode->Next = newNode;
}
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
	// �������� �����͸� �ִ´�.

	// ���� �ڵ� 
	// �����ڵ带 �˸� �ڷᱸ���� ������� �� �� �ۿ� ����.

	// 1.newNode�� ������ش�.
	// 
	// 2. _root���� �����Ѵ�.
	// current = _root
	// 
	// 3-1. _root�� NULL�� �ƴ϶��
	// current�� Next�� null�� �ɶ����� 
	// current�� Next�� �ѱ��.
	// newNode�� �ּҸ� current Next�� ���Խ�Ų��.
	// 3-2. _root�� NULL�̶��
	// _root�� newNode�� ���Խ�Ų��.

	// 1.newNode�� ������ش�.
	Node* newNode = new Node();
	newNode->Data = data;
	newNode->Next = nullptr;

	// 2. _root���� �����Ѵ�.
	Node* current = _root;

	// 3-1. _root�� NULL�� �ƴ϶��
	if (_root != nullptr)
	{
		// current->Next�� null�� �ɶ�����.
		// current�� Next�� �ѱ��.
		while (current->Next != nullptr)
		{
			current = current->Next;
		}

		// newNode�� �ּҸ� current Next�� ���Խ�Ų��.
		current->Next = newNode;
	}
	// 3-2. _root�� NULL�̶��
	else
	{
		// _root�� newNode�� ���Խ�Ų��.
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

	// 1. DeletedNode�� �����.
	Node* deletedNode = _root;

	// 2. CurrentNode�� �����.
	Node* currentNode = _root;

	
	// 3. DeletedNode�� ���� ���������� ������.
	while (deletedNode->Next != nullptr)
	{
		deletedNode = deletedNode->Next;
	}

	// 4. CurrentNode�� Next�� DeletedNode�� ���� �� ���� ������ �ѱ��.
	while (currentNode->Next != deletedNode)
	{
		currentNode = currentNode->Next;
	}

	// 5. DeletedNode�� �����.
	if(deletedNode != nullptr)
	{
		delete deletedNode;
		deletedNode = nullptr;
	}

	// 6. CurrentNode�� Next�� NULLó�����ش�.
	currentNode->Next = nullptr;
}

int LinkedList::at(int index)
{
	// �����ڵ�

	// current�� �����Ѵ�.
	Node* current = _root;

	// (index)�� ��ŭ Next�� �̵��Ѵ�.
	for (int i = 0; i < index; i++)
	{
		current = current->Next;
	}

	// �� ���� return �Ѵ�.
	return current->Data;
}

void LinkedList::remove_data(int data)
{
	// 1. deleteNode�� �����.
	Node* deleteNode = _root;

	// // 2. CurrentNode�� �����.
	Node* currentNode = _root;

	// 3. deleteNode�� Data���� �Ű����� data�� ���� ���� ���ö����� Next�� �̵��Ѵ�.
	while ((deleteNode->Data != data) && (deleteNode->Next != nullptr))
	{
		deleteNode = deleteNode->Next;
	}

	// 4-2. �Ű����� data���� Data�� ���� ��尡 �������� �ʴ´ٸ�
	// 4-2-1. ���� �������� ������ ǥ���Ѵ�.
	if (deleteNode->Next == nullptr)
	{
		cout << "������� ���� �������� �ʽ��ϴ�. " << endl;
		return;
	}

	// 4-1. �Ű����� data���� Data�� ���� ��尡 �����Ѵٸ�
	// 4-1-1. currentNode�� Next�� deleteNode�� ���� �� ���� ������ �ѱ��.
	while (currentNode->Next != deleteNode)
	{
		currentNode = currentNode->Next;
	}

	// 4-1-2. currentNode�� Next�� deleteNode�� next�� �����Ѵ�.
	currentNode->Next = deleteNode->Next;

	// 4-1-3. deleteNode�� �����Ѵ�.
	delete deleteNode;
	deleteNode = nullptr; // �̰� �ص��ǰ� ���ص� �Ǵµ� ���ִ� ������ �鿩��
	// ���߿� �̰� ���ؼ� ������ �߻��� �� �ִ�.
}

void LinkedList::add_data(int data, int index)
{
	// 1. newNode�� �����.
	Node* newNode = new Node;
	newNode->Data = data;
	newNode->Next = nullptr;

	// 2. CurrentNode�� �����.
	Node* CurrentNode = _root;

	// 3. CurrentNode�� index-1�� Next�� �ű��.
	for (int i = 0; i < index-1; i++)
	{
		CurrentNode = CurrentNode->Next;
	}

	// 4. newNode�� next�� CurrentNode�� Next�� �����Ѵ�.
	newNode->Next = CurrentNode->Next;
	
	// 5. CurrentNode�� next�� newNode�� �����Ѵ�.
	CurrentNode->Next = newNode;
}

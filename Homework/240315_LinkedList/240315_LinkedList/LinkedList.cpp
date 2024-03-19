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

		// prev ���� �߰� ����
		newNode->Prev = currentNode;
		currentNode->Next = newNode;
	}
	else
	{
		_root = newNode;
	}
}

// pop�� ��쿣 prev�����ؼ� �߰��� ������ ������ �����ϴ�.
void LinkedList::pop_back()
{
	if (_root == nullptr)
	{
		printf("_root�� nullptr�̱� ������ pop�� ��Ұ� �����ϴ�.\n");
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

// at�� ��쿡�� pop�� ���õǾ� �߰��� ������ ������ �����ϴ�.
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
		// ������� �ϴ� �����Ͱ� �������� ���� ��� 
		if (deleteNode->Next == nullptr) 
		{
			cout << "������� �����Ͱ� �������� �ʽ��ϴ�." << endl;
			return;
		}
		deleteNode = deleteNode->Next;
	}

	// _root�� Data�� ������� �ϴ� data�� ��츦 ����Ѵ�.
	// �켱 _root�� Data�� ������� �ϴ� data�� �ƴ� ���
	// ����� prev�� �����Ѵ�.
	if (deleteNode->Prev != nullptr)
	{
		while (currentNode->Next != deleteNode)
		{
			currentNode = currentNode->Next;
		}

		// deleteNode�� ���ŵǾ�� �ϹǷ�
		// deleteNode->Next�� Prev�� currentNode�� �ǵ��� �Ѵ�.
		// ��, deleteNode->Next�� nullptr�� ��쿣 
		// currentNode->Next = nullptr ���ָ� �ȴ�.
		if (deleteNode->Next == nullptr)
		{
			currentNode->Next = nullptr;
		}
		// deleteNode->Next�� nullptr�� �ƴ϶�� 
		// deleteNode->Next�� prev�� currentNode�� ���ش�.
		else
		{
			deleteNode->Next->Prev = currentNode;
			currentNode->Next = deleteNode->Next;
		}
	}
	// _root�� Data�� ������� �ϴ� data�� ���
	// _root�� ���� ���� ������ _root�� prev�� nullptr�� �����.
	// �� ��쿣 ���� ������ ������ �ʵ��� currentNode�� nullptr�� ����� �ش�.
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
		// index�� ����Ʈ�� �������� ���ϰų� ����Ʈ�� ũ�⸦ �Ѿ�ٸ� �������� �����͸� �߰��Ѵ�.
		if (currentNode->Next == nullptr)
		{
			cout << "����Ʈ�� �������� �����͸� �߰��մϴ�." << endl;
			break;
		}
		currentNode = currentNode->Next;
	}

	Node* newNode = new Node();
	newNode->Data = data;

	// �ְ��� �ϴ°��� �� ó�� ��ġ�� ���
	if (currentNode->Prev == nullptr)
	{
		currentNode->Prev = newNode;
		newNode->Next = currentNode;
		newNode->Prev = nullptr;
		_root = newNode;
	}
	// �ְ��� �ϴ°��� �� �������� ���
	else if(currentNode->Next == nullptr)
	{
		currentNode->Next = newNode;
		newNode->Prev = currentNode;
		newNode->Next = nullptr;
	}
	// �ְ��� �ϴ°��� ����Ʈ ������ ���
	else
	{
		currentNode->Prev->Next = newNode;
		newNode->Prev = currentNode->Prev;
		newNode->Next = currentNode;
		currentNode->Prev = newNode;
	}
}

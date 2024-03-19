#pragma once

template <typename T>
class BinaryTree
{
	struct Node
	{
		T Data;
		Node* Parent;
		Node* Left;
		Node* Right;
	};


	Node* _root = nullptr;

private:
	Node* CreateNode(T data)
	{
		Node* newNode = new Node();
		newNode->Parent = nullptr;
		newNode->Left = nullptr;
		newNode->Right = nullptr;
		newNode->Data = data;
		return newNode;
	}

	Node* GetNode(T data)
	{
		Node* current = _root;
		while (current != nullptr)
		{
			if (current->Data < data)
			{
				current = current->Right;
			}
			else if (data < current->Data)
			{
				current = current->Left;
			}
			else if (data == current->Data)
			{
				return current;
			}
		}

		return nullptr;
	}
	void RemoveNode(Node* removeNode);
public:
	void AddData(T data);
	T GetData(T data); // ��� ��ȸ������ , �����Ҷ��� �ٸ� ������ �¿����մϴ�.
	void RemoveData(T data);

public:
	BinaryTree();
	~BinaryTree();
};

template <typename T>
BinaryTree<T>::BinaryTree()
{
}

template <typename T>
BinaryTree<T>::~BinaryTree()
{
	if (_root != nullptr)
	{
		delete _root;
		_root = nullptr;
	}
}
//
//template <typename T>
//BinaryTree<T>::Node* BinaryTree<T>::GetNode(T data)
//{
//	Node* current = _root;
//	while (current != nullptr)
//	{
//		if (current->Data < data)
//		{
//			current = current->Right;
//		}
//		else if (data < current->Data)
//		{
//			current = current->Left;
//		}
//		else if (data == current->Data)
//		{
//			return current;
//		}
//	}
//
//	return nullptr;
//}
//
//template <typename T>
//BinaryTree<T>::Node* BinaryTree<T>::CreateNode(T data)
//{
//	Node* newNode = new Node();
//	newNode->Parent = nullptr;
//	newNode->Left = nullptr;
//	newNode->Right = nullptr;
//	newNode->Data = data;
//	return newNode;
//}

template <typename T>
void BinaryTree<T>::AddData(T data)
{
	// 1. _root�� null�̸�
	// 2.	_root�� ���� �־��ְ� ����.
	if (_root == nullptr)
	{
		Node* newNode = CreateNode(data);
		_root = newNode;
	}

	//[���� �����ڸ��� ã�´�.]
	//1. current�� _root�� �޾��ش�.
	Node* current = _root;
	while (current != nullptr)
	{
		//2. currentData�� �� ������
		if (current->Data < data)
		{
			// 3. �������� ��������� �����ʿ� �߰����ְ� ����.
			if (current->Right == nullptr)
			{
				Node* newNode = CreateNode(data);
				current->Right = newNode;
				newNode->Parent = current;
				return;
			}
			else
			{
				// 3-1.�׷��� ������ current�� ���������� �̵��Ѵ�.
				current = current->Right;
			}
		}
		//2-1. currentData�� �� ũ��
		else if (data < current->Data)
		{
			//3-1. ������ ��������� ���ʿ� �߰����ְ� �����Ѵ�.
			if (current->Left == nullptr)
			{
				Node* newNode = CreateNode(data);
				current->Left = newNode;
				newNode->Parent = current;
				return;
			}
			else
			{
				//3-2. �׷��� ������ current�� �������� �̵��Ѵ�.
				current = current->Left;
			}
		}
		else
		{
			//�������� ������ ����.
			return;
		}
	}
}

template <typename T>
T BinaryTree<T>::GetData(T data)
{
	Node* findNode = this->GetNode(data);

	if (findNode)
	{
		return findNode->Data;
	}
	else
	{
		return NULL;
	}
}

template <typename T>
void BinaryTree<T>::RemoveData(T data)
{
	// 1. ���� ��带 ã�´�. (���� ���)
	// 2. ���� ����� ��ü ��� ã�´�.
	// 3. ���� ����� �����͸� ��ü �����ͷ� �ٲ��ش�.
	// 4. ��ü�� ��带 �����.
	Node* currentNode = _root;
	Node* deletedNode = nullptr;
	Node* replaceNode = nullptr;

	// 1. ���� ��带 ã�´�. (���� ���) (�Լ��� �����ΰڽ��ϴ�.)
	deletedNode = this->GetNode(data);


	// 2. ���� ����� ��ü ��� ã�´�.
	//��ü ���� �������� ������ ���� �������̴�.
	if (deletedNode->Left == nullptr)
	{
		//������ ����ִ� ��쿣 �������� ���� ����
		if (deletedNode->Right == nullptr)
		{
			//�����ʵ� ���������, �׳�带 ����� �Լ��� �����Ѵ�.
			this->RemoveNode(deletedNode);
			return;
		}
		else
		{
			//���� ����� �������� ���� ������ ã�´�.
			replaceNode = deletedNode->Right;
			while (replaceNode->Left != nullptr)
			{
				replaceNode = replaceNode->Left;
			}
		}
	}
	else
	{
		//���� ����� ������ ���� �������� ã�´�.
		replaceNode = deletedNode->Left;
		while (replaceNode->Right != nullptr)
		{
			replaceNode = replaceNode->Right;
		}
	}


	// 3. ���� ����� �����͸� ��ü �����ͷ� �ٲ��ش�.
	deletedNode->Data = replaceNode->Data;

	// 4. ��ü�� ��带 �����.
	this->RemoveNode(replaceNode);
}


template <typename T>
void BinaryTree<T>::RemoveNode(BinaryTree<T>::Node* removeNode)
{
	if (removeNode->Parent->Left == removeNode)
	{
		removeNode->Parent->Left = nullptr;
	}
	else
	{
		removeNode->Parent->Right = nullptr;
	}
	//2. ��ü�� �����
	//3. �Լ��� �����Ѵ�.
	delete removeNode;
	removeNode = nullptr;
}
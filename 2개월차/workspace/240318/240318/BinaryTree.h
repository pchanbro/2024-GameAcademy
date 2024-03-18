#pragma once
// cpp 관련 없어도 된다는 부분 240318 영상 1시간 부근 쯤 다시 보기

template<typename T>
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
	Node* CreateNode(T data);
	Node* GetNode(T data);
	void RemoveNode(Node* removeNode);
public:
	void AddData(T data);
	T GetData(T data); // 얘는 조회용이지, 수정할때는 다른 로직을 사용해야 한다.
	void RemoveData(T data);

public:
	BinaryTree(); // => Init()
	~BinaryTree(); // => Delete()
};

template<typename T>
BinaryTree<T>::BinaryTree()
{

}

template<typename T>
BinaryTree<T>::~BinaryTree()
{
	if (_root != nullptr)
	{
		delete _root;
		_root = nullptr;
	}
}

template<typename T>
BinaryTree<T>::Node* BinaryTree<T>::GetNode(T data)
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

template<typename T>
BinaryTree<T>::Node* BinaryTree<T>::CreateNode(T data)
{
	Node* newNode = new Node();
	newNode->Parent = nullptr;;
	newNode->Left = nullptr;
	newNode->Right = nullptr;
	newNode->Data = data;
	return newNode;
}


template<typename T>
void BinaryTree<T>::AddData(T data)
{
	// 1. current, prev를 만든다 (root 값)
	// 2. while(3 ~ 5) 반복
	// 3. if(current->data < inputdata) 라면 오른쪽으로 이동한다.
	// 4. else if(current->data > inputdata) 라면 왼쪽으로 이동한다.
	// 5. 겹치면, 추가하지 않고 종료한다.

	// 1. _root가 null이면
	// 2. _root에 값을 넣어주고 종료.
	if (_root == nullptr)
	{
		Node* newNode = CreateNode(data);
		_root = newNode;
	}

	// 핵심!! [내가 넣을자리를 찾는다.]
	// 1. current를 _root로 받아준다.
	Node* current = _root;
	while (current != nullptr)
	{
		// 2. currentData가 더 작으면
		if (current->Data < data)
		{
			// 3-1.오른쪽이 비어있으면 오른쪽에 추가해주고 종료.
			if (current->Right == nullptr)
			{
				Node* newNode = CreateNode(data);
				current->Right = newNode;
				newNode->Parent = current;
				return;
			}
			else
			{
				// 3-2. 그렇지 않으면 current를 오른쪽으로 이동한다.
				current = current->Right;
			}
		}
		// 2-1. currentData가 더 크면
		else if (data < current->Data)
		{
			// 3-1. 왼쪽이 비어있으면 왼쪽에 추가해주고 종료.
			if (current->Left == nullptr)
			{
				Node* newNode = CreateNode(data);
				current->Left = newNode;
				newNode->Parent = current;
				return;
			}
			else
			{ // 3-2. 그렇지 않으면 current를 왼쪽으로 이동한다.
				current = current->Left;
			}
		}
		else
		{
			// 같은값이 있으면 종료
			return;
		}
	}
}

template<typename T>
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

template<typename T>
void BinaryTree<T>::RemoveData(T data)
{
	// 1. 지울 노드를 찾는다. (원래 노드)
	// 2. 지울 노드의 대체 노드 찾는다.
	// 3. 지울 노드의 데이터를 대체 데이터로 바꿔준다.
	// 4. 대체된 노드를 지운다.

	Node* currentNode = _root;
	Node* deletedNode = nullptr;
	Node* replaceNode = nullptr;

	// 1. 지울 노드를 찾는다. (원래 노드) (많이쓰니까 함수로 만들어두자)
	deletedNode = this->GetNode(data);

	// replaceNode는 오른쪽 노드의 가장 왼쪽 노드이거나
	// 왼쪽 노드의 가장 오른쪽 노드를 구해야 _root와 가장 근접한 값이 온다.
	// 2. 지울 노드의 대체 노드를 찾는다.
	// 여기선 지울노드의 왼쪽 노드의 가장 오른쪽 노드를 구하겠다.

	if (deletedNode->Left == nullptr)
	{
		// 왼쪽이 비어있는 경우엔 오른쪽의 가장 왼쪽을 찾는다.
		if (deletedNode->Right == nullptr)
		{
			// 오른쪽도 비어있으면, 그 노드를 지우고 함수를 종료한다.
			// 나 자신만 지우고 나를 연결한 포인터만 지우면 된다.
			// 1. 연결된 포인터부터 끊는다.
			this->RemoveNode(deletedNode);
			return;
		}
		else
		{
			// 지울 노드의 오른쪽의 가장 왼쪽을 찾는다.
			replaceNode = deletedNode->Right;
			while (replaceNode->Left != nullptr)
			{
				replaceNode = replaceNode->Left;
			}
		}
	}
	else
	{
		// 지울 노드의 오른쪽의 가장 왼쪽을 찾는다.
		replaceNode = deletedNode->Left;
		while (replaceNode->Right != nullptr)
		{
			replaceNode = replaceNode->Right;
		}
	}

	// 3. 
	deletedNode->Data = replaceNode->Data;

	
	// 4. 대체된 노드를 지운다.
	this->RemoveNode(replaceNode);
	
}

template<typename T>
void BinaryTree<T>::RemoveNode(BinaryTree<T>::Node* removeNode)
{
	if (removeNode->Parent->Left == removeNode)
	{
		removeNode->Parent->Left == nullptr;
	}
	else
	{
		removeNode->Parent->Right == nullptr;
	}
	// 2. 본체를 지우고
	// 3. 함수를 종료한다.
	delete removeNode; // removeNode가 가리키고 있는걸 지우겠다.
	removeNode = nullptr; // 윗줄로 인해 removeNode가 허공을 가리키고 있으니 그걸 방지하겠다.
}

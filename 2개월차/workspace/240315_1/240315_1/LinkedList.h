#pragma once

struct Node
{
	int Data;
	Node* Next;
};

class LinkedList
{
private:
	Node* _root = nullptr;

public:
	LinkedList();
	~LinkedList();
	void push_back(int data);
	void pop_back();
	int at(int index);

};


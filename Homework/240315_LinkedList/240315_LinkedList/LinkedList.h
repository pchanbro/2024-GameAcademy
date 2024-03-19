#pragma once

// prev추가한 버전
struct Node
{
	int Data; 
	Node* Next;
	Node* Prev;
};

class LinkedList
{
private:
	Node* _root = nullptr;

public:
	LinkedList();
	~LinkedList();

public:
	void push_back(int data);
	void pop_back();
	int at(int index);
	void remove_data(int data);
	void add_data(int data, int index);
};


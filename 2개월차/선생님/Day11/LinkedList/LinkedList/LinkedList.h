#pragma once
struct Node
{
	int Data;	//�ڱ��ڽ� ������ 
	Node* Next;//���� �����͸� ����Ű�� ������
};


class LinkedList
{
private:
	//������� ���� �ڸ�.
	//�� �����Ҵ����� ����ִ°���??
	//	=> nullptr �����ϼ����־..
	Node* _root = nullptr;


	//������ �Ҹ���
public:
	LinkedList();
	~LinkedList();

	//�Լ����� �������� �������� ����մϴ�.
	// �� public�� ���Ͷ� ��ȣ�ۿ��ϴ� �κ�
	// �� public�� ������ �Ҹ��� �̷�����..
public:
	//list �������� �����͸� �ִ´�.
	void push_back(int data);
	void pop_back();
	int at(int index);


	//������ ���� �Ǻ��Ͽ� �� ��带 ����
	//�ߺ��� �����Ͱ� ������
	//�տ� �ε��� �����Ͱ� ����.
	void remove_data(int data);

	// �������ϴ� �ε�����
	// ������ �ֱ�
	void add_data(int data, int index);
};


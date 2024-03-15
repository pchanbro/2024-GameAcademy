#pragma once

template <typename Node> // ���⼭�� Node �ڸ��� ���� T�� ���̴µ� �� �κ���
// vector ������ �� <int> <float> �̷������� ��ȯ���� �����ϴµ� 
// ���� ������ �� int�̸� T�� ��� int�� �ǰ� ���� float�� �ϸ� T�� ��� float�� �ȴ�. �׷� ����
class MyVector
{
private:
	Node* _arr = nullptr;
	int _size = 0;
	int _capacity = 2; // �ٵ� �ű涧���� ��ġ�� �ٲ�ϱ� capacity��°� ����
	// �ٵ� �̰͵� �Ű��������� 1.5�踸 �Ǵµ� �̷� �κе��� �Ը���� �ٲٰ� �;
	// ���ӻ翡�� ���� vector�� ����°�
public: 
	void push_back(Node data);
	Node at(int index);

	// �̰͵� �Լ���.
	// ��ȯ�ڷ��� : Node 
	// �Լ��� : operator
	// �Ű����� : int index
	Node operator[](int index);
	// �� operator�� 
	// vec.oprator[](1)
	// vec[1] 
	// �� �ΰ����� �����Ŵ�
	// ���ʹ� �ᱹ�� �迭�� �ٸ�����̶�� �����ص��Ǵµ�
	// operator[] �� �迭�� �ٸ� ����̶�� �����ϴ� �Ǿȵſ�!!
	// operator�� �Լ��� ��, �Լ�ȣ���̶�� �����ض�.
public:
	MyVector();
	~MyVector();
};

// Ŭ���� �����ڷ� �� �� �ִ� ��
// ���߿� 
// Damage Ŭ����(ū ���ӿ��� ������ ������ ���̴�)
// ������ �������̵��� Ȱ���ؼ� ����� ���ش�.
#include <iostream>

using namespace std;


void main()
{
	// �迭�� �����Ҵ�

	// �迭 = ������
	// ����ϴٶ�� ���� ������ ����߽��ϴ�.

	// �����Ҵ���
	// �迭�ε� �Ҽ��ִµ�
	// �����������ͷ� �޴°Ծƴϰ�
	// �׳� �Ȱ��� ������ �����ͷ� �迭 �����Ҵ��� �մϴ�.

	//new int[ũ��]
	int* arr = new int[10];

	int count = 20;
	//int myArr[count];

	//��Ÿ�� ���߿� �޸𸮸� �Ҵ��ϴ°Ŷ�, �׶��´� �迭ũ�⸦ ��� ������ ��������.
	int* myArr = new int[count];
	for (int i = 0; i < count; i++)
	{
		myArr[i] = i;
	}
	//�̷��� ����˴ϴ�.

	//�����ϴ� ���!!
	//delete[] �ּҰ�;
	delete[] myArr;

}
#include <iostream>

using namespace std;

void main()
{
	// �迭�� �����Ҵ�

	// �迭 = ������
	// ����ϴ�
	// �����Ҵ���
	// �迭�ε� �� �� �ִ�.
	// �����������ͷ� �޴°� �ƴϰ�
	// �׳� �Ȱ��� ������ �����ͷ� �迭 �����Ҵ��� �Ѵ�.

	// new int[ũ��]
	int* arr = new int[10];

	int count = 20;
	// int myArr[count]; �̰� �ȵ���

	// ������ ���� �Ҵ��̶�� ��Ⱑ �ٸ���
	// ��Ÿ�� ���߿� �޸𸮸� �Ҵ��ϴ°Ŷ�, �� �� �´� �迭ũ�⸦ ��� ������ ��������
	int* myArr = new int[count];
	for (int i = 0; i < count; i++)
	{
		myArr[i] = i;
	}
	// �̷��� ���� �ȴ�.

	// �����ϴ� ���
	// delete[] �ּҰ�;
	delete[] myArr;

}
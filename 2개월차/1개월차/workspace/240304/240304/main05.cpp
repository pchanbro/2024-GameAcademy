#include<iostream>
#include<vector>

using namespace std;

void CallByValue(int value);
void CallByReference(int& value2);
// ����õ
void CallByAddress(int* value3);

void main()
{
	// �Լ�!
	// ȣ���ϴ� �뵵�� ����߾���
	int value = 4;
	// �ٵ� �Լ� �ȿ����� �� ������ �ȵȴ�.
	
	//CallByValue(value);
	/*
	{
		int value1 = value;
		{
			value1++;
			printf("Hello World : %d\n", value1);
		}
	}
	*/

	// �׷��� ����� �״�� 4�� ��µȴ�.
	printf("valuse :%d\n", value);

	//CallByReference(value);
	// ���Ӱ� �޸𸮰� �߰��� �߻����� ����
	// �����Ѵ�.
	/*{
		int& value2 = value;
		{
			value2++;
			printf("Hello World! : %d\n", value2);
		}
	}*/

	// ������ -> �ּҰ�
	// �Ϲ� ���� => ������ �ּҰ�
	// &������
	//CallByAddress(&value);
	//{
	//	int* value3 = &value;
	//	{
	//		(*value3)++;
	//		printf("Hello World! : %d\n", value3);
	//	}
	//}

	
	printf("valuse :%d\n", value);

}

void CallByValue(int value1)
{
	// �Լ����� ���� �������� ����ϸ� 5�� ��µ����� �� ������ main���� value�ʹ� �ٸ� �����̴�.
	value1++;
	printf("Hello World! : %d\n", value1);
}

void CallByReference(int& value2)
{
	
	value2++;
	printf("Hello World! : %d\n", value2);
}

void CallByAddress(int* value3)
{
	// value3 => �ּҰ�
	(*value3)++;
	printf("Hello World! : %d\n", value3);
}
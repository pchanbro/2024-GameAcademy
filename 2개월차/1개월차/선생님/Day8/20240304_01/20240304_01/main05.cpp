#include <iostream>
using namespace std;


//��ȯ�ڷ��� �Լ���(�ŰԺ�����);
void CallByValue(int value1);
void CallByReference(int& value2);
//�� ��õ
void CallByAddress(int* value3);
void main()
{
	//�Լ�!
	//ȣ���ϴ� �뵵�� ���
	int value = 4;
	//::CallByValue(value);
	//{
	//	int value1 = value;
	//	{
	//		value1++;
	//		printf("Hello World! : %d\n", value1);
	//	}
	//}

	//::CallByReference(value);
	//{
	//	//���Ӱ� �޸𸮰� �߰��� �߻����� ����.
	//	//�����Ѵ�.
	//	int& value2 = value;
	//	{
	//		value2++;
	//		printf("Hello World! : %d\n", value2);
	//	}
	//}

	//������ => �ּҰ�
	//�Ϲ� ���� => ������ �ּҰ�
	// &������
	//::CallByAddress(&value);
	/*{
		int* value3 = &value;
		{
			(*value3)++;
			printf("Hello World! : %d\n", *value3);
		}
	}*/

	printf("value : %d\n", value);
}

void CallByValue(int value1)
{
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
	//value3 => �ּҰ�
	//�ּҰ��� ������ ���� ++ �ؾ���.
	(*value3)++;
	printf("Hello World! : %d\n", *value3);
}
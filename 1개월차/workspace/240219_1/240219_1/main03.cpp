#include <iostream>

using namespace std;

void main()
{
	// IF�� �ǽ�

	// 1. ���� 4���� �Է¹޴´�.
	// 2. ������ ������ 400�� �̻��̸� A�� ����Ѵ�.
	// 3. ������ ������ 350�� �̻��̸� B�� ����Ѵ�.
	// 4. ������ ������ 300�� �̻��̸� C�� ����Ѵ�.
	// 5. �� �̸��̸� D�� ����Ѵ�.

	// if / else if / else ���� Ȱ���Ͽ� �ǽ�
	
	int num1 = 0, int num2 = 0,	int num3 = 0, int num4 = 0;

	printf("num1�� �Է��ϼ��� : ");
	scanf_s("%d", &num1);
	printf("num2�� �Է��ϼ��� : ");
	scanf_s("%d", &num2);
	printf("num3�� �Է��ϼ��� : ");
	cin >> num3;
	printf("num4�� �Է��ϼ��� : ");
	cin >> num4;

	int sum = num1 + num2 + num3 + num4;

	cout << "�� �� ������ " << sum << " " << "A" < endl;
	printf("����� ");
	if (400 <= sum)
	{
		printf("A �Դϴ�.\n");
	}
	else if(350 <= sum)
	{
		cout << "B �Դϴ�.\n";
	}
	else if (300 <= sum)
	{
		cout << "C �Դϴ�." << endl;
		// endl : \n �� ����.
		// endl => end line (�ٸ���)
	}
	else
	{
		cout << "D �Դϴ�." << endl;
	}

	// TIP ������ �ٲٱ�
	// (Ctrl + R + R) 
	
	// �����ϴ� ���α׷���
	//	���α׷��Ӱ� �ƴѻ������ ���� ��
	//	�����ϴ� ���α׷��Ӵ� ���� ����� ���
	//	��������� ��� : ����Ű �߾��� ���
}
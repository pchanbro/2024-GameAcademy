#include <iostream>

using namespace std;

void main()
{
	//IF�� �ǽ�

	//1. ���� 4���� �Է¹޴´�.
	//2. ������ ������ 400�� �̻��̸� A�� ����Ѵ�
	//3. ������ ������ 350�� �̻��̸� B�� ����Ѵ�
	//4. ������ ������ 300�� �̻��̸� C�� ����Ѵ�
	//5. �� �̸��̸� D�� ����Ѵ�
	
	//if / else if / else ���� Ȱ���Ͽ�  �ǽ�

	//��õ�帮�� ����� �ƴ�.
	int score1 = 0, score2 = 0, score3 = 0, score4 = 0;

	//int input1 = 0;
	//int input;

	//int ������, ������, ������ = ��, ������;


	printf("1�� ������ �Է����ּ��� : ");
	//�Է��Լ�
	scanf_s("%d", &score1);

	//scanf_s("%d", &score2);
	printf("2�� ������ �Է����ּ��� : ");
	cin >> score2; //������������ �׳��Է�
	printf("3�� ������ �Է����ּ��� : ");
	cin >> score3;
	printf("4�� ������ �Է����ּ��� : ");
	cin >> score4;
	//c input
	int allScore = score1 + score2 + score3 + score4;

	//c output
	//cout << "�Ҹ�1" << "�Ҹ�2" << "�Ҹ�3"

	if (400 <= allScore)
	{
		//printf("�� �� ������ %d A\n", sum);
		cout << "�� �� ������ " << allScore << " " << "A" << endl;
	}
	else if (350 <= allScore)
	{
		cout << "B\n";
	}
	else if (300 <= allScore)
	{
		cout << "C" << endl;
		//endl : \n �Դϴ�.
		//end l => end line (�ٸ���)
	}
	else
	{
		cout << "D" << endl;
	}


	//TIP ������ �ٲٱ�
	//  (Ctrl + R + R)

	// �����ϴ� ���α׷���
	//   ���α׷��Ӱ� �ƴѻ������ ������ 
	//   �����ϴ� ���α׷��Ӵ� ���� ����� ���
	// ��������� ��� : ����Ű �߾��»��
}
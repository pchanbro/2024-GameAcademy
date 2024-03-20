#include <iostream>
#include <vector>

using namespace std;

// ������ (���̹� ��Ģ)
// �빮�ڷ� ���� (Pascal Case)
struct Student
{
	// ������ �빮�ڷ� ����
	int English;
	int Math;
	int Korean;
};

void main()
{
	// 2. ����ü
	// �Լ��� main 05���� �ϴ°ɷ� ����

	// ����ü�� �����ΰ�?

	// ��������, �ڷ���

	// ��������
	// �ڷ��� ������ = ��;

	// int, bool, float, char

	// �ڷ��� ���� 
	
	// �⺻ �ڷ���
	//	- C++ �������� �⺻������ �������ִ� �ڷ���
	// ����� ���� �ڷ���
	//	- ����ڰ� �ʿ��ؼ� Ŀ�����ϰ� ���� �ڷ���
	//	- ����ü�� ���⿡ ����
	//	- enum�� ����ü��

	// ����ü�� 
	// ���� ���ϴ� �����ͼ��� ���� �� �ִ�.

	// ��������
	// �ڷ��� ������ = ��;
	Student student = {};
	student.English = 80;
	student.Math = 90;
	student.Korean = 85;

	// �ϳ��� �ڷ��� �ȿ� �������� ���� ����ų �� �ִ�.

	vector<Student> students;
	students.push_back(student);

	cout << "�������� : " << student.English << endl;
	cout << "�������� : " << student.Math << endl;
	cout << "�������� : " << student.Korean << endl;

	// �ǽ� 
	// 10���� �л� ���� �����͸� vector ����Ʈ�� ���� 
	// ��������� ���� ������ ���

	srand(time(NULL));
	vector<Student> students10;

	for (int i = 0; i < 10; i++)
	{
		Student temp;
	
		temp.English = rand() % 101;
		temp.Math = rand() % 101;
		temp.Korean = rand() % 101;

		students10.push_back(temp);
	}

	for (int i = 0; i < students10.size(); i++)
	{
		printf("%d��° �л��� ���� ���� : %d\n", i+1, students10[i].English);
		printf("%d��° �л��� ���� ���� : %d\n", i+1, students10[i].Math);
		printf("%d��° �л��� ���� ���� : %d\n", i+1, students10[i].Korean);
		puts("");
	}

	for (int i = 0; i < students10.size() - 1; i++)
	{
		for (int j = 1+i; j < students10.size(); j++)
		{
			int sum1 = students10[i].English + students10[i].Math + students10[i].Korean;
			int sum2 = students10[j].English + students10[j].Math + students10[j].Korean;

			if (sum1 < sum2)
			{
				Student temp = students10[i];
				students10[i] = students10[j];
				students10[j] = temp;
			}
		}
	}

	cout << "���� ������� ���" << endl;

	for (int i = 0; i < students10.size(); i++)
	{
		printf("%d�� �л��� ���� ���� : %d\n", i + 1, students10[i].English);
		printf("%d�� �л��� ���� ���� : %d\n", i + 1, students10[i].Math);
		printf("%d�� �л��� ���� ���� : %d\n", i + 1, students10[i].Korean);
		printf("%d�� �л��� ��� ���� : %.2f\n", i + 1, float(students10[i].English + students10[i].Math + students10[i].Korean)/4.0);
		puts("");
	}
}
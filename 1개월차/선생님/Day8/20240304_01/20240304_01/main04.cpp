#include <iostream>
#include <vector>
using namespace std;

//������ (���ֱ̹�Ģ)
//�빮�ڷ� ���� (Pascal Case)
struct Student
{
	//������ �빮�ڷ� ���� (Pascal Case)
	int English;
	int Math;
	int Korean;
};

void main()
{
	// 2. ����ü
	// �Լ��� main05����!

	//����ü�� �����̳�!!

	//��������, �ڷ���
	 
	
	//��������
	//�ڷ��� ������ = ��;

	//int, bool, float, char

	//�ڷ��� ����
	
	//�⺻ �ڷ���
	//  - C++ �������� �⺻������ �������ִ� �ڷ���
	//����� ���� �ڷ���
	//  - ����ڰ� �ʿ��ؼ� Ŀ�����ϰ� ���� �ڷ���
	//  - ����ü�� ���⿡ ����
	//  - enum

	// ����ü�� 
	//  ���� ���ϴ� �����ͼ��� ������ִ�.


	//��������
	//�ڷ��� ������ = ��;
	
	//�ϳ��� �ڷ����ȿ� �������� ���� ����ų�� �ִ�.
	

	// �ǽ� 
	// 10���� �л� ���������͸� vector����Ʈ�θ��� (�������޾Ƽ�)
	// ������� ���

	// 100 100 100
	// 80  70  90
	// 60  60  60

	//N��ŭ ���������͸� �ְڴ�.
	vector<Student> students;
	for (int i = 0; i < 10; i++)
	{
		Student student = {};
		student.English = rand() % 101;
		student.Math = rand() % 101;
		student.Korean = rand() % 101;
		students.push_back(student);
	}

	Student studenArr[10] = {};
	for (int i = 0; i < 10; i++)
	{
		Student student = {};
		student.English = rand() % 101;
		student.Math = rand() % 101;
		student.Korean = rand() % 101;
		studenArr[i] = student;
	}

}
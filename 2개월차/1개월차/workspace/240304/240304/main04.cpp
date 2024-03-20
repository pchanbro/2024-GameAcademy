#include <iostream>
#include <vector>

using namespace std;

// 컨벤션 (네이밍 규칙)
// 대문자로 시작 (Pascal Case)
struct Student
{
	// 변수도 대문자로 시작
	int English;
	int Math;
	int Korean;
};

void main()
{
	// 2. 구조체
	// 함수는 main 05에서 하는걸로 변경

	// 구조체가 무엇인가?

	// 변수선언, 자료형

	// 변수선언
	// 자료형 변수명 = 값;

	// int, bool, float, char

	// 자료형 종류 
	
	// 기본 자료형
	//	- C++ 문법에서 기본적으로 제공해주는 자료형
	// 사용자 정의 자료형
	//	- 사용자가 필요해서 커스텀하게 만든 자료형
	//	- 구조체는 여기에 속함
	//	- enum도 구조체다

	// 구조체는 
	// 내가 원하는 데이터셋을 만들 수 있다.

	// 변수선언
	// 자료형 변수명 = 값;
	Student student = {};
	student.English = 80;
	student.Math = 90;
	student.Korean = 85;

	// 하나의 자료형 안에 여러개의 값을 기억시킬 수 있다.

	vector<Student> students;
	students.push_back(student);

	cout << "영어점수 : " << student.English << endl;
	cout << "수학점수 : " << student.Math << endl;
	cout << "국어점수 : " << student.Korean << endl;

	// 실습 
	// 10명의 학생 점수 데이터를 vector 리스트로 만들어서 
	// 평균점수가 높은 순으로 출력

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
		printf("%d번째 학생의 영어 점수 : %d\n", i+1, students10[i].English);
		printf("%d번째 학생의 수학 점수 : %d\n", i+1, students10[i].Math);
		printf("%d번째 학생의 국어 점수 : %d\n", i+1, students10[i].Korean);
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

	cout << "점수 순위대로 출력" << endl;

	for (int i = 0; i < students10.size(); i++)
	{
		printf("%d등 학생의 영어 점수 : %d\n", i + 1, students10[i].English);
		printf("%d등 학생의 수학 점수 : %d\n", i + 1, students10[i].Math);
		printf("%d등 학생의 국어 점수 : %d\n", i + 1, students10[i].Korean);
		printf("%d등 학생의 평균 점수 : %.2f\n", i + 1, float(students10[i].English + students10[i].Math + students10[i].Korean)/4.0);
		puts("");
	}
}
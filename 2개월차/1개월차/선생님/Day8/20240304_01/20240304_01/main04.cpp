#include <iostream>
#include <vector>
using namespace std;

//컨벤션 (네이밍규칙)
//대문자로 시작 (Pascal Case)
struct Student
{
	//변수도 대문자로 시작 (Pascal Case)
	int English;
	int Math;
	int Korean;
};

void main()
{
	// 2. 구조체
	// 함수는 main05에서!

	//구조체가 무엇이냐!!

	//변수선언, 자료형
	 
	
	//변수선언
	//자료형 변수명 = 값;

	//int, bool, float, char

	//자료형 종류
	
	//기본 자료형
	//  - C++ 문법에서 기본적으로 제공해주는 자료형
	//사용자 정의 자료형
	//  - 사용자가 필요해서 커스텀하게 만든 자료형
	//  - 구조체는 여기에 속함
	//  - enum

	// 구조체는 
	//  내가 원하는 데이터셋을 만들수있다.


	//변수선언
	//자료형 변수명 = 값;
	
	//하나의 자료형안에 여러개의 값을 기억시킬수 있다.
	

	// 실습 
	// 10명의 학생 점수데이터를 vector리스트로만들어서 (랜덤값받아서)
	// 순서대로 출력

	// 100 100 100
	// 80  70  90
	// 60  60  60

	//N명만큼 점수데이터를 넣겠다.
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
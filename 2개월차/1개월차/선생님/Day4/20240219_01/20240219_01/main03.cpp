#include <iostream>

using namespace std;

void main()
{
	//IF문 실습

	//1. 점수 4개를 입력받는다.
	//2. 점수의 총합이 400점 이상이면 A를 출력한다
	//3. 점수의 총합이 350점 이상이면 B를 출력한다
	//4. 점수의 총합이 300점 이상이면 C를 출력한다
	//5. 그 미만이면 D를 출력한다
	
	//if / else if / else 문을 활용하여  실습

	//추천드리는 방법은 아님.
	int score1 = 0, score2 = 0, score3 = 0, score4 = 0;

	//int input1 = 0;
	//int input;

	//int 변수명, 변수명, 변수명 = 값, 변수명;


	printf("1번 점수를 입력해주세요 : ");
	//입력함수
	scanf_s("%d", &score1);

	//scanf_s("%d", &score2);
	printf("2번 점수를 입력해주세요 : ");
	cin >> score2; //돼지꼬리없이 그냥입력
	printf("3번 점수를 입력해주세요 : ");
	cin >> score3;
	printf("4번 점수를 입력해주세요 : ");
	cin >> score4;
	//c input
	int allScore = score1 + score2 + score3 + score4;

	//c output
	//cout << "할말1" << "할말2" << "할말3"

	if (400 <= allScore)
	{
		//printf("내 총 점수는 %d A\n", sum);
		cout << "내 총 점수는 " << allScore << " " << "A" << endl;
	}
	else if (350 <= allScore)
	{
		cout << "B\n";
	}
	else if (300 <= allScore)
	{
		cout << "C" << endl;
		//endl : \n 입니다.
		//end l => end line (줄맺음)
	}
	else
	{
		cout << "D" << endl;
	}


	//TIP 변수명 바꾸기
	//  (Ctrl + R + R)

	// 일잘하는 프로그래머
	//   프로그래머가 아닌사람들이 봤을때 
	//   일잘하는 프로그래머는 빨리 만드는 사람
	// 빨리만드는 사람 : 단축키 잘쓰는사람
}
#include <iostream>
using namespace std;

enum eChampionName {
	CN_GAREN = 100,	// 0부터 시작하기 싫은 경우.
	CN_GANGPLANK,
	CN_GALIO,

	//가능한 값은 그렇게 수정은 안함.



	CN_END
};

enum eErrorCode {
	ERR_NETWORK = -100001, //에러 코드 : 네트워크 오류입니다. 다시시도해주세요 출력
};

void main()
{
	//enum
	// 새로운 자료형

	//변수 선언 공식
	//자료형 변수명;
	//자료형 변수명 = 값;
	//int - 정수형
	//enum - 열거형 (정수로 표현)
	//enum : 값에 이름을 지어줄수있다.


	int myChampion = CN_GAREN;	// 0 - 가렌, 1 - 갱플랭크, 2 - 갈리오
	//생산성이 너무 떨어집니다.

	if (myChampion == CN_GAREN)
	{
		//dfasf
	}
	else if (myChampion == CN_GANGPLANK)
	{
		//asdfsa
	}

	//코드 직관성을 위해 사용 (가독성을 위한 문법)


	//자료형
	//int
	//enum (우리가 자료형을 새롭게 만들겠다.)

	//int 변수명 = 값;
	eChampionName 변수명 = CN_GAREN; // (나중에 불편한 경우가 생김..)
	//그래서 사용은 보통 int 변수에 담아서 사용한다..



	// enum 활용
	// (enum + switch)문은 효율이 아주좋습니다.
	switch (변수명)
	{
	case CN_GAREN:
		cout << "변수가 가렌입니다." << endl;
		break;
	case CN_GANGPLANK:
		cout << "변수가 갱플랭크입니다." << endl;
		break;
	case CN_GALIO:
		cout << "변수가 갈리오입니다." << endl;
		break;
	default:
		break;
	}
}
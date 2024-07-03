#include <iostream>

using namespace std;

enum WeaponType
{
	WT_LASER,
	WT_SANTAN,
	WT_DEFAULT
};

void main()
{
	// 게임 속도
	// 제일빠른 연산 ==> 비트연산

	// 파츠 (무기 타입)
	//      (레이저총, 산탄총, etc) (이런것들 종류가 32가지는 안넘겟죠?)

	// 비트연산의 단점은 
	// 32가지를 넘기면 구현에 문제가 생기는다는 것



	//0000
	//0001 => WT_LASER
	//0010 => WT_SANTAN
	//0100 => WT_DEFAULT

	//0011 => 레이저총이면서, 산탄총인경우.
	int weapon = (1 << WT_LASER) | (1 << WT_SANTAN);

	printf("weapon : %d\n", weapon);

	//weapon is laser
	// C랑 C++에서는
	// if(숫자) 숫자가 0이 아니면 true
	// 그 외의 언어에서는
	// if(숫자) 하면 에러가 난다(if문 안의 조건을 비교연산자로 확실히 해줘라)
	if (0 < (weapon & ( 1 << WT_LASER)))
	{
		printf("공격 관통 옵션 추가\n");
	}

	if (0 < (weapon & (1 << WT_SANTAN)))
	{
		printf("산탄 옵션 추가\n");
	}

	if (0 < (weapon & (1 << WT_DEFAULT)))
	{
		printf("공격 두 번 가능 추가\n");
	}

}
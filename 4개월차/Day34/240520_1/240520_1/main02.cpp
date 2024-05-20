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
	int weapon = (1 << WT_LASER) | (1 << WT_SANTAN);

	cout << WT_LASER << endl;

	printf("weapon : %d\n", weapon);

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
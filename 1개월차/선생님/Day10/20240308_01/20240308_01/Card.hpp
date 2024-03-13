// 본질은 헤더파일
#pragma once
#include "Test2.hpp"


void Function1()
{
	printf("aaa");
	Function3();
}

struct Card
{
	int Index;

	void Print()
	{
		printf("%d", Index);
	}


	void Swap(Card& another)
	{

	}
};
// 헤더파일임과 동시에 cpp파일
// 본질은 헤더파일

#pragma once
#include <iostream>
#include "Test.hpp"

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
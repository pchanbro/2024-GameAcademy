// ��������Ӱ� ���ÿ� cpp����
// ������ �������

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
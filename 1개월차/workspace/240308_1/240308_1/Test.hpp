#pragma once
#include <iostream>
#include "Card.hpp"

void Function2()
{
	Function1();
}

void Function3()
{
	printf("AA");
}

// ���� ���� Test.hpp�� Card.hpp ���°� ������ �߻���

// Test.hpp => Card.hpp�� �ҷ����µ�
// Card.hpp => Test.hpp �� �ʿ��ϸ�

// ���⼭ ������ �߻�

// Test.hpp => Function2 ����, Function3����, Function1 ����
// Card.hpp => #inlcude "Test.hpp"  Function2 ����, Function3 ����, Function1 ����

// Function2 �����ΰ� �� �� ��ġ��
// ===> ������ ����


// �׻� ���α׷��� ������ 
// main�� �����ϴ� cpp���� ����


// main02.cpp
// #include "Test.cpp" => #inlcude "Card.hpp" (Function1 ����) Function2 ����, Function3 ����
// #include "Card.hpp" => pragma once�� ����, �̹� �� �� �������� ����

// Function1 ȣ��
// => Card.hpp�� ����.
//	=> Card.hpp ������ �����Ϸ��� ���ϱ�
//		Function3�� ȣ���� �����.
//		Function3�� ã�� ���� include�� ������ �ȴ�.
//		 "Test.hpp" << �� ������ �������� �ϴ�
//			pragma once �� ����, �̹� �� �� �������� ����.
//				�׷��� ��������� �� ��𿡵� ���� ������ ���带�ϸ�, �ĺ��ڸ� ã�� �� ���ٰ� ��.


// �׷��� ���!!
//	���̵�
//		���� ��¥ .h, .cpp�� ���� ������ �˰�	
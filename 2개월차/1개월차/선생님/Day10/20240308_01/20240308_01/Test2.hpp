#pragma once
#include "Card.hpp"
#include <iostream>

void Function2()
{
	Function1();
}

void Function3()
{
	printf("AA");
}


//Main => Test2.hpp �ҷ�����
//Test2.hpp => Card.hpp �� �ҷ����µ�
//Card.hpp => Test2.hpp �� �ʿ��ϸ�!!

//���⼭ ������ �߻���.

//Test2.hpp => Function2 ����, Function3 ����, Function1 ����
//Card.hpp => #include "Test2.hpp"  Function2 ����, Function3 ����, Function1 ����

// Function2 �����ΰ� �ι� ��ġ��
//  ==> ������ ����


// �׻� ���α׷��� ������?
//  => main�� �ִ� cpp���� �����Ѵ�.

// main02.cpp
//  #include "Test2.hpp"  => #include "Card.hpp" (Function1 ����)  Function2 ����, Function3 ����
//	#include "Card.hpp" => pragma once�� ���� , �̹� �ѹ� �������� ����.

// Function1ȣ�� 
//  => Card.hpp �� ����.
//   => Card.hpp ������ �����Ϸ��� ���ϱ�
//		Function3 �� ȣ���ؾ���.
//      Function3�� ã������ ���� include�� �����Ե˴ϴ�.
//       "Test2.hpp" << �������� ���������ϴ�
//				 pragma once�� ���� , �̹� �ѹ� �������� ����.
//				�׷��� ��������� �� ��𿡵� ���⶧���� ���带�ϸ�, �ĺ��ڸ� ã���� ���ٰ� ��.


// �׷��� ���!!!
//		���̵带 �帮�ڽ��ϴ�.
//		���� ��¥ .h, .cpp �� ���� �����ɾ˰� �� Ŀ���Ҽ��ִ�.
//			�׷��� �ƴ϶��, .hpp�������δ� ����������!!
//			������� ������ ��������� �Ҹ��Դϴ�!!
//			����� ���漱���̳� �ڷ��� ����!!


#include "Answer.h"
#include <iostream>
using namespace std;

string Answer::getAnswer()
{
	printf("������ �����մϴ�.\n");
	return _answerList[rand() % 6];
}
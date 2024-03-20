#include "Answer.h"
#include <iostream>
using namespace std;

string Answer::getAnswer()
{
	printf("정답을 선택합니다.\n");
	return _answerList[rand() % 6];
}
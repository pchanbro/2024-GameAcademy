#pragma once
#include <iostream>
using namespace std;

class Answer
{
private:
	string _answerList[6] = { "position", "surprise", "umbrella", "triangle", "reaction" };
public:
	string _answer = "";
	string getAnswer();
};

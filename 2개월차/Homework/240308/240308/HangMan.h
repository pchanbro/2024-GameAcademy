#pragma once
#include <iostream>
using namespace std;

class HangMan
{
private:
	int _round = 1;
	int _correctNum = 0;
	int _answerLength = 8;
	string _input = "";
	bool _answerState[8] = {false,};
	
public:
	HangMan();
	~HangMan();
	bool IsContinue();
	bool IsAllCorrect();
	void PrintState(string answer);
	string InputAnswer();
	void CompareWord(string answer, string input);
};

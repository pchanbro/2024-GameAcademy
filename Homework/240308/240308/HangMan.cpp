#include "HangMan.h"
#include "Answer.h"
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

HangMan::HangMan()
{
	srand(time(NULL));
	printf("HangMan Start\n");
	Answer answer;
	answer._answer = answer.getAnswer();

	while (IsContinue())
	{
		system("cls");
		PrintState(answer._answer);
		_input = InputAnswer();
		CompareWord(answer._answer, _input);
		system("pause");
	}

	if (_correctNum == 8)
	{
		printf("정답!!");
	}
	else
	{
		printf("게임 패배...");
	}
}

HangMan::~HangMan()
{
	printf("\n게임 종료\n");
}

bool HangMan::IsContinue()
{
	if (_round <= 20 && !IsAllCorrect())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool HangMan::IsAllCorrect()
{
	int correctNum = 0;
	for (int i = 0; i < _answerLength; i++)
	{
		if (_answerState[i])
		{
			correctNum++;
		}
	}
	if (correctNum == _answerLength)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void HangMan::PrintState(string answer)
{
	for (int i = 0; i < _answerLength; i++)
	{
		if (_answerState[i])
		{
			printf("%c ", answer[i]);
		}
		else
		{
			printf("_ ");
		}
	}
	puts("");
}

string HangMan::InputAnswer()
{
	string input;
	printf("정답을 입력하세요 : ");
	cin >> input;

	return input;
}

void HangMan::CompareWord(string answer, string input)
{
	int inputDigit = 0;
	for (int i = 0; input[i]; i++)
	{
		inputDigit++;
	}

	for (int i = 0; i < inputDigit; i++)
	{
		if (answer[i] == input[i])
		{
			if (_answerState[i] != true)
			{
				_answerState[i] = true;
				_correctNum++;
			}
		}
	}
}
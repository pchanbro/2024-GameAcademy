	// 숙제
	// 1. 별찍기 4종
	// *
	// **
	// ***
	// ****
	// *****

	//     *
	//    **
	//   ***
	//  ****
	// *****

	// *****
	// ****
	// ***
	// **
	// *

	// *****
	//  ****
	//   ***
	//    **
	//     *

#include <iostream>
using namespace std;

// 1. 별 출력 모양 선택
int ChooseShape()
{
	int choice;
	cout << "1번" << endl;
	cout << "*    " << endl;
	cout << "**   " << endl;
	cout << "***  " << endl;
	cout << "**** " << endl;
	cout << "*****" << endl;
	
	cout << "2번" << endl;
	cout << "    *" << endl;
	cout << "   **" << endl;
	cout << "  ***" << endl;
	cout << " ****" << endl;
	cout << "*****" << endl;

	cout << "3번" << endl;
	cout << "*****" << endl;
	cout << "**** " << endl;
	cout << "***  " << endl;
	cout << "**   " << endl;
	cout << "*    " << endl;

	cout << "4번" << endl;
	cout << "*****" << endl;
	cout << " ****" << endl;
	cout << "  ***" << endl;
	cout << "   **" << endl;
	cout << "    *" << endl;

	cout << "출력하려는 별의 모양을 선택하세요 :";
	cin >> choice;

	return choice;
}

// 2. 별 출력 줄 수 선택
int ChooseLineNumber()
{
	int num;
	cout << "별을 몇 줄 출력할건지 정하세요 : ";
	cin >> num;

	return num;
}

// 3. 별 출력
void PrintStar(int choosedShape, int choosedLineNum)
{
	switch (choosedShape)
	{
	case 1: 
		for (int i = 1; i <= choosedLineNum; i++)
		{
			for (int j = 1; j <= i; j++)
			{
				cout << "*";
			}
			cout << endl;
		}
		break;
	case 2:
		for (int i = 1; i <= choosedLineNum; i++)
		{
			for (int j = choosedLineNum ; 1 <= j; j--)
			{
				if (i < j)
				{
					cout << " ";
				}
				else
				{
					cout << "*";
				}
			}
			cout << endl;
		}
		break;
	case 3:
		for (int i = 1; i <= choosedLineNum; i++)
		{
			for (int j = choosedLineNum ; i <= j; j--)
			{
				cout << "*";
			}
			cout << endl;
		}
		break;
	case 4:
		for (int i = 0; i < choosedLineNum; i++)
		{
			for (int j = 0; j < choosedLineNum; j++)
			{
				if (j < i)
				{
					cout << " ";
				}
				else
				{
					cout << "*";
				}
			}
			cout << endl;
		}
		break;
	default:
		cout << "잘못 선택하셨습니다." << endl;
		break;
	}
}

void main()
{
	// 1. 별 출력 모양 선택
	int shape = ChooseShape();

	// 2. 별 출력 줄 수 선택
	int line = ChooseLineNumber();

	// 3. 별 출력
	PrintStar(shape, line);
}
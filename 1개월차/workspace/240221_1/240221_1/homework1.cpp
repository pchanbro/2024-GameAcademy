	// ����
	// 1. ����� 4��
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

// 1. �� ��� ��� ����
int ChooseShape()
{
	int choice;
	cout << "1��" << endl;
	cout << "*    " << endl;
	cout << "**   " << endl;
	cout << "***  " << endl;
	cout << "**** " << endl;
	cout << "*****" << endl;
	
	cout << "2��" << endl;
	cout << "    *" << endl;
	cout << "   **" << endl;
	cout << "  ***" << endl;
	cout << " ****" << endl;
	cout << "*****" << endl;

	cout << "3��" << endl;
	cout << "*****" << endl;
	cout << "**** " << endl;
	cout << "***  " << endl;
	cout << "**   " << endl;
	cout << "*    " << endl;

	cout << "4��" << endl;
	cout << "*****" << endl;
	cout << " ****" << endl;
	cout << "  ***" << endl;
	cout << "   **" << endl;
	cout << "    *" << endl;

	cout << "����Ϸ��� ���� ����� �����ϼ��� :";
	cin >> choice;

	return choice;
}

// 2. �� ��� �� �� ����
int ChooseLineNumber()
{
	int num;
	cout << "���� �� �� ����Ұ��� ���ϼ��� : ";
	cin >> num;

	return num;
}

// 3. �� ���
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
		cout << "�߸� �����ϼ̽��ϴ�." << endl;
		break;
	}
}

void main()
{
	// 1. �� ��� ��� ����
	int shape = ChooseShape();

	// 2. �� ��� �� �� ����
	int line = ChooseLineNumber();

	// 3. �� ���
	PrintStar(shape, line);
}
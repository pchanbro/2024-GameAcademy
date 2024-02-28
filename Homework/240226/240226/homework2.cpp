// ���������� �ϳ����� (�迭���)
#include <iostream>

using namespace std;

enum eHand {
	RCP_HAND_LEFT,
	RCP_HAND_RIGHT,
	RCP_HAND_END
};

enum eRockScissorPaper {
	RCP_ONE_SCISSOR,
	RCP_ONE_ROCK,
	RCP_ONE_PAPER,
	RCP_ONE_END
};


// 1. ���ӽ��� �˸���
void PrintGameStartText()
{
	printf("��������������������������������������������������������������������������\n");
	printf("��  Start RockScissorPaper One out   ��\n");
	printf("��������������������������������������������������������������������������\n");
	cout << endl;
}

// 2. �� �� ����
void ChooseMyHand(int* myHand)
{
	cout << "�޼��� �����ϼ���(0 : ����, 1 : ����, 2 : ��) : ";
	cin >> myHand[RCP_HAND_LEFT];
	while((myHand[RCP_HAND_LEFT] != RCP_ONE_ROCK) && (myHand[RCP_HAND_LEFT] != RCP_ONE_SCISSOR) && (myHand[RCP_HAND_LEFT] != RCP_ONE_PAPER))
	{
		cout << "�÷��̾��� �޼��� �߸� ���õǾ����ϴ�. �ٽ� �����ϼ���.." << endl;
		cin >> myHand[RCP_HAND_LEFT];
	}

	cout << "�������� �����ϼ���(0 : ����, 1 : ����, 2 : ��) : ";
	cin >> myHand[RCP_HAND_RIGHT];
	while ((myHand[RCP_HAND_RIGHT] != RCP_ONE_ROCK) && (myHand[RCP_HAND_RIGHT] != RCP_ONE_SCISSOR) && (myHand[RCP_HAND_RIGHT] != RCP_ONE_PAPER))
	{
		cout << "�÷��̾��� �������� �߸� ���õǾ����ϴ�. �ٽ� �����ϼ���.." << endl;
		cin >> myHand[RCP_HAND_RIGHT];
	}
	
}

// 3. ��ǻ�� �� ����
void ChooseComHand(int* comHand)
{
	cout << "��ǻ�Ͱ� ���� �����մϴ�. " << endl;
	comHand[RCP_HAND_LEFT] = rand() % RCP_ONE_END;
	comHand[RCP_HAND_RIGHT] = rand() % RCP_ONE_END;
	cout << endl;
}

// 4. ���� ������ �� ���
void PrintHandState(int* myHand, int* comHand)
{
	cout << "�÷��̾� �޼� : ";
	switch (myHand[RCP_HAND_LEFT])
	{
	case RCP_ONE_SCISSOR:
		cout << "����" << endl;
		break;
	case RCP_ONE_ROCK:
		cout << "����" << endl;
		break;
	case RCP_ONE_PAPER:
		cout << "��" << endl;
		break;
	default:
		break;
	}

	cout << "�÷��̾� ������ : ";
	switch (myHand[RCP_HAND_RIGHT])
	{
	case RCP_ONE_SCISSOR:
		cout << "����" << endl;
		break;
	case RCP_ONE_ROCK:
		cout << "����" << endl;
		break;
	case RCP_ONE_PAPER:
		cout << "��" << endl;
		break;
	default:
		break;
	}

	cout << "��ǻ�� �޼� : ";
	switch (comHand[RCP_HAND_LEFT])
	{
	case RCP_ONE_SCISSOR:
		cout << "����" << endl;
		break;
	case RCP_ONE_ROCK:
		cout << "����" << endl;
		break;
	case RCP_ONE_PAPER:
		cout << "��" << endl;
		break;
	default:
		break;
	}

	cout << "��ǻ�� ������ : ";
	switch (comHand[RCP_HAND_RIGHT])
	{
	case RCP_ONE_SCISSOR:
		cout << "����" << endl;
		break;
	case RCP_ONE_ROCK:
		cout << "����" << endl;
		break;
	case RCP_ONE_PAPER:
		cout << "��" << endl;
		break;
	default:
		break;
	}	

	cout << endl;
}

// 5. �ϳ������� �� �� ���� 
int chooseOneOutMyHand(int* myHand)
{
	int choice;
	cout << "���� �����ϼ���(0 : �޼�, 1: ������) :";
	cin >> choice;

	return myHand[choice];
}

// 6. �ϳ������� ��ǻ�� �� ���� 
int chooseOneOutComHand(int* comHand)
{
	cout << "��ǻ�Ͱ� ���� �����մϴ�. " << endl;
	int choice = rand() % RCP_HAND_END;
	cout << endl;

	return comHand[choice];
}

// 7. ���� ������ �� ���
void PrintChoosedHand(int choosedMyHand, int choosedComHand)
{
	cout << "�÷��̾� : ";
	switch (choosedMyHand)
	{
	case RCP_ONE_SCISSOR:
		cout << "����" << endl;
		break;
	case RCP_ONE_ROCK:
		cout << "����" << endl;
		break;
	case RCP_ONE_PAPER:
		cout << "��" << endl;
		break;
	default:
		break;
	}

	cout << "��ǻ�� : ";
	switch (choosedComHand)
	{
	case RCP_ONE_SCISSOR:
		cout << "����" << endl;
		break;
	case RCP_ONE_ROCK:
		cout << "����" << endl;
		break;
	case RCP_ONE_PAPER:
		cout << "��" << endl;
		break;
	default:
		break;
	}
	cout << endl;
}

// 8. ��� ���
void ShowResult(int choosedMyHand, int choosedComHand)
{
	cout << "���������� �ϳ����� ��� " << endl;
	
	if (((choosedMyHand == RCP_ONE_ROCK) && (choosedComHand == RCP_ONE_SCISSOR)) || ((choosedMyHand == RCP_ONE_SCISSOR) && (choosedComHand == RCP_ONE_PAPER)) || ((choosedMyHand == RCP_ONE_PAPER) && (choosedComHand == RCP_ONE_ROCK)))
	{
		cout << "�÷��̾� �¸�!!" << endl;
	} 
	else if (((choosedMyHand == RCP_ONE_ROCK) && (choosedComHand == RCP_ONE_PAPER)) || ((choosedMyHand == RCP_ONE_SCISSOR) && (choosedComHand == RCP_ONE_ROCK)) || ((choosedMyHand == RCP_ONE_PAPER) && (choosedComHand == RCP_ONE_SCISSOR)))
	{
		cout << "�÷��̾� �й�.." << endl;
	}
	else
	{
		cout << "���º�" << endl;
	}
}

void main()
{
	srand(time(NULL));

	// 1. ���ӽ��� �˸���
	PrintGameStartText();

	// 2. �� �� ����
	int myHand[2] = {};
	ChooseMyHand(myHand);

	// 3. ��ǻ�� �� ����
	int comHand[2] = {};
	ChooseComHand(comHand);

	// 4. ���� ������ �� ���
	PrintHandState(myHand, comHand);

	// 5. �ϳ������� �� �� ���� 
	int choosedMyHand = chooseOneOutMyHand(myHand);

	// 6. �ϳ������� ��ǻ�� �� ���� 
	int choosedComHand = chooseOneOutComHand(comHand);

	// 7. ���� ������ �� ���
	PrintChoosedHand(choosedMyHand, choosedComHand);

	// 8. ��� ���
	ShowResult(choosedMyHand, choosedComHand);

}
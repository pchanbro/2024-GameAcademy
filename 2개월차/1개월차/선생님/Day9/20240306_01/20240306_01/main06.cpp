#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;


void main()
{
	//�ֿܼ����� ���ϱ���̰�
	//�����ܼ� �ٷ�°� �����ϵ� �ȳ��Ҿ��.
	//�ٴ����ָ� �ܼ� �Ⱦ��ϴ�. (�ְܼ��� �ȸ�����!)
	//�̰� ���ؾȵǸ� ��������������.


	int oldGameTime = ::GetTickCount64(); // ���� ���ӽð��� ����Ѵ�.	(0��)
	//GetTickCount => ������ �����ϰ� ��ms�� ��������?

	while (true)
	{
		//1�ʿ� �ѹ���
		int currentGameTime = GetTickCount64();
		if (1000 < currentGameTime - oldGameTime)
		{
			system("cls");
			cout << "1�ʰ� �������ϴ�." << endl;
			oldGameTime = currentGameTime;
		}
		//2D �ִϸ��̼�
		//�̹��� �������� ü�����ϴ� �������� �ִϸ��̼��� �ִµ�
		//�� �˰����� �̰ſ���.

	}
}
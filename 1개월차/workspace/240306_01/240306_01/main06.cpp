#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

void main()
{
	// �ֿܼ����� ���� ���
	// �ܼ� �ٷ�� ���� �����ϵ� �ȳ��Ҵ�.
	// �ٴ����ָ� �ܼ� �Ⱦ���. (�ְܼ��� �ȸ����)
	// ���ؾȵǸ� �������� �ʾƵ� ����.

	int oldGameTime = ::GetTickCount64(); // ���� ���ӽð��� ����Ѵ�. ���ι� �����ڸ��� ������(0��)

	//GetTickCount => ������ �����ϰ� �� ms�� ��������?

	while (true)
	{
		// 1�ʿ� �� ���� �������� ���ִ� ���
		int currentGameTime = GetTickCount64();
		if (1000 < currentGameTime - oldGameTime)
		{
			system("cls");
			cout << "1�ʰ� �������ϴ�. " << endl;
			oldGameTime = currentGameTime;
		}
		// �� ������ 
		// 2D �ִϸ��̼�
		// �̹��� �������� ü�����ϴ� �������� �ִϸ��̼��� �ִµ�
		// �� �˰����� �̰Ŵ�.
	}
}
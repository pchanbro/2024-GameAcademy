#include <iostream>
using namespace std;

enum WeaponType
{
	WT_LASER,
	WT_SANTAN,
	WT_DEFAULT
};

void main() 
{
	// ���� �ӵ�
	// ���Ϻ��� ���� ==> ��Ʈ����

	// ���� (���� Ÿ��)
	//      (��������, ��ź��, etc) (�̷��͵� ������ 32������ �ȳѰ���?)

	// ��Ʈ������ ������ 
	// 32������ �ѱ�� ������ ������ ����´ٴ� ��



	//0000
	//0001 => WT_LASER
	//0010 => WT_SANTAN
	//0100 => WT_DEFAULT

	//0011 => ���������̸鼭, ��ź���ΰ��.
	int weapon = (1 << WT_LASER) | (1 << WT_SANTAN);

	printf("weapon : %d\n", weapon);

	//weapon is laser
	// C / C++ 
	// if(����) ���ڰ� 0�̾ƴϸ� true
	// C++�� �ƴϸ�
	// if(����) ==> ���� (�񱳿����ڷ� Ȯ���ϰ� ������մϴ�.)
	// C++ -> C#
	// C# -> C++ 
	if (0 < (weapon & (1 << WT_LASER)))
	{
		printf("���� ���� �ɼ� �߰�\n");
	}

	//weapon is santan
	if (0 < (weapon & (1 << WT_SANTAN)))
	{
		printf("��ź �ɼ� �߰�\n");
	}

	//weapon is default
	if (0 < (weapon & (1 << WT_DEFAULT)))
	{
		printf("���� �ι� ���� �߰�\n");
	}
}
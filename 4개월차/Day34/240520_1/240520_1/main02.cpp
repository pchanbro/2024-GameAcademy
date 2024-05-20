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
	int weapon = (1 << WT_LASER) | (1 << WT_SANTAN);

	cout << WT_LASER << endl;

	printf("weapon : %d\n", weapon);

	// C�� C++������
	// if(����) ���ڰ� 0�� �ƴϸ� true
	// �� ���� ������
	// if(����) �ϸ� ������ ����(if�� ���� ������ �񱳿����ڷ� Ȯ���� �����)
	if (0 < (weapon & ( 1 << WT_LASER)))
	{
		printf("���� ���� �ɼ� �߰�\n");
	}

	if (0 < (weapon & (1 << WT_SANTAN)))
	{
		printf("��ź �ɼ� �߰�\n");
	}

	if (0 < (weapon & (1 << WT_DEFAULT)))
	{
		printf("���� �� �� ���� �߰�\n");
	}

}
#include "pch.h"

void Comment1()
{
	// 1. Flipbook �ϼ�
	//    -duration, loop ���
	// 
}

void Comment2()
{
	// if�� ���ۿ���

	bool conditionHeavy1 = true;	// ex) CheckCollision (���� ���� ���ſ��� ��)
	bool conditionHeavy2 = false;
	bool conditionLight3 = true;	// 
	bool conditionLight4 = false;

	// if������
	// || ���굿���� true�� ������ �ڿ� ������ ���� �ʴ´�.
	if (conditionLight3 || conditionHeavy1) // �׷��� ||(or) ���ǿ��� ������ �ָ� �տ� ������
	{
		printf("�ش� �ڵ尡 ����ȴ�.\n");
	}
	else
	{
		printf("�ش� �ڵ尡 ����ȴ�.\n");
	}

	// if������ 
	// && ������ ������ false�� ������ ���� ������ ���� �ʴ´�.
	if (conditionLight3 && conditionHeavy1) // �׷��� &&(and) ���۵� ������ �ָ� �տ� ������
	{
		printf("�ش� �ڵ尡 ����ȴ�.\n");
	}
	else
	{
		printf("�ش� �ڵ尡 ����ȴ�.\n");
	}

	// �׷��ٰ� �̰� �ǽ��ϸ鼭 �� �ʿ�� ����. 

	// �׳� �˾����� ������ ������ָ� ����.

	RECT rc1;
	RECT rc2;
	if (Input->GetKeyDown(KeyCode::d) && Collision::RectInRect(rc1, rc2))
	{
		// �׳� �������� ����ȭ �����
		// Ȯ���ϰ� �ʹ� ���̰ų� ������ �ݺ��ϴ°� �ڷ� ������
	}

	// ���� �ٲܶ���
	// (��)����Ѱ��϶�, ����������..

	// Ű���� ���������� ����Ѱǰ�?
}

void Comment3()
{
	// Flipbook�̶�?

	// ���� �ִϸ��̼�

	// �������� ���̿� ����ϰ� �׸� �׷��ְ�
	// ���徿 ������ �ѱ�� �������� �ִϸ��̼� ȿ���� ���°�
	// �׷���

	// �𸮾󿡴� Flipbook �̶�� �ִ� ��� Animation�� ���� ����
	// ����Ƽ���� Animation���� ���յǾ� ����
}

void Comment4()
{
	// �ǽ�

	// FlipbookActor�� ��ӹ޾Ƽ� 
	// CreatureActor, UserCharacterController�� �����

	// Space�� ������ ����
	// ȭ��ǥ ���Ʒ��翷�� ������ Move
	// ������ ������ Idle ����

	// �����

	// + �ݹ� �Ѵٸ� ���ͱ��� ����
	// �����ϸ� ���� �������

	// �̰͵� �ݹ��Ѵٸ� ���� ü�±�������
}
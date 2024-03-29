#include <iostream>
#include "Defines.h"
using namespace std;

class GameManager
{
DECLARE_SINGLE(GameManager)

public:
	void GameStart()
	{
		printf("������ �����մϴ�.\n");
	}
};

void Function()
{
	//static�� �ѹ��� �ʱ�ȭ�ǰ�
	//�ٽ� �����Ҷ��� ������ ���� �ʴ´�.
	static int a = 0;
	a++;
	printf("%d\n", a);

	
}


void main()
{

	//�̱��������̶�??
	// �̱��������̶�
	// ���α׷����� �� �ϳ��� ��ü�� �����ϰ� ����� ����

	//�Ʒ��� �ȵǰ��ؾ���..
	/*MySingleton* single1 = new MySingleton();
	MySingleton* single2 = new MySingleton();
	MySingleton* single3 = new MySingleton();
	MySingleton* single4 = new MySingleton();
	MySingleton* single5 = new MySingleton();*/

	// �̷��� ����� �ȴ�.
	// ���α׷��Ӱ� ���ؼ� �Ѱ��� ����� ������
	// ���������� �Ѱ��� ����� ������ �ټ������� �Ǽ��� �����Ҽ� �����ϱ�

	// ����������??
	// GameManager ���� ������ �����ϴ� Ŭ����
	// ������ �־���� ������ ����
	// GameManager �� ���ϳ��� �����ϰ� �ϱ����� �̱��� ������ ���ϴ�.

	for (int i = 0; i < 10; i++)
	{
		Function();
	}

	GameManager::GetInstance()->GameStart();


	// �̱����� ������ �˰�, �־��������˰�, ��� �������� �˾Ҵµ�
	// �긦 �� ���� ����°���???

	// �⺻������
	// ���������� ����ϴ°� �����ٰ� ���ϴ�.
	// �޸𸮰���������
	// ���α׷��ְ���������

	// �޸� ����
	// 1. Code����
	// 2. Data���� (static�� ��������), �뷮�� �����. (read�� ������, write�� ����)
	// 3. Heap����
	// 4. Stack���� 

	// ���� �����ٴ°���?
	// ����������??

	// GameManager �� ȣ���ϴ°�
	// �ǰ� ������������ GameManager�� �����ϰ� �˴ϴ�.

	// ��𼭳� �����ֱ⶧����
	// ĸ��ȭ�� 100% �ߵǾ��ִ°� �ƴ϶��
	// �ڵ尡 ���ϼ��ۿ� ����

	// ��? ������ �����̴�.
	// ���������� ���ڴ�.
	// ���� �˾Ƽ� �� �����ϴ� �ڵ尡 ���� �ڵ��.


	// ���������� ���꼺�� �÷����. (���ϱ� ������)
	// ������ �̱����� �Ⱦ��� ���Ӱ����� ��������
	// �����е��� �̷��� �Ű澲������ �̱��� ���� ����˴ϴ�.

}
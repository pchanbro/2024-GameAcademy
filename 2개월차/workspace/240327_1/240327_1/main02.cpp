#include <iostream>

using namespace std;

class Key
{

};

class MasterKey : public Key
{

};

int main()
{
	// �� ��ȯ ĳ���� (4����)

	// 1���� C�����Դϴ�.

	// �ڷ����� ����
	int a = 3;
	float b = 1.1f;
	string str = "My String";
	bool d = true;

	// 1. - C���� ĳ����
	int e = (int)b;

	// �ּҰ��� ����(int)�� �޴´�.
	// int f  = (int)&b;
	// printf("%d\n", f);
	

	// 2. C++������ ĳ����
	// -1. static_cast (���� ĳ����)
	// flaot -> int
	int g = static_cast<int>(b);

	// -2. dynamic_cast
	MasterKey* key = new MasterKey();
	Key* myKey1 = dynamic_cast<MasterKey*>(key);

	// -3. reinterpret_cast
	// ���� �Ⱦ���.
	// �޸� �״�� ĳ�������ٶ�.
	// �������� �̷��� �϶�°� �ƴϸ� ������ ���ٰ� �Ѵ�.
	int bb = 123;
	int* ptr1 = reinterpret_cast<int*>(bb);

	cout << *ptr1 << endl;

	return 0;
}
#include <iostream>
#include <functional> // C++20 ���� ����ϱ� ���� �켱 ����������
using namespace std;

void Run1()
{
	cout << "Run1" << endl;
}

void Run2(int a)
{
	cout << "Run2, " << a << endl;
}

int Run3(int a)
{
	cout << "Run2, " << a << endl;

	return a + 3;
}

class TestObject
{
public:
	void DoSomething()
	{
		cout << "DoSomething" << endl;
	}
};

void main()
{
	// C++20 ���� ����ϴ� ���
	// visual studio 2019, 2017 << ���⼭�� �ȵ�, C++20����� �ƿ� ����.

	// �Լ������͹���
	// ��ȯ�ڷ��� ���ӽ����̽�::*������(�Ű�����) = ��;
	// function<��ȯ�ڷ���(�Ű�����)> ������ = ��;
	function<void()> myFunction1 = &Run1;
	function<void(int)> myFunction2 = &Run2;
	function<int(int)> myFunction3 = &Run3;

	myFunction1();
	myFunction2(2);
	cout << "Result : " << myFunction3(4) << endl;

	// �̷��� �����ϴ� ����
	function<void(TestObject&)> myFunction4 = &TestObject::DoSomething;

	TestObject t1;
	myFunction4(t1);

	// ������ ������ �ڵ�(�ᱹ�� �� ��)�� �Ʒ��� ����.
	// �׷��ٸ� ���� �Ϸ����� ���� �� �����? 
	// ������� �޶� �տ��� �� ��ó�� ������ �ֱ� ����
	// ���� �̰��� �������� �𸣰� �Ⱦ��� ���� �����Ѵ�.
	function<void()> myFunction5 = nullptr;
	// bind(���ε���ų �Լ�, �����ų object)
	myFunction5 = bind(&TestObject::DoSomething, &t1);
	myFunction5();

	// �� �ñ��Ѱ� �ִٸ� 
	// function, bind, (mem_fn) �˻��� �غ���
}
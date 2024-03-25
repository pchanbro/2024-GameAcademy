#define Interface class
#include <iostream>
#include <string>

using namespace std;

Interface IDoorOpener
{
public:
	virtual void OpenDoor() abstract;
};

class Key : public IDoorOpener // MasterKey�� �θ�Ŭ����, QusetKey�� �θ�Ŭ����
{
	// private	 => ���θ� ���� ����
	// protected => ���� + ���� ��ӹ��� �ָ� ���� ����
	// public	 => �ƹ��� ���� ����
protected:
	string _name;

public:
	void SetName(string name)
	{
		_name = name;
	}

	void OpenDoor()
	{
		printf("[%s] ���� ���� ���ߴ�\n", _name.c_str());
	}

	void CloseDoor()
	{
		printf("[%s] ���� ���� ���ߴ�\n", _name.c_str());
	}
};


// ��� ���� ( : public �ڷ���)
class MasterKey : public Key  // Key�� �ڽ�Ŭ����
{
public:
	// override�� ��������
	virtual void OpenDoor() override
	{
		printf("[%s] ���� ������\n", _name.c_str());
	}

	virtual void CloseDoor() override
	{
		printf("[%s] ���� �ݾҴ�\n", _name.c_str());
	}
};


void main()
{
	// 2. Ŭ����
	// ## Ŭ������ 4���� Ư¡
	// �߿��ѵ�, �ܿ�� ���� ����
	// �ٵ� �ڿ����� �ܿ���

	// ��Ӽ�, ������, ĸ��ȭ, �߻�ȭ (����ü�� �� ������� �ʴ� Ư¡)
	
	// Ŭ���� 
	// �̷е� ���� Ȱ�뵵 �ؾ���
	
	// Ŭ������ ���� ���ܱ�
	// ���α׷��ӿ��� ö���� �䱸
	// ������ ���� ����ϴ�

	// Ŭ���� = ����ü (C++������)
	// �ٵ� �츮�� C++������ ���� �ƴϱ� ������
	// ������ �ؾ��Ѵ�.

	// Ŭ���� (��ü)
	// ����ü (������)




	// ��� ����
	
	// ��Ӽ�
	{
		// ������ �Լ��� ��Ȱ���� �� �� �ִ�. (���� ū ����)
		// ������� ���Ͽ� _name�� SetName �Լ��� �� �� �ִ�.
		MasterKey* masterKey = new MasterKey;
		masterKey->SetName("������Ű");
		// cout << masterKey->_name << endl;
		masterKey->OpenDoor();

		delete masterKey;
	}




	// ������
	{
		// �θ�Ŭ������, �ڽ�Ŭ������ �������� ��
		// �θ�Ŭ���� �ڷ������� �ڽ�Ŭ���� �Լ��� ȣ���� �� �ִ�. (virtual Ű���带 ����Ͽ�)

		//
		Key* key = new MasterKey();
		// �����ʹϱ� key�� masterKey�� �ٶ󺸰� �ִٰ� ���� �ȴ�.
		// �ᱹ �ϴ� Key �����Ͷ�� ���� �ٽ�
		// �׷��� masterKey�� ��ҵ��� �ٶ��� ����
		// �ٵ� ���� virtual Ű���尡 masterKey�� ��Ҹ� �ٶ󺸰� �ִ�.
		// ����� virtual Ű����� 4Byte �߰�
		key->SetName("������Ű2");
		key->OpenDoor();

		delete key;
		// �������� ���� ���� �� ��� ����ϴ��� �˷��ְڴ�.
	}



	// ĸ��ȭ 
	// �̰� ���� ����.
	// �̹� �˰��ִ�.
	// ��� ������, ��������
	// �� ������
	// how, what, why

	// public:
	// ��ü ��
	// private, protected�� ���°���
	// �⺻������ 
	// �������� ������ �ܺο� �����Ű�� �ʴ°��� Ŭ������ �⺻ ��Ģ
	
	// �ܺο� �����Ű�� ������ � ������ �ִ°�?
	
	// Ŭ���� << �ϳ��� å���� ����ϴ� �ڷ���
	
	// Ŭ���� ������
	// TimeManager << 
	//  �ð��� �������ִ� �ڷ���

	// �������� ����
	// �ð���� ����
	// ������ ��꿡 ���̴� ����� ������

	// TimeManager�� ������ ���� ���忡��
	// �� ���κ������� ��Ʈ���� �ʿ䰡 ����.
	// ������ �𸣴°� �������� ����.

	// �ܺο����� �ܼ��ϰ� 
	// ����ð�
	// ���������� ~ ���������� �ɸ��ð�

	// Unity�� Time.deltaTime �̷���



	
	// �߻�ȭ
	// �ٸ������� "�������̽�"
	// �߻�ȭ�� �Լ��� ����Ǿ��ְ�, ���� ���Ǵ� �ȵǾ��ִ� ����

	{
		IDoorOpener* key1 = new Key();
		key1->OpenDoor();
	}

}
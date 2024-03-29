#define Interface class 
#include <iostream>
#include <string>
using namespace std;

Interface IDoorOpener
{
public:
	virtual void OpenDoor() abstract;
};

Interface IDoorCloser
{
public:
	virtual void CloseDoor() abstract;
};

class Key : public IDoorOpener, public IDoorCloser	// MasterKey �θ�Ŭ����, QuestKey �θ�Ŭ����
{
//private   => ���θ� ���ٰ���
//protected => ���� + ���� ��ӹ��� �ָ� ���ٰ���
//public    => �ƹ��� ���ٰ���
protected:
	string _name;

public:
	void SetName(string name)
	{
		_name = name;
	}

	virtual void OpenDoor() override
	{
		printf("[%s] ���� ���� ���ߴ�.\n", _name.c_str());
	}

	virtual void CloseDoor() override
	{
		printf("[%s] ���� ���� ���ߴ�.\n", _name.c_str());
	}
};


//��� ���� ( : public �ڷ��� )
class MasterKey : public Key		// Key �ڽ�Ŭ����
{
public:
	//override�� ��������
	virtual void OpenDoor() override
	{
		printf("[%s] ���� ������.\n", _name.c_str());
	}

	virtual void CloseDoor() override
	{
		printf("[%s] ���� �ݾҴ�.\n", _name.c_str());
	}
};

class QuestKey : public Key		// Key �ڽ�Ŭ����
{
public:
	virtual void OpenDoor() override
	{
		printf("[%s] ����Ʈ�� ����Ǹ� ���� ����.\n", _name.c_str());
	}

	virtual void CloseDoor() override
	{
		printf("[%s] ����Ʈ�� ����Ǹ� ���� ����.\n", _name.c_str());
	}
};


void main()
{
	// 2. Ŭ����
	// ## Ŭ������ 4���� Ư¡
	// �߿��ѵ�, �ܿ�ű��� �ƴմϴ�.

	// ��Ӽ�, ������, ĸ��ȭ, �߻�ȭ

	// Ŭ����
	// �̷и� �� ����
	// Ȱ����� �ؾ��ؿ� �����

	// Ŭ���� (��ü)
	// ����ü (������)


	//���
	{
		// ������ �Լ��� ��Ȱ���� �� �� �ִ�. (���� ū ����)
		//������� ���Ͽ� _name�� SetName �Լ��� �����ִ�.
		MasterKey* masterKey = new MasterKey();
		masterKey->SetName("������Ű");
		masterKey->OpenDoor();
		delete masterKey;
	}

	//������
	{
		// �θ�Ŭ������, �ڽ�Ŭ������ �����Ͽ�����
		// �θ�Ŭ���� �ڷ������� �ڽ�Ŭ���� �Լ��� ȣ���� �� �ִ�. (virtual Ű���� ���)

		// �θ�Ŭ������ �ڽ�Ŭ������ ����
		//Key* key
		//new Master()
		Key* key = new MasterKey();
		key->SetName("������Ű2");
		key->OpenDoor();

		delete key;
		//�������� ���߿� �����Ҷ� ��� ���Ǵ���, �����Կ�
	}

	//ĸ��ȭ
	//�̰� ���� ������
	//�̹� �˰��ֽ��ϴ�.
	//��� ���°���, ��������
	//�� ������?
	//   public:
	//��ü �� 
	// private, protected �� ���°���
	//�⺻������ 
	// �������� ������ �ܺο� �����Ű�� �ʴ´�.
	// Ŭ������ �⺻ ��Ģ�Դϴ�.
	
	// �ܺο� �����Ű�� ������ ��ü � ������ �ֱ淡
	// �� ���Ѱ� �����ϰ� ������ �Ƚ�Ű����???

	// Ŭ���� << 
	// �ϳ��� å���� ����ϴ� �ڷ���
	
	// Ŭ���� ������
	// TimeManager 
	//  �ð��� �������ִ� �ڷ���

	// �������� ����
	//  �ð���õ� ����
	//  �������� ��꿡 ���̴� ����� ������

	// TimeManager�� �����پ��� ���忡��
	// �� ���κ������� ��Ʈ���� �ʿ䰡 ������??
	// �������� ������ private�� �ƿ� ������ ��Ű�� �ʴ´�.
	// �ܺο����� �ܼ��Ѱ�
	// ����ð�
	// ���������� ~ ����������  �ɸ��ð�

	// Time.deltaTime



	// �߻�ȭ
	// �ٸ������� "�������̽�"
	// �߻�ȭ�� �Լ��� ����Ǿ��ְ�, ���� ���Ǵ� �ȵǾ��ִ� ����
	{
		Key* key1 = new Key();
		IDoorOpener* opener = key1;
		opener->OpenDoor();

		IDoorCloser* closer = key1;
		closer->CloseDoor();
	}


}

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

class Key : public IDoorOpener, public IDoorCloser	// MasterKey 부모클래스, QuestKey 부모클래스
{
//private   => 본인만 접근가능
//protected => 본인 + 나를 상속받은 애만 접근가능
//public    => 아무나 접근가능
protected:
	string _name;

public:
	void SetName(string name)
	{
		_name = name;
	}

	virtual void OpenDoor() override
	{
		printf("[%s] 문을 열지 못했다.\n", _name.c_str());
	}

	virtual void CloseDoor() override
	{
		printf("[%s] 문을 닫지 못했다.\n", _name.c_str());
	}
};


//상속 문법 ( : public 자료형 )
class MasterKey : public Key		// Key 자식클래스
{
public:
	//override는 가독성용
	virtual void OpenDoor() override
	{
		printf("[%s] 문을 열었다.\n", _name.c_str());
	}

	virtual void CloseDoor() override
	{
		printf("[%s] 문을 닫았다.\n", _name.c_str());
	}
};

class QuestKey : public Key		// Key 자식클래스
{
public:
	virtual void OpenDoor() override
	{
		printf("[%s] 퀘스트가 통과되면 문이 열림.\n", _name.c_str());
	}

	virtual void CloseDoor() override
	{
		printf("[%s] 퀘스트가 통과되면 문이 닫힘.\n", _name.c_str());
	}
};


void main()
{
	// 2. 클래스
	// ## 클래스의 4가지 특징
	// 중요한데, 외울거까진 아닙니다.

	// 상속성, 다형성, 캡슐화, 추상화

	// 클래스
	// 이론만 들어도 어려운데
	// 활용까지 해야해요 저희는

	// 클래스 (객체)
	// 구조체 (데이터)


	//상속
	{
		// 변수와 함수를 재활용을 할 수 있다. (가장 큰 장점)
		//상속으로 인하여 _name과 SetName 함수를 쓸수있다.
		MasterKey* masterKey = new MasterKey();
		masterKey->SetName("마스터키");
		masterKey->OpenDoor();
		delete masterKey;
	}

	//다형성
	{
		// 부모클래스로, 자식클래스를 생성하였을때
		// 부모클래스 자료형으로 자식클래스 함수를 호출할 수 있다. (virtual 키워드 사용)

		// 부모클래스로 자식클래스를 생성
		//Key* key
		//new Master()
		Key* key = new MasterKey();
		key->SetName("마스터키2");
		key->OpenDoor();

		delete key;
		//다형성은 나중에 수업할때 어떻게 사용되는지, 익힐게요
	}

	//캡슐화
	//이건 제일 쉬워요
	//이미 알고있습니다.
	//어떻게 쓰는건지, 무엇인지
	//왜 쓰는지?
	//   public:
	//대체 왜 
	// private, protected 를 쓰는건지
	//기본적으로 
	// 내부적인 변수를 외부에 노출시키지 않는다.
	// 클래스의 기본 원칙입니다.
	
	// 외부에 노출시키지 않으면 대체 어떤 장점이 있길래
	// 그 편한걸 감수하고 노출을 안시키는지???

	// 클래스 << 
	// 하나의 책임을 담당하는 자료형
	
	// 클래스 예시중
	// TimeManager 
	//  시간을 관리해주는 자료형

	// 내부적인 변수
	//  시계관련된 엔진
	//  내부적인 계산에 쓰이는 잡다한 변수들

	// TimeManager를 가져다쓰는 입장에서
	// 저 내부변수까지 컨트롤할 필요가 있을까??
	// 내부적인 변수는 private로 아예 노출을 시키지 않는다.
	// 외부에서는 단순한게
	// 현재시간
	// 이전프레임 ~ 현재프레임  걸린시간

	// Time.deltaTime



	// 추상화
	// 다른언어에서는 "인터페이스"
	// 추상화는 함수만 선언되어있고, 본문 정의는 안되어있는 상태
	{
		Key* key1 = new Key();
		IDoorOpener* opener = key1;
		opener->OpenDoor();

		IDoorCloser* closer = key1;
		closer->CloseDoor();
	}


}

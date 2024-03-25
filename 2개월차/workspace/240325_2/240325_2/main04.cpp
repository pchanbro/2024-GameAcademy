#define Interface class
#include <iostream>
#include <string>

using namespace std;

Interface IDoorOpener
{
public:
	virtual void OpenDoor() abstract;
};

class Key : public IDoorOpener // MasterKey의 부모클래스, QusetKey의 부모클래스
{
	// private	 => 본인만 접근 가능
	// protected => 본인 + 나를 상속받은 애만 접근 가능
	// public	 => 아무나 접근 가능
protected:
	string _name;

public:
	void SetName(string name)
	{
		_name = name;
	}

	void OpenDoor()
	{
		printf("[%s] 문을 열지 못했다\n", _name.c_str());
	}

	void CloseDoor()
	{
		printf("[%s] 문을 닫지 못했다\n", _name.c_str());
	}
};


// 상속 문법 ( : public 자료형)
class MasterKey : public Key  // Key의 자식클래스
{
public:
	// override는 가독성용
	virtual void OpenDoor() override
	{
		printf("[%s] 문을 열었다\n", _name.c_str());
	}

	virtual void CloseDoor() override
	{
		printf("[%s] 문을 닫았다\n", _name.c_str());
	}
};


void main()
{
	// 2. 클래스
	// ## 클래스의 4가지 특징
	// 중요한데, 외울것 까진 않음
	// 근데 자연스레 외워짐

	// 상속성, 다형성, 캡슐화, 추상화 (구조체는 잘 사용하지 않는 특징)
	
	// 클래스 
	// 이론도 어려운데 활용도 해야함
	
	// 클래스는 뉴비 절단기
	// 프로그래머에게 철학을 요구
	// 문법도 제일 깊숙하다

	// 클래스 = 구조체 (C++에서는)
	// 근데 우리는 C++에서만 쓸게 아니기 때문에
	// 구분을 해야한다.

	// 클래스 (객체)
	// 구조체 (데이터)




	// 상속 문법
	
	// 상속성
	{
		// 변수와 함수를 재활용을 할 수 있다. (가장 큰 장점)
		// 상속으로 인하여 _name와 SetName 함수를 쓸 수 있다.
		MasterKey* masterKey = new MasterKey;
		masterKey->SetName("마스터키");
		// cout << masterKey->_name << endl;
		masterKey->OpenDoor();

		delete masterKey;
	}




	// 다형성
	{
		// 부모클래스로, 자식클래스를 생성했을 때
		// 부모클래스 자료형으로 자식클래스 함수를 호출할 수 있다. (virtual 키워드를 사용하여)

		//
		Key* key = new MasterKey();
		// 포인터니까 key가 masterKey를 바라보고 있다고 보면 된다.
		// 결국 일단 Key 포인터라는 것이 핵심
		// 그래서 masterKey의 요소들은 바라보지 못함
		// 근데 이제 virtual 키워드가 masterKey의 요소를 바라보고 있다.
		// 참고로 virtual 키워드는 4Byte 추가
		key->SetName("마스터키2");
		key->OpenDoor();

		delete key;
		// 다형성은 나중 수업 때 어떻게 사용하는지 알려주겠다.
	}



	// 캡슐화 
	// 이건 제일 쉽다.
	// 이미 알고있다.
	// 어떻게 쓰는지, 무엇인지
	// 왜 쓰는지
	// how, what, why

	// public:
	// 대체 왜
	// private, protected를 쓰는건지
	// 기본적으로 
	// 내부적인 변수를 외부에 노출시키지 않는것이 클래스의 기본 원칙
	
	// 외부에 노출시키지 않으면 어떤 장점이 있는가?
	
	// 클래스 << 하나의 책임을 담당하는 자료형
	
	// 클래스 예시중
	// TimeManager << 
	//  시간을 관리해주는 자료형

	// 내부적인 변수
	// 시계관련 엔진
	// 내부적 계산에 쓰이는 잡다한 변수들

	// TimeManager를 가져다 쓰는 입장에서
	// 저 내부변수까지 컨트롤할 필요가 없다.
	// 오히려 모르는게 좋을때도 많다.

	// 외부에서는 단순하게 
	// 현재시간
	// 이전프레임 ~ 현재프레임 걸린시간

	// Unity의 Time.deltaTime 이런거



	
	// 추상화
	// 다른언어에서는 "인터페이스"
	// 추상화는 함수만 선언되어있고, 본문 정의는 안되어있는 상태

	{
		IDoorOpener* key1 = new Key();
		key1->OpenDoor();
	}

}
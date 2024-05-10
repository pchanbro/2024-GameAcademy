#include "pch.h"

void Comment1()
{
	// 1. Circle Collider 만든거 확인
	// 2. UI - 이론설명
	// 3. 간단하게 구현
}

void Comment2()
{
	// UI를 진행할 것

	// UI (User Interface)
	// UX (User Experience) -> 기획단계( 버튼을, 캐시샵을 등등을 어디에 두는게 유저한테 좋을까? 등등 )

	// 게임에는 크게 2가지가 존재
	// World, UI (유저한테 보여주는 전부)
	// 
	// World, Camera (게임을 구성하는 전부)

	// 비중이 높은거에 비해 난이도가 높지 않아 
	// 신입들에게 많이 시킨다.


}

void Comment3()
{
	// UI를 구성할때 제일 중요한거

	// 1. Panel
	// UI라는 base클래스를 만들어줄거다.

	// base클래스를 만드는이유
	//  - 클래스 속성중, 다형성을 활용하기 위해
	//  - FlipActor, SpriteActor
	//  - Actor이기 때문에 조작하기에 뭔가 공통점으로 해줘야 할 수 있는데
	//  - 둘 다 한번에 Update라던지, 이런 함수들을 호출할수가 없다.
}

void Comment4()
{
	// UI.cpp에서 
	
	// SetIsShow라는 함수로 안만들고
	// Show, Hide라는 함수들로 나눠 만드는이유

	// 함수는 가독성이 1순위 (SetIsShow보다는 Show, Hide가 유저[프로그래머]가 읽기에 더 수월하다.)
	// SetCenterRect << 이런건 가독성이 너무 없지 않았나?
	// 2순위는 범용성
	// 가독성이 범용성을 너무 깨면 그걸 지켜주기 위해 좀 수정한 것
}

void Comment5()
{
	// Panel은 계층구조 Hierachy를 가진다.
	// Panel에서 다른 UI들을 가지고 있을수만 있으면 된다.
}

void Comment6()
{
	// Image 클래스를 만들어서
	// Panel에 이미지를 붙여보자

	// [Panel] 아래에 다음과 같은것들이 있다.
	//   - Image
	//   - Button
	//   - Label (글자)
	//   - [Panel]
	//       - Image
}

void Comment7()
{
	// 실습 : Panel에 Image를 넣어서 화면 가운데에 이미지 UI 출력하기

	// Scene에서
	// 1. Panel을 만들고
	// 2. Image를 만들고
	// 3. Image를 Panel에 연결해주고 
	// 4. Image에게 Sprite를 세팅해주고 

	// Panel을 씬에서 
	// Init, Render, Update, Release를 실행해준다.
}

void Comment8()
{
	// 숙제:
	// 이미지가 부모 패널에 따라서, 위치 변하도록 프레임워크 코드 수정
}

void Comment9()
{
	// 선생님이 언리얼할때 제일 힘들었던게
	// 언리얼만의 매크로가 진짜 많은데
	// 그게 어떤 의미인지, 왜 써야하는지 모를때가 많은데
	// 코드해석이 더 안됐음
	// 그런거 좀 익숙해지라고 

//#define DECLARE_CHILD(ClassName, ParentName)		\
//	using Super = ParentName;						\
//public:												\
//	ClassName() {}									\
//	virtual ~ClassName() {}							\

	// 이걸 추가한거다
}
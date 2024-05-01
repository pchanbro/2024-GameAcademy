#include "pch.h"

void Comment1()
{
	// 1. 부동소수점
	//  - (프로그래밍에 관련된 상식)

	// 2. 캐릭터 만들기

	// 3. 카메라까지 붙여보도록 하자
	//  - 현재 카메라는 화면고정되어 있음
}

void Comment2()
{
	// 부동소수점
	// 콘솔에서 Day28만들고 진행함
}

void Comment3()
{
	// 캐릭터 만들기 

	// FlipbookActor를 상속받아서
	// CreatureActor, UserCharacterController를 만들고

	// Space를 누르면 
	// Attack
	// 화살표 위아래양옆 을 누르면
	// Move
	// 가만히 있으면
	// Idle 상태 

	// 만들기



	// Actor
	//  - 기능만 존재하는 더미
	//  - 화면에 존재하는 객체

	// Controller
	//  - 기능을 실행시켜주는 객체
	//  - 화면애는 존재안한다.

	// Actor => 생성하면 화면에 나와야한다.
	//    (따로 안보이게 처리한게 아니라면..)


	// 객체지향이 어렵다면, Actor만 만들고
	// 추후 확장시켜주고자 할 때 Controller를 만들면 된다.
}

void Comment4()
{
	// Creature는 현재 방향에 따라서,
	//	- Flipbook이 변경되어야 한다.

	// 방향이 바뀌면 >> SetFlipbook을 새롭게 해줘야겠다.
	// 가 떠올라야 한다.

	// 그걸 위해 ChangeDirection을 만들자
	// ChangeDirection
	//  --> SetFlipbook를 해준다.

	// 원래라면, 기능을 실행하기 위해서
	// Controller를 만들어야하지만,
	
	// Too much 같은데?
	//  아니면, 기능부터 빨리좀 확인해보고 싶은데

	// Actor에 땜빵코드를 작성한다.

	// 땜빵코드 => 일단 구현을 위해서 빠르게만들고
	//    나중에 수정할 코드를 말하는 것

	// 이런 경우엔 다음과 같은걸 적어준다.
	// TODO : Controller로 교체할 것들
	// XXX : 어떤 위험이 있을때 코멘트
}

void Comment5()
{
	// 플레이어 이동구현
	//  - 지금 이동을 구현하게 되면,
	//  - 여태까지 다른게임들 만들 때 이동 구현과 다른점은

	// 그동안은 Sprite를 이동하거나,
	// 단순하게 Rectangle을 이동

	// Flipbook을 변경시켜서 움직여야한다.

	// SetFlipbook()

	// 키입력 받았을때
	//    -> SetFlipbook() (Idle 모션으로)

	// 움직이는 상태도 고려해야함.
	// SetFlipbook을 해줄때
	// 플레이어의 상태에 따라 Idle, Move 상대 구분 필요

	// SetFlipbook은 거의 항상 일어나야함
	// -> 왜?
	// -> 갑자기 맞았을수도 있고
	// -> 속도가 갑자기 0이 됐을수도 있고
	// => state에 따라서, Flipbook이 세팅되어야함.

	// _state라는 변수를 만들어
	// 외부의 기능이 들어오면,
	// 총합적으로 판단하여
	// state를 제어해줄것이다.
}

void Comment6()
{
	//상태패턴

	// 공격을 만든다.

	// 공격을 만들때,
	// 이동중에 공격할수있어요. (다만, 이동중에 공격하면 멈춰야해요.)
	// 이동중에는 공격할수없어요.
	//  기획서에 이 문장이 적히고 (혹은 구두로)
	//  몇달동안 내용이 안바뀌는게아니라
	//  QA한번하고 말바뀝니다.

	// 기획자도 머릿속으로 구상한거지, 실제로하면 다를수있거든요

	// UpdateAttack
	// UpdateMove
	// UpdateIdle 
	// 이렇게 상태에따라 Update함수를 나눠두면

	// 공격하다가 움직이는거
	// 움직이다가 공격하는거
	// Idle상태에서만 공격하는거
	// 모두 유연하게 대처가능함.


	//숙제
	// 몬스터 만들고
	// 내앞에 몬스터가 있으면
	//   - 내앞에 무기충돌체를 잠깐 생성시킨다.
	//   - 무기충돌체랑 몬스터랑 충돌이 되면
	// 몬스터 삭제
}
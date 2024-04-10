#include "pch.h"

void Comment1()
{
	// 코드를 문서화 하는게 md파일 (markdown)
	// md 파일이 회사에서 쓸 일이 있을것, 

	// 회사에서 자주쓰이는
	// 슬랙, 노션 등등 모두 markdown 기반으로 만들어진 프로그램

	// 그리고 회사에서 코드 문서화할때
	// md 파일을 많이 사용한다.

	// visual studio의 유일한 단점이라 생각하는게 
	// md 파일을 공식적으로 지원을 안한다는것 (preview버전에서는 지원한다고 예전에 본 적은 있다만..)
}

void Comment2()
{
	// 오늘 배울거
	// 오늘은 1번과 2번이 세트다

	// 1. Actor, GameObject 개념 배우기
	// 2. Collision Manager 충돌 매니저
	// 3. 벽돌깨기 만들기
}

void Comment3()
{
	// 선생님의 생각으로는 
	
	// 1. Actor, GameObject
	// - 두 엔진의 철학차이 (Unity, Unreal)

	// - Unity에서는 GameObject라고 부른다.
	// - Unreal에서는 Actor라고 부른다.
	// 하는 역할은 비슷하다고 본다.

	// - Unity에서 Gameobject란
	// - Scene에 [존재/등장]하는 최소 단위

	// - Unreal에서 Actor란
	// - Scene에 등장하는 최소 단위
	
	// Unreal : Actor(배우)
	// Unity : Gameobject(프로그래밍 자료형의 가장 기초단위)

	// Unreal : 우리는 영화를 만드는데, 여기에 등장하는 배우를 구현한다. 배우를 위한 자료형.
	//		등장하는 것들을 위주로 많이 작성한다.
	//		(Enemy, Player, Brick, Wall)

	// Unity : 자료형의 가장 기초단위
	//			- Scene에서 동작하려면 GameObject를 무조건 생성해라.
	//			- 그리고 GameObject끼리 상호작용으로 게임을 만들것이다.
	//			- 이 뜻은 게임에 등장하지 않아도 존재하는것만으로도 효과를 낼 존재도 Gameobject이어야 한다.

	// 우리는 우리만의 Framework
	// 유니티나 언리얼이나 만들 때 비슷하다.
	// Player를 만들고 싶다. 
	
	// Unreal : Actor자료형을 상속받아서, Player를 만든다.
	//		Actor가 아니면 불가능한게 너무 많아서 Actor를 상속받아서 만들 수 밖에 없다.
	
	// Unity : GameObject에 Component로 Player라는 Component를 붙인다.
	//		GameObject를 상속받아서 무언가 만들 수 없다.

	// 우리의 경우
	// 이름은 Actor라 지어주고
	// 언리얼 늬앙스로 따라갈거다.
	// 근데 Actor나 GameObject나 다를게 딱히 없다.


	// Unity -> Collider가 Component로 들어간다.
	// Unreal -> Actor안에서 설정하게끔 되어있다. ( 내부적으론 Compont)
}

void Comment4()
{
	// Component (컴포넌트)

	// 컴포넌트가 게임에서 되게 중요한 패턴

	// CBD
	// Component Based Development
	// 컴포넌트 기반의 프로그래밍

	// 패턴 -> 기법 -> 꼼수
	// 디자인패턴
	// 컴포넌트 패턴이라고하는 디자인패턴이 존재한다.
	
	// 객체하나를 만들고
	// 여기에 여러가지 Component를 붙여서
	// 객체 하나를 여러가지 느낌으로 커스터마이징 가능하도록 만드는 기법
	
	// 1초마다 몇미터씩 움직이는 Component
	// 은신상태를 하게하는 Component가 있다.

	// 롤 - 상태이상
	// StunComponent
	// hideComponent은신 컴포넌트
}
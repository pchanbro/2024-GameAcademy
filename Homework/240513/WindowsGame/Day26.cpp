#include "pch.h"

void Comment1()
{
	// 두더지 잡기 완성
	
	// - 애니메이션 (Flipbook) 만들기
}

void Comment2()
{
	// 두더지잡기 남은 부분
	// - 해머로 때렸을 때 점수오르게

	// 해머로 잡는 부분 수도코드
	// 
	// if( 마우스를 눌렀을 때)
	//		for ( 두더지 리스트 ) {
	//			해머랑 두더지(나와있는 상태)랑 겹쳐있으면
	//			두더지가 Die 상태로 변경된다.
	//			점수가 오른다.
	//		}
}

void Comment3()
{
	// 해머도 클래스로 만들 수 있다.

	// 해머를 클래스로 만들기

	// 다음주 월요일까지 숙제 2048 게임 만들기
}

void Comment4()
{
	// 해머엑터
	// - 기능
	// 내려찍는다.
	
	// 선생님이 생각했을때
	// 해머엑터의 기능은
	//  - 마우스를 따라다닌다.
	//  - 두더지를 충돌시키면 점수가 오른다.

	// 플레이어 해머엑터에게만 해당되고
	// 만약에, 멀티 플레이어가 되면
	//  - 마우스를 따라다닌다.
	//  - 두더지를 충돌시키면 점수가 오른다.
	// 라는 기능은 없는것이 맞다고 생각하신다.

	// 근데 사실 멀티게임이 될 수 없기 때문에 이 경우는 배제하는게 맞다. 라고 생각할수도 있다.

	// 근데 선생님이 수업 때 하고싶으신 말은
	// 
	// AI기능인지
	// 컨트롤러에서 해줘야하는 기능인지를 구분해야 한다는 것이다.

	// 엔진부터 배운사람들
	// 혹은 기초를 어설프게 배운사람들
	// => 엑터랑 컨트롤러를 구분을 쉽게 못함(중요)
	// 신입들이 배울게 많아지면서 요즘 대부분의 신입이 그렇듯 하다
	

	// 선생님은 해머를 만들기 위해
	// 해머엑터, 컨트롤러(플레이어해머컨트롤러) 두 가지를 만든다.

	// 플레이어해머컨트롤러
	//  - 플레이어 해머를 마우스 위치로 변경시킨다.
	//  - 마우스를 클릭하면, 플레이어 해머와 두더지가 충돌되어 있으면 점수가 오른다.
	//		두더지는 죽는다.
}

void Comment5()
{
	// Flipbook

	// 애니메이션

	// Flipbook 구상
	//  이미지 하나에 여러장 박혀있도록 구한다.

	// Flipbook => 여러개의 sprite를 이어주는 동작
	// sprite[] 형식으로 들고있을수 있긴하다.
	// sprite[] 형식(배열 형식)으로 들고있으면 엔진이 아니기 때문에 많이 불편해짐.

	// 그래서 사진의 격자를 나눠서 할거다
	/*Texture는 한 장.
		몇 번째 line의
		Start지점 몇부터 end지점 몇까지가
		점프 애니메이션이다.*/

		//Texture* texture;
		//Vector2Int size;
		//Int start = 0;
		//Int end = 0;
		//Int line = 0;


		//숙제 FlipbookActor 완성하기.
		// -  duration이랑, loop 기능.
}
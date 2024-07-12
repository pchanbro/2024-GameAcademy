#include  "pch.h"


void Comment1()
{
	// 오늘 수업은
	// 두더지 잡기 만들거에요.

	// 3시간동안 쭉 만들거에요


	// 목적 : 이 프레임워크 
	//		사용할수있도록 익히기!
}

void Comment2()
{
	// 두더지 잡기
	// 1. 어떤 클래스를 만들것인지 미리 구조짜기
	//  - 미리 해둬야 나중에 코드짜다가 크게 안엇나가요.
	//		-> 코드를 말로 바꾸는 힘

	// 클래스 목록
	//  1. 씬 클래스 (MoleGameScene) 
	//		- 실제 두더지 잡기에서 일어나는 게임 룰에 관한 내용들

	//  2. 두더지 클래스
	//		- 두더지 (나오기, 들어가기, 죽기)

	// 클래스를 나눌수록
	// 협업하기에 좋아요.
	// 협업하기에 좋다 ==> 유지보수에 좋다. 
	// 근데 혼자 작업하기에는 빡셉니다.
	// -> 코드양이 늘어나기 때문..

	// 클래스를 안나눌수록
	// 혼자 작업하기 편하다
	// 혼자 작업하기 편하다 ==> 생산성이 좋다. 

	// 결코 오해하면 되는 내용 : 
	// 생산성이 좋을수록 유지보수가 안좋다 (X)
	// 유지보수가 좋을수록 생산성이 안좋다 (X)
}

void Comment3()
{
	//이미지가 있는게임을 만들때는 
	// 저같은 경우에는 이미지 작업을 먼저합니다.


	//Texture, Sprite
	// 왠만하면
	// 텍스처에 다담아두는게 좋습니다.


	// 최적화는 
	// 리소스에서 줄이는게 항상 더 효율적이다.
	
	// 메모리 개념
	// 이미지를 로딩할때,
	// 컴퓨터는 2의 승수배로 로딩하게 된다.
	// (texture크기가 50 x 50) 이거면
	// 이거대로 못읽어요 
	// 2 4 8 16 32 64
	// ==> 64 x 64 로 읽게됩니다.
	// 260 x 260 (512 x 512)
	// => 2 4 8 16 32 64 128 256 512

	// 가로길이 2049 이미지
	// 2 4 8 16 32 64 128 256 512 1024 2048
	// 4096 x 4096
	// 으로 읽게됨

	// Atlas


	// 아니 선생님
	// 저희 이미지 하나로 쓰는게 메모리 절약할떄 좋다고하시지 않았나요?
	// 왜 해머따로, 두더지따로 하나요??

	// 사실 합치는게 좋긴합니다. ( 편의 )
	// 한장면에 로딩될때, 같은 텍스처에 있으면 절약
	// 만약에 같이 없는데 같은 텍스처에 있으면 낭비
}
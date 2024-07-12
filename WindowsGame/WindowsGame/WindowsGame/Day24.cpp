#include "pch.h"

void Comment1()
{
	// 리소스매니저
	// 만드는 중

	// 리소스 매니저란
	// 게임할 때 외부파일, (어떤 애플이든 외부파일은 필요하다) (오디오, 3D모델링, 텍스처, 애니메이션 파일)
	// 매니저(관리하는 객체)

	// 주요 기능 : [리소스 로드Load] [리소스 가져오기 Get] 

	// 프레임워크에서 매니저
	// => 기본적으로 보통 엔진에서 지원을 해줌

	// 우리는 Windows API를 활용해 게임을 만들고 있으므로
	// Windows에서 밖에 안돌아감
	
	// Mac, IOS, Android 등
	// OS마다 리소스를 로딩하는 방식이 다 다름
	
	// Windows API에서 제공해주는 이미지 로딩

	// Android(무조건 JAVA)
	// Android API에서 제공해주는 이미지로딩.

	// IOS (Swift, Object-C)
	// Swift, Object-C 에서 제공해주는 이미지로딩 API를 활용해서

	// Load함수에서 
	// 처음보는 함수들 되게 많이 나올거다
	// 근데 외울 필요 1도 없다.
	// 선생님도 모름(면접관도 인터넷 없으면 모른다)

	// 근데 면접관도 모르는걸 왜배우냐? => 이 생각으로 공부하는건 좋지 않다
	// 지금은 프레임워크에서 제공하는걸 직접 만들어보면서 사용하고 있는것이기 때문이다
	// 지금은 엔진의 기능을 직접 구현해본다. 라는 취지로 접근해라

	// 이 리소스매니저의 코드는 100% 이해할 필요가 없다.
	// 내부적으로 어떻게 관리하는지 / 어떻게 사용하는지 정도만 이해해라.


	// 디버깅할때는 상대경로 기준을
	//		.vcxproj 파일 기준으로 하고
	// 배포할떄는
	//		.exe 파일 기준으로 상대경로를 정한다.
	// ../ => 폴더를 하나 밖으로 나간다.
	// ../Resources/Mole/bg_mole.bmp 이 파일을 찾으려 하는데 파일이 없다더라.

}

void Comment2()
{
	//Sprite를 그리는 방법
	
	// Sprite란 Texture에서 어디부터 어디까지 (Texture의 일부)
	// Texture란 이미지 파일 로드한 것
	// 어떻게 가지고 있었는지... 
	// 해당 Texture의 HDC, HBITMAP 따로 존재했다.

	// 그럼 이제 Render 할 때
	// 게임 화면에 대한 BackBuffer에 내가 원하는 Texture의 x, y, cx, cy 영역을 가져온다.
}

void Comment3()
{
	//주말숙제

	// 두더지게임
	// 이미지붙일건데

	// 1. 마우스 우클릭하면
	// 해머가 내려치는 모션이 되어야함.

	// 2. 두더지를 잡았을때
	// 두더지 우는모습 1초나와야함.
}
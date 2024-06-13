#include "pch.h"

void Comment1()
{
	// 1. 타일맵액터에 카메라 적용.
	// 2. (culling) - 안보이는 부분은 굳이 그럴필요가 없음
	// 3. 젤다 캐릭터 등장
	// 4. 캐릭터 움직임
}

void Comment2()
{
	// 1. 타일맵액터에 카메라 적용.
}

void Comment3()
{
	// DirectX를 배우는 이유 
	//	- 렌더링 과정을 배움
	//	- 가장 무거운 작업이 렌더링
	//		-> 어떻게 해야 최적화 할 수 있을지를 고민하게 한다.
	//		-> 대부분의 최적화와 연결된 내용

	//	- 선생님은 렌더링, 파이프라인만 제대로 배우면 DirectX를 굳이 배울 필요가 없다고 생각하심
	//	- 자체엔진 만들거 아니면 진짜 쓸모없음  <- MS MVP가 인터뷰터 실제로 한 말

}

void Comment4()
{
	// 2. Culling
	// 굳이 사용자가 보지도 못할 공간을 Render할 필요가 없음

	// Culling이라고 카메라가 비추지 않는 영역은
	// Render를 안하도록 하는 기법
}

void Commetn5()
{
	// 캐릭터
	// TileActor

	// 일반캐릭터

	// Actor, Controller 분리작업
	// Actor -> 배우 (기능만 들고 있음0

	// Controller -> 게임 로직을 담당
	//  - 키보드를 누르면 왼쪽으로 가라
	//  - 마우스를 누르면 어디로 가라.

	// 나는 일단 게임은 어떻게든 만들순있겠다.
	// 하지만, [Actor, Controller] 개념은 잘 모르겠다.
	// 머릿속으로 생각만해두고 쓰지마세요.

	// 맵툴 지금 잘 동작하는것 같은데
	// 왜 바꾸는가?

	// 사실 지금 상태는 매우 잘못됐다

	// 액터 -> 배우(등장 객체)(기능만 있어야 한다)
	// 액터가 스스로 키보드 인풋을 받아서 게임 로직을 형성하려하면 안된다.
}

void Comment6()
{
	// - assert
	// assert : 개발중에만 오류표시해주는 기능 그래서 아무리 많이 심어도 부하가 없다.
	// assert( 조건 )
	// 조건이 참일때만 코드를 통과하고,
	// 조건이 거짓이면, 에러를 내보낸다. (프로그램이 뻑난다)

	// 언제쓰냐?
	// 유효성체크

	// 
}

void Comment7()
{
	// 실습
	// 캐릭터 움직이는걸 타일맵 움직이는거랑 동일하게 맞추기
	// 왼쪽키를 누르면, 왼쪽타일로 한칸
	// 오른쪽키를 누르면 오른쪽타일로 한칸
	// ...
	// 4방향 모두 완료하기 

	// 못하면 숙제로
}

void Comment8()
{
	// 렌더링 파이프라인

	// DirectX 수업을 3개월과정
	// 아주 길게함

	// 보통 수업들으면 남는게 없다.

	// DirectX는 코드가 중요한게 아니다.

	// 렌더링 파이프라인 이 한가지가 중요한 것

	// 렌더링 파이프라인
	// ->

	// 현재 Winodws API 그림은 어떻게 그리나?
	// - 비트맵 그림그리는 함수를 사용해서 그림을 그린다.
	// - TransparentBlt, BitBlt 등.
	// -> CPU를 사용해서 그림을 그림


	// CPU를 사용해서 그림을 그리다보니,
	// 게임 최적화 => 그림 그리는거.
	// CPU가 GPU보다 못해도 50배는 느리다.
	// -> 매우 비효율적이고 느려진다.

	// GPU => 그래픽카드를 사용해서 빠르게 그림을 그리는 방법
	// [하드웨어 가속] 이거를 이제 코드로 컨트롤할 수 있게 해주겠다.
	// DirectX 개념
	// (GPU를 내맘대로 컨트롤하겠다.)

	// Game Engine, DirectX로 만든게임들 보면,
	// 뭔가 많이 그림을 그리는데, 크게 느리지 않다.

	// 그러면
	// 어떻게해야 GPU를 쓸 수 있을까?

	// GPU는 하드웨어영역.
	// 그렇게 많이는 안열어줬다.

	// 렌더링 파이프라인을 구축해서 
	// 이 순서대로 렌더링해라(그림을 그려라)

	// 1. Vertex Shader
	// 2. Tessellation
	// 3. Geometry Shader
	// 4. Rasterization
	// 5. Pixel Shader (fragment Shader)
	// 6. Frame Buffer

	// CPU를 쓰기위해서는 
	// CPU에서 정리된 데이터를 GPU에 넘겨줘야 일을 할 수 있다.
	// 크게 2가지
	// [Shader라는 코드] (HLSL 문법), Vertex Data

	// Shader - C++, C# 같은 GPU를 위한 고급 문법
	// 테크니컬아티스트 << Shader 코드를 짜는사람이 존재했으나
	// 요즘은 AI를 짜거나, Visual Shader (아티스트가 딸깍딸깍 만들 수 있게 됨)

	// Direct X => 3D 게임

	// Vertex Data (정점 위치)
	// 3D 모델

	// Game 세상은 (World 와 Camera 로 이루어져 있다.)

	// ★★★ 1. Vertex Shader (★CPU가 한다★) ★★★
	//  - Vertex Data를 넘겨줍니다.
	//  - World, View, Projection 이라는 과정을 거친다.
	// World - (게임세상에 존재하는 모든 모델들의 정점 데이터를 List로 만든다)
	// View - (World에 있는 모든 정점데이터들을 내 현재 카메라 맞게 수정해준다.)
	// Projection - (View 까지 끝난 데이터를 실제로 스크린화면에 맞춰서 재조정)
	//			   - 최적화 (안그려도 되는 모델같은 경우 여기서 컷 해준다.) (frustom culling)

	// 2. Tessellation (최적화 작업) (CPU가 한다)
	//  - (화면전체크기 보편적으로 1920 * 1080 => 이거에 비해 너무 정점수가 많음)
	//  - Level Of Detail (LOD)
	//  - 멀리서 찍을수록, 로우 폴리곤 모델을 사용하도록 변경 (모델러가 작업필요)

	// 3. Geometry Shader (퀄리티 작업) (최적화 반대) (CPU가 한다)
	//  - 그림자를 만드는 작업
	//  - 먼저 그림을 그린다.
	//  - 한번 더 그리는 작업
	//  - 2번 그림을 그리는 것이기 때문에 (그림자 On 하면, 부하가 2배)
	//  - 게임하다가 렉걸려서, 가장 최적화모드로 바꾸면 보통 그림자가 먼저 없어진다.

	// ★4. Rasterization (픽셀 대입) (GPU가 한다)
	//   - 각 pixel당 어떤 색으로 칠하면될지, 색 보간작업 진행.
	//   - Texture 입히기
	//   - 중요한건 이 과정부터 GPU가 한다는게 중요하다.

	// ★5. Pixel Shader (Fragment Shader)
	//  - 1920 * 1080 => 이 숫자만큼
	//  - 매 프레임 2,073,600 만큼 계산
	//  - (4K) 매 프레임  8,294,400 만큼 계산 
	//  - 조명 효과, 오브젝트끼리 조명을 방해하는 것 등 계산

	// 6. Frame Buffer (엔진에서도 직접 다뤄야함) (엔진 작업중에서도 가장 최상급으로 분류됨)
	// - Alpha Blending (요정도는 Windows API에서도 가능)
	//   - Alpha끼리 만났을 때 다른색으로 나와야겠지
	// - Stencil Buffer (이게 좀 어려움(
	//   - 방탈출 게임같은거에서 [책상안쪽 확인하기] 돋보기로 가져다대면 (책상모델은 그대론데 책상 안쪽을 보여주는것)
	//  - Z-Test
	//  (그래서 누가 앞에있는 모델인지)
	// Windows API에서도 Layer에 따라서 먼저 그려주는 순서가 달라짐.
	//   카메라중에 앞에있으면 나중에 그려줌. (먼거부터 그림그리기)
}
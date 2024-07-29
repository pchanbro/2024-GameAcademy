#include "pch.h"

void Comment1()
{
	//기능
	//	- Map 구현 [V]
	//	- 타워 건설 기능 [V]
	//	- WAVE 시스템 기능 [V]
	//		- 몬스터가 생성되는거까지 해야하는거 아닌가요?
	//	- 몬스터 AI
	//		- 몬스터를 D키눌렀을때 1번몬스터 생성
	//		- 몬스터를 F키눌렀을때 2번몬스터 생성
	//	
	//		- 몬스터가 생성되는 위치는 항상 Wave 시작포인트 
	//		- 몬스터가 Wave EndPoint로 이동하게 Astar 작업
	// 
	//	- 타워 공격 기능
	//		- 몬스터가 타워사거리 안에 있으면 타워가 공격하도록 
	// 
	//	- Life 기능

	//r

	// [타워 건설 기능]
	//		A를 누르면 FB_DrillTank1
	//		S를 누르면 FB_DrillTank2


	// [WAVE 시스템 기능]
	//  - 실제 개발에 들어갈때, 
	//   - 당장코드치기 시작해야할때.
	//   - 당장할수있는거부터 가장 최소화
	//   - 자기가 한번도 안해본 코드 
	//		- 구현해야하는내용이 한두개가 
	//		- 뭐부터해야할지
	//		- 이렇게하면 저거나중에 꼬일거같고
	//		- 이렇게하면 나중에 저객체가 문제가 생길거같고
	//		- 생각이 진짜 많아집니다. 
	
	// 당장 할수있는 가장 간단한기능
	//   1. 라운드 시작했다고 글자 (스프라이트) 띄우기
	//   2. 얘 곧 없어져야하잖아요. 그것도 생각해야하는거 아닌가요.

	// [3. BuildTime에는 DrillTank1, Tank1 이미지로 보여주고, WaveTime에는 DrillTank2, Tank2 이미지로 보여주는 기능]
	//  - TowerState로 관리해서 SetFlipbook을 해주면 되겠다.
	//  - TowerState를 대체 어떻게 변경할건데?

	// 액터를 어딘가에 저장해두고,
	// WaveController에서 변경이 일어나면
	// WaveController -> TowerBuildController를 호출해서 TowerActor의 State를 변경하도록 해주면되겠다.
	// WaveController -> TowerGameScene을 가져와야합니다.
	// WaveController는 항상 TowerGameScene이 있어야만 동작할수있어요.

	// WaveController 는 TowerGameScene 요게존재해야하고
	// WaveController 는 TowerBuildController 가 항상 있어야한다.
	// 결합이 되게 강하게되었는 형태

	// 이벤트호출로 풀어나가는 방식 < 약한결합.

	// △ 방법으로 어쩔수없이 저런 방식으로 구현해야할떄가 있습니다.


	// 글자 구현 [Label]
	// 

}
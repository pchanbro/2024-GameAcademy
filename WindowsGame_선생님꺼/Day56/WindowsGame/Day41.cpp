#include "pch.h"

void Comment1()
{
	// 1. Console에서 Astar 적용
	// 2. Windows API 에서 Astar 적용
	//		Controller에서 우클릭을 누르면 
	//		플레이어가 해당 타일로 이동.
	
	
	// 3. DataManager

}


void Comment2()
{
	// Windows API 에서 Astar 적용


	// Controller
	// 
	// if(마우스 우클릭을 누르면)
	//		Vector2Int startTilePos = 내가 현재 서있는 타일
	//		Vector2Int endTilePos = 누른지점의 타일을 구함.
	//		Calulator_Astar(startTilePos, endTilePos) 
	//       => return : vector<Vector2Int> _path (가야하는 내용 담도록 설정)

	// Actor 
	// 
	// if( _pathIndex != _path.size() )
	//		플레이어 Move 변경
	//		플레이어 EndPos = _path[_pathIndex++];

	// Console 적용한 로직 => Game Engine, 지금만들고있는 프로젝트에 적용하는 능력
	//		프로그래머들끼리 평가하는 실력


	// 2가지로 기능 분류
	//  1. 캐릭터가 vector<Vector2Int> _path가 있을때, 자동이동하는 기능 (A작업자)
	//  2. Astar 기능 (B작업자)


}


void Comment3()
{
	// 캐릭터의 데미지
	// 이동속도

	// 몬스터의 이동속도 데미지
	// 어떤스킬을 가지고있는지?

	// 코드에서 조절하는것이 아닙니다.

	// 따로 데이터를 빼놔서, 기획자가 직접 수정할수있게끔..


	// 모든 프로그램은
	// [로직 + 데이터]

	// 데이터 매니저

	// 데이터
	//  - 여러가지 형태로 게임의 데이터를 저장합니다.

	//  1. text or binary
	//  2. excel
	//  3. json (구조체를 text로 변환하는 방법중에 하나)


	// 이동속도, 데미지 , 이름
	//  - 데이터 매니저 
	// (플레이어)
	// (몬스터)


	// 타워 디펜스 (뼈대)
	//  => 서버

}
#include "pch.h"

void Comment1()
{
	// 1. Console에서 Astar 적용
	// 2. WindowsAPI 에서 Astar 적용
	//		Controller에서 우클릭을 누르면
	//		플레이어가 해당 타일로 이동.

	
	// 3. DataManager
}

void Comment2()
{
	// Windows API에서 Astar 적용

	
	// Controller
	//
	// if(마우스 우클릭을 누르면)
	//		Vector2Int* startTile = 내가 현재 서있는 타일
	//		Vector2Int* endTile = 누른 지점의 타일을 구함.
	//		Calculator_Astar(startTilePos, endTilePos)
	//      => return : vector<Vector2Int> _path 변수에 가야하는 내용 담도록 설정

	// Actor
	// 
	// if( _pathIndex != _path.size() )
	//		플레이어 Move 변경
	//		플레이어 EndPos = _path[_pathIndex++];

	// Console 적용한 로직 => Game Engine, 지금 만들고있는 프로젝트에 적용하는 능력
	//		프로그래머들끼리 평가하는 실력 -> 로직을 프로젝트에 적용하는 능력


	// 2가지로 기능 분류(현업에서는 이걸 2명이서 따로 만드는 경우도 있다)
	// 1. 캐릭터가 vector<Vector2Int> _path가 있을 때, 자동이동하는 기능 (A작업자)
	// 2. Astar 기능 (B작업자) (이 경우 A작업자의 완성을 기다리다간 야근하니까 미리 기능을 만들어두기도 한다)
}

void Comment3()
{
	// 캐릭터의 데미지
	// 이동속도

	// 몬스터의 이동속도 데미지
	// 어떤스킬을 가지고 있는지?

	// 코드에서 조절하는것이 아니다.

	// 따로 데이터를 빼놔서, 기획자가 직접 수정할 수 있게끔


	// 모든 프로그램은
	// 코드(로직)(프로그래머) + 데이터(기획자)

	// 데이터 매니저

	// 데이터
	//  - 여러가지 형태로 게임의 데이터를 저장한다.

	// 1. text or binary
	// 2. xml
	// 3. excel
	// 4. json(구조체를 텍스트로 변환하는 방법 중 하나)

	// 다음에 다음 내용을 담은걸 만들어보자
	// 이동속도, 데미지, 이름
	// - 데이터 매니저
	// (플레이어)
	// (몬스터)
}
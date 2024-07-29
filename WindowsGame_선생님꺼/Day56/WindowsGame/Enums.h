#pragma once

enum class SceneType
{
	None,
	Dev1Scene,
	Dev2Scene,

	InGameScene,
	MoleGameScene,
	TowerGameScene
};

enum class ColliderType
{
	None,
	Box,
	Circle
};

//뒤에 둘수록 마지막에 그린다.
enum class LayerType
{
	BackGround,
	Object,

	Character,

	Indicator,

	End
};

enum CollisionLayerType : uint8
{
	CLT_DEFAULT,
	CLT_CREATURE,
	CLT_ITEM
};


enum class GameState
{
	None,
	Wait,
	Play
};
enum class MoleGameState
{
	None,
};

enum class EBuildState
{
	Valid,		//설치버튼은 눌렀는데, 설치가 가능한 위치일때,
	Invalid,	//설치버튼은 눌렀는데, 설치가 불가능한 위치일떄,
	None		//설치버튼을 안누른상태
};

//웨이브 상태
enum class EWaveState
{
	None,
	BuildTime,	//타워 건설하는 시간
	WaveTime,	//웨이브 등장하는 시간
};

enum class ETowerState
{
	Rest,
	Idle,
	Attack
};

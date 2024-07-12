#pragma once

// Scene Type
enum class SceneType
{
	// 예를들어 로딩창
	// 타이틀씬
	// 인게이씬 등등

	None,
	Dev1Scene,
	Dev2Scene,

	InGameScene,
	MoleGameScene,
	Game2048Scene,
	TowerDefenseScene,
};

enum class ColliderType
{
	None,
	Box,
	Circle
};

// 뒤에 둘수록 마지막에 그린다.
enum class LayerType
{
	BackGround,
	Object,

	Character,

	End
};

enum CollisionLayerType : uint8   // 뒤의 : uint8은 uint8의 범위까지만 하겠다는거, 여기에 int가 들어가면 int의 범위까지만 하겠다는거
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
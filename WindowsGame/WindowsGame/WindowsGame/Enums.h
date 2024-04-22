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
};

enum class ColliderType
{
	None,
	Box,
	Circle
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
#pragma once

// Scene Type
enum class SceneType
{
	// ������� �ε�â
	// Ÿ��Ʋ��
	// �ΰ��̾� ���

	None,
	Dev1Scene,
	Dev2Scene,

	InGameScene,
	MoleGameScene,
	Game2048Scene,
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
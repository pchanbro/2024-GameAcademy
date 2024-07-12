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
	TowerDefenseScene,
};

enum class ColliderType
{
	None,
	Box,
	Circle
};

// �ڿ� �Ѽ��� �������� �׸���.
enum class LayerType
{
	BackGround,
	Object,

	Character,

	End
};

enum CollisionLayerType : uint8   // ���� : uint8�� uint8�� ���������� �ϰڴٴ°�, ���⿡ int�� ���� int�� ���������� �ϰڴٴ°�
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
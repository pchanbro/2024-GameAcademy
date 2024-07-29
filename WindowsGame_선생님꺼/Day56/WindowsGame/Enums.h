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

//�ڿ� �Ѽ��� �������� �׸���.
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
	Valid,		//��ġ��ư�� �����µ�, ��ġ�� ������ ��ġ�϶�,
	Invalid,	//��ġ��ư�� �����µ�, ��ġ�� �Ұ����� ��ġ�ϋ�,
	None		//��ġ��ư�� �ȴ�������
};

//���̺� ����
enum class EWaveState
{
	None,
	BuildTime,	//Ÿ�� �Ǽ��ϴ� �ð�
	WaveTime,	//���̺� �����ϴ� �ð�
};

enum class ETowerState
{
	Rest,
	Idle,
	Attack
};

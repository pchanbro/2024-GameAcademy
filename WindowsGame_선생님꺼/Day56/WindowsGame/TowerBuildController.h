#pragma once
class FlipbookActor;
class TowerBuildController
{
public:
	void Init();
	void Update();

public:
	void BuildTower(Vector2Int cellPos, int64 towerId);

	void HideTargetCursor();

private:
	FlipbookActor* _targetCursor = nullptr;
	EBuildState _buildState = EBuildState::None;
	Vector2Int _buildCellPos = {};
	int64 _buildTowerId = 0;
};


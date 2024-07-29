#include "pch.h"
#include "TowerBuildController.h"
#include "TowerActor.h"
#include "Scene.h"
#include "TowerGameScene.h"
#include "Tilemap.h"
#include "FlipbookActor.h"
void TowerBuildController::Init()
{
	{
		_targetCursor = new FlipbookActor();
		_targetCursor->Init();
		_targetCursor->SetFlipbook(Resource->GetFlipbook(L"FB_Target"));
		_targetCursor->SetPos(Vector2(WIN_SIZE_X / 2, WIN_SIZE_Y / 2));
		_targetCursor->SetLayer(LayerType::Indicator);

		CurrentScene->SpawnActor(_targetCursor);

		HideTargetCursor();
	}
}
void TowerBuildController::Update()
{
	// TODO : 치트키 부분 삭제예정
	if (Input->GetKeyDown(KeyCode::A))
	{
		_buildState = EBuildState::Invalid;
		_buildTowerId = 100001;
	}

	// TODO : 치트키 부분 삭제예정
	if (Input->GetKeyDown(KeyCode::S))
	{
		_buildState = EBuildState::Invalid;
		_buildTowerId = 100002;
	}


	if (_buildState == EBuildState::Valid || _buildState == EBuildState::Invalid)
	{
		Vector2 pos = Input->GetMousePos();

		// 현재 마우스 좌표 => CellPos 변경
		TowerGameScene* towerGameScene = dynamic_cast<TowerGameScene*>(CurrentScene);
		if (towerGameScene == nullptr)
		{
			return;
		}
		_buildCellPos = towerGameScene->GetCellPos(pos);
		Tile* tile = towerGameScene->GetTile(_buildCellPos);
		Vector2 worldPos = towerGameScene->GetTilemapPos(_buildCellPos);

		// Valid 상태로 바꿔주는 조건
		if (tile != nullptr && tile->IsBuildableTile() && towerGameScene->GetCellPos(_buildCellPos) == 0)
		{
			_buildState = EBuildState::Valid;
			_targetCursor->SetPos(worldPos);
		}
		else
		{
			_buildState = EBuildState::Invalid;
			this->HideTargetCursor();
		}
	}


	if (Input->GetKeyDown(KeyCode::LeftMouse))
	{
		if (_buildState == EBuildState::Valid)
		{
			this->BuildTower(_buildCellPos, _buildTowerId);
			_buildState = EBuildState::None;
			this->HideTargetCursor();
		}
	}
}

void TowerBuildController::BuildTower(Vector2Int cellPos, int64 towerId)
{
	TowerGameScene* towerGameScene = dynamic_cast<TowerGameScene*>(CurrentScene);
	if (towerGameScene == nullptr)
	{
		return;
	}

	GET_SINGLE(GameEventManager)->GetEvent<Vector2Int, int64>("TowerBuild")->Invoke(cellPos, towerId);
	Vector2 worldPos = towerGameScene->GetTilemapPos(cellPos);
	TowerActor* actor = new TowerActor();
	actor->Init();
	actor->SetData(towerId);
	actor->SetPos(worldPos);
	CurrentScene->SpawnActor(actor);
}

void TowerBuildController::HideTargetCursor()
{
	_targetCursor->SetPos(Vector2(-99999, -99999));
}
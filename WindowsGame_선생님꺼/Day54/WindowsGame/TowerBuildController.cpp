#include "pch.h"
#include "TowerBuildController.h"
#include "TowerActor.h"
#include "Scene.h"
void TowerBuildController::Init()
{

}
void TowerBuildController::Update()
{
	if (Input->GetKeyDown(KeyCode::A))
	{
		Vector2 pos = Input->GetMousePos();

		printf("타워를 설치한다.[%f, %f]\n", pos.x, pos.y);

		TowerActor* actor = new TowerActor();
		actor->Init();
		actor->SetPos(pos);
		CurrentScene->SpawnActor(actor);
	}
}
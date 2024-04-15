#include "pch.h"
#include "InGameScene.h"
#include "BrickActor.h"
#include "BallActor.h"
#include "PaddleActor.h"
#include "PlayerController.h"
#include "BoxCollider.h"

void InGameScene::Init()
{
	Super::Init();

	{
		_paddle = new PaddleActor();
		_paddle->Init();
		this->SpawnActor(_paddle);
	}


}
void InGameScene::Render(HDC hdc)
{
	Super::Render(hdc);

	wstring str = L"InGameScene";
	::TextOut(hdc, 0, 45, str.c_str(), str.length());
}
void InGameScene::Update()
{
	Super::Update();
}
void InGameScene::Release()
{
	Super::Release();
}
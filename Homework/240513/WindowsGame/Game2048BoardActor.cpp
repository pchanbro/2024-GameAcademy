#include "pch.h"
#include "Game2048BoardActor.h"
#include "BoxCollider.h"

void Game2048BoardActor::Init()
{
	Super::Init();

	this->SetName("Board");

}
void Game2048BoardActor::Render(HDC hdc)
{
	Super::Render(hdc);
}
void Game2048BoardActor::Update()
{
	Super::Update();
}
void Game2048BoardActor::Release()
{
	Super::Release();
}

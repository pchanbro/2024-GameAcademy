#include "pch.h"
#include "Dev2Scene.h"
#include "OmokStoneActor.h"
#include "BoxCollider.h"

void Dev2Scene::Init()
{
	Super::Init();
	/* 바둑판 소환.. 오래걸림
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			OmokBoard* board = new OmokBoard();
			board->SetBody(Shape::MakeCenterRect(i * 30 + 200, j * 30 + 30, 30, 30));

			BoxCollider* collider = new BoxCollider();
			collider->SetCollision(Shape::MakeCenterRect(0, 0, 30, 30));
			board->AddComponent(collider);

			board->Init();
			_omokBoard.push_back(board);
			this->SpawnActor(board);
		}
	}*/

	{
		Resource->LoadTexture(L"T_BlackStone", L"Omok/BlackStone.bmp");
		Resource->CreateSprite(L"S_BlackStone", Resource->GetTexture(L"T_BlackStone"));
		Resource->LoadTexture(L"T_WhiteStone", L"Omok/WhiteStone.bmp");
		Resource->CreateSprite(L"S_BlackStone", Resource->GetTexture(L"T_WhiteStone"));
	}

	ChangeTurnState(TurnState::BlackTurn);
}

void Dev2Scene::Render(HDC hdc)
{
	Super::Render(hdc);

	wstring str = L"Dev2Scene";
	::TextOut(hdc, 0, 45, str.c_str(), str.length());
}

void Dev2Scene::Update()
{
	Super::Update();
	
	if (Input->GetKeyDown(KeyCode::LeftMouse))
	{
		OmokStoneActor* stone= new OmokStoneActor();
		stone->Init();

		POINT mousePos = Input->GetMousePos();
		int posX = mousePos.x - (mousePos.x % 30);
		int posY = mousePos.y - (mousePos.y % 30);
		stone->SetBody(Shape::MakeCenterRect(posX + 15, posY + 15, 30, 30));

		BoxCollider* collider = new BoxCollider();
		collider->SetCollision(Shape::MakeCenterRect(0, 0, 30, 30));
		stone->AddComponent(collider);

		this->SpawnActor(stone);
		cout << "소환" << endl;

		if (GetTurnState() == TurnState::BlackTurn)
		{
			ChangeTurnState(TurnState::WhiteTurn);
		}
		else
		{
			ChangeTurnState(TurnState::BlackTurn);
		}
	}
}

void Dev2Scene::Release()
{
	Super::Release();

}
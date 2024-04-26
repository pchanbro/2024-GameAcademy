#include "pch.h"
#include "Dev1Scene.h"
#include "PlayerActor.h"
#include "BoxCollider.h"
#include "SpriteActor.h"
#include "FlipbookActor.h"
#include "Flipbook.h"

void Dev1Scene::Init()
{
	// �θ� �Լ� ȣ���Ϸ���
	// super.Init(); Ȥ��
	// base.Init();
	// ������ ������Ͽ� Super ���� ����������� �̷��� ����.
	Super::Init();

	// Windows API������ bmp�ۿ� ����� �ȵȴ�.(png���ϰ����� �ε� �Ұ���)
	// ������ ���� ��������
	// png������ �ξ� �� ������ �� �� �ִ�. (�̰� Direct X���� �������ִ� API�� ���� �ε��� ��!)

	// �ؽ�ó Ű, ã�� ����ŷ� ���ؼ� �ܿ��, ��ġ�� �ʰ� �����ϼ�, Texture�� T�� ����, Sprite�� S�� ����
	/*Resource->LoadTexture(L"T_MoleBackground", L"Mole/bg_mole.bmp"); 
	Resource->CreateSprite(L"S_MoleBackground", Resource->GetTexture(L"T_MoleBackground"));

	{
		SpriteActor* spriteActor = new SpriteActor();
		spriteActor->SetSprite(Resource->GetSprite(L"S_MoleBackground"));
		spriteActor->Init();
		spriteActor->SetBody(Shape::MakeCenterRectLTRB(0, 0, 1134, 770));
		SpawnActor(spriteActor);
	}*/

	Resource->LoadTexture(L"T_Character", L"FlipbookTest/character.bmp");
	FlipbookInfo info = {};
	info.start = 0;
	info.end = 12;
	info.size = Vector2Int(32, 32);
	info.texture = Resource->GetTexture(L"T_Character");
	Resource->CreateFlipbook(L"FB_CharacterIdle", info);

	{
		FlipbookActor* flipbookActor = new FlipbookActor();

		flipbookActor->SetFlipbook(Resource->CreateFlipbook(L"FB_CharacterIdle", info));
		flipbookActor->SetPos(Vector2(WIN_SIZE_X / 2, WIN_SIZE_Y / 2));

		SpawnActor(flipbookActor);
	}
}

void Dev1Scene::Render(HDC hdc)
{
	// �θ��Լ� ���� �����ϰ� �ڽ��� �Լ��� �����ϴ°��� �Ϲ����̴�.
	Super::Render(hdc);

	wstring str = L"Dev1Scene";
	::TextOut(hdc, 0, 45, str.c_str(), str.length());

}

void Dev1Scene::Update()
{
	Super::Update();

	
}
void Dev1Scene::Release()
{
	Super::Release();
}
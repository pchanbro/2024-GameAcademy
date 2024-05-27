#pragma once
#include "TilemapActor.h"
class MapToolTilemapActor : public TilemapActor
{
	DECLARE_CHILD(MapToolTilemapActor, TilemapActor);

public:
	// Ÿ���� Ŭ���Ǿ����� ����
	void Update_Picking();
	void Save();
	void Load();

public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
};


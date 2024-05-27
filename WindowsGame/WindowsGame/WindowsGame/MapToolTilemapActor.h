#pragma once
#include "TilemapActor.h"
class MapToolTilemapActor : public TilemapActor
{
	DECLARE_CHILD(MapToolTilemapActor, TilemapActor);

public:
	// 타일이 클릭되었을때 반응
	void Update_Picking();
	void Save();
	void Load();

public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
};


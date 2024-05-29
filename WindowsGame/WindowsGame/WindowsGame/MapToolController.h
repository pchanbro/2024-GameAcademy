#pragma once
class MapToolTilemapActor;
class MapToolController
{
private:
	MapToolTilemapActor* _mapToolActor = nullptr;
public:	
	void SetLink(MapToolTilemapActor* mapToolActor); // Init 대신 SetLink라고 한다
	void Update();
};


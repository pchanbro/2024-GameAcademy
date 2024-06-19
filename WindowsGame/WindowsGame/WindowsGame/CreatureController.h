#pragma once
class CreatureActor;
class CreatureController
{
private:
	CreatureActor* _actor;

public:
	void SetLink(CreatureActor* actor);
	void Update();
	vector<Vector2Int> Calculator_Astar(Vector2Int startPos, Vector2Int endPos);

};

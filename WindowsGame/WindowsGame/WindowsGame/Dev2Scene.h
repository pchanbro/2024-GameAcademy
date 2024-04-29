#pragma once
#include "Scene.h"

enum class TurnState
{
	BlackTurn,
	WhiteTurn,
	None
};

class MoleActor;
class HammerActor;
class OmokBoard;

class Dev2Scene : public Scene
{
	using Super = Scene;
public :
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

	void ChangeTurnState(TurnState playerTurn) { _playerTurn = playerTurn; }
	TurnState GetTurnState() { return _playerTurn; }

private:
	vector<OmokBoard*> _omokBoard;
	TurnState _playerTurn;
};
#pragma once
#include "Scene.h"

class MoleActor;
class HammerActor;

class Dev2Scene : public Scene
{
	using Super = Scene;
public :
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

public:
	//void ChangeGameState(GameState state);
	//GameState GetGameState() { return _gameState; }

private:
	MoleActor* _mole = nullptr;
	HammerActor* _hammer = nullptr;
	GameState _gameState = GameState::None;
};
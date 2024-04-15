#pragma once
#include "Scene.h"

// 헤더에서 웬만하면 include 안하기 때문에 그냥 전방선언만 해준다.
class BrickActor;
class BallActor;
class PaddleActor;
class PlayerController;

class InGameScene : public Scene
{
	using Super = Scene;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

public:
	void ChangeGameState(GameState state);
	GameState GetGameState() { return _gameState; }

private:
	PaddleActor* _paddle = nullptr;
	BallActor* _ball = nullptr;
	PlayerController* _playerController = nullptr;
	GameState _gameState = GameState::None;
	BrickActor* _brick = nullptr;
	vector<BrickActor*> _bricks;
};


#pragma once
#include "Scene.h"
class SpriteActor;
class MoleActor;
class MoleGameScene : public Scene
{
	using Super = Scene;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

public:
	void ChangeGameState(MoleGameState state);
	MoleGameState GetGameState() { return _gameState; }

	MoleGameState _gameState = MoleGameState::None;

	SpriteActor* _hammer = nullptr;

	float _regenTimer = 0.5f;
	vector<MoleActor*> _moles;
};


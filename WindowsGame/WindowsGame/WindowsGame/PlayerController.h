#pragma once
//여기서 조작할 Actor들을 받아준다.
class PaddleActor;
class BallActor;
class PlayerController
{
public:
	void Init(PaddleActor* paddle, BallActor* ball);
	void Update();

	void SetCanBallController(bool canBallControl) { _canBallControl = canBallControl; }

private:
	PaddleActor* _paddle = nullptr;
	BallActor* _ball = nullptr;

	bool _canBallControl = false;
};


#pragma once
#include "SpriteActor.h"

enum class MoleActorState
{
	Out,
	In,
	Die,
	None
};

class MoleActor : public SpriteActor
{
public:
	using Super = SpriteActor;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

public:
	//¶¥±¼¿¡¼­ ³ª¿À´Ù
	void ComeOut();
	//¶¥±¼·Î µé¾î°¡´Ù.
	void ComeIn();
	//Á×¾ú´Ù.
	void Die();

	void ChangeState(MoleActorState state);
	MoleActorState GetState() { return _state; }
private:
	float _comeInTimer = 0.0f;
	MoleActorState _state = MoleActorState::Out;

};


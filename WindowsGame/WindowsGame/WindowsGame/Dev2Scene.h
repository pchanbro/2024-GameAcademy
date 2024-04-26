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
};
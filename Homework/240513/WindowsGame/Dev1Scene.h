#pragma once
#include "Scene.h" // 헤더 파일에는 왜 include 하지 말라했는데 이건 상속하기 위해 include했다.
class BoxCollider;
class FlipbookActor;
class Dev1Scene : public Scene
{
	using Super = Scene;
public:
	virtual void Init() override; // override는 보여주기용, 코멘트용, 딱히 효과는 없다.
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;


private:
	void LoadResource();

protected:
	FlipbookActor* _monster;
	vector<BoxCollider*> _colliders;
};


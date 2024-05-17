#pragma once

// 이름이 너무 길다고 생각된다면
// 웬만하면 줄이지 마라.
// 64자가 넘는지를 일단 생각해라
// 다큐먼트상으로는 128자 까지 쓰인다고 한다
class HammerActor;
class MoleActor;
class PlayerHammerController
{
public:
	void Init(HammerActor* playerHammer, vector<MoleActor*> moles);
	void Update();

	//  - 플레이어 해머를 마우스 위치로 변경시킨다.
	void ChangePlayerHammerPos();

	//  - 마우스를 클릭하면, 플레이어 해머와 두더지가 충돌되어 있으면 점수가 오른다.
	//		두더지는 죽는다.
	void CatchMole();

private:
	HammerActor* _playerHammer;
	vector<MoleActor*> _moles;

};


// 앞으로 만들 씬들은 이 씬 파일을 상속받아서 만들거다.

#pragma once
class Scene
{

//----------------------------
//  ## 기본함수
//----------------------------
public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

};


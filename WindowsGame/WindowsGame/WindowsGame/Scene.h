// ������ ���� ������ �� �� ������ ��ӹ޾Ƽ� ����Ŵ�.

#pragma once
class Scene
{

//----------------------------
//  ## �⺻�Լ�
//----------------------------
public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

};


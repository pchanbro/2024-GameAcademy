#pragma once
class Actor;
class Component
{
protected:
	Actor* _owner = nullptr;

public: // �ظ��� actor�� getter, setter�� ���´�.
	void SetOwner(Actor* owner) { _owner = owner; }
	Actor* GetOwner() { return _owner; }

public:
	// ���ӱ���
	// �⺻������ ���� Init, Render, Update, Release �Ѵ�.
	// �� �ȿ��� Actor���� Init, Render, Update, Release �� ������ ���� �� �ۿ� ����.
	// Actor���� ���� Component���� �ڿ������� Init, Render, Update, Release �Լ����� �����ֱ⸦ ���󰣴�.
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();
};


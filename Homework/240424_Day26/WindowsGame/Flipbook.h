#pragma once
#include "ResourceBase.h"
// �ø����� �̰� ��!
// �̰� Ȱ���ϴ°� ��¥��
struct FlipbookInfo
{
	Texture* texture;
	Vector2Int size;
	int start = 0;
	int end = 0;
	int line = 0;

	float duration = 1.0f;	// �� flipbook�� ��ü �����ϴµ� �ɸ��� �ð�.
	bool loop = true;		// ��� �ִϸ��̼��� �ݺ����� ����
};
class Flipbook : public ResourceBase
{
protected: // ��ӹ޾Ƽ� �� �� �ֵ��� protected�� ���ش�.
	// �����ӿ�ũ���� ����� �������� ��κ� portected�� ���ָ� ����.
	FlipbookInfo _info = {};

public:
	Flipbook();
	virtual ~Flipbook(); // virtual �Ҹ��ڰ� ������ dynamic_cast�� �ȵ�

public:
	void SetInfo(const FlipbookInfo& info) { _info = info; }
	// �׳� FlipbookInfo �� �ϸ� ���簡 �Ͼ �� ������
	// FlipbookInfo&�� �ؼ� ���۷��� ���·� ������ �޸� ���� ���� �� �ִ�.
	// �ٵ� FlipbookInfo&�� �ϸ� ������ �� ������ 
	// const�� �ٿ��ش�.
	// �����ӿ�ũ�ϱ� ������ �ְ�!
	const FlipbookInfo& GetInfo() { return _info; } 
};


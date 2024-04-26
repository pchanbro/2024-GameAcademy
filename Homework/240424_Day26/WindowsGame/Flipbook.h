#pragma once
#include "ResourceBase.h"
// 플립북은 이게 끝!
// 이걸 활용하는게 진짜다
struct FlipbookInfo
{
	Texture* texture;
	Vector2Int size;
	int start = 0;
	int end = 0;
	int line = 0;

	float duration = 1.0f;	// 이 flipbook이 전체 실행하는데 걸리는 시간.
	bool loop = true;		// 계속 애니메이션을 반복할지 여부
};
class Flipbook : public ResourceBase
{
protected: // 상속받아서 쓸 수 있도록 protected로 해준다.
	// 프레임워크에서 만드는 변수들은 대부분 portected로 해주면 좋다.
	FlipbookInfo _info = {};

public:
	Flipbook();
	virtual ~Flipbook(); // virtual 소멸자가 없으면 dynamic_cast가 안됨

public:
	void SetInfo(const FlipbookInfo& info) { _info = info; }
	// 그냥 FlipbookInfo 로 하면 복사가 일어날 수 있으니
	// FlipbookInfo&로 해서 레퍼런스 형태로 보내면 메모리 낭비를 줄일 수 있다.
	// 근데 FlipbookInfo&만 하면 위험할 수 있으니 
	// const를 붙여준다.
	// 프레임워크니까 안전성 있게!
	const FlipbookInfo& GetInfo() { return _info; } 
};


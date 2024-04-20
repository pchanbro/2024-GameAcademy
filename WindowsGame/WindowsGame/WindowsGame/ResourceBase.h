#pragma once
// 다 똑같은 부모클래스를 상속받으면 언젠간 dynamic_cast를 통해 유용하게 쓰일 수 있다.
class ResourceBase
{
public:
	ResourceBase();
	virtual	~ResourceBase();
};


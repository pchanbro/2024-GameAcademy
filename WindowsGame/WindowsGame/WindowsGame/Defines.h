#pragma once
// ��ũ�θ� �߰��ϰڴ�.

#define DECLARE_SINGLE(ClassName)		\
private:								\
	ClassName() {}						\
	~ClassName() {}						\
public:									\
	static ClassName* GetInstance()		\
	{									\
		static ClassName instance;		\
		return &instance;				\
	}									\

#pragma once
// 매크로를 추가하겠다.

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

#define GET_SINGLE(ClassName)	ClassName::GetInstance()

// 이걸 쓰면 앞으로 Input, Time이라는 변수명을 사용할 수 없다.
#define Input GET_SINGLE(InputManager)
#define Time GET_SINGLE(TimeManager)
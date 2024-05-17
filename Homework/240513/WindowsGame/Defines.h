#pragma once
// 매크로를 추가하겠다.

#define SAFE_DELETE(p) { if(p) delete (p); (p) = NULL;}
#define SAFE_DELETE_ARRAY(p) { if(p) delete (p); (p) = NULL;}

#define DECLARE_SINGLE(ClassName)		\
private:								\
	ClassName() {}						\
	~ClassName() {}						\
public:									\
	static ClassName* GetInstance()		\
	{									\
		static ClassName instance;		\
		return &instance;				\
	}									

#define DECLARE_CHILD(ClassName, ParentName)		\
	using Super = ParentName;						\
public:												\
	ClassName() {}									\
	virtual ~ClassName() {}							

#define GET_SINGLE(ClassName)	ClassName::GetInstance()

// 이걸 쓰면 앞으로 Input, Time이라는 변수명을 사용할 수 없다.
#define Input GET_SINGLE(InputManager)
#define Time GET_SINGLE(TimeManager)
#define Resource GET_SINGLE(ResourceManager)
#define Random GET_SINGLE(RandomManager)
#define CurrentScene (GET_SINGLE(SceneManager)->GetCurrentScene())

// (0.000001)
#define EPSILON 1e-6f


// 경고메세지
#define Alert(title, message) MessageBox(_hWnd, title, message, NULL)
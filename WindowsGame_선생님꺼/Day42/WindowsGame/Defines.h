#pragma once
//매크로 추가해줄거에요.

#define SAFE_DELETE(p) {if(p) delete (p); (p) = NULL;}
#define SAFE_DELETE_ARRAY(p) {if(p) delete[] (p); (p) = NULL;}


#define DECLARE_SINGLE(ClassName)			\
private:									\
	ClassName() {}							\
	~ClassName() {}							\
public:										\
	static ClassName* GetInstance()			\
	{										\
		static ClassName instance;			\
		return &instance;					\
	}


#define DECLARE_CHILD(ClassName, ParentName)		\
	using Super = ParentName;						\
public:												\
	ClassName() {}									\
	virtual ~ClassName() {}						

#define GET_SINGLE(ClassName)	ClassName::GetInstance()

#define Input GET_SINGLE(InputManager)
#define Time GET_SINGLE(TimeManager)
#define Resource GET_SINGLE(ResourceManager)
#define Random GET_SINGLE(RandomManager)
#define CurrentScene (GET_SINGLE(SceneManager)->GetCurrentScene())
#define DATA GET_SINGLE(DataManager)

// (0.000001)
#define EPSILON 1e-6f

#define Deg2Rad(x) 0.0174533 * x
#define Rad2Deg(x) 57.2958 * x


//경고메세지
#define Alert(title, message) MessageBox(_hWnd, title, message, NULL)
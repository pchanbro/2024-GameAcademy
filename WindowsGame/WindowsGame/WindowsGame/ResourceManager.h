#pragma once
class ResourceBase;
class ResourceManager
{
	DECLARE_SINGLE(ResourceManager);

	// 이 매니저엔 기본적으로 Init과 Release가 있어야 한다.
public:
	void Init();
	void Release();

private:
	wstring _resourcePath;
	map<string, ResourceBase*> _resources;
};

//map은
// BinaryTree의 데이터를 key로 들어가게 하고 (wstring)
// 그 안에 실제 데이터(ResourceBase*) 가 따로 있다.

// map의 장점 : 검색이 빠르다.
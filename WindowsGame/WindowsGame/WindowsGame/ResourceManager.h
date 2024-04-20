#pragma once
class ResourceBase;
class Texture;
class Sprite;
class ResourceManager
{
	DECLARE_SINGLE(ResourceManager);

	// 이 매니저엔 기본적으로 Init과 Release가 있어야 한다.
public:
	void Init();
	void Release();

	Texture* LoadTexture(const wstring& key, const wstring& path, uint32 transparent = RGB(255, 0, 255));
	Texture* GetTexture(const wstring& key);

	Sprite* CreateSprite(const wstring& key, Texture* texture, int x = 0, int y = 0, int cx = 0, int cy = 0);
	Sprite* GetSprite(const wstring& key);

private:
	wstring _resourcePath;
	map<wstring, ResourceBase*> _resources;
};

// 경로 
// ../Resources/Mole/bg_mole.bmp 이 파일을 찾으려 하는데 파일이 없다더라.
// ../ 이니까 WindowsGame.vcxproj 기준으로 폴더 하나 앞으로 나가야 한다는 것


//map은
// BinaryTree의 데이터를 key(wstring)로 들어가게 하고 
// 그 안에 실제 데이터(ResourceBase*) 가 따로 있다.

// map의 장점 : 검색이 빠르다.
#pragma once
class ResourceBase;
class Texture;
class Sprite;
class Flipbook;
struct FlipbookInfo;
class Sound;

class ResourceManager
{
	DECLARE_SINGLE(ResourceManager);

	// 이 매니저엔 기본적으로 Init과 Release가 있어야 한다.
public:
	void Init();
	void Release();

	// 여기서 값을 미리 넣어준 것을 디폴트 인자라고 한다. 헤더 파일에서는 이렇게 먼저 넣어줘도 되지만 cpp파일에서는 이렇게 미리 넣어주면 오류가 난다.
	Texture* LoadTexture(const wstring& key, const wstring& path, uint32 transparent = RGB(255, 0, 255));
	Texture* GetTexture(const wstring& key);

	Sprite* CreateSprite(const wstring& key, Texture* texture, int x = 0, int y = 0, int cx = 0, int cy = 0);
	Sprite* GetSprite(const wstring& key);

	Flipbook* CreateFlipbook(const wstring& key, FlipbookInfo info);
	Flipbook* GetFlipbook(const wstring& key);

	Sound* GetSound(const wstring& key);
	Sound* LoadSound(const wstring& key, const wstring& path);

private:
	wstring _resourcePath;
	map<wstring, ResourceBase*> _resources;
};

// 경로 
// ../Resources/Mole/bg_mole.bmp 이 파일을 찾으려 하는데 파일이 없다더라.
// ../ 이니까 WindowsGame.vcxproj 기준으로 폴더 하나 앞으로 나가야 한다는 것

// 디버깅할때는 상대경로 기준을
//		.vcxproj 파일 기주으로 하고
// 배포할떄는
//		.exe 파일 기준으로 상대경로를 정한다.
// ../ => 폴더를 하나 밖으로 나간다.
// ../Resources/Mole/bg_mole.bmp 이 파일을 찾으려 하는데 파일이 없다더라.


//map은
// BinaryTree의 데이터를 key(wstring)로 들어가게 하고 
// 그 안에 실제 데이터(ResourceBase*) 가 따로 있다.

// map의 장점 : 검색이 빠르다.
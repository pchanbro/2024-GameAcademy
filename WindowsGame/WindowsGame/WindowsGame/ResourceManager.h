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

	// �� �Ŵ����� �⺻������ Init�� Release�� �־�� �Ѵ�.
public:
	void Init();
	void Release();

	// ���⼭ ���� �̸� �־��� ���� ����Ʈ ���ڶ�� �Ѵ�. ��� ���Ͽ����� �̷��� ���� �־��൵ ������ cpp���Ͽ����� �̷��� �̸� �־��ָ� ������ ����.
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

// ��� 
// ../Resources/Mole/bg_mole.bmp �� ������ ã���� �ϴµ� ������ ���ٴ���.
// ../ �̴ϱ� WindowsGame.vcxproj �������� ���� �ϳ� ������ ������ �Ѵٴ� ��

// ������Ҷ��� ����� ������
//		.vcxproj ���� �������� �ϰ�
// �����ҋ���
//		.exe ���� �������� ����θ� ���Ѵ�.
// ../ => ������ �ϳ� ������ ������.
// ../Resources/Mole/bg_mole.bmp �� ������ ã���� �ϴµ� ������ ���ٴ���.


//map��
// BinaryTree�� �����͸� key(wstring)�� ���� �ϰ� 
// �� �ȿ� ���� ������(ResourceBase*) �� ���� �ִ�.

// map�� ���� : �˻��� ������.
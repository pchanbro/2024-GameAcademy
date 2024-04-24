#pragma once
class ResourceBase;
class Texture;
class Sprite;
class Flipbook;
class FlipbookInfo;
class ResourceManager
{
	DECLARE_SINGLE(ResourceManager);

	// �� �Ŵ����� �⺻������ Init�� Release�� �־�� �Ѵ�.
public:
	void Init();
	void Release();

	Texture* LoadTexture(const wstring& key, const wstring& path, uint32 transparent = RGB(255, 0, 255)); // ���⼭ ���� �̸� �־��� ���� ����Ʈ ���ڶ�� �Ѵ�. ��� ���Ͽ����� �̷��� ���� �־��൵ ������ cpp���Ͽ����� �̷��� �̸� �־��ָ� ������ ����.
	Texture* GetTexture(const wstring& key);

	Sprite* CreateSprite(const wstring& key, Texture* texture, int x = 0, int y = 0, int cx = 0, int cy = 0);
	Sprite* GetSprite(const wstring& key);

	Flipbook* CreateFlipbook(const wstring& key, FlipbookInfo)
	Flipbook* GetFlipbook(const wstring& key);

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
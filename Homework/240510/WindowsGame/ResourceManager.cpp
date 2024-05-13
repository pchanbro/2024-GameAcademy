#include "pch.h"
#include "ResourceManager.h"
#include "ResourceBase.h"
#include "Texture.h"
#include "Sprite.h"
#include "Flipbook.h"
#include "Sound.h"

void ResourceManager::Init()
{
	_resources.clear();
	_resourcePath = L"../Resources/";
}
void ResourceManager::Release()
{
	// resources 다 delete 해줘야함

	// for-ranged 방식
	for (auto& item : _resources) // _resources의 내용들을 다 돈다. key를 받기 위해서 이렇게 쓴다. for문으로는 이게 불가능
	{
		SAFE_DELETE(item.second);
	}
	_resources.clear();
}

Texture* ResourceManager::LoadTexture(const wstring& key, const wstring& path, uint32 transparent)
{
	// 이미 키에 대한 값이 존재하면 그냥 바로 리턴
	if (_resources.contains(key))
	{
		return GetTexture(key);
	}

	wstring fullPath = _resourcePath + path;
	Texture* texture = new Texture();
	texture->LoadBmp(fullPath);
	texture->SetTransparent(transparent);

	_resources[key] = texture;

	return texture;
}

Texture* ResourceManager::GetTexture(const wstring& key) // 1줄짜리
{
	return dynamic_cast<Texture*>(_resources[key]);
}

Sprite* ResourceManager::CreateSprite(const wstring& key, Texture* texture, int x, int y, int cx, int cy)
{
	if (_resources.contains(key))
	{
		return GetSprite(key);
	}

	// cx cy가 0으로 오면 전체크기로 받아줌
	if (cx == 0)
	{
		cx = texture->GetSize().x;
	}

	if (cy == 0)
	{
		cy = texture->GetSize().y;
	}

	Sprite* sprite = new Sprite(texture, x, y, cx, cy);
	_resources[key] = sprite;
	return sprite;
}
Sprite* ResourceManager::GetSprite(const wstring& key)
{
	return dynamic_cast<Sprite*>(_resources[key]);

}

Flipbook* ResourceManager::CreateFlipbook(const wstring& key, FlipbookInfo info)
{
	if (_resources.contains(key))
	{
		return GetFlipbook(key);
	}

	Flipbook* flipbook = new Flipbook();
	flipbook->SetInfo(info);
	_resources[key] = flipbook;
	return flipbook;
}

Flipbook* ResourceManager::GetFlipbook(const wstring& key)
{
	return dynamic_cast<Flipbook*>(_resources[key]);
}

Sound* ResourceManager::LoadSound(const wstring& key, const wstring& path)
{
#ifdef USE_SOUND
	if (_resources.contains(key))
	{
		return GetSound(key);
	}

	Sound* sound = new Sound();
	wstring fullPath = _resourcePath + path;
	sound->LoadWave(fullPath);
	_resources[key] = sound;
	return sound;
#else
	return nullptr;
#endif
}

Sound* ResourceManager::GetSound(const wstring& key)
{
#ifdef USE_SOUND
	return dynamic_cast<Sound*>(_resources[key]);
#else
	return nullptr;
#endif
}
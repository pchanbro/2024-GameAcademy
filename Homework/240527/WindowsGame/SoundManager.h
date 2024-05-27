#pragma once
class SoundManager
{
	DECLARE_SINGLE(SoundManager);

public:
	void Init();
	void Release();
	void Play(const wstring& key, bool loop = false);

	LPDIRECTSOUND GetSoundDevice() {
		return _soundDevice;
	}

private:
	LPDIRECTSOUND _soundDevice = nullptr; // 사운드카드 본체
};

// 신입분들 코드보면
// 매니저가 아니어야할것들도 매니저로 많이 들어가있다
// 예를들면 enemyManager 같은거
#include "pch.h"
#include "Sound.h"

Sound::~Sound()
{
#ifdef USE_SOUND
	if (_soundBuffer)
	{
		_soundBuffer->Release();
	}
#endif
}

bool Sound::LoadWave(const wstring& path)
{
#ifdef USE_SOUND
	HMMIO file = mmioOpen((wchar_t *)path.c_str(), NULL, MMIO_READ);
	if (file == NULL)
	{
		Alert(L"Error", L"사운드 파일 / 인식 못함.");
		return false;
	}

	MMCKINFO parent;
	// 메모리 셋(memset) 이것들은 같은 거 둘중 하나는 기억해야함
	memset(&parent, 0, sizeof(parent));
	//ZeroMemory(&parent, sizeof(parent));

	parent.fccType = mmioFOURCC('W', 'A', 'V', 'E');
	mmioDescend(file, &parent, NULL, MMIO_FINDRIFF);

	MMCKINFO child;
	memset(&child, 0, sizeof(child));
	child.ckid = mmioFOURCC('f', 'm', 't', ' ');
	mmioDescend(file, &child, &parent, MMIO_FINDCHUNK);

	WAVEFORMATEX wft;
	// .wav   , .mp3 (x)
	memset(&wft, 0, sizeof(wft));
	mmioRead(file, (char*)&wft, sizeof(wft));

	mmioAscend(file, &child, 0);
	child.ckid = mmioFOURCC('d', 'a', 't', 'a');
	mmioDescend(file, &child, &parent, MMIO_FINDCHUNK);

	memset(&_bufferDesc, 0, sizeof(DSBUFFERDESC));
	_bufferDesc.dwBufferBytes = child.cksize;
	_bufferDesc.dwSize = sizeof(DSBUFFERDESC);
	_bufferDesc.dwFlags = DSBCAPS_STATIC;
	_bufferDesc.lpwfxFormat = &wft;

	// 사운드 버퍼 생성과정
	LPDIRECTSOUND soundDevice = GET_SINGLE(SoundManager)->GetSoundDevice();
	if (FAILED(soundDevice->CreateSoundBuffer(&_bufferDesc, &_soundBuffer, NULL)))
	{
		Alert(L"Error", L"사운드 버퍼 생성 실패");
		return false;
	}

	// C++에서 쓰이는 문법
	// C++의 꽃
	// void 포인터
	// 포인터 => 주소값을 기억하는 자료형(모두가 똑같은 값의 형식 4바이트)
	// int*, float*, 클래스*
	// 굳이 포인터 앞에 자료형을 붙인 이유
	//  - 문법이라서
	//  - 나중에 사용할 때, 얘가 어떤 형인지 알아야하니까

	// void*는 그냥 주소값만 들고있겠다라는 의미
	// 나중에 사용이 필요하면 
	// 그 때 형변환을 해주겠다는 것
	// 엔진 다루는 사람들이 많이 쓴다.

	void* write1 = NULL;
	void* write2 = NULL;
	DWORD len1;
	DWORD len2;

	// 버퍼에 값을 쓸때는 항상
	// 락을 걸고
	// 쓰고
	// 락을 풀고

	// 락을 건다는 것은 
	// 이 파일을 지금부터 내가 쓸거니까 건들지 마라
	// 건들거면 내가 다 쓸때까지 기다려라.
	// 라는 의미

	//락을 걸고
	_soundBuffer->Lock(0, child.cksize, &write1, &len1, &write2, &len2, 0);

	// 쓰고
	if (write1)
	{
		mmioRead(file, (char*)write1, len1);
	}
	if (write2)
	{
		mmioRead(file, (char*)write2, len2);
	}

	//락을 푼다.
	_soundBuffer->Unlock(write1, len1, write2, len2);

	mmioClose(file, 0);
	_soundBuffer->SetCurrentPosition(0);
#endif
	return true;
}

void Sound::Play(bool loop)
{
#ifdef USE_SOUND
	if (loop)
	{
		_soundBuffer->Play(0, 0, DSBPLAY_LOOPING);
	}
	else
	{
		_soundBuffer->Play(0, 0, 0);
	}
#endif
}

void Sound::Stop(bool reset)
{
#ifdef USE_SOUND
	_soundBuffer->Stop();

	if (reset)
	{
		_soundBuffer->SetCurrentPosition(0);
	}
#endif
}
#include "pch.h"
#include "TimeManager.h"


void TimeManager::Init()
{
	// 초 정밀 고속 타이머 사용

	// QueryPerformanceFrequency => 1초를 초정밀 타이머로 쪼갰을 때 몇 번 쪼갤 수 있는지 반환
	::QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*>(&_frequency));
	::QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&_prevCount));
}

void TimeManager::Updata()
{
	uint64 currentCount;
	::QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&currentCount));

	_deltaTime = (currentCount - _prevCount) / static_cast<float>(_frequency);
	_prevCount = currentCount;

	// 1초에 몇 번 화면갱신이 되었는지를 보기위한 변수
	_frameCount++;
	_frameTime += _deltaTime;

	if (1.0f <= _frameTime)
	{
		_fps = static_cast<uint32>(_frameCount / _frameTime);

		_frameTime = 0.0f;
		_frameCount = 0;
	}
}

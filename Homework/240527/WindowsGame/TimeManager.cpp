#include "pch.h"
#include "TimeManager.h"


void TimeManager::Init()
{
	// �� ���� ��� Ÿ�̸� ���

	// QueryPerformanceFrequency => 1�ʸ� ������ Ÿ�̸ӷ� �ɰ��� �� �� �� �ɰ� �� �ִ��� ��ȯ
	::QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*>(&_frequency));
	::QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&_prevCount));
}

void TimeManager::Updata()
{
	uint64 currentCount;
	::QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&currentCount));

	_deltaTime = (currentCount - _prevCount) / static_cast<float>(_frequency);
	_prevCount = currentCount;

	// 1�ʿ� �� �� ȭ�鰻���� �Ǿ������� �������� ����
	_frameCount++;
	_frameTime += _deltaTime;

	if (1.0f <= _frameTime)
	{
		_fps = static_cast<uint32>(_frameCount / _frameTime);

		_frameTime = 0.0f;
		_frameCount = 0;
	}
}

#pragma once
#include <random>
#include <chrono>

class RandomModule
{
public:
	RandomModule() 
	{
		//시드를 현재 시간으로 변경
		// high_resolution_clock => 초정밀 시계
		// 초정밀 시계로 .now() => 지금 시간을
		// .time_since_epoch().count() 1970년 1월 1일 기준으로 몇초가 지났냐
		auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
		_engine.seed(seed);
	}
	~RandomModule() {}

public:
	// 지정된 범위 내의 정수를 반환하는 메서드
	int GetRandomInt(int min, int max)
	{
		std::uniform_int_distribution<int> dist(min, max);
		return dist(_engine);
	}

	// 지정된 범위 내의 실수를 반환하는 메서드
	double GetRandomDouble(double min, double max)
	{
		std::uniform_real_distribution<double> dist(min, max);
		return dist(_engine);
	}

private:
	std::mt19937 _engine;	//랜덤 엔진
};
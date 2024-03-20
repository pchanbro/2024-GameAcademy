#pragma once
// 여기에 적을코드는
// 이해하려고 하지마라..
// 아 이런 느낌이구나..
// 하는 마음가짐으로 해라

#include <random>
#include <chrono>

class RandomModule
{
public:
	RandomModule()
	{
		// auto 키워드
		int a = 3;
		float b = 3.5;
		std::string c = "ss";
		auto d = "dd";
		auto e = 3;
		auto f = 3.5;
		// 뭐 이렇게 자유롭게 쓸 수 있다.

		// 시드를 현재 시간으로 변경
		// high_resolution_clock => 초정밀 시계
		// 초정밀 시계로 .now() => 지금 시간을
		// .time_since_epoch() 1970년 1월 1일을 기준으로 몇초가 지났냐
		auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
		_engine.seed(seed);
	}
	~RandomModule()	{}

public: // 그냥 선 긋는 느낌으로 다시 public 적어주자
	int GetRandomInt(int min, int max)
	{
		std::uniform_int_distribution<int> dist(min, max);
		return dist(_engine);
	}

	double GetRandomDouble(double min, double max)
	{
	std:uniform_real_distribution<double> dist(min, max);
		return dist(_engine);
	}
private:
	std::mt19937 _engine;
};


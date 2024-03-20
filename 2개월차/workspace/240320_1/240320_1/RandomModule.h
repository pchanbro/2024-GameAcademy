#pragma once
// ���⿡ �����ڵ��
// �����Ϸ��� ��������..
// �� �̷� �����̱���..
// �ϴ� ������������ �ض�

#include <random>
#include <chrono>

class RandomModule
{
public:
	RandomModule()
	{
		// auto Ű����
		int a = 3;
		float b = 3.5;
		std::string c = "ss";
		auto d = "dd";
		auto e = 3;
		auto f = 3.5;
		// �� �̷��� �����Ӱ� �� �� �ִ�.

		// �õ带 ���� �ð����� ����
		// high_resolution_clock => ������ �ð�
		// ������ �ð�� .now() => ���� �ð���
		// .time_since_epoch() 1970�� 1�� 1���� �������� ���ʰ� ������
		auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
		_engine.seed(seed);
	}
	~RandomModule()	{}

public: // �׳� �� �ߴ� �������� �ٽ� public ��������
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


#pragma once
#include <random>
#include <chrono>

class RandomModule
{
public:
	RandomModule() 
	{
		//�õ带 ���� �ð����� ����
		// high_resolution_clock => ������ �ð�
		// ������ �ð�� .now() => ���� �ð���
		// .time_since_epoch().count() 1970�� 1�� 1�� �������� ���ʰ� ������
		auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
		_engine.seed(seed);
	}
	~RandomModule() {}

public:
	// ������ ���� ���� ������ ��ȯ�ϴ� �޼���
	int GetRandomInt(int min, int max)
	{
		std::uniform_int_distribution<int> dist(min, max);
		return dist(_engine);
	}

	// ������ ���� ���� �Ǽ��� ��ȯ�ϴ� �޼���
	double GetRandomDouble(double min, double max)
	{
		std::uniform_real_distribution<double> dist(min, max);
		return dist(_engine);
	}

private:
	std::mt19937 _engine;	//���� ����
};
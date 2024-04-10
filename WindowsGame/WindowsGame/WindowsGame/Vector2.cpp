#include "pch.h"
#include "Vector2.h"

Vector2 Vector2::operator-(const POINT pt)
{
	return Vector2{ static_cast<float>(x - pt.x), static_cast<float>(y - pt.y) };
}
Vector2 Vector2::operator-(const Vector2 other)
{
	return Vector2{ x - other.x, y - other.y };
}
void Vector2::operator-=(const Vector2 other)
{
	this->x -= other.x;
	this->y -= other.y;
}
Vector2 Vector2::operator+(const POINT pt)
{
	return Vector2{ static_cast<float>(x + pt.x), static_cast<float>(y + pt.y) };
}
Vector2 Vector2::operator+(const Vector2 other)
{
	return Vector2{ x + other.x, y + other.y };
}
void Vector2::operator+=(const Vector2 other)
{
	this->x += other.x;
	this->y += other.y;
}
Vector2 Vector2::operator*(const float other)
{
	return Vector2{ x * other, y * other };
}
void Vector2::operator*=(const float other)
{
	this->x *= other;
	this->y *= other;
}
Vector2 Vector2::operator/(const float other)
{
	return Vector2{ x / other, y / other };
}
void Vector2::operator/=(const float other)
{
	this->x /= other;
	this->y /= other;
}

float Vector2::Length()
{
	return static_cast<float>(::sqrt(x * x + y * y));
}

Vector2 Vector2::Normalize()
{
	float length = this->Length();
	if (length <= 0.00000000001f) // �̰� length == 0 �� �ǹ̸� ���� �ǵ� length == 0 �̷��� ���� �ȵǱ� ������ length <= 0.00000000001f �̷��� ǥ���Ѵ�.
	{
		return *this;
	}
	return Vector2{ x / length, y / length };
}

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}
Vector2::Vector2()
{
	this->x = 0;
	this->y = 0;
}

float Vector2::Dot(Vector2 other)
{
	return x * other.x + y * other.y;
}

Vector2 Vector2::Reflect(Vector2 normal)
{

	// origin : �ڱ��ڽ�
	// normal : �븻����, ��������, ���̰� 1
	
	// �ٵ� ���⼭ �� normal�� origin ��� ���̰� 1�϶� �����ΰ�?
	// origin���� ���̰� 1�� ������ ���� �𸣰ڴ�.
	// �ݻ����� ���� ���ʹ� ���⸸ �˸� �Ǵϱ� �׷��ǰ�?

	Vector2 normalizedNormalVector = normal.Normalize();
	Vector2 normalizedOriginVector = this->Normalize();

	Vector2 temp = normalizedNormalVector;
	float tempLength = normalizedOriginVector.Dot(normal * -1);
	temp *= tempLength;

	return normalizedOriginVector + temp * 2;
}

Vector2 Vector2::Reflect(Vector2 originVector, Vector2 normal)
{
	Vector2 normalizedNormalVector = normal.Normalize();
	Vector2 normalizedOriginVector = originVector.Normalize();

	Vector2 temp = normalizedNormalVector;
	float tempLength = normalizedOriginVector.Dot(normal * -1);
	temp *= tempLength;

	return normalizedOriginVector + temp * 2;
}
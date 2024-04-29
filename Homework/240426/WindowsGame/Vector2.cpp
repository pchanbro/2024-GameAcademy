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
	if (length <= 0.00000000001f) // 이게 length == 0 의 의미를 가진 건데 length == 0 이렇게 쓰면 안되기 때문에 length <= 0.00000000001f 이렇게 표시한다.
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

Vector2::Vector2(POINT pt)
{
	this->x = static_cast<float>(pt.x);
	this->y = static_cast<float>(pt.y);
}


float Vector2::Dot(Vector2 other)
{
	return x * other.x + y * other.y;
}

Vector2 Vector2::Reflect(Vector2 normal)
{

	// origin : 자기자신
	// normal : 노말벡터, 법선벡터, 길이가 1
	
	// 근데 여기서 왜 normal과 origin 모두 길이가 1일때 가정인가?
	// origin까지 길이가 1인 이유가 뭔지 모르겠다.
	// 반사했을 때의 벡터는 방향만 알면 되니까 그런건가? -> 맞다 그리고 모든 방향벡터는 길이가 1이다.

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
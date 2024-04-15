#include "pch.h"
#include "Vector2Int.h"

Vector2Int::Vector2Int() : x(0), y(0)
{

}

Vector2Int::Vector2Int(int x, int y) : x(x) , y(y)
{

}

Vector2Int::Vector2Int(Vector2 vector) : x(static_cast<int>(vector.x)), y(static_cast<int>(vector.x))
{

}

Vector2Int::Vector2Int(POINT point)
{

}

Vector2Int::Vector2Int operator+(const Vector2Int& other)
{

}

Vector2Int::Vector2Int operator-(const Vector2Int& other)
{

}

Vector2Int::Vector2Int operator*(const Vector2Int& other)
{

}

void Vector2Int::operator+=(const Vector2Int& other)
{

}

void Vector2Int::operator-=(const Vector2Int& other)
{

}

void Vector2Int::operator*=(int32 value)
{

}

int32 Vector2Int::LengthSquared()
{

}

float Vector2Int::Length()
{

}

int32 Vector2Int::Dot(Vector2Int other)
{

}
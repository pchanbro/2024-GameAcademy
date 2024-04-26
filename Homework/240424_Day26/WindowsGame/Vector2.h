#pragma once
// class와 struct는 차이는 딱히 없는데 그냥 단어 차이
// 근데 이제 쓰이는 용도가 있다.
// struct는 data에 쓰이고 class는 객체
// 대부분의 vector는 구조체이다.
struct Vector2
{
	float x = 0, y = 0;

	Vector2 operator-(const POINT pt); // const는 뒤의거 변경 안된다는 의미로 사용
	Vector2 operator-(const Vector2 other);
	void operator-=(const Vector2 other);
	Vector2 operator+(const POINT pt);
	Vector2 operator+(const Vector2 other);
	void operator+=(const Vector2 other);
	Vector2 operator*(const float other);
	void operator*=(const float other);
	Vector2 operator/(const float other);
	void operator/=(const float other);

	float Length();
	Vector2 Normalize(); // 벡터의 길이를 1로 만들어준다.

	Vector2(float x, float y); // 생성자
	Vector2(); // 생성자
	Vector2(POINT pt);

	// 내적은 Dot
	// 내적은 주로 두 vector사이의 각도 계산할 때 많이 쓰인다.
	// A Dot B = A.x * B.x + A.y * B.y
	// A Dot B = |A||B|cos(theta)
	//		-> A B 둘 다 길이가 1이면 A Dot B = cos(theta)
	//		-> theta는 두 벡터가 이루는 각도를 나타낸다.
	//		-> 즉, 내적은 두 벡터가 이루는 각도를 구할 때 사용한다.
	// Tip1. 
	//  - cos 그래프는
	//	- 0도일 때 1, 90도일 때 0, 180도 일 때 -1

	// Tip2.
	//  - 내적으로는 각도가 180도가 넘는 각도는 구할 수 없다.

	// Tip3.
	//  - other 벡터가 내 뒤에 있는지 확인하려면
	//	- 내적이 0보다 작으면 내 뒤에 있습니다. (90도가 넘어갔다는 뜻)
	
	float Dot(Vector2 other);


	Vector2 Reflect(Vector2 normal);

	static Vector2 Reflect(Vector2 originVector, Vector2 normal);

	// 많이 쓰는 기능들은 이렇게 만들어주면 가독성도 좋아지고 이후 움직임을 만들어 줄 때 편해진다.
	static Vector2 Zero()
	{
		return Vector2(0, 0);
	}

	static Vector2 Up()
	{
		return Vector2(0, -1);
	}

	static Vector2 Down()
	{
		return Vector2(0, 1);
	}

	static Vector2 Right()
	{
		return Vector2(1, 0);
	}

	static Vector2 Left()
	{
		return Vector2(-1, 0);
	}
};
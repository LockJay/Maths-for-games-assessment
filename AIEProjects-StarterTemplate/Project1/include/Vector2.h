#ifndef VECTOR2_H
#define VECTOR2_H
#include <cmath>

class Vector2
{
public:

	Vector2();
	Vector2(float a, float b);
	Vector2(const Vector2 &other);
	~Vector2();

	float x;
	float y;

	void operator=(const Vector2 &other);
	bool operator==(const Vector2 &other);
	void operator+=(const Vector2 &other);
	void operator-=(const Vector2 &other);
	Vector2 operator+(const Vector2 &other);
	Vector2 operator-(const Vector2 &other);

	Vector2 ScalarMultiplication(Vector2 a, float scalar);
	float ScalarMultiplication(float a, float b);

	float Magnitude(Vector2 a);
	float Dot(Vector2 a, Vector2 b);

	Vector2 Normalise(Vector2 a);
};







#endif
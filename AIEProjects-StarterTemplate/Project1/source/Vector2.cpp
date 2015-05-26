#include "Vector2.h"

Vector2::Vector2()
{
	x = 0.0f;
	y = 0.0f;
}

Vector2::Vector2(float a, float b)
{
	x = a;
	y = b;
}

Vector2::Vector2(const Vector2 &other)
{
	*this = other;
}

Vector2::~Vector2()
{

}

void Vector2::operator=(const Vector2 &other)
{
	x = other.x;
	y = other.y;
}

bool Vector2::operator==(const Vector2 &other)
{
	return x == other.x && y == other.y;
}

void Vector2::operator+=(const Vector2 &other)
{
	x += other.x;
	y += other.y;
}

void Vector2::operator-=(const Vector2 &other)
{
	x -= other.x;
	y -= other.y;
}

Vector2 Vector2::operator+(const Vector2 &other)
{

	float tempX = x + other.x;
	float tempY = y + other.y;

	Vector2 temp(tempX, tempY);

	return temp;

}

Vector2 Vector2::operator-(const Vector2 &other)
{

	float tempX = x - other.x;
	float tempY = y - other.y;

	Vector2 temp(tempX, tempY);

	return temp;

}

Vector2 Vector2::ScalarMultiplication(Vector2 a, float scalar)
{

	float tempX = scalar * a.x;
	float tempY = scalar * a.y;

	Vector2 temp(tempX, tempY);
	
	return temp;

}

float Vector2::Magnitude(Vector2 a)
{

	float tempX = a.x * a.x;
	float tempY = a.x * a.x;

	return sqrt(tempX + tempY);

}

float Vector2::Dot(Vector2 a, Vector2 b)
{
	return 0.0f;
}

Vector2 Vector2::Normalise(Vector2 a)
{

	float length = Magnitude(a);

	float tempX = a.x / length;
	float tempY = a.y / length;

	Vector2 temp(tempX, tempY);

	return temp;

}
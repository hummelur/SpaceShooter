#include "Vector2D.h"

#include <cmath>

Vector2D::Vector2D(){}

Vector2D::Vector2D(float x, float y)
	: x(x), y(y) {
}

Vector2D::~Vector2D()
{
}

void Vector2D::set(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2D Vector2D::operator+(const Vector2D &vector)
{
	return Vector2D(x + vector.x, y + vector.y);
}

Vector2D& Vector2D::operator+=(const Vector2D &vector)
{
	x += vector.x;
	y += vector.y;

	return *this;
}

Vector2D Vector2D::operator-(const Vector2D &vector)
{
	return Vector2D(x - vector.x, y - vector.y);
}

Vector2D& Vector2D::operator-=(const Vector2D &vector)
{
	x -= vector.x;
	y -= vector.y;

	return *this;
}

Vector2D Vector2D::operator*(float scalar)
{
	return Vector2D(x*scalar, y*scalar);
}

Vector2D& Vector2D::operator*=(float scalar)
{
	x *= scalar;
	y *= scalar;

	return *this;
}

Vector2D Vector2D::operator/(float scalar)
{
	return Vector2D(x / scalar, y / scalar);
}

Vector2D& Vector2D::operator/=(float scalar)
{
	x /= scalar;
	y /= scalar;

	return *this;
}
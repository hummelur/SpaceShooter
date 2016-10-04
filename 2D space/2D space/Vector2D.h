#ifndef INCLUDED_VECTOR2D
#define INCLUDED_VECTOR2D

class Vector2D {
public:
	float x, y;

	// Constructor
	Vector2D();
	Vector2D(float x, float y);

	// Destructor
	~Vector2D();

	// Methods
	void set(float x, float y);

	//Overloaded operators
	Vector2D operator+(const Vector2D &vector);
	Vector2D& operator+=(const Vector2D &vector);
	Vector2D operator-(const Vector2D &vector);
	Vector2D& operator-=(const Vector2D &vector);
	Vector2D operator*(float scalar);
	Vector2D& operator*=(float scalar);
	Vector2D operator/(float scalar);
	Vector2D& operator/=(float scalar);

};
#endif // !INCLUDED_VECTOR2D

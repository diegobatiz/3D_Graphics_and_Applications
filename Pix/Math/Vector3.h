#pragma once

struct Vector3
{
	float x, y, z;

	Vector3() : x{ 0.f }, y{ 0.f }, z{ 0.f } {}
	Vector3(float s) : x{ s }, y{ s }, z{ s } {}
	Vector3(float i, float j, float k) : x{ i }, y{ j }, z{ k } {}
	Vector3(const Vector3& v) : x{ v.x }, y{ v.y }, z{ v.z } {}
		  
	Vector3 operator-() const { return Vector3(-x, -y, -z); }
	Vector3 operator+(const Vector3& rhs) const { return Vector3(x + rhs.x, y + rhs.y, z + rhs.z); }
	Vector3 operator-(const Vector3& rhs) const { return Vector3(x - rhs.x, y - rhs.y, z - rhs.z); }
	Vector3 operator*(float s) const { return Vector3(x * s, y * s, z * s); }
	Vector3 operator/(float s) const { return Vector3(x / s, y / s, z / s); }

	Vector3& operator+=(const Vector3& rhs) { x += rhs.x; y += rhs.y; z += rhs.z; return *this; }
	Vector3& operator-=(const Vector3& rhs) { x -= rhs.x; y -= rhs.y; z -= rhs.z; return *this; }
	Vector3& operator*=(float s) { x *= s; y *= s; z *= s; return *this; }
	Vector3& operator/=(float s) { x /= s; y /= s; z /= s; return *this; }
};
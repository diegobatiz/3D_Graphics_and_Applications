#include "MathHelper.h"
#include <cmath>

float MathHelper::MagnitudeSquared(const Vector2& v)
{
	return v.x * v.x + v.y * v.y;
}

float MathHelper::MagnitudeSquared(const Vector3& v)
{
	return v.x * v.x + v.y * v.y + v.z * v.z;
}

float MathHelper::Magnitude(const Vector2& v)
{
	return sqrt(MagnitudeSquared(v));
}

float MathHelper::Magnitude(const Vector3& v)
{
	return sqrt(MagnitudeSquared(v));;
}

Vector2 MathHelper::Normalize(const Vector2& v)
{
	return v / Magnitude(v);
}

Vector3 MathHelper::Normalize(const Vector3& v)
{
	return v / Magnitude(v);
}
 
float MathHelper::Dot(const Vector2& a, const Vector2& b)
{
	return (a.x * b.x) + (a.y * b.y);
}

float MathHelper::Dot(const Vector3& a, const Vector3& b)
{
	return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

Vector3 MathHelper::Cross(const Vector3& a, const Vector3& b)
{
	return Vector3(a.y * b.z - b.y * a.z, a.z * b.x - b.z * a.x, a.x * b.y - b.x * a.y);
}

bool MathHelper::AreEqual(float a, float b)
{
	return abs(a - b) < 0.01f;
}

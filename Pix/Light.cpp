#include "Light.h"

X::Color Light::ComputeLightColor(const Vector3& position, const Vector3& normal) const
{
	return X::Color();
}

void Light::SetAmbient(const X::Color color)
{
	mAmbient = color;
}

void Light::SetDiffuse(const X::Color color)
{
	mDiffuse = color;
}

void Light::SetSpecular(const X::Color color)
{
	mSpecular = color;
}

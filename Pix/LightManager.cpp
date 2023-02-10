#include "LightManager.h"

LightManager* LightManager::Get()
{
	static LightManager sInstance;

	return &sInstance;
}

void LightManager::OnNewFrame()
{
	mLights.clear();
}

void LightManager::AddDirectionalLight(const Vector3& direction)
{
}

void LightManager::AddPointLight(const Vector3& position, float constant, float linear, float quadratic)
{
}

void LightManager::AddSpotLight(const Vector3& position, const Vector3& direction, float constant, float linear, float quadratic, )
{
}

void LightManager::SetLightingAmbient(const X::Color& color)
{
	mAmbient = color;
}

void LightManager::SetLightingDiffuse(const X::Color& color)
{
	mDiffuse = color;
}

void LightManager::SetLightingSpecular(const X::Color& color)
{
	mSpecular = color;
}

X::Color LightManager::ComputeLightColor(const Vector3& position, const Vector3& normal) const
{
	if (mLights.empty())
	{
		return X::Colors::White;
	}

	X::Color color;
	for (auto& light : mLights)
	{
		color += light->ComputeLightColor(position, normal);
	}

	return color;
}

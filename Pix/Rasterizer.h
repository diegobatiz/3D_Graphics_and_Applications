#pragma once

#include <XEngine.h>
#include "Math/Vertex.h"

enum class FillMode
{
	Solid,
	WireFrame
};

enum class ShadeMode
{
	Flat, 
	Gouraud,
	Phong
};

class Rasterizer
{
public:
	static Rasterizer* Get();

public:
	void SetColor(X::Color color);
	void SetFillMode(FillMode fillMode);
	void SetShadeMode(ShadeMode shadeMode);

	ShadeMode GetShadeMode();

	void DrawPoint(int x, int y);

	void DrawPoint(const Vertex& vertex);
	void DrawLine(const Vertex& a, const Vertex& b);
	void DrawTriangle(Vertex a, Vertex b, Vertex c);

private:
	X::Color mColor = X::Colors::White;
	FillMode mFillMode = FillMode::Solid;
	ShadeMode mShadeMode = ShadeMode::Gouraud;

	void DrawFilledTriangle(const Vertex& v0, const Vertex& v1, const Vertex& v2);
};
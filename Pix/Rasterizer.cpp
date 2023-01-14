#include "Rasterizer.h"

Rasterizer* Rasterizer::Get()
{
	static Rasterizer sInstance;
	return &sInstance;
}

void Rasterizer::SetColor(X::Color color)
{
	mColor = color;
}

void Rasterizer::SetFillMode(FillMode fillMode)
{
	mFillMode = fillMode;
}

void Rasterizer::DrawPoint(int x, int y)
{
	X::DrawPixel(x, y, mColor);
}

void Rasterizer::DrawPoint(const Vertex& vertex)
{
	SetColor(vertex.color);
	DrawPoint(static_cast<int>(vertex.pos.x), static_cast<int>(vertex.pos.y));
}

void Rasterizer::DrawLine(const Vertex& a, const Vertex& b)
{
	int dx = b.pos.x - a.pos.x;
	int dy = b.pos.y - a.pos.y;
	int D = 2 * dy - dx;
	int y = a.pos.y;

	float t = 0.0f;
	Vertex vertex;
	
	for (int x = a.pos.x; x < b.pos.x; ++x)
	{
		t = (static_cast<float>(x) - a.pos.x) / (b.pos.x - a.pos.x);
		vertex.color = LerpColor(a.color, b.color, t);
		vertex.pos.x = x;
		vertex.pos.y = y;

		DrawPoint(vertex);
		if (D > 0)
		{
			++y;
			D = D - 2 * dx;
		}
		D = D + 2 * dy;
	}
}

void Rasterizer::DrawTriangle(const Vertex& a, const Vertex& b, const Vertex& c)
{
}

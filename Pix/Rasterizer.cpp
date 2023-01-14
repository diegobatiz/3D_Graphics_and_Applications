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
	float dx = b.pos.x - a.pos.x;
	float dy = b.pos.y - a.pos.y;
	if (abs(dx) <= 0.01f)
	{
		if (a.pos.y < b.pos.y)
		{
			DrawLineHigh(a, b);
		}
		else
		{
			DrawLineHigh(b, a);
		}
	}
	else
	{
		float m = dy / dx;
		if (abs(m) < 1)
		{
			if (a.pos.x < b.pos.x)
			{
				DrawLineLow(a, b);
			}
			else
			{
				DrawLineLow(b, a);
			}
		}
		else
		{
			if (a.pos.y < b.pos.y)
			{
				DrawLineHigh(a, b);
			}
			else
			{
				DrawLineHigh(b, a);
			}
		}
	}
}

void DrawLineLow(const Vertex& left, const Vertex& right)
{
	float dx = right.pos.x - left.pos.x;
	float startX = static_cast<int>(left.pos.x);
	int endX = static_cast<int>(right.pos.x);
	for (int x = startX; x < endX; ++x)
	{
		float t = static_cast<float>(x - startX) / dx;
		Rasterizer::Get()->DrawPoint(LerpVertex(left, right, t));
	}
}

void DrawLineHigh(const Vertex& bottom, const Vertex& top)
{
	float dy = top.pos.y - bottom.pos.y;
	float startY = static_cast<int>(bottom.pos.y);
	int endY = static_cast<int>(top.pos.y);
	for (int y = startY; y < endY; ++y)
	{
		float t = static_cast<float>(y - startY) / dy;
		Rasterizer::Get()->DrawPoint(LerpVertex(bottom, top, t));
	}
}

void Rasterizer::DrawTriangle(const Vertex& a, const Vertex& b, const Vertex& c)
{
	switch (mFillMode)
	{
	case FillMode::Solid:
	{

	}
	break;
	case FillMode::WireFrame:
	{
		DrawLine(a, b);
		DrawLine(b, c);
		DrawLine(c, a);
	}
	break;
	}
}

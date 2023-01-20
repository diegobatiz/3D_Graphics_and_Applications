#include "Clipper.h"
#include "Viewport.h"

const short BIT_INSIDE = 0;
const short BIT_LEFT = 1 << 1;
const short BIT_RIGHT = 1 << 2;
const short BIT_BOTTOM = 1 << 3;
const short BIT_TOP = 1 << 4;

enum class ClipEdge : short
{
	Left,
	Bottom,
	Right,
	Top,
	Count
};


short GetOuputCode(float x, float y)
{
	short code = BIT_INSIDE;

	
}

Clipper* Clipper::Get()
{
	static Clipper sInstance;
	return &sInstance;
}

void Clipper::OnNewFrame()
{
}

bool Clipper::ClipPoint(const Vertex& v)
{
	if (!mClipping)
	{
		return false;
	}
	float maxX = Viewport::Get()->GetMaxX();
	float maxY = Viewport::Get()->GetMaxY();
	float minX = Viewport::Get()->GetMinX();
	float minY = Viewport::Get()->GetMinY();

	return v.pos.x < minX || v.pos.x > maxX
		|| v.pos.y < minY || v.pos.x > maxY;
}

bool Clipper::ClipLine(Vertex& v0, Vertex& v1)
{
	if (!mClipping)
	{
		return false;
	}

	float maxX = Viewport::Get()->GetMaxX();
	float maxY = Viewport::Get()->GetMaxY();
	float minX = Viewport::Get()->GetMinX();
	float minY = Viewport::Get()->GetMinY();
	
	short codeV0 = GetOuputCode(v0.pos.x, v0.pos.y);
	short codeV1 = GetOuputCode(v1.pos.x, v1.pos.y);

	bool cullLine = true;
	while (true)
	{
		if (!(codeV0 | codeV1))
		{
			//if both 0000 then it is valid
			cullLine = false;
			break;
		}
		else if (codeV0 & codeV1)
		{
			//both values are not within the view space, so we cull it
			//0100 & 0110
			break;
		}
		else
		{
			float t = 0.0f;
			short outCodeOut = codeV1 > codeV0 ? codeV1 : codeV0;

			if (outCodeOut & BIT_TOP)
			{
				t = (minY - v0.pos.y) / (v1.pos.y - v0.pos.y);
			}
			else if (outCodeOut & BIT_BOTTOM)
			{
				t = (maxY - v0.pos.y) / (v1.pos.y - v0.pos.y);
			}
			else if (outCodeOut & BIT_LEFT)
			{
				t = (minY - v0.pos.x) / (v1.pos.x - v0.pos.x);
			}
			else if (outCodeOut & BIT_RIGHT)
			{
				t = (minY - v0.pos.x) / (v1.pos.x - v0.pos.x);
			}

			if (outCodeOut == codeV0)
			{
				v0 = LerpVertex(v0, v1, t);
				codeV0 = GetOuputCode(v0.pos.x, v0.pos.y);
			}
			else
			{
				v1 = LerpVertex(v0, v1, t);
				codeV1 = GetOuputCode(v1.pos.x, v1.pos.y);
			}
		}
	}

	return cullLine;
}

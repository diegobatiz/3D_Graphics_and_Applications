#pragma once
#include "Math/Vertex.h"

class Clipper
{
public:
	static Clipper* Get();
public:

	void OnNewFrame();

	bool ClipPoint(const Vertex& v);
	bool ClipLine(Vertex& v1, Vertex& v2);

	bool IsClipping() const { return mClipping; }
	void SetClipping(bool clip) { mClipping = clip; }

private:
	bool mClipping = false;
};
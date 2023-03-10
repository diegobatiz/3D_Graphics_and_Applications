#pragma once

#include "Math/Vertex.h"

enum class Topology
{
	Point,
	Line, 
	Triangle
};

enum class Cullmode
{
	None,
	Front,
	Back
};

class PrimitivesManager
{
public:
	static PrimitivesManager* Get();

	void OnNewFrame();
	void SetCullMode(Cullmode mode);
	void SetCorrectUV(bool correct);

	bool BeginDraw(Topology topology, bool applyTransform = false);
	void AddVertex(const Vertex& vertex);
	bool EndDraw();

private:
	std::vector<Vertex> mVertexBuffer;
	Topology mTopology = Topology::Triangle;
	Cullmode mCullMode = Cullmode::None;
	bool mDrawBegin = false;
	bool mApplyTransform = false;
	bool mCorrectUv = false;
};
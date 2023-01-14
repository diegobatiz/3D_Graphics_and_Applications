#include "PrimitivesManager.h"
#include "Rasterizer.h"


PrimitivesManager* PrimitivesManager::Get()
{
	static PrimitivesManager sInstance;
	return &sInstance;
}


bool PrimitivesManager::BeginDraw(Topology topology)
{
	mDrawBegin = true;
	mTopology = topology;
	mVertexBuffer.clear();
	return true;
}

void PrimitivesManager::AddVertex(const Vertex& vertex)
{
	if (mDrawBegin)
	{
		mVertexBuffer.push_back(vertex);
	}
}

bool PrimitivesManager::EndDraw()
{
	if (!mDrawBegin)
	{
		return false;
	}

	switch (mTopology)
	{
	case Topology::Point: break;
	case Topology::Line: break;
	case Topology::Triangle: break;
	default:
		return false;
	}

	mDrawBegin = false;
	return true;
}

#include "Model.h"

void Model::Load(const std::string& fileName)
{
	mFileName = fileName;

	std::vector<Vector3> positions;
	std::vector<Vector3> normals;
	std::vector<uint32_t> positionIndices;
	std::vector<uint32_t> normalsCount;

	FILE* file = nullptr;
	fopen_s(&file, fileName.c_str(), "r");
	if (file == nullptr)
	{
		char buffer[128];
		sprintf_s(buffer, "Cannot open model file %s", fileName.c_str());
		MessageBoxA(nullptr, buffer, "Model Error", MB_OK | MB_ICONEXCLAMATION);
		return;
	}

	while (true)
	{
		char buffer[128];
		int result = fscanf_s(file, "%s", buffer, (uint32_t)std::size(buffer));
		if (result == EOF)
		{
			break;
		}
		if (strcmp(buffer, "v") == 0)
		{
			float x, y, z = 0.0f;
			fscanf_s(file, "%f &f &f\n", &x, &y, &z);
			positions.push_back({ x, y, z });
		}
		else if (strcmp(buffer, "f") == 0)
		{
			uint32_t v[3];
			if (fscanf_s(file, "%d//%*d %d//%*d %d//%*d\n", &v[0], &v[1], &v[2]) != 3)
			{
				char buffer[128];
				sprintf_s(buffer, "Unexpected format for %s", fileName.c_str());
				MessageBoxA(nullptr, buffer, "Model Error", MB_OK | MB_ICONEXCLAMATION);
				return;
			}

			positionIndices.push_back(v[0]);
			positionIndices.push_back(v[1]);
			positionIndices.push_back(v[2]);
		}
	}

	mVertices.resize(positionIndices.size());
	normals.resize(positions.size());
	normalsCount.resize(positions.size());
	for (size_t i = 2; i < positionIndices.size(); i += 3)
	{

	}

}

const std::string& Model::GetFileName() const
{
	return mFileName;
}

const Vertex& Model::GetVertex(int index) const
{
	return mVertices[index];
}

int Model::GetVertexCount() const
{
	return static_cast<int>(mVertices.size());
}

#include "CmdPopMatrix.h"
#include "VariableCache.h"
#include "MatrixStack.h"

bool CmdPopMatrix::Execute(const std::vector<std::string>& params)
{
	if (params.size() > 0)
	{
		return false;
	}

	auto vc = VariableCache::Get();

	MatrixStack::Get()->PopMatrix();
	return true;
}

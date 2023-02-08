#include "CmdPushRotationZ.h"
#include "VariableCache.h"
#include "MatrixStack.h"

bool CmdPushRotationZ::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 1)
	{
		return false;
	}

	auto vc = VariableCache::Get();
	float radian = vc->GetFloat(params[0]);

	MatrixStack::Get()->PushRotationZ(radian);
	return true;
}

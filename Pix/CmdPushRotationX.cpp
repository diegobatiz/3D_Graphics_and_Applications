#include "CmdPushRotationX.h"
#include "VariableCache.h"
#include "MatrixStack.h"

bool CmdPushRotationX::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 1)
	{
		return false;
	}

	auto vc = VariableCache::Get();
	float radian = vc->GetFloat(params[0]);

	MatrixStack::Get()->PushRotationX(radian);
	return true;
}

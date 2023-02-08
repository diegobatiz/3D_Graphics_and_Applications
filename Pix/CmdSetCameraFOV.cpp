#include "CmdSetCameraFOV.h"
#include "VariableCache.h"
#include "Camera.h"

bool CmdSetCameraFOV::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 1)
	{
		return false;
	}

	auto vc = VariableCache::Get();
	float fov = vc->GetFloat(params[0]);

	Camera::Get()->SetFOV(fov);
	return true;
}

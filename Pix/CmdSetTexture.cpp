#include "CmdSetTexture.h"
//#include "ModelCache.h"

bool CmdSetTexture::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 1)
	{
		return false;
	}

	//add texture to cache
	return true;
}


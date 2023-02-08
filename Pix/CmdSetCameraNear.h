#pragma once

#include "Command.h"


class CmdSetCameraNear : public Command
{
public:
	const char* GetName() override
	{
		return "SetCameraNear";
	}

	const char* GetDescription() override
	{
		return
			"SetCameraNear(nearPlane)\n"
			"\n"
			"- Sets the near plane of the camera (nearPlane).";
			
	}

	bool Execute(const std::vector<std::string>& params);
};
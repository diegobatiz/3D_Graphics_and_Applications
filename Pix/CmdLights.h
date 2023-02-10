#pragma once

#include "Command.h"


class CmdSetLightAmbient : public Command
{
public:
	const char* GetName() override
	{
		return "SetCameraDirection";
	}

	const char* GetDescription() override
	{
		return
			"SetCameraDirection(x, y, z)\n"
			"\n"
			"- Sets the direction of the camera (x, y, z).";
			
	}

	bool Execute(const std::vector<std::string>& params);
};
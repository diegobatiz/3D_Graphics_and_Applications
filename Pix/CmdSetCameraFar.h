#pragma once

#include "Command.h"


class CmdSetCameraFar : public Command
{
public:
	const char* GetName() override
	{
		return "SetCameraFar";
	}

	const char* GetDescription() override
	{
		return
			"SetCameraFar(farPlane)\n"
			"\n"
			"- Sets the far plane of the camera (farPlane).";
			
	}

	bool Execute(const std::vector<std::string>& params);
};
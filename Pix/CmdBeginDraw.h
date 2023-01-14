#pragma once

#include "Command.h"

class CmdBeginDraw : public Command
{
	const char* GetName()
	{
		return "Begin Draw";
	}
	const char* GetDescription()
	{
		return "BeginDraw(topology) begins drawing a primitive";
	}

	bool Execute(const std::vector<std::string>& params);
};
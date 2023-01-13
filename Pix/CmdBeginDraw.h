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
		return "BeginDraw(topology) begins drawing";
	}

	bool Execute(const std::vector<std::string> )
};
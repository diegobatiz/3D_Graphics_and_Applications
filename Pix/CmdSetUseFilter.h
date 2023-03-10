#pragma once

#include "Command.h"

class CmdSetUseFilter: public Command
{
public:
	const char* GetName()
	{
		return "SetUseFilter";
	}
	const char* GetDescription()
	{
		return "SetUseFilter() enable or disable bilinear filtering";
	}

	bool Execute(const std::vector<std::string>& params);
};
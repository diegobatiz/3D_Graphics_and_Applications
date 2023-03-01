#pragma once

#include "Command.h"

class CmdSetShading: public Command
{
public:
	const char* GetName()
	{
		return "SetShading";
	}
	const char* GetDescription()
	{
		return "SetShading(shademode) sets the triangle's shade mode";
	}

	bool Execute(const std::vector<std::string>& params);
};
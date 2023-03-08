#pragma once
#include "Command.h"


class CmdSetTexture : public Command
{
public:
	const char* GetName() override
	{
		return "SetTexture";
	}

	const char* GetDescription() override
	{
		return "SetTexture(filename)";
	}

	bool Execute(const std::vector<std::string>& params);
};

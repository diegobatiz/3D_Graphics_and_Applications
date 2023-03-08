#pragma once
#include "Command.h"


class CmdSetAddressMode : public Command
{
public:
	const char* GetName() override
	{
		return "SetAddressMode";
	}

	const char* GetDescription() override
	{
		return "SetAddressMode(addressMode) sets the texture address mode";
	}

	bool Execute(const std::vector<std::string>& params);
};

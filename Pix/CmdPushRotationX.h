#pragma once

#include "Command.h"


class CmdPushRotationX : public Command
{
public:
	const char* GetName() override
	{
		return "PushRotationX";
	}

	const char* GetDescription() override
	{
		return
			"PushRotationX(radian)\n"
			"\n"
			"- Pushes a rotation around x axis into the matrix stack (radian).";
			
	}

	bool Execute(const std::vector<std::string>& params);
};
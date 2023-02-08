#pragma once

#include "Command.h"


class CmdPushRotationZ : public Command
{
public:
	const char* GetName() override
	{
		return "PushRotationZ";
	}

	const char* GetDescription() override
	{
		return
			"PushRotationZ(radian)\n"
			"\n"
			"- Pushes a rotation around z axis into the matrix stack (radian).";

	}

	bool Execute(const std::vector<std::string>& params);
};
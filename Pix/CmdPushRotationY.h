#pragma once

#include "Command.h"


class CmdPushRotationY : public Command
{
public:
	const char* GetName() override
	{
		return "PushRotationY";
	}

	const char* GetDescription() override
	{
		return
			"PushRotationY(radian)\n"
			"\n"
			"- Pushes a rotation around y axis into the matrix stack (radian).";

	}

	bool Execute(const std::vector<std::string>& params);
};
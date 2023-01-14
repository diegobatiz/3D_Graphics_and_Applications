#pragma once

#include "Command.h"

class CmdEndDraw : public Command
{
	const char* GetName()
	{
		return "End Draw";
	}
	const char* GetDescription()
	{
		return "EndDraw() using the vertices will draw the primitives";
	}

	bool Execute(const std::vector<std::string>& params);
};


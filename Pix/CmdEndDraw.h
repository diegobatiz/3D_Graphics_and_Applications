#pragma once

#include "Command.h"

class CmdEndDraw : public Command
{
public:
	const char* GetName()
	{
		return "EndDraw";
	}
	const char* GetDescription()
	{
		return "EndDraw() using the vertices will draw the primitives";
	}

	bool Execute(const std::vector<std::string>& params);
};


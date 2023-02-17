#pragma once
#include "Command.h"


class CmdSetLightAmbient : public Command
{
public:
	const char* GetName() override
	{
		return "SetLightAmbient";
	}

	const char* GetDescription() override
	{
		return
			"SetLightAmbient(r, g, b)";
			
	}

	bool Execute(const std::vector<std::string>& params);
};

class CmdSetLightDiffuse : public Command
{
public:
	const char* GetName() override
	{
		return "SetLightDiffuse";
	}

	const char* GetDescription() override
	{
		return
			"SetLightDiffuse(r, g, b)";

	}

	bool Execute(const std::vector<std::string>& params);
};

class CmdSetLightSpecular : public Command
{
public:
	const char* GetName() override
	{
		return "SetLightSpecular";
	}

	const char* GetDescription() override
	{
		return
			"SetLightSpecular(r, g, b)";

	}

	bool Execute(const std::vector<std::string>& params);
};

class CmdAddDirectionalLight : public Command
{
public:
	const char* GetName() override
	{
		return "AddDirectionalLight";
	}

	const char* GetDescription() override
	{
		return
			"AddDirectionalLight(x, y, z)";

	}

	bool Execute(const std::vector<std::string>& params);
};

class CmdAddPointLight : public Command
{
public:
	const char* GetName() override
	{
		return "AddPointLight";
	}

	const char* GetDescription() override
	{
		return
			"AddPointLight(x, y, z, <constant>, <linear>, <quadratic>)";

	}

	bool Execute(const std::vector<std::string>& params);
};

class CmdAddSpotLight : public Command
{
public:
	const char* GetName() override
	{
		return "AddSpotLight";
	}

	const char* GetDescription() override
	{
		return
			"AddSpotLight(x, y, z, x, y, z, <constant>, <linear>, <quadratic>, <decay>)";

	}

	bool Execute(const std::vector<std::string>& params);
};
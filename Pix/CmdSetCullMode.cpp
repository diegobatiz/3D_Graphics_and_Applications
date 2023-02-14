#include "CmdSetCullMode.h"
#include "PrimitivesManager.h"

bool CmdSetCullMode::Execute(const std::vector<std::string>& params)
{
    if (params.size() < 1)
    {
        return false;
    }
    Cullmode cullmode = Cullmode::Back;
    if (params[0] == "back") { cullmode = Cullmode::Back; }
    else if (params[0] == "front") { cullmode = Cullmode::Front; }
    else if (params[0] == "none") { cullmode = Cullmode::None; }
    else { return false; }

   PrimitivesManager::Get()->SetCullMode(cullmode);

    return true;
}

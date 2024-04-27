#pragma once
#include <string>

//MOD CONFIG
inline const std::string NAME = "awesomeMod"; //Name of the mod, used for the required/allowed checks and to check if loaded mod is unique
inline const std::string DISPLAY_NAME = "My Test Mod"; //Display name in game, used mainly for the imgui context
inline const std::string VERSION = "0.0.1"; //Version of the mod, used to check in require/allowed list
inline const int REQUIRED_VERSION = 2; //Required loader version for this mod
inline const bool HGE_ONLY = false; //Will only run if the loader blocks Low-Grade edition from launching 
inline const std::string CONFIG_INI_PATH = "./mods/modconfig.ini";
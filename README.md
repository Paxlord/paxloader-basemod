# Base Mod for Pax's MHFZ Mod Loader
This repo is meant to act as a mod template and documentation for my mod loader.

## Getting Started
1. Clone the repo
2. Edit the config.h
3. Every function that should be edited are exposed in BaseMod.cpp having to edit any other existing files in this template should be very rare.

## Mod Structure
The base mod class derives from a Mod virtual class. This base mod class has to expose the same functions and members as the virtual class for it to be considered a valid Mod that can be loaded by the mod loader. 

Here's the class definition : 
```cpp
class BaseMod :
	public Mod
{
public:

	using Mod::Mod;

	void Attach() override;
	void Detach() override;
	void DrawUI() override;
	void UpdateQuest() override;
	void UpdateLobby() override;
	void InitImGUIContext(ImGuiContext* ctx) override {
		ImGui::SetCurrentContext(ctx);
	}
};
```

- ```Attach()``` : Is executed once when the mod is loaded into memory, this should be used as an initialization function for 90% of cases. This is also where you should set up your hooks and where you should offset your addresses. 
- ```Detach()``` : Is meant to be used as a clean up function, (**Not Implemented Yet** will be implemented when I find a decent way to detect the game shutting down in the loader.)
- ```DrawUI()``` : Has direct access to the injected ImGUI context and can call any ImGUI function from there. By default everything drawn here will be inside the main mod menu inside a collapsible header with mod display name. ImGui supports Child Windows if you need seperate UI Context outside of the main mod menu. 
- ```UpdateQuest()``` : Direct access to the main update function in game. The code here runs every GAME frame while the player is inside a quest. Pretty useful for catching unstable pointers and doing stuff like reading inputs.
- ```UpdateLobby()``` : Same as UpdateQuest but runs every game frame while the player is in Mezeporta. (**Not Implemented Yet** will be implemented when I find a good enough hooking point.)
- ```InitImGUIContext()``` : Should not be touched, is used to pass the main context at initialization. 

## Config.h
A config header file can be found in the project. This is used as metadata for when the mod is loaded. 

```cpp
inline const std::string NAME = "awesomeMod"; //Name of the mod, used for the required/allowed checks and to check if loaded mod is unique
inline const std::string DISPLAY_NAME = "My Test Mod"; //Display name in game, used mainly for the imgui mod menu
inline const std::string VERSION = "0.0.1"; //Version of the mod, used for the version check in required/allowed list
inline const int REQUIRED_VERSION = 1; //Required loader version for this mod
inline const bool HGE_ONLY = false; //Will only run if the loader blocks Low-Grade edition from launching
```


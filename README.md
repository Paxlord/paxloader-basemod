# Base Mod for Pax's MHFZ Mod Loader
This repo is meant to act as a mod template and documentation for my mod loader.

## Mod Structure
The base mod class derives from a Mod virtual class. This base mod class has to expose the same functions and members as the virtual class for it to be considered a valid Mod that can be loaded by the mod loader. 
A mod exposes a few different functions, here's the class definition : 
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

- ```Attach()``` : Is executed once when this mod is loaded into memory, this should be used as an initialization function for 90% of cases. This also where you should set up your hooks and where you should offset your addresses. 
- ```Detach()``` : Is meant to be used as a clean up function, **Not Implemented Yet** will be implemented when I find a use for it.
- ```DrawUI()``` : Has direct access to the injected ImGUI context and can call any ImGUI function from there.
- ```UpdateXX()``` : Direct access to the main update function in game. The code here runs every GAME frame. Pretty useful for catching unstable pointers and reading inputs.
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

## Getting Started
1. Clone the repo
2. Edit the config.h
3. Everything function is exposed in BaseMod.cpp having to edit any other file in this template should be very rare.

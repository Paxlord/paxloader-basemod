#pragma once
#include <Windows.h>
#include <string>
#include "imgui/imgui.h"

extern int mhfdll_addy = 0;

class Mod {
public:
	std::string name;
	std::string display_name;

	Mod(std::string name, std::string display_name) {
		this->name = name;
		this->display_name = display_name;
	}

	void initImGuiContext(ImGuiContext* ctx) {
		ImGui::SetCurrentContext(ctx);
	}

	//Will run once at game start, where you initialize things like hooks
	virtual void Attach() = 0;
	//Will run once on detach, used to clean up memory if needed
	virtual void Detach() = 0;
	//Linked to the main injected imgui context, can draw whatever here
	virtual void DrawUI() {};
	//Will run every frame in the main update function in quests
	virtual void UpdateQuest() {};
	//WIll run every frame in the main update function in the lobby
	virtual void UpdateLobby() {};
};

extern "C" __declspec(dllexport) void setDllAddress(int dll_addy) {
	mhfdll_addy = dll_addy;
}
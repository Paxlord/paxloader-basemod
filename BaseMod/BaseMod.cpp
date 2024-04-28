#include "BaseMod.h"
#include <Windows.h>
#include <iostream>
#include <MinHook.h>
#include "globals.h"
#include "config.h"

bool myCheckBox = false;
int counter = 0;

//Will run once at game start, use it to setup hooks, offset address, initialize stuff...
void BaseMod::OnAttach() {
	std::cout << "This is a call from test mod attach function! dll handle is : " << mhfdll_addy << std::endl;
}

//Will run once at game end, loader doesn't use it for now
void BaseMod::OnDetach() {

}

//Will run once the ImGUI and Dx9 Context has been initialized, use this function to create texture data
void BaseMod::OnImGUIInit() {

}

//Has access to the main ImGui context, can draw anything related to the mod in there
void BaseMod::DrawModMenu() {
	if (ImGui::CollapsingHeader(DISPLAY_NAME.c_str())) {
		ImGui::Text("Hello From Mod %d", counter);
		ImGui::Checkbox("Test checkbox", &myCheckBox);
	}
}

void BaseMod::DrawUI(bool show_menu) {

}

//TO DO: Will hook the main lobby update function and run once every game frame
void BaseMod::OnUpdateLobby() {

}

//Will hook the main quest update function and run once every game frame
void BaseMod::OnUpdateQuest() {
	counter++;
}

extern "C" {
	__declspec(dllexport) Mod* createMod() {
		return new BaseMod(NAME, DISPLAY_NAME, VERSION, REQUIRED_VERSION, HGE_ONLY);
	}
}
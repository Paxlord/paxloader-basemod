#include "BaseMod.h"
#include <Windows.h>
#include <iostream>
#include <MinHook.h>
#include "globals.h"
#include "config.h"


bool myCheckBox = false;
int counter = 0;

//Will run once at game start, use it to setup hooks, offset address, initialize stuff...
void BaseMod::Attach() {
	std::cout << "This is a call from test mod attach function! dll handle is : " << mhfdll_addy << std::endl;
}

//Will run once at game end, loader doesn't use it for now
void BaseMod::Detach() {

}

//Has access to the main ImGui context, can draw anything related to the mod in there
void BaseMod::DrawUI() {
	ImGui::Text("Hello From Mod %d", counter);
	ImGui::Checkbox("Test checkbox", &myCheckBox);
}

//TO DO: Will hook the main lobby update function and run once every game frame
void BaseMod::UpdateLobby() {

}

//Will hook the main quest update function and run once every game frame
void BaseMod::UpdateQuest() {
	counter++;
}

extern "C" {
	__declspec(dllexport) Mod* createMod() {
		return new BaseMod(NAME, DISPLAY_NAME, VERSION, REQUIRED_VERSION, HGE_ONLY);
	}
}
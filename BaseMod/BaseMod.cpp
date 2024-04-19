#include "BaseMod.h"


void BaseMod::Attach() {
	std::cout << "This is a call from test mod attach function! dll handle is : " << mhfdll_addy << std::endl;
}

void BaseMod::Detach() {

}

void BaseMod::DrawUI() {

}

void BaseMod::UpdateLobby() {

}

void BaseMod::UpdateQuest() {

}

extern "C" {
	__declspec(dllexport) Mod* createMod() {
		return new BaseMod("awesomeMod", "My Test Mod");
	}
}
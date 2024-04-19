#pragma once
#include "mod.h"
#include <iostream>
#include "binutils.h"

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
		std::cout << "Passing context" << std::endl;
		ImGui::SetCurrentContext(ctx);
	}
};

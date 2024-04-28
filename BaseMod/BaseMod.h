#pragma once
#include "mod.h"

class BaseMod :
	public Mod
{
public:

	using Mod::Mod;

	void OnAttach() override;
	void OnDetach() override;
	void DrawUI(bool show_menu) override;
	void DrawModMenu() override;
	void OnUpdateQuest() override;
	void OnUpdateLobby() override;
	void OnImGUIInit() override;
	void InitImGUIContext(ImGuiContext* ctx) override {
		ImGui::SetCurrentContext(ctx);
	}
};

#pragma once
#include "mod.h"
#include <iostream>

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
};

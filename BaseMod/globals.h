#pragma once

inline int mhfdll_addy = 0;

inline void OffsetByDll(int& addy) {
	addy += mhfdll_addy;
}

extern "C" __declspec(dllexport) void setDllAddress(int dll_addy) {
	mhfdll_addy = dll_addy;
}
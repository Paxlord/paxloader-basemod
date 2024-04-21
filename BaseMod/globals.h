#pragma once

extern int mhfdll_addy = 0;

inline int OffsetByDll(int addy) {
	return addy + mhfdll_addy;
}

extern "C" __declspec(dllexport) void setDllAddress(int dll_addy) {
	mhfdll_addy = dll_addy;
}
#pragma once
#include <stdlib.h>
#include <Windows.h>

namespace binutils {

	void ProtectedRead(void* dest, void* src, int len){
		DWORD oldProtect = 0;
		VirtualProtect(dest, len, PAGE_EXECUTE_READWRITE, &oldProtect);
		memcpy(dest, src, len);
		VirtualProtect(dest, len, oldProtect, &oldProtect);
	}

	void ReadBytes(void* read_address, void* read_buffer, int len){
		ProtectedRead(read_buffer, read_address, len);
	}

	void WriteBytes(void* src_address, void* patch, int len) {
		ProtectedRead(src_address, patch, len);
	}

	void DetourCall(void* jmp_addr, void* function_addr, int bytes_to_nop) {
		int jmp_addr_len = 5;
		DWORD offset = ((DWORD)function_addr - (DWORD)jmp_addr) - jmp_addr_len;
		int patch_len = jmp_addr_len + bytes_to_nop;
		BYTE* patch = (BYTE*)malloc(sizeof(BYTE) * (size_t)patch_len);
		memset(patch, 0x90, patch_len);
		patch[0] = 0xe8;
		memcpy(patch + 1, &offset, 4);
		WriteBytes(jmp_addr, patch, patch_len);
	}

	void DetourJMP(void* jmp_addr, void* function_addr, int bytes_to_nop) {
		int jmp_addr_len = 5;
		DWORD offset = ((DWORD)function_addr - (DWORD)jmp_addr) - jmp_addr_len;
		int patch_len = jmp_addr_len + bytes_to_nop;
		BYTE* patch = (BYTE*)malloc(sizeof(BYTE) * (size_t)patch_len);
		memset(patch, 0x90, patch_len);
		patch[0] = 0xe9;
		memcpy(patch + 1, &offset, 4);
		WriteBytes(jmp_addr, patch, patch_len);
	}


}
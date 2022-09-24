#pragma once
#include "../imgui/imgui.h"
#include <Windows.h>
#include <TlHelp32.h>
#include <iostream>

namespace Bypass {
	LPVOID NT = GetProcAddress(LoadLibraryW(L"ntdll"), "NtOpenFile");
	bool EXEC(HANDLE handler) {
		if (NT) {
			char Bytes[5];
			memcpy(Bytes, NT, 5);
			if (WriteProcessMemory(handler, NT, Bytes, 5, NULL)) {
				ImGui::Text("Valve Anti Cheat (VAC) Has been bypassed");
				return TRUE;
			}
		}
		return FALSE;
	}

	bool BUP(HANDLE handler) {
		if (NT) {
			char Bytes[5];
			memcpy(Bytes, NT, 5);
			WriteProcessMemory(handler, NT, Bytes, 0, 0);
			return TRUE;
		}
		return FALSE;
	}
}
#pragma once
#include <Windows.h>
#include <TlHelp32.h>

namespace Injector {
	bool Inject_Process(DWORD PID, string FILE) {
		if (PID == NULL) {
			return false;
		}
		char CDLL[MAX_PATH];
		GetFullPathName(FILE.c_str(), MAX_PATH, CDLL, 0);
		HANDLE handler = OpenProcess(PROCESS_ALL_ACCESS, FALSE, PID);
		LPVOID ALLOCAT = VirtualAllocEx(handler, NULL, sizeof(CDLL), MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
		if (!WriteProcessMemory(handler, ALLOCAT, CDLL, sizeof(CDLL), NULL)) {
			return FALSE;
		}
		CreateRemoteThread(handler, 0, 0, (LPTHREAD_START_ROUTINE)LoadLibrary, ALLOCAT, 0, 0);
		if (handler) {
			CloseHandle(handler);
		}
		return TRUE;
	}
}
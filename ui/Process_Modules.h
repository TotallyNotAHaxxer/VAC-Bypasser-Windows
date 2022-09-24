#pragma once
#include <fstream>
#include <iostream>
#include <Windows.h>
#include <iostream>
#include <TlHelp32.h>
#include "Extras.h"

using namespace std;

namespace ProcFuncs {

	// Base Address 

	auto GMADDR(DWORD procid, auto mname) {
		HANDLE handler = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, procid);
		if (handler != INVALID_HANDLE_VALUE) {
			MODULEENTRY32 Entry;
			Entry.dwSize = sizeof(Entry);
			if (Module32First(handler, &Entry)) {
				do {
					if (!strcmp(Entry.szModule, mname)) {
						CloseHandle(handler);
						return (uintptr_t)Entry.modBaseAddr;
					}
				} while (Module32Next(handler, &Entry));
			}
		}
	}

	// Process data

	DWORD ProcData(const char* PN) {
		HANDLE handler = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
		PROCESSENTRY32 Entry;
		Entry.dwSize = sizeof(Entry);
		if (!Process32First(handler, &Entry)) {
			return NULL;
		}
		do {
			if (!strcmp(Entry.szExeFile, PN)) {
				CloseHandle(handler);
				return Entry.th32ProcessID;
			}
		} while (Process32Next(handler, &Entry));
	}

	
}
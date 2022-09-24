#pragma once
#include "WINDOWS_EXTERNAL_HARDWARE_INFORMATION(Included Header Files).h"
#include "WINDOWS_EXTERNAL_HARDWARE_INFORMATION_ASSEMBLY.h"

/*
Function loads the CPUI information, all values are stored in the WINVARS namespace 

Call the function without any resulted values, This method works for only x86

builds, but later on we might want to be using assembly X64 to run the applicatiopn on a 

lower level for all compile forms. This might create a security vulnerability but it will be patched and debugged 

soon enough before product releases ~ RE43P3R

*/



std::string TYPE() {
	const DWORD id = 0x80000002;
	char T[49];
	memset(T, 0, sizeof(T));
	for (DWORD t = 0; t < 3; t++) { CPU_ASM(id + t); memcpy(T + 16 * t + 0, &deax, 4); memcpy(T + 16 * t + 4, &debx, 4); memcpy(T + 16 * t + 8, &decx, 4); memcpy(T + 16 * t + 12, &dedx, 4);}
	return T;
}


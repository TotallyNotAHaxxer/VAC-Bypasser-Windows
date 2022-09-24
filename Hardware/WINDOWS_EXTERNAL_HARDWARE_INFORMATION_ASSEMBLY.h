#pragma once
#include "WINDOWS_EXTERNAL_HARDWARE_INFORMATION(Included Header Files).h"


DWORD deax;
DWORD debx;
DWORD decx;
DWORD dedx;

void CPU_ASM(DWORD VEAX) {
	__asm {
		mov eax, VEAX
		cpuid
		mov deax, eax
		mov debx, ebx
		mov decx, ecx
		mov dedx, edx
	}
}
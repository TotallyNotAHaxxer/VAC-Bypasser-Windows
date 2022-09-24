#pragma once
#include "WINDOWS_EXTERNAL_HARDWARE_INFORMATION(Included Header Files).h"
#include "WINDOWS_EXTERNAL_HARDWARE_INFORMATION_ASSEMBLY.h"

std::string MANUFACID() {
	char ID[25];
	memset(ID, 0, sizeof(ID));
	CPU_ASM(0);
	memcpy(ID + 0, &debx, 4);
	memcpy(ID + 4, &dedx, 4);
	memcpy(ID + 8, &decx, 4);
	return ID;
}


#pragma once
#include "WINDOWS_EXTERNAL_HARDWARE_INFORMATION(Included Header Files).h"


static const int kMaxInfoBuffer = 256;


std::string MEMI() {
	std::string memory_info;
	MEMORYSTATUSEX statusex;
	statusex.dwLength = sizeof(statusex);
	if (GlobalMemoryStatusEx(&statusex)) {
		unsigned long long total = 0, remain_total = 0, avl = 0, remain_avl = 0;
		double decimal_total = 0, decimal_avl = 0;
		remain_total = statusex.ullTotalPhys % GBYTES;
		total = statusex.ullTotalPhys / GBYTES;
		avl = statusex.ullAvailPhys / GBYTES;
		remain_avl = statusex.ullAvailPhys % GBYTES;
		if (remain_total > 0) { decimal_total = (remain_total / MBYTES) / DKBYTES; } 
		if (remain_avl > 0) { decimal_avl = (remain_avl / MBYTES) / DKBYTES; }
		decimal_total += (double)total;
		decimal_avl += (double)avl;
		char  buffer[kMaxInfoBuffer];
		sprintf_s(buffer, kMaxInfoBuffer, "TOTAL  [ %.2f GB ] -  (%.2f GB available)", decimal_total, decimal_avl);
		memory_info.append(buffer);
	}
	return memory_info;
}

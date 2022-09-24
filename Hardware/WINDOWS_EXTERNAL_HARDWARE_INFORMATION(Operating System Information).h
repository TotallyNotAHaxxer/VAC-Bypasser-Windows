#pragma once
#include "WINDOWS_EXTERNAL_HARDWARE_INFORMATION(Included Header Files).h"

std::string OSI() {
	os_version = {
		sizeof(OSVERSIONINFO)
	};
	GetVersionEx(&os_version); // Deprecated : but working
	if (os_version.dwMajorVersion == 5 && os_version.dwMinorVersion == 0) { os_name = WIN2000; }
	if (os_version.dwMajorVersion == 5 && os_version.dwMinorVersion == 1) { os_name = WINXP; }
	if (os_version.dwMajorVersion == 6 && os_version.dwMinorVersion == 0) { os_name = WIN2003; }
	if (os_version.dwMajorVersion == 5 && os_version.dwMinorVersion == 2) { os_name = WINVISTA; }
	if (os_version.dwMajorVersion == 6 && os_version.dwMinorVersion == 1) { os_name = WIN72000; }
	if (os_version.dwMajorVersion == 6 && os_version.dwMinorVersion == 2) { os_name = WIN10200; }
	return os_name;
}
#pragma once
#include <iostream> 
#include <string>
#include <string.h>
#include <iphlpapi.h>
#include <windows.h>  
#include <intrin.h>
#pragma comment(lib, "iphlpapi.lib")
#pragma warning(disable: 4996)

#define  GBYTES  1073741824  
#define  MBYTES  1048576  
#define  KBYTES  1024  
#define  DKBYTES 1024.0  
#define  WINVISTA "windows vista"
#define  WIN10200 "windows 10"
#define  WIN72000 "windows 7"
#define  WIN2003  "windows 2003"
#define  WIN2000  "windows 2000"
#define  WINXP    "windows XP"


OSVERSIONINFO  os_version;             // Operating System Version
MEMORYSTATUSEX st_statusx;            // Memory Status (STATUS X)
std::string   os_name;               // Operating System Name
std::string   me_info;              // Memory Information 
int cpuinf[4] = { -1 };            // CPU Information call
char cpumanufac[32] = { 0 };      // CPU Manufacturer
char cput[32] = { 0 };           // CPU type 
char cpuf[32] = { 0 };          // CPU Frequency
unsigned long long Total  = 0;
unsigned long long remain = 0;
unsigned long long AVL = 0;
unsigned long long RAVL = 0;
double decimal_total = 0;
double decimal_tavl = 0;

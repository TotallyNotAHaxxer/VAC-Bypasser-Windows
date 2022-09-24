#pragma once
#include <iostream>
#include <fstream>

using namespace std;

namespace Extra_Functions {
	// File checking
	bool F_Exists(string fname) {
		ifstream F(fname.c_str());
		if (F) {
			return true; // file does exist
		}
		else {
			return false; // file does NOT exist
		}
	}
	// Random ID's for generation
	// this code was rewritten and changed out 
	// this is due to the amount of vulnerabilities within the code 
	// the injector was injecting but would break, bug was fixed 
	// laggy would sometimes crash game or pid due to something not being closed most likely handler 
	string Random(const size_t len) {
		string random;
		static const char bet[] = { "ABCDEFGHIJKLMNOPQRSTUVWXYabcdefghijklmnopqrstuvwxyzZ1234567890" };
		srand((unsigned)time(NULL) * 5);
		for (int i = 0; i < len; ++i) {
			random += bet[rand() % (sizeof(bet) - 1)];
		}
		return random;
	}

}
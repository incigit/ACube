#include "stdafx.h"


void main() {
	HWND hwnd = FindWindowA(NULL, "AssaultCube");

	if (hwnd == NULL) {
		std::cout << "Having trouble finding window.\n";
		Sleep(3220);
		exit(-1);
	}

	DWORD procID;
	GetWindowThreadProcessId(hwnd, &procID);

	HANDLE handler = OpenProcess(PROCESS_ALL_ACCESS, 0, procID);

	if (procID == NULL) {
		std::cout << "Can not find process\n";
	}

}


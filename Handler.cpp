#include "stdafx.h"
#include "Handler.h"



void main() {
	HWND hwnd = FindWindowA(NULL, "AssaultCube");

	if (hwnd == NULL) {
		std::cout << "Having trouble finding window.\n";
		Sleep(3220);
		exit(-1);
	}
	else {
		std::cout << "Window locked on.\n";
	}

	DWORD procID;
	GetWindowThreadProcessId(hwnd, &procID);

	HANDLE handler = OpenProcess(PROCESS_ALL_ACCESS, 0, procID);

	if (procID == NULL) {
		std::cout << "Can not find process\n";
		Sleep(3220);
		exit(-1);
	}
	else {
		std::cout << "Process locked on. ID = " << procID << ". \n\n";
	}

	int baseAdress = 0x00509B74;
	int healthOffset = 0xF8;
	//int localPlayer = *((int*)baseAdress);
	int adressToWriteHealth = baseAdress + healthOffset;
	int value;

	for (;;) {
		std::cout << "Set health to:\n";
		std::cin >> value;
		WriteProcessMemory(handler, (LPVOID)adressToWriteHealth, &value, sizeof(value), 0);
	}



}



//void setHealth(int baseAdress, int healthOffset, HANDLE &handler) {
//	std::cout << "Set health to:\n";
//	int value;
//	int adressToWriteHealth = baseAdress + healthOffset;
//	std::cin >> value;
//	WriteProcessMemory(handler, (LPVOID)adressToWriteHealth, &value, 4, 0);
//}
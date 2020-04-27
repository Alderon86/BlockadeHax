#pragma once
#include <Windows.h>
#include <iostream>

struct Console {
	static void Consolebypass() {
		DWORD CheckerValue;
		DWORD* OrginalValue = &CheckerValue;
		VirtualProtect((PVOID)&FreeConsole, 1, PAGE_EXECUTE_READWRITE, OrginalValue);
		*(BYTE*)(&FreeConsole) = (0xC3);
	}
	static void ShowConsole(const char* title)
	{
		Consolebypass();
		AllocConsole();
		freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);
		freopen_s((FILE**)stdin, "CONIN$", "r", stdin);
		SetConsoleTitleA(title);
	}
	static void Log(const char* text)
	{
		std::cout << "[BLOCKADEHAX] [LOG] " << text << std::endl;
	}
};
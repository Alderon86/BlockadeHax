#pragma once
#include <Windows.h>
#include <iostream>

struct Console {
	static void ShowConsole(const char* title)
	{
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
